/*
 * Solange der Taster gedrückt ist,
 * leuchtet die LED
 * T1 mit int. PULLUP-R
 * T2 mit ext. PULLDOWN-R
 */

//Bereich 1
int ledPin = 4; // LED an pin 4
int inPin = 2;  // Taster an Digital-Pin 2
int val = 0;    // variable um den Pinstatus zu speichern

//Bereich 2
void setup()
{
pinMode(ledPin, OUTPUT); // setzt pin 4 als Ausgang
pinMode(inPin, INPUT);   // setzt pin 2 als Eingang
  
  pinMode(LED_BUILTIN, OUTPUT); // pin 13 ist der LED interne LED Ausgang
  pinMode(7, INPUT_PULLUP);     // setzt einen PULLUP-R auf Eingang 7
                                // Taster nach GND, interner PULLUP-R
}

//Bereich 3
void loop()
{
digitalWrite(LED_BUILTIN, !digitalRead(7)); //Int. LED Ausgang 13
 
val = digitalRead(inPin);  // liest pin 2 ein
digitalWrite(ledPin, val); // setzt pin 4 auf den Wert von pin 4
}
