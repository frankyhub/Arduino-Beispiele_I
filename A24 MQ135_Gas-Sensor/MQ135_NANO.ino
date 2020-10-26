 
/*
Board: NANO
ATMega328P Old Bootloader

KHF 26.10.2020

Seriell: 9600 Baud 

08:49:08.605 -> CO2-Gehalt: 832.58 ppm
08:49:10.602 -> CO2-Gehalt: 832.58 ppm
08:49:12.596 -> CO2-Gehalt: 832.58 ppm
08:49:14.603 -> CO2-Gehalt: 852.50 ppm
08:49:16.612 -> CO2-Gehalt: 852.50 ppm
08:49:18.601 -> CO2-Gehalt: 842.50 ppm
08:49:20.622 -> CO2-Gehalt: 842.50 ppm
08:49:22.626 -> CO2-Gehalt: 822.73 ppm
08:49:24.631 -> CO2-Gehalt: 812.97 ppm
08:49:26.651 -> CO2-Gehalt: 812.97 ppm
08:49:28.638 -> CO2-Gehalt: 842.50 ppm
08:49:30.640 -> CO2-Gehalt: 832.58 ppm
*/

#include "MQ135.h"
float ppm;
MQ135 gassensor = analogRead(A3);
void setup() {
 Serial.begin(9600);
 pinMode(A3, INPUT);
}
void loop() {
 ppm = gassensor.getPPM();
 Serial.print("CO2-Gehalt: ");
 Serial.print(ppm * 100);
 Serial.println(" ppm");
 delay (2000);
}
