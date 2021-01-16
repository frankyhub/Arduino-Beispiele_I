/* LED schalten
 *  Board Wemos D1 mini
 *  192.168.1.103
 *  
*/




#include <ESP8266WiFi.h>

 
const char* ssid = "xxx"; //SSID aus dem Router
const char* password = "xxx"; //Passwort für den Zugang zum WLAN
 
const String htmlOK = "HTTP/1.1 200 OK";
const String htmlContentType = "Content-Type: text/html";
const String htmlBegin = "<!DOCTYPE HTML><html>";
const String htmlLinks = "<head><link rel='stylesheet' href='http://frankyhub.de/image/d1.css'/><link rel='shortcut icon' href='http://frankyhub.de/image/fr.ico' /></head><body>";
const String htmlEnd = "</body></html>";
const String htmlBreakLine = "</br>";
 
//int ledPin = D13; //digitaler PIN 5 des Wemos D1 an welchem die LED angeschlossen ist.
int ledStatus = LOW; //aktueller Status der LED (default / start  -> AUS)
WiFiServer server(80); //Port auf welchem der Server laufen soll.
 

int ledStatus = LOW; //aktueller Status der LED (default / start  -> AUS)
WiFiServer server(80); //Port auf welchem der Server laufen soll.
 
void setup() {
  pinMode(BUILTIN_LED, OUTPUT); 
  Serial.begin(115200); //Baudrate für die Serielle Geschwindigkeit.
  delay(10); //10ms. Warten damit die Seriele Kommunikation aufgebaut wurde.
  
  pinMode(BUILTIN_LED, OUTPUT); //Den BUILTIN_LED als ausgang setzen.
  digitalWrite(BUILTIN_LED, ledStatus); //Die LED initial auf den Status "AUS" setzen.
   
  Serial.print("Aufbau der Verbindung zu: "); //Ausgabe der SSID auf der Seriellen Schnittstelle.
  Serial.println(ssid);
  
  WiFi.begin(ssid, password); //Initialisieren der Wifi Verbindung.
 
  while (WiFi.status() != WL_CONNECTED) { //Warten bis die Verbindung aufgebaut wurde.
    delay(500);
    //Einen Punkt auf der Seriellen Schnittstelle ausgeben so das der Benutzer erkennt dass, das Sketch noch läuft.
    Serial.print("."); 
  }
  //Bei erfolgreicher Verbindung wird der folgende Text ausgeben.
  Serial.print("Mit ");
  Serial.print(ssid);
  Serial.print("erfolgreich verbunden!");
 
  
  server.begin(); // Starten des Servers.
  Serial.println("Server gestartet"); //Ausgabe auf der Seriellen Schnittstelle das der Server gestartet wurde.
 
  // Ausgabe der IP Adresse 
  Serial.print("Adresse : http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
}
/**
 * Die Funktion gibt den HTML Kopf auf dem Client aus.
 * Dieses wird für jeden Respond verwendet.
 **/
void printHtmlHeader(WiFiClient client){
  client.println(htmlOK);
  client.println(htmlContentType);
  client.println("");
  client.println(htmlBegin);
  client.println(htmlLinks); 
}
void loop() {
  //Prüfen ob sich ein Client verbunden hat, wenn nicht die Loop "verlassen"
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
 
  // Wenn sich ein Client verbunden hat solange warten bis Daten gesendet werden.
  Serial.println("Neuer Client verbunden.");
  while(!client.available()){
    delay(1);
  }
 
  //Lesen der Anfrage vom Client
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();
  //Wenn in der Anfrage die Zeichenkette "/toggle" vorkommt dann...
  if (request.indexOf("/toggle") != -1) {
    if(ledStatus == HIGH){
      ledStatus = LOW;
    } else {
        ledStatus = HIGH;
    }
    digitalWrite(BUILTIN_LED, ledStatus);
    Serial.print("LED Status: ");
    Serial.println(ledStatus);
  } 
 //Gibt den Html Header auf der Antwort aus.
 printHtmlHeader(client);
  
  //Ab hier wird die Webseite zusammengesetzt.
  client.println("<div class='mainWrapper'>"); 
  client.print("Die LED ist : ");
  
  String value = "-undefined-";
  
  //Die Adresse für die Bilder
  const String imgStartUrl = "http://frankyhub.de/image/";
  String imgUrl = imgStartUrl + "light_on.png";
  
  if(ledStatus == HIGH) {
    value = "AN";
  } else {
    value = "AUS";
    imgUrl = imgStartUrl + "light_off.png";
  }
  client.print(value);  
  
  client.println(htmlBreakLine);
  client.println(htmlBreakLine);
 
  client.println("<img src='"+imgUrl+"' widht='64' height='64'/>");
  client.println(htmlBreakLine);
  
  client.print("<div class='headline'>Klicke <a href=\"/toggle\">hier</a> um die LED ");
  client.print(value=="AN"?"aus":"an");
  client.print(" zuschalten.</div>");
  client.println("");
  client.println("</div>"); 
  client.println(htmlEnd);
 
  delay(1); //1ms. Pause
}
