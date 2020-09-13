/*Blink LED */

int GELB_L = 7;
int GELB_R = 5;

void setup()
{
pinMode(GELB_L, OUTPUT);
pinMode(GELB_R, OUTPUT);
}

void loop()
{
digitalWrite(GELB_L, LOW);
digitalWrite(GELB_R, HIGH);
delay(1000);
digitalWrite(GELB_L, HIGH);
digitalWrite(GELB_R, LOW);
delay(1000);
}
