
/* Roboterarm Servo ansteuerung
 *  Board NANO
 *  ATmega328P
 *  LIB: VarSpeedServo.h
 *  https://github.com/netlabtoolkit/varspeedservo
 *  
 *  Version history 
 *  V1.1 20-10-2020 KHF 4xSpeed eingefügt
 *  V1.0 18-10-2020 KHF Start Release
 */


#include <VarSpeedServo.h> 


VarSpeedServo Gr_servo; //Greifarm
VarSpeedServo Dr_servo; //Drehteller
VarSpeedServo Ki_servo;
VarSpeedServo He_servo;

int Poti1 = A1;     //Greifarm
int Poti2 = A2;     //Drehteller
int Joystick_Kippen = A3; //Kipp
int Joystick_Heben = A4; //Heben

int Greifarm;
int Drehteller;
int Kippen;
int Heben;

//Speed festlegen:
int SPEED_Gr = 30; //30 bei Test
int SPEED_Dr = 20; 
int SPEED_Ki = 25; 
int SPEED_He = 25; 

void setup() {
  Gr_servo.attach(6);   //PWM#6
  Dr_servo.attach(9);   //PWM#9
  Ki_servo.attach(10);  //PWM#10
  He_servo.attach(11);  //PWM#11
} 
 
void loop() {

int Poti1 = analogRead(A1);
int Poti2 = analogRead(A2);
int Joystick_Kippen = analogRead(A3);
int Joystick_Heben = analogRead(A4);

  //Greifarm
  Greifarm = map(Poti1, 0, 1023, 0, 175);
  Gr_servo.write(Greifarm, SPEED_Gr);

//Drehteller
Drehteller = map(Poti2, 0, 1023, 0, 175);
Dr_servo.write(Drehteller, SPEED_Dr);

  //Kippen
  Kippen = map(Joystick_Kippen, 0, 1023, 175, 0);
  Ki_servo.write(Kippen, SPEED_Ki);

//Heben
Heben = map(Joystick_Heben, 0, 1023, 0, 175);
He_servo.write(Heben, SPEED_He);

    delay(100);
}
