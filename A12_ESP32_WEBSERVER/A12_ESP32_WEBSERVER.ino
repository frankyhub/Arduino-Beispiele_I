/* ESP32 WEB Server mit 433MHZ Sender 
 *  V13 26.03.2020
 *  Board ESP32 DEV Module
 *  Einstellungen:  https://dl.espressif.com/dl/package_esp32_index.json
 *                  C:\Users\User\Documents\Arduino\libraries
 *  
 *  
 *  IP Adresse siehe seriellen Monitor 
 *  Upload 921600
 *  CPU Freq 240MHz
 *  Flash Freq 80MHz
 *  Flash Mode QIO
 *  Flash Size 4MB
 *  Part Scheme Default 4 MB  with Spiffs
 *  Core Debug Level keine
 *  PSRAM Disabled
 *  COM COM12
 *  
 *  Programmer: AVRISP
 *  
 *  
 *  Routereinstellungen:
 *  Router: http://tplinklogin.net/ http://192.168.1.1/
 *  
 *  MAC address:  A4:CF:12:9A:2B:18 // Router:   A4-CF-12-9A-2B-18
 *  
 *  IPAddress local_IP      192.168.1.108
 *  IPAddress gateway       192.168.1.1
 *  IPAddress subnet        255.255.0.0
 *  IPAddress primaryDNS    8.8.8.8
 *  IPAddress secondaryDNS  8.8.4.4 
 *  
 *  Änderungen;
 *  V11: HTML Fettschrift
 *  
 */


// 433MHZ Sender
#include <RCSwitch.h>
RCSwitch mySwitch = RCSwitch();

//mySwitch.enableTransmit
const int RC = 12; //Sender an ESP Pin 12

//attachInterrupt(RC, ISR, Mode);


// WEB-Server
// Wi-Fi library
#include <WiFi.h>

// WLAN Zugang:
const char* ssid     = "xxx"; //Eigenen SSID eintragen!
const char* password = "xxx"; /Eigenes Passwort eintagen!

//Static IP address
IPAddress local_IP(192, 168, 1, 109);
// Gateway IP address
IPAddress gateway(192, 168, 1, 1);
//DHCP EInstellung am TPL-Router
IPAddress subnet(255, 255, 0, 0);
IPAddress primaryDNS(8, 8, 8, 8); // optional
IPAddress secondaryDNS(8, 8, 4, 4); // optional

// web server port 80
WiFiServer server(80);

// Variable zum Speichern der HTTP-Anforderung
String header;

// Hilfsvariablen zum Speichern des aktuellen Ausgabezustands
String output25State = "off";
String output26State = "off";
String output27State = "off";
String output32State = "off";
String output33State = "off";
String output34State = "off";

// Zuweisen von Ausgabevariablen zu GPIO-Pins
const int output25 = 25; //Schlafzimmer Deckenleuchte  
const int output26 = 26; //Schlafzimmer Schrankleuchte  
const int output27 = 27; //Flurleuchte
const int output32 = 32; //Woz Fernseh-Leuchte
const int output33 = 33; //Woz Stehleuchte 
const int output34 = 34; //Bad


void setup() 
{
  
//433 MHZ Sender
  mySwitch.enableTransmit(12);  // Der Sender ist an Pin 12 angeschlossen
//  mySwitch.setPulseLength(183);
//  mySwitch.setRepeatTransmit(3);


//WEB-Server
  Serial.begin(115200);
  // Initialisierung der Ausgabevariablen als Ausgänge
  pinMode(output25, OUTPUT); 
  pinMode(output26, OUTPUT);
  pinMode(output27, OUTPUT);
  pinMode(output32, OUTPUT);
  pinMode(output33, OUTPUT);
  pinMode(output34, OUTPUT);
  
  // Ausgänge auf LOW setzen
  digitalWrite(output25, LOW);
  digitalWrite(output26, LOW);
  digitalWrite(output27, LOW);
  digitalWrite(output32, LOW);
  digitalWrite(output33, LOW);
  digitalWrite(output34, LOW);
  
  // Herstellen der Wlan-Verbindung mit SSID und Passwort
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  // Lokale IP-Adresse anzeigen und Webserver starten
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();
}


