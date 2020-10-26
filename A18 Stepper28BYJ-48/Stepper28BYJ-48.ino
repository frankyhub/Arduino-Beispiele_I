/* Stepper 
 *  stepper motor  28BYJ-48 
 *  Board: NANO
 *  
 *  KHF 26.10.2020
ebay: https://www.ebay.de/itm/3x-Schrittmotor-28BYJ-48-mit-ULN2003A-Treiber-fur-Arduino-RBP-Mikrocontroller/164237903929?_trkparms=aid%3D111001%26algo%3DREC.SEED%26ao%3D1%26asc%3D225078%26meid%3D93f623dd54f649649933a431538eb3e3%26pid%3D100675%26rk%3D1%26rkt%3D15%26mehot%3Dnone%26sd%3D164237903929%26itm%3D164237903929%26pmt%3D1%26noa%3D1%26pg%3D2380057%26brand%3DMarkenlos&_trksid=p2380057.c100675.m4236&_trkparms=pageci%3A1dc5e136-1487-11eb-9b96-2ef43906d994%7Cparentrq%3A513ad5bf1750aca477515175fff3f166%7Ciid%3A1
 */

#include <Stepper.h>
/*
<Stepper.h>-Funktionen:
Stepper(steps, pin1, pin2)
Stepper(steps, pin1, pin2, pin3, pin4)
setSpeed(rpm)
step(steps)
*/

#define STEPS 2038 // Motor (28BYJ-48)
Stepper stepper(STEPS, 8, 9, 10, 11); // NANO Platine V1.0 NANO V3.1
// Treiber Platine     1  3   2   4          


void setup() {
}

void loop() {
  stepper.setSpeed(3); // 3 rpm
  stepper.step(2038); // 2038 steps/20Sek
  stepper.setSpeed(3); // 3 rpm
  stepper.step(-2038); // -2038 steps/20Sek
          delay(1000); //Pause
  
  stepper.setSpeed(6); // 6 rpm
  stepper.step(2038); // 2038 steps/10 Sek
  stepper.setSpeed(6); // 6 rpm
  stepper.step(-2038); // 2038 steps/10 Sek
          delay(1000); //Pause
  
  stepper.setSpeed(12); // 12 rpm
  stepper.step(2038); // 2038 steps/5 Sek
  stepper.setSpeed(12); // 12 r8pm
  stepper.step(-2038); // 2038 steps/5 Sek
          delay(1000); //Pause
  
  stepper.setSpeed(18); // 18 rpm
  stepper.step(2038); // 2038 steps/3.3 Sek
      delay(1000); //Pause
  stepper.setSpeed(18); // 18 rpm
  stepper.step(-2038); // 2038 steps/3.3 Sek
      delay(1000); //Pause
}
