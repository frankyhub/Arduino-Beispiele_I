// Frequenz-/Rechteckgenerator  https://www.elektronik-labor.de/Arduino/Rechteck.html

#define INLENGTH 5       //maximale Größe der Zahl
#define INTERMINATOR 'H' //'H' von 'Hz'

char inString[INLENGTH+2];
int inCount;

#define MinFreq 33
#define MaxFreq 65535
#define Ausgangspin 13   //muss kein PWM-Pin sein

unsigned int Frequenz = 100; //Hz (Maximum: 65535 Hz)

void setup(){

  Serial.begin(9600);
  Serial.println("Bitte angeben wieviel Hz ausgegeben werden sollen (mit 'Hz')!");
  
  tone(Ausgangspin, Frequenz);
}

void loop(){
  Eingabe();  //Eingabe-Funktion, die Eingabe-String entgegennimmt

  //Zeichenkette -> Zahl
  //Alternative: http://www.arduino.cc/cgi-bin/yabb2/YaBB.pl?num=1176289764
  /*Alternative:
   * 
   * if (serInString[0]==73)  // I
{ for (int i=1; i <= digseq; i++)
 { if (serInString[i]==',')
   { p++;
     i++;
     }    
   char valchar=serInString[i];
     if(p==8 || p==12 || p==13)                        // digital outputs
     { // other code      
     }
     else                                           // PWM outputs
     { valpwm = 0;
       valpwm = (serInString[i]-48)*100;
       valpwm = valpwm + (serInString[i+1]-48)*10;
       valpwm = valpwm + (serInString[i+2]-48);
     
       i=i+2;                                    
       analogWrite(p,valpwm);                   
     }
 }  
}
*/
  Frequenz=atol(inString);

  //Bereich prüfen
  Frequenz=constrain(Frequenz, MinFreq, MaxFreq);

  Serial.print("Es wird gesetzt: ");
  Serial.print(Frequenz,DEC);
  Serial.println("Hz!");

  tone(Ausgangspin, Frequenz);
}

void Eingabe(){
  inCount=0;          //Ziffern-Zähler rücksetzen
  
  do 
  {
    while (Serial.available()==0);       
    inString[inCount] = Serial.read();
    if(inString[inCount]==INTERMINATOR) break;
    if((inString[inCount]<'0')||(inString[inCount]>'9')){
      //continue;     //geht nicht
      inCount--;      //-> Workaround
    }
  }
  while(++inCount < (INLENGTH+1));
  Serial.flush();
}
