#include <Stepper.h>
 
#define STEPS 32
 
// Stepper Anschlüsse
#define IN1 8
#define IN2 10
#define IN3 9
#define IN4 11
 
// Library initialisieren
Stepper stepper(STEPS, IN4, IN2, IN3, IN1);
 
// Joystick/Poti an NANO A0
#define joystick A0

int LED13 = 13;     // Interne LED
 
void setup()
{
   Serial.begin(9600);
}
 
void loop()
{


    
// Analogwert einlesen
int val = analogRead(joystick);
 Serial.print(val);  
  Serial.println();  
 
// Wenn Joystick in Mittelstellung = Motor stopp
if( (val > 500) && (val < 523) )
{
digitalWrite(IN1, LOW);
digitalWrite(IN2, LOW);
digitalWrite(IN3, LOW);
digitalWrite(IN4, LOW);
digitalWrite(LED13, HIGH); 
}
 
else
{
// Motor rechts
while (val >= 523)
{
  digitalWrite(LED13, LOW); 
// map Speed zwischen 0 und 500 rpm
int speed_ = map(val, 523, 1023, 5, 500);

// Motor Speed
stepper.setSpeed(speed_);
 
// Motordrehung = 1 Stepp
stepper.step(1);
 
val = analogRead(joystick);
 Serial.print(val);  
  Serial.println();  
}
 
// Motor links
while (val <= 500)
{
    digitalWrite(LED13, LOW);
// Speed zwischen 0 und 500 rpm
int speed_ = map(val, 500, 0, 5, 500);
// Set Motor Speed
stepper.setSpeed(speed_);
 
// Motordrehung = 1 Stepp
stepper.step(-1);
val = analogRead(joystick);
 Serial.print(val);  
  Serial.println();  
}
}
}
