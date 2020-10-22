
/*
Board: NANO
Prozessor: ATmega328P (Old Bootloader)

stepper motor  28BYJ-48 
ebay: https://www.ebay.de/itm/3x-Schrittmotor-28BYJ-48-mit-ULN2003A-Treiber-fur-Arduino-RBP-Mikrocontroller/164237903929?_trkparms=aid%3D111001%26algo%3DREC.SEED%26ao%3D1%26asc%3D225078%26meid%3D93f623dd54f649649933a431538eb3e3%26pid%3D100675%26rk%3D1%26rkt%3D15%26mehot%3Dnone%26sd%3D164237903929%26itm%3D164237903929%26pmt%3D1%26noa%3D1%26pg%3D2380057%26brand%3DMarkenlos&_trksid=p2380057.c100675.m4236&_trkparms=pageci%3A1dc5e136-1487-11eb-9b96-2ef43906d994%7Cparentrq%3A513ad5bf1750aca477515175fff3f166%7Ciid%3A1
 */

#include <Stepper.h>

// Get steps per turn and RPM out of datasheet:
// ============================================
// 5.625/64 deg per step --> 4096 steps for 360 deg
// step relates to half-step sequencing, which means 8 steps
// We use 4 full steps ==> 2048 steps per turn
//
// recommended frequency range 600-1000Hz for 8 half-steps
// 1000Hz/4096 half-steps --> approx 4sec per turn is max speed 
// ==> 15rpm
// Note: actually we will use ~500Hz using the 4 step approach
// but motor will not be able to turn faster.

// Get stepping sequence out of datasheet:
// =======================================
// Stepping sequence as given in datasheet
// this is an 8-step half-step approach
//         Steps
// Wire  1  2  3  4  5  6  7  8
// 1                    x  x  x
// 2              x  x  x 
// 3        x  x  x
// 4     x  x                 x
// 
// We use only even / full steps thus:
//         Steps
// Wire  2  4  6  8
//   1         x  x
//   2      x  x 
//   3   x  x 
//   4   x        x
// 
// Code of Arduino Stepper Lib has implemented:
//         Steps
// Wire  1  2  3  4
//   1         x  x
//   2   x  x      
//   3      x  x 
//   4   x        x
//
// ==> Simple Solution: exchange wire 2&3


const int stepsPerRevolution = 2048;  // here go the 2048 steps
// for your motor

// initialize the stepper library on pins 8 through 11 -> IN1, IN2, IN3, IN4
// as shown above, we need to exchange wire 2&3, which we do in the constructor
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);

void setup() 
{
  // set the speed at 15 rpm:
  myStepper.setSpeed(15);
  // initialize the serial port:
  Serial.begin(9600);
}

void loop() 
{
  // step one revolution  in one direction:
  Serial.println("clockwise");
  myStepper.step(stepsPerRevolution);
  delay(500);

  // step one revolution in the other direction:
  Serial.println("counterclockwise");
  myStepper.step(-stepsPerRevolution);
  delay(500);
}
