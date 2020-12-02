/*
 * LED dimmen
 * Board: Uno
 
 PWM: 3, 5, 6, 9, 10, and 11. 
 Provide 8-bit PWM output with the analogWrite() function.
 
 6 Analog Input Pins A0-A5
 
 LED: 13int LED
   
 */

//byte LED1 = 6; //LED dimmen
//byte LED2 = 4; //LED schalten
//byte LED3 = A5; //LED an Analogeingang schalten

//int REGLER1 = A1; //LED dimmen
//int REGLER2 = A2; //LED schalten

int ReglerWert1; //LED dimmen
int ReglerWert2; //LED schalten

void setup()
{
pinMode(6, OUTPUT); //LED dimmen
pinMode(4, OUTPUT); //LED schalten
pinMode(A5, OUTPUT); //LED schalten

// Seriellen Monitor starten
Serial.begin(9600);
}

void loop()
{
/*
//LED mit Analogeingang dimmen  
ReglerWert1 = analogRead(REGLER1);
analogWrite (LED1, map(ReglerWert1, 0, 1023, 0, 255));
*/
//LED mit Analogeingang dimmen  
ReglerWert1 = analogRead(A1);
analogWrite (6, map(ReglerWert1, 0, 1023, 0, 255));

/*
//LED mit Analogeingang e/a schalten 
ReglerWert2 = analogRead(REGLER2);
digitalWrite(LED2,ReglerWert2);
digitalWrite(LED3,ReglerWert2); //LED an Analogeingang schalten
*/
//LED mit Analogeingang e/a schalten 
ReglerWert2 = analogRead(A2);
digitalWrite(4,ReglerWert2);
digitalWrite(A5,ReglerWert2); //LED an Analogeingang schalten
}
