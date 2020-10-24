#include <M5Stack.h>
#include "DHT12.h"
#include <Wire.h>     //The DHT12 uses I2C comunication.
DHT12 dht12;          //Preset scale CELSIUS and ID 0x5c.

/*
For configuration library:
DHT12 dht12("Scale temperature","ID device for I2C");
On "Scale temperature" you can select the preset scale:
CELSIUS, FAHRENHEIT or KELVIN.
And on "ID device", you can put ID sensor, on DHT12
normally is 0x5c.
Examples:
  DHT12 dht12;
The preset scale is CELSIUS and ID is 0x5c.
  DHT12 dht12(KELVIN);
the preset scale is KELVIN and ID is 0x5c.
  DHT12 dht12(FAHRENHEIT,0x53);
The preset scale is FAHRENHEIT and ID is 0x53.
*/
  int xt=10;
  int yt=80;
  int xf=10;
  int yf=150;
  int xp=260;
  int yp=150;

  
void setup() {
  M5.begin();
  Wire.begin();
M5.Lcd.setTextSize(3);
  Serial.println("Temp. und Feuchte:");
  M5.Lcd.println("Temp und Feuchte:");

}

void loop() {
  //Read temperature with preset scale.
  Serial.print("Temperatur: ");
     M5.Lcd.setCursor(xt, yt);
     M5.Lcd.print("Temp: ");
  Serial.print(dht12.readTemperature());

  M5.Lcd.print(dht12.readTemperature());

  //Read humidity.
  Serial.print("*C    Feuchte: ");
  M5.Lcd.print(" *C");
  Serial.print(dht12.readHumidity());
  M5.Lcd.setCursor(xf, yf);
    M5.Lcd.print("Feuchte:");     
  M5.Lcd.println(dht12.readHumidity());
    M5.Lcd.setCursor(xp, yp);
M5.Lcd.print("%");
  /*

  //Read temperature as forced fahrenheit.
  Serial.println("%RH");
  Serial.println("%RH");
  Serial.print("Temperatura: ");
  Serial.print(dht12.readTemperature(FAHRENHEIT));

  //Read termperature as forced kelvin.
  Serial.println("*F");
  Serial.print("Temp: ");
  Serial.print(dht12.readTemperature(KELVIN));
  Serial.println("*K");
*/
  delay(5000);
}
