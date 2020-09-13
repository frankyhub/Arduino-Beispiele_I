/* Analogwertanzeige
 *  Temperaturanzeige: Poti durch NTC ersetzen
 *  Board: Uno
 */


#include <LiquidCrystal.h>
int tempPin = 5;
//                RS  E  D4 D5  D6 D7
LiquidCrystal lcd(12, 11, 8, 7, 6, 5);
void setup()
{
  lcd.begin(16, 2);
}



void loop()
{
  int tempReading = analogRead(tempPin);

  double tempK = log(10000.0 * ((1024.0 / tempReading - 1)));
  tempK = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * tempK * tempK )) * tempK );       //  Temp Kelvin  0.0000000876741 = 23,23C
  float tempC = tempK - 274.15;            // Kelvin zu Celcius wandeln //- 273.15
  //float tempF = (tempC * 9.0)/ 5.0 + 32.0; //  Celcius zu Fahrenheit wandeln

  // Display Temperatur in C
  lcd.setCursor(2, 0);
  lcd.print("Analogwert:           ");
  // Display Temperature in F
  //lcd.print("Temp         F  ");
  lcd.setCursor(5, 1);
  // Display Temperatur in C
  lcd.print(tempC);
  // Display Temperatur in F
  //lcd.print(tempF);
  delay(500);
}
