/* 
 *  Ultraschallsensor HC-R04 Abstand für Calliope aufbereiten
 *  
 *  HC-R04 Trigger an NANO Pin 9
 *  HC-R04 Echo an NANO Pin 6
 *  NANO Ausgang Pin 5 an Calliope C16 (A1)
 *  
 *  KHF 18.11.2020
 *  V1.0
 * Board: NANO
*/ 


int Abstand;
int Calliope = 5;



// Define Trig and Echo pin:
#define trigPin 9
#define echoPin 6

// Define variables:
long duration;
int distance;

void setup() {
  // Define inputs and outputs:
  pinMode(Calliope, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  //Begin Serial communication at a baudrate of 9600:
  Serial.begin(9600);
}
void loop() {
  // Clear the trigPin by setting it LOW:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  // Trigger the sensor by setting the trigPin high for 10 microseconds:
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Read the echoPin, pulseIn() returns the duration (length of the pulse) in microseconds:
  duration = pulseIn(echoPin, HIGH);
  // Calculate the distance:
  distance = duration * 0.034 / 2;
  // Print the distance on the Serial Monitor (Ctrl+Shift+M):
  Serial.print("Distance = ");
  Serial.print(distance);
  Serial.println(" cm");

delay(50);
 
{


Abstand = distance;
analogWrite (Calliope, Abstand*30);

 Serial.println(Abstand);
 Serial.println(Calliope);
}









  
}
