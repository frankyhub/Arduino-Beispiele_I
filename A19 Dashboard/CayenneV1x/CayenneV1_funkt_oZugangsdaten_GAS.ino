/*ESP8266 mit DHT11 Sensor und Relais gesteuert über MQTT Dashboard Cayenne
 * https://cayenne.mydevices.com/ 
 * Board: ESP8266 Module ....  WeMos D1 R2 & mini
 * Uploadspeed: 921600
 * CPU Freq: 80MHz
 * Flash Size 4M
 * 
 * Voreinstellungen Boardverwalter 
 * C:\Users\User\Documents\Arduino\libraries\LoRa-ESP32-OLED\esp32\variants\WIFI_LoRa_32
 *  http://arduino.esp8266.com/stable/package_esp8266com_index.json
 *  https://dl.espressif.com/dl/package_esp32_index.json
 *   
 * KHF 23.10.2020
 *  
 *  --------------------------
 * Gassensor (NANO)
 * #include "MQ135.h"
 *float ppm;
 *MQ135 gassensor = analogRead(A3);
 *void setup() {
 * Serial.begin(9600);
 * pinMode(A0, INPUT);
 *}
 *void loop() {
 * ppm = gassensor.getPPM();
 * Serial.print("CO2-Gehalt: ");
 * Serial.print(ppm * 100);
  *Serial.println(" ppm");
 * delay (2000);
 *}
 *  KHF 26.10.2020
 * ----------------------------------
 */

 
//#define CAYENNE_DEBUG
#define CAYENNE_PRINT Serial
#include <CayenneMQTTESP8266.h>
#include <DHTesp.h>


// WiFi network info.
#define SSID "xxx"
#define WIFIPASSWORD "xx"

// Cayenne Zugangsdaten. Diese erhalten wir vom Cayenne Dashboard.
#define USERNAME "x"
#define PASSWORD "x"
#define CLIENTID "x"

//Kanäle zur Kommunikation mit dem Dashboard
#define KANAL_TEMPERATUR 1
#define KANAL_FEUCHTE 2
#define KANAL_RELAIS 3
#define KANAL_STATUS 4
#define KANAL_CO2 5

#define PIN_DHT 5
#define PIN_RELAIS 4

//globale Variablen
boolean relais_status = 0;
TempAndHumidity neueWerte;
DHTesp dht;
  


//
#include "MQ135.h"
#define ANALOGPIN A0    //  Define Analog PIN on Arduino Board
#define RZERO 206.85    //  Define RZERO Calibration Value
MQ135 gasSensor = MQ135(ANALOGPIN);
//

void setup() {
  Serial.begin(115200);
  pinMode(PIN_RELAIS,OUTPUT);
  digitalWrite(PIN_RELAIS,relais_status);
  dht.setup(PIN_DHT, DHTesp::DHT11);
  Cayenne.begin(USERNAME, PASSWORD, CLIENTID, SSID, WIFIPASSWORD);

//
  Serial.begin(9600);
  float rzero = gasSensor.getRZero();
  delay(3000);
  Serial.print("MQ135 RZERO Calibration Value : ");
  Serial.println(rzero);
//
}


void loop() {
  Cayenne.loop();
}

// Diese Funktion wird von Cayenne.loop in regelmäßigen Abständen aufgerufen
// Hier sollten die Daten der Sensoren übertragen werden
CAYENNE_OUT_DEFAULT()
{
  neueWerte = dht.getTempAndHumidity();
  if (dht.getStatus() == 0) {
    Cayenne.celsiusWrite(KANAL_TEMPERATUR,neueWerte.temperature);
    Cayenne.virtualWrite(KANAL_FEUCHTE,neueWerte.humidity,TYPE_RELATIVE_HUMIDITY,UNIT_PERCENT);
    Cayenne.virtualWrite(KANAL_CO2,gasSensor.getPPM(),TYPE_RELATIVE_HUMIDITY,UNIT_PERCENT);
  }
  Cayenne.digitalSensorWrite(KANAL_STATUS,relais_status);
}

//Diese Funktion wird von Cayenne.loop aufgerufen wenn Daten für Aktoren von Cayenne anstehen
//Hier sollte auf diese Daten reagiert werden
CAYENNE_IN_DEFAULT()
{
  if (request.channel == KANAL_RELAIS) {
    relais_status = getValue.asInt();
    digitalWrite(PIN_RELAIS,relais_status);
  }




  //
    float ppm = gasSensor.getPPM();
  delay(1000);
  digitalWrite(13,HIGH);
  Serial.print("CO2 ppm value : ");
  Serial.println(ppm);


  //
}
