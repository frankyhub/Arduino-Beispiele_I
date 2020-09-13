/* Lauflicht
 *  LED dimmen
 *  Board: Uno
 */





int ledPin9 = 9;

int ledPin10 = 10;

int ledPin11 = 11;

int ledPin6 = 6;

int ledPin5 = 5;

int ledPin3 = 3;


//Digital
int ledPin2 = 2;
int ledPin4 = 4;
int ledPin7 = 7;
int ledPin8 = 8;


int zeit= 2;

void setup()
{
  pinMode(ledPin2, OUTPUT); // setzt pin als Ausgang
  pinMode(ledPin4, OUTPUT); // setzt pin als Ausgang
  pinMode(ledPin7, OUTPUT); // setzt pin als Ausgang
  pinMode(ledPin8, OUTPUT); // setzt pin als Ausgang
  
  pinMode(ledPin3, OUTPUT); // setzt pin als Ausgang
  pinMode(ledPin5, OUTPUT); // setzt pin als Ausgang
  pinMode(ledPin6, OUTPUT); // setzt pin als Ausgang
  pinMode(ledPin9, OUTPUT);
    pinMode(ledPin10, OUTPUT);
    pinMode(ledPin11, OUTPUT);
}

void loop()
{


  
  //LED9
  for (int helligkeit =1; helligkeit <= 255; helligkeit = helligkeit +1)
    {
    analogWrite(ledPin9, helligkeit);
    delay(zeit);
    digitalWrite(ledPin2, HIGH);
    }
  for (int helligkeit =255; helligkeit >= 0; helligkeit = helligkeit -1)
    {
    analogWrite(ledPin9, helligkeit);
    delay(zeit);
       digitalWrite(ledPin2, LOW);
    }

  
    //LED10
  for (int helligkeit =1; helligkeit <= 255; helligkeit = helligkeit +1)
    {
    analogWrite(ledPin10, helligkeit);
    delay(zeit);
    digitalWrite(ledPin4, HIGH);
    }
  for (int helligkeit =255; helligkeit >= 0; helligkeit = helligkeit -1)
    {
    analogWrite(ledPin10, helligkeit);
    delay(zeit);
           digitalWrite(ledPin4, LOW);
    }
  
  
    //LED11
  for (int helligkeit =1; helligkeit <= 255; helligkeit = helligkeit +1)
    {
    analogWrite(ledPin11, helligkeit);
    delay(zeit);
        digitalWrite(ledPin7, HIGH);
    }
  for (int helligkeit =255; helligkeit >= 0; helligkeit = helligkeit -1)
    {
    analogWrite(ledPin11, helligkeit);
    delay(zeit);
            digitalWrite(ledPin7, LOW);
    }  
  
    //LED6
  for (int helligkeit =1; helligkeit <= 255; helligkeit = helligkeit +1)
    {
    analogWrite(ledPin6, helligkeit);
    delay(zeit);
    digitalWrite(ledPin8, HIGH);
    }
  for (int helligkeit =255; helligkeit >= 0; helligkeit = helligkeit -1)
    {
    analogWrite(ledPin6, helligkeit);
    delay(zeit);
    digitalWrite(ledPin8, LOW);
    }
  
      //LED5
  for (int helligkeit =1; helligkeit <= 255; helligkeit = helligkeit +1)
    {
    analogWrite(ledPin5, helligkeit);
    delay(zeit);
    }
  for (int helligkeit =255; helligkeit >= 0; helligkeit = helligkeit -1)
    {
    analogWrite(ledPin5, helligkeit);
    delay(zeit);
    }
  
      //LED3
  for (int helligkeit =1; helligkeit <= 255; helligkeit = helligkeit +1)
    {
    analogWrite(ledPin3, helligkeit);
    delay(zeit);
        digitalWrite(ledPin2, HIGH);
    }
  for (int helligkeit =255; helligkeit >= 0; helligkeit = helligkeit -1)
    {
    analogWrite(ledPin3, helligkeit);
    delay(zeit);
        digitalWrite(ledPin2, LOW);
    }
  
  
        //LED5
  for (int helligkeit =1; helligkeit <= 255; helligkeit = helligkeit +1)
    {
    analogWrite(ledPin5, helligkeit);
    delay(zeit);
        digitalWrite(ledPin4, HIGH);
    }
  for (int helligkeit =255; helligkeit >= 0; helligkeit = helligkeit -1)
    {
    analogWrite(ledPin5, helligkeit);
    delay(zeit);
        digitalWrite(ledPin4, LOW);
    }
  
      //LED6
  for (int helligkeit =1; helligkeit <= 255; helligkeit = helligkeit +1)
    {
    analogWrite(ledPin6, helligkeit);
    delay(zeit);
    digitalWrite(ledPin7, HIGH);
    }
  for (int helligkeit =255; helligkeit >= 0; helligkeit = helligkeit -1)
    {
    analogWrite(ledPin6, helligkeit);
    delay(zeit);
        digitalWrite(ledPin7, LOW);
    }
  
      //LED11
  for (int helligkeit =1; helligkeit <= 255; helligkeit = helligkeit +1)
    {
    analogWrite(ledPin11, helligkeit);
    delay(zeit);
    digitalWrite(ledPin8, HIGH);
    }
  for (int helligkeit =255; helligkeit >= 0; helligkeit = helligkeit -1)
    {
    analogWrite(ledPin11, helligkeit);
    delay(zeit);
    digitalWrite(ledPin8, LOW);
    }
  
    
    //LED10
  for (int helligkeit =1; helligkeit <= 255; helligkeit = helligkeit +1)
    {
    analogWrite(ledPin10, helligkeit);
    delay(zeit);
    }
  for (int helligkeit =255; helligkeit >= 0; helligkeit = helligkeit -1)
    {
    analogWrite(ledPin10, helligkeit);
    delay(zeit);
    }
  

  
  
}
