/*
 * Board: Nano
 * 
 * 21.1.2021
 * 
 */

#include <Wire.h>
#include <SoftwareSerial.h>


int E4 = 4;         // S Taster-Eingang     
int LED13 = 13;     // Interne LED


int leseE4;         // Taster-Eingang lese

                       // Taster Entprellen
long entprelle = 50;   // 50ms

void setup() {

Serial.begin(9600);
  
 // Interner Pullup, E2 in Ruhe auf HIGH
pinMode(E4, INPUT_PULLUP);
pinMode(LED13, OUTPUT);   // Interne LED
}

void loop() {  
  leseE4 = digitalRead(E4);
  delay(entprelle);
  leseE2 = digitalRead(E2);
  delay(entprelle);
  
  if (leseE4 == LOW) 
  {
    digitalWrite(LED13, HIGH);
    Serial.print("1");
    Serial.println();
  } 

  if (leseE4 == HIGH) 
  {
    digitalWrite(LED13, LOW);
    Serial.print("0");
    Serial.println();
  }

}
