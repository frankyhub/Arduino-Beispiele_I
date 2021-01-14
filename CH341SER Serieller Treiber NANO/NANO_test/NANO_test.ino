/*  NANO blink
 *  Board: NANO
 *  Old Bootloader
 *  CH341SER COM-Treiber instaalliert
 *  KHF14-01-2021
 *  
 */


int _led_L = LED_BUILTIN; //int _led_L = 13;
void setup()
{
    pinMode(_led_L, OUTPUT);
}

void loop()
{
    digitalWrite(_led_L, HIGH);
    delay(1500);
    digitalWrite(_led_L, LOW);
    delay(1500);
    digitalWrite(_led_L, HIGH);
    delay(300);
    digitalWrite(_led_L, LOW);
    delay(300);
        digitalWrite(_led_L, HIGH);
    delay(300);
   digitalWrite(_led_L, LOW);
    delay(300);
}
