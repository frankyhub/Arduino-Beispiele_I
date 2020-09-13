/* 
 * FLIP FLOP
 mit SET und RESET
 mit Taster entprellen
 */

int E2 = 2;         // R Taster-Eingang
int E4 = 4;         // S Taster-Eingang     
int LED13 = 13;     // Interne LED

int leseE2;         // Taster-Eingang lesen
int leseE4;         // Taster-Eingang lese

                       // Taster Entprellen
long entprelle = 50;   // 50ms

void setup()
{ 
  pinMode(E2, INPUT_PULLUP); // Interner Pullup, E1 in Ruhe auf HIGH
  pinMode(E4, INPUT_PULLUP);
  pinMode(LED13, OUTPUT);   // Interne LED
}

void loop()
{  
  leseE4 = digitalRead(E4);
  delay(entprelle);
  leseE2 = digitalRead(E2);
  delay(entprelle);
  
  if (leseE4 == LOW) 
  {
    digitalWrite(LED13, HIGH);    
  } 
  
  if (leseE2 == LOW) 
  {
    digitalWrite(LED13, LOW);
  } 

}
