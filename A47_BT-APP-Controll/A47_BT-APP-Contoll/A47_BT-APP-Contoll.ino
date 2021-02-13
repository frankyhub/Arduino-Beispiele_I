/*

PROGRAMMINFO

Funktion: NANO zur Ansteuerung von 2 Getriebemotoren über eine APP
          Getriebemotore am L293D 

Version: 13.02.2021

(x) C++ Arduino IDE V1.8.13
() Python Thonny V3.3.3
() OpenRoberta https://lab.open-roberta.org/ 

Board: NANO 328P

Einstellungen:  
https://arduino.esp8266.com/stable/package_esp8266com_index.json

APP: http://appinventor.mit.edu/

 */
 
int motor1Pin1 = 3; // pin 2 an L293D 
int motor1Pin2 = 5; // pin 7 an L293D 
int enable1Pin = 4; // pin 1 an L293D 
int motor2Pin1 = 9; // pin 10 an L293D 
int motor2Pin2 = 10; // pin 15 an L293D 
int enable2Pin = 8;  // pin 9 an L293D 
int state;
int flag=0;        
int stateStop=0;
void setup() {
    // Outputs:
    pinMode(motor1Pin1, OUTPUT);
    pinMode(motor1Pin2, OUTPUT);
    pinMode(enable1Pin, OUTPUT);
    pinMode(motor2Pin1, OUTPUT);
    pinMode(motor2Pin2, OUTPUT);
    pinMode(enable2Pin, OUTPUT);
    // Enable1Pins
    digitalWrite(enable1Pin, HIGH);
    digitalWrite(enable2Pin, HIGH);
    // Serieller Monitor
    Serial.begin(9600);
}

void loop() {
    //Wenn gesendet wird, Zustand lesen und speichern
    if(Serial.available() > 0){     
      state = Serial.read();   
      flag=0;
    }   
    // 'F' = vorwärts
    if (state == 'F') {
        digitalWrite(motor1Pin1, HIGH);
        digitalWrite(motor1Pin2, LOW); 
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, HIGH);
        if(flag == 0){
          Serial.println("Vorwärts");
          flag=1;
        }
    }
    
    // 'R' = rechts
    else if (state == 'R') {
        digitalWrite(motor1Pin1, HIGH); 
        digitalWrite(motor1Pin2, LOW); 
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, LOW);
        if(flag == 0){
          Serial.println("Rechts");
          flag=1;
        }
        delay(1500);
        state=3;
        stateStop=1;
    }
    // 'S' = Stopp
    else if (state == 'S' || stateStop == 1) {
        digitalWrite(motor1Pin1, LOW); 
        digitalWrite(motor1Pin2, LOW); 
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, LOW);
        if(flag == 0){
          Serial.println("STOPP");
          flag=1;
        }
        stateStop=0;
    }
    // 'L' = links
    else if (state == 'L') {
        digitalWrite(motor1Pin1, LOW); 
        digitalWrite(motor1Pin2, LOW); 
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, HIGH);
        if(flag == 0){
          Serial.println("Links");
          flag=1;
        }
        delay(1500);
        state=3;
        stateStop=1;
    }
    // 'B' = zurück
    else if (state == 'B') {
        digitalWrite(motor1Pin1, LOW); 
        digitalWrite(motor1Pin2, HIGH);
        digitalWrite(motor2Pin1, HIGH);
        digitalWrite(motor2Pin2, LOW);
        if(flag == 0){
          Serial.println("Rückwärts");
          flag=1;
        }
    }
    //For debugging purpose
    Serial.println(state);
}
