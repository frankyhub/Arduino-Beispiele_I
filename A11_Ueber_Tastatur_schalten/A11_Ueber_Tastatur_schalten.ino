/* Interne LED 13 über Serial Monitor und Tastatur
ein/ ausschalten 
e=EIN
a=AUS
*/

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("*** LED Steuerung ***");
  Serial.println("*** e= einschalten, a=ausschalten***");
  Serial.println("e oder a mit RETURN senden oder SEND betätigen");
}

void loop()
{
  if (Serial.available())//Ist eine Eingabe erfolgt
   { 
    char Eingabe =
    Serial.read();    //Eingabe auslesen
    
    if(Eingabe =='e')
      {digitalWrite(LED_BUILTIN, HIGH);
         Serial.println("LED wurde eingeschalten");
         }
    if(Eingabe =='a')
        {digitalWrite(LED_BUILTIN, LOW);
         Serial.println("LED wurde ausgeschalten");
        }
    }
  }
