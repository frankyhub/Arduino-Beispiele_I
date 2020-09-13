/*
 * LED dimmen
 * Board: Uno
 */

int LED = 6;
int REGLER = A0;
int ReglerWert;

void setup()
{
pinMode(LED, OUTPUT);
// Seriellen Monitor starten
Serial.begin(9600);
}
void loop()
/*
Alternativ kannst du auch den map-Befehl verwenden: 
{
Serial.print(ReglerWert);
ReglerWert = analogRead(REGLER);
analogWrite(LED, ReglerWert / 4);
}
*/

{
ReglerWert = analogRead(REGLER);
analogWrite (LED, map(ReglerWert, 0, 1023, 0, 255));
}
