
/*
 * LED1 dimmen
 * LED3 schalten
 * Board: Uno
 */

int LED1 = 6;
int LED3 = 4;

int REGLER1 = A0;
int REGLER2 = A1;

int ReglerWert1;
int ReglerWert2;

void setup()
{
pinMode(LED1, OUTPUT);
pinMode(LED3, OUTPUT); 
  
// Seriellen Monitor starten
Serial.begin(9600);
}

void loop()
{
//LED mit Analogeingang dimmen  
ReglerWert1 = analogRead(REGLER1);
analogWrite (LED1, map(ReglerWert1, 0, 1023, 0, 255));

//LED mit Analogeingang e/a schalten  
ReglerWert2 = analogRead(REGLER2);
digitalWrite(LED3,ReglerWert2);
delay(100);
  
/*  
if (ReglerWert2>700) digitalWrite(LED3, HIGH);
if (ReglerWert2<400) digitalWrite(LED3, LOW);
Serial.print(ReglerWert2);
Serial.println(); 
*/
}