void loop()
{
//WEB-Server  
  
  WiFiClient client = server.available();   // Eingehende Clients

  if (client) {                             // Wenn ein neuer Client eine Verbindung herstellt,
    Serial.println("New Client.");          // im seriellen Port anzeigen
    String currentLine = "";                // Erstellen eines Strings für eingehende Daten vom Client
    while (client.connected()) {            // Schleife, während der Client verbunden ist
      if (client.available()) {             // wenn es Daten vorhanden, die vom Client gelesen werden können,
        char c = client.read();             // lesen der Daten, dann
        Serial.write(c);                    // am seriellen Monitor ausgeben
        header += c;
        if (c == '\n') {                    // Wenn das Byte ein Zeilenumrandzeichen ist
          // Wenn die aktuelle Zeile leer ist,zwei Zeilenzeilenzeichen in einer Reihe.
          // Dies ist das Ende der Client-HTTP-Anforderung, also Antwort senden:
          if (currentLine.length() == 0) {
            // HTTP-Header beginnen immer mit einem Antwortcode (z.B. HTTP/1.1 200 OK)
            // und ein Inhaltstyp, damit der Client weiß, was kommt, dann eine leere Zeile:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();

//************************************************************************ GPIO 25 Schlafzimmer Deckenleuchte  *************************************************************************
            
             if (header.indexOf("GET /25/on") >= 0) 
            {
              Serial.println("GPIO 25 on");
              output25State = "on";
              digitalWrite(output25, HIGH);
              
                            mySwitch.switchOff("01011", "10000");
                            delay(100);   // 100ms Pause
            } 
            else if (header.indexOf("GET /25/off") >= 0) 
                        {
              Serial.println("GPIO 25 off");
              output25State = "off";
              digitalWrite(output25, LOW);
              
                            mySwitch.switchOn("01011", "10000");
                            delay(100);   // 100ms Pause  
            }            
            
//************************************************************************ GPIO 26 Schlafzimmer Schrankleuchte ***********************************************************

            else if (header.indexOf("GET /26/on") >= 0) 
            {
              Serial.println("GPIO 26 on");
              output26State = "on";
              digitalWrite(output26, HIGH);
              
                                  mySwitch.switchOff("01011", "01000");
                                  delay(100);   // 100ms Pause
            } 
            else if (header.indexOf("GET /26/off") >= 0) 
            {
              Serial.println("GPIO 26 off");
              output26State = "off";
              digitalWrite(output26, LOW);
              
                                  mySwitch.switchOn("01011", "01000");              
                                  delay(100);  // 100ms Pause                              
            }
            
//************************************************************************ GPIO 27 Flurleuchte ************************************************************
            
            else if (header.indexOf("GET /27/on") >= 0) 
            {
              Serial.println("GPIO 27 on");
              output27State = "on";
              digitalWrite(output27, HIGH);
              
                              mySwitch.switchOff("01011", "00100"); 
                              delay(100);  // 100ms Pause
            } 
            else if (header.indexOf("GET /27/off") >= 0) 
                        {
              Serial.println("GPIO 27 off");
              output27State = "off";
              digitalWrite(output27, LOW);
              
                               mySwitch.switchOn("01011", "00100");
                               delay(100);   // 100ms Pause
            }


//************************************************************************ GPIO 32 Wohnzimmer Fernsehleuchte *************************************************************

            else if (header.indexOf("GET /32/on") >= 0) 
            {
              Serial.println("GPIO 32 on");
              output32State = "on";
              digitalWrite(output32, HIGH);
                            
                                  mySwitch.switchOff("10011", "10000");
                                  delay(100);   // 100ms Pause
            } 
            else if (header.indexOf("GET /32/off") >= 0) 
                        {
              Serial.println("GPIO 32 off");
              output32State = "off";
              digitalWrite(output32, LOW);
                            
                               mySwitch.switchOn("10011", "10000");
                               delay(100);   // 100ms Pause
            }

//************************************************************************ GPIO 33 Wohnzimmer Stehleuchte *************************************************************************
            
            else if (header.indexOf("GET /33/on") >= 0) 
            {
              Serial.println("GPIO 33 on");
              output33State = "on";
              digitalWrite(output33, HIGH);
                            
                                  mySwitch.switchOff("10011", "01000");
                                  delay(100);   // 100ms Pause              
            } 
            else if (header.indexOf("GET /33/off") >= 0) 
                        {
              Serial.println("GPIO 33 off");
              output33State = "off";
              digitalWrite(output33, LOW);
                            
                               mySwitch.switchOn("10011", "01000");
                               delay(100);   // 100ms Pause
            }

//************************************************************************ GPIO 34 Badleuchte *********************************************************************

           else if (header.indexOf("GET /34/on") >= 0) 
            {
              Serial.println("GPIO 34 on");
              output34State = "on";
              digitalWrite(output34, HIGH);
                                          
                                  //mySwitch.switchOff("01011", "01000");
                                  //delay(100);   // 100ms Pause
            } 
            else if (header.indexOf("GET /34/off") >= 0) 
                        {
              Serial.println("GPIO 34 off");
              output34State = "off";
              digitalWrite(output34, LOW);
                            
                               //mySwitch.switchOn("01011", "00100");
                               //delay(100);   // 100ms Pause
            }

//************************************************************************ HTML **************************************************************************************            
            
            // HTML web page
            client.println("<!DOCTYPE html><html>");
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<link rel=\"icon\" href=\"data:,\">");
            // CSS to style the on/off buttons 
            // Feel free to change the background-color and font-size attributes to fit your preferences
            client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
            client.println(".button { background-color: #0085ff; border: none; color: white; padding: 16px 40px;");   //background-color: #4CAF50; //grün //#e33900 rot //#0085ff blau
            client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
            client.println(".button2 {background-color: #555555;}</style></head>");     //background-color: #555555; //grau
            
            // Webseitenüberschrift
            client.println("<body><h1>KHF Web Server</h1>");

            
//************************************************************************ GPIO 32 Wohnzimmer Fernsehleuchte *************************************************************

          // Aktuelle Anzeige des aktuellen Zustands und ON/OFF-Tasten für GPIO 32  
          // client.println("<p>GPIO 32 - Status "     + output32State + "</p>");
              client.println("<p><b>Wohnzimmer Fernsehleuchte </b></p>");
            // If the output32State is off, it displays the ON button       
            if (output32State=="off") 
            {
              client.println("<p><a href=\"/32/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/32/off\"><button class=\"button button2\">OFF</button></a></p>");
            }
            
//************************************************************************ GPIO 33 Wohnzimmer Stehleuchte **************************************************************************

          // Aktuelle Anzeige des aktuellen Zustands und ON/OFF-Tasten für GPIO 33  
          // client.println("<p>GPIO 33 - Status "     + output33State + "</p>");
              client.println("<p><b>Wohnzimmer Stehleuchte </b></p>");
            // If the output33State is off, it displays the ON button       
            if (output33State=="off") 
            {
              client.println("<p><a href=\"/33/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/33/off\"><button class=\"button button2\">OFF</button></a></p>");
            }
            
//************************************************************************ GPIO 25 Schlafzimmer-Deckenleuchte *************************************************************************

            // Aktuelle Anzeige des aktuellen Zustands und ON/OFF-Tasten für GPIO 25  
            //client.println("<p>GPIO 25 - Status " + output25State + "</p>");
              client.println("<p><b>Schlafzimmer Deckenleuchte  </b></p>");//client.println("<p><b>Schlafzimmer Deckenleuchte " + output25State + "</b></p>");
            
            // If the output25State is off, it displays the ON button       
            if (output25State=="off") {
              client.println("<p><a href=\"/25/on\"><button class=\"button \"><b>ON</b></button></a></p>");
            } else {
              client.println("<p><a href=\"/25/off\"><button class=\"button button2\">OFF</button></a></p>");
            }

//************************************************************************ GPIO 26 Schlafzimmer-Schrankleuchte ***********************************************************

            // Aktuelle Anzeige des aktuellen Zustands und ON/OFF-Tasten für GPIO 26 
                        client.println("<p><b>Schlafzimmer Schrankleuchte  </b></p>");//client.println("<p><b>Schlafzimmer Schrankleuchte " + output26State + "</b></p>");
            // If the output26State is off, it displays the ON button       
            if (output26State=="off") {
              client.println("<p><a href=\"/26/on\"><button class=\"button \"><b>ON</b></button></a></p>");
            } else {
              client.println("<p><a href=\"/26/off\"><button class=\"button button2\">OFF</button></a></p>");
            } 

//************************************************************************ GPIO 27 Flurleuchte  **********************************************************
               
            // Aktuelle Anzeige des aktuellen Zustands und ON/OFF-Tasten für GPIO 27  
            client.println("<p><b>Flurleuchte  </b></p>");             //            client.println("<p><b>Flurleuchte " + output27State + "</b></p>");
            // If the output27State is off, it displays the ON button       
            if (output27State=="off") {
              client.println("<p><a href=\"/27/on\"><button class=\"button\"><b>ON</b></button></a></p>");
            } else {
              client.println("<p><a href=\"/27/off\"><button class=\"button button2\">OFF</button></a></p>");
            }

            
/*
//************************************************************************ GPIO 34 Fernsehleuchte **************************************************************************

          // Aktuelle Anzeige des aktuellen Zustands und ON/OFF-Tasten für GPIO 34  
          // client.println("<p>GPIO 34 - Status "     + output34State + "</p>");
              client.println("<p>Fernsehleuchte " + output34State + "</p>");
            // If the output34State is off, it displays the ON button       
            if (output34State=="off") 
            {
              client.println("<p><a href=\"/34/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/34/off\"><button class=\"button button2\">OFF</button></a></p>");
            }
*/
//**************************************************************************************************************************************************************************
            
            client.println("</body></html>");
        
            
            // Die HTTP-Antwort endet mit einer leeren Zeile
            client.println();
            // Beenden aus der While-Schleife
            break;
          } else { // Wenn eine neue Zeile, dann lösche die currentLine
            currentLine = "";
          }
        } else if (c != '\r') {  // wenn etwas anderes als RETURN gdrückt,
          currentLine += c;      // dann füge es am Ende der currentLine hinzu
        }
      }
    }
    // Löschen der Headervariablen
    header = "";
    // Verbindung schließen
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
  }
} //************************************************************************************** Programm-ENDE ********************************************************************
