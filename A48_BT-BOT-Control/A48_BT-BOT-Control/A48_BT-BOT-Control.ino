/* 

PROGRAMMINFO:

Funktion: ESP32 Bluetooth BOT-Control. Mover 2 mit APP gesteuert
Bluetooth: Der UNO meldelt sich mit ESP32khf

Version: 16.02.2021
(x) C++ Arduino IDE V1.8.13
Board: ESP32vn IoT UNO V1.0.4

Einstellungen:  https://dl.espressif.com/dl/package_esp32_index.json

https://arduino.esp8266.com/stable/package_esp8266com_index.json
https://dl.espressif.com/dl/package_esp32_index.json
http://dan.drown.org/stm32duino/package_STM32duino_index.json
https://dl.espressif.com/dl/package_esp32_index.json
https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_dev_index.json

  
 */

#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;


//-------------ESP32 UNO / L298N-------------------------
int motor1Pin1 = 34; // pin 5 an L293N IN1
int motor1Pin2 = 35; // pin 6 an L293N IN2
int enable1Pin = 12; // pin 4 an L293N ENA
int motor2Pin1 = 36; // pin 7 an L293N IN3
int motor2Pin2 = 39; // pin 8 an L293N IN4
int enable2Pin = 13;  // pin 9 an L293N ENB
int state;
int flag=0;        
int stateStop=0;
//----------------------------------------

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32khf"); //Bluetooth Name im HAndy/Tablet sichtbar
  Serial.println("Das Gerät ist gestartet, Bluetooth-Kopplung jetzt möglich!");


//----------------------------------------
// Outputs:
    pinMode(motor1Pin1, OUTPUT);
    pinMode(motor1Pin2, OUTPUT);
    pinMode(enable1Pin, OUTPUT);
    pinMode(motor2Pin1, OUTPUT);
    pinMode(motor2Pin2, OUTPUT);
    pinMode(enable2Pin, OUTPUT);
    // Enable1Pins
    digitalWrite(enable1Pin, HIGH);
    digitalWrite(enable2Pin, HIGH);
//----------------------------------------
  
}

void loop() {
  if (Serial.available()) {
    SerialBT.write(Serial.read());
  }
  if (SerialBT.available()) {
    Serial.write(SerialBT.read());
  }
  delay(20);

//----------------------------------------
//Wenn gesendet wird, Zustand lesen und speichern
    if(Serial.available() > 0){     
      state = Serial.read();   
      flag=0;
    }   
    // 'F' = vorwärts
    if (state == 'F') {
        digitalWrite(motor1Pin1, HIGH);
        digitalWrite(motor1Pin2, LOW); 
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, HIGH);
        if(flag == 0){
          Serial.println("Vorwärts");
          flag=1;
        }
    }
    
    // 'R' = rechts
    else if (state == 'R') {
        digitalWrite(motor1Pin1, HIGH); 
        digitalWrite(motor1Pin2, LOW); 
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, LOW);
        if(flag == 0){
          Serial.println("Rechts");
          flag=1;
        }
        delay(1500);
        state=3;
        stateStop=1;
    }
    // 'S' = Stopp
    else if (state == 'S' || stateStop == 1) {
        digitalWrite(motor1Pin1, LOW); 
        digitalWrite(motor1Pin2, LOW); 
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, LOW);
        if(flag == 0){
          Serial.println("STOPP");
          flag=1;
        }
        stateStop=0;
    }
    // 'L' = links
    else if (state == 'L') {
        digitalWrite(motor1Pin1, LOW); 
        digitalWrite(motor1Pin2, LOW); 
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, HIGH);
        if(flag == 0){
          Serial.println("Links");
          flag=1;
        }
        delay(1500);
        state=3;
        stateStop=1;
    }
    // 'B' = zurück
    else if (state == 'B') {
        digitalWrite(motor1Pin1, LOW); 
        digitalWrite(motor1Pin2, HIGH);
        digitalWrite(motor2Pin1, HIGH);
        digitalWrite(motor2Pin2, LOW);
        if(flag == 0){
          Serial.println("Rückwärts");
          flag=1;
        }
    }
    //For debugging purpose
    Serial.println(state);

//----------------------------------------

  
}
