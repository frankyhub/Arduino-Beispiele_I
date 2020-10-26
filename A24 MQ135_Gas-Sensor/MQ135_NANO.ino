  
/*
Board: NANO
ATMega328P Old Bootloader

KHF 25.10.2020

Seriell: 9600 Baud 

18:36:03.010 -> MQ135 RZERO Calibration Value : 849.93
18:36:03.111 -> CO2 ppm value : 705.52
18:36:04.089 -> CO2 ppm value : 705.52
18:36:05.106 -> CO2 ppm value : 705.52
18:36:06.089 -> CO2 ppm value : 705.52

*/

#include "MQ135.h"
#define ANALOGPIN A0    //  Define Analog PIN on Arduino Board
#define RZERO 206.85    //  Define RZERO Calibration Value
MQ135 gasSensor = MQ135(ANALOGPIN);

void setup()
{
  Serial.begin(9600);
  float rzero = gasSensor.getRZero();
  delay(3000);
  Serial.print("MQ135 RZERO Calibration Value : ");
  Serial.println(rzero);
}

void loop() {
  float ppm = gasSensor.getPPM();
  delay(1000);
  digitalWrite(13,HIGH);
  Serial.print("CO2 ppm value : ");
  Serial.println(ppm);
}
