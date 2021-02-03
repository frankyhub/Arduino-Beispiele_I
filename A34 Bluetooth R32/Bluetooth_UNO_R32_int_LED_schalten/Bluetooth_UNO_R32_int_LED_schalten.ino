/* Bluetooth Test für ESP32 UNO R32
 *  Terminal Test mit APP "Serial Bluetooth Terminal"
 *  Vor dem Test, erst unter Tablett-Einstellungen den UNO "ESP32test" verbinden
 *  
 *  Eingabe in der Statuszeile der APP:
 *  led_on -> interne LED EIN
 *  led_off -> interne LED AUS
 *  
 *  In M1 kann led_on gespeichert werden und
 *  in M2 kann led_off gespeichert werde.
 *  Ein kurzer Tastendruck auf M1/M2 schaltet die interne LED ein/aus
 *  
 *  Anschluss des DS18B20-Temperatursensors am GPIO39
 *  Die Sensorwerte Temperatur in °C und Fahrenheit werden in der APP alle 10s ausgegeben
 */

// Libraries
#include "BluetoothSerial.h"
#include <OneWire.h>
#include <DallasTemperature.h>

// Überprüfen, ob die Bluetooth-Konfigurationen aktiviert sind
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

// Bluetooth Serial-Objekt
BluetoothSerial SerialBT;

// GPIO2, interne LED
const int ledPin =  2;

// GPI39 ist mit dem DS18B20 verbunden
const int oneWireBus = 39;          
// Einrichten der oneWire-Instanz für die Kommunikation mit OneWire-Geräten
OneWire oneWire(oneWireBus);
// oneWire-Verweis auf den Dallas Temperatursensor übergeben
DallasTemperature sensors(&oneWire);

// Empfangene und gesendete Nachrichten verarbeiten
String message = "";
char incomingChar;
String temperatureString = "";

// Timer Hilfsvariable
unsigned long previousMillis = 0;    // Intervall, in dem die Sensorwerte veröffentlicht werden sollen
const long interval = 10000;         

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(115200);
  // Bluetooth device name
  SerialBT.begin("ESP32");
  Serial.println("Das Gerät ist gestartet, jetzt können mit Bluetooth koppeln!");
}

void loop() {
  unsigned long currentMillis = millis();
  // Send temperature readings
  if (currentMillis - previousMillis >= interval){
    previousMillis = currentMillis;
    sensors.requestTemperatures(); //Sensorwerte: Ausgabe in °C              und in                    Fahrenheit
    temperatureString = String(sensors.getTempCByIndex(0)) + "C  " +  String(sensors.getTempFByIndex(0)) + "F";
    SerialBT.println(temperatureString); 
  }
  // Empfangene Nachrichten lesen (LED-Steuerbefehl)
  if (SerialBT.available()){
    char incomingChar = SerialBT.read();
    if (incomingChar != '\n'){
      message += String(incomingChar);
    }
    else{
      message = "";
    }
    Serial.write(incomingChar);  
  }
  // Überprüfen der empfangenen Nachricht
  if (message =="led_on"){
    digitalWrite(ledPin, HIGH);
  }
  else if (message =="led_off"){
    digitalWrite(ledPin, LOW);
  }
  delay(20);
}
