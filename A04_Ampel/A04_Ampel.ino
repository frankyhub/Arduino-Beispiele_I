/*
 * Ampel
 * Board: Uno
 */

int ROT = 5; 
int GELB = 6;
int GRUEN = 7;

void setup() {
pinMode(ROT, OUTPUT);   
pinMode(GELB, OUTPUT);   
pinMode(GRUEN, OUTPUT); 
}

void loop() {
digitalWrite(ROT, HIGH);      //1
digitalWrite(GELB, LOW);      //2
delay(5000);                  //3
digitalWrite(GELB, HIGH);     //4
delay(2000);                 //5
digitalWrite(ROT, LOW);       //6
digitalWrite(GELB, LOW);      //7
digitalWrite(GRUEN, HIGH);  //8
delay(3000);                  //9
digitalWrite(GRUEN, LOW);   //10
digitalWrite(GELB, HIGH);     //11
delay(2000);                  //12

}
