/* Beispiel Array
 *  Board: UNO
 *  
 *  Aufbau: https://www.tinkercad.com/things/bayWo9URcHv-smooth-bruticus/editel?tenant=circuits
 *  KHF 22.10.2020
 */
int timer = 100;           
int ledPins[] = {2, 7, 4, 6, 5, 3};       
int pinCount = 6;           

void setup() {
  for (int thisPin = 0; thisPin < pinCount; thisPin++) {
  pinMode(ledPins, OUTPUT);
  }
}

void loop() {

  for (int thisPin = 0; thisPin < pinCount; thisPin++) {
    digitalWrite(ledPins, HIGH);
    delay(timer);
    digitalWrite(ledPins, LOW);
  }

  for (int thisPin = pinCount - 1; thisPin >= 0; thisPin--) {
    digitalWrite(ledPins, HIGH);
    delay(timer);
    digitalWrite(ledPins, LOW);
  }
}
