/* Impulszählern
 *  Board: Uno
 */


#include <LiquidCrystal.h>
int tempPin = 5;
//                RS  E  D4 D5  D6 D7
LiquidCrystal lcd(12, 11, 8, 7, 6, 5);

const int buttonPin = 4;     // Eingang Zählerpin
boolean buttonState, oldButtonState;
unsigned long anzeigeMillis, aktMillis;
const int anzeigeZeit = 1000;

void setup() 
{
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(9600);
  buttonState = digitalRead(buttonPin);
  oldButtonState = buttonState;
  {
      lcd.begin(16, 2);
  }
  }
void loop()

  {
    static int Puls;
  aktMillis = millis();
  buttonState = digitalRead(buttonPin);

  if ( buttonState && !oldButtonState ) {   // positive Flanke erkannt
    //delay(200); // Entprellen
    Puls++;
  }
  oldButtonState = buttonState;
  if (aktMillis - anzeigeMillis >= anzeigeZeit) {
    anzeigeMillis = aktMillis;
    Serial.print("Puls: ");
    Serial.println(Puls);
    
    lcd.setCursor(0, 0);
    lcd.print("Impulse:           ");
    lcd.setCursor(9, 0);
    lcd.print(Puls);
    
  }
}
