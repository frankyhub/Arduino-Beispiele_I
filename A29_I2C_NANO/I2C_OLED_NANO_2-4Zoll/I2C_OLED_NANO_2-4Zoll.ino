/***************************************************
Board NANO

Library: https://www.buydisplay.com/white-2-4-inch-arduino-raspberry-pi-oled-display-module-128x64-spi-i2c


****************************************************/
#include <Wire.h>
#include "er_oled.h"

/*
  == Hardware connection ==
 Note:The module needs to be jumpered to I2C interface. R18,R21 Short and R19,R20 Open    
  Unused signal pin Recommended to connect to GND
       OLED   =>    Arduino
  *1.   GND    ->    GND
  *2.   VCC    ->    3.3
  *4.   DC     ->    VSS    
  *7.   SCL    ->    SCL
  *8,9  SDA    ->    SDA  (oled PIN 8 nad PIN9 short)   
  *16.  RES    ->    8
*/

uint8_t oled_buf[WIDTH * HEIGHT / 8];

void setup() {
  Serial.begin(9600);
  Serial.print("OLED Example\n");
  Wire.begin();
  
  /* display an image of bitmap matrix */
  er_oled_begin();
  er_oled_clear(oled_buf);
  er_oled_bitmap(0, 0, PIC1, 128, 64, oled_buf);
  er_oled_display(oled_buf);
  delay(3000);  
  command(0xa7);//--set Negative display 
  delay(3000);
  command(0xa6);//--set normal display
  
  er_oled_clear(oled_buf);
  er_oled_bitmap(0, 0, PIC2, 128, 64, oled_buf);
  er_oled_display(oled_buf);
  delay(3000);
  
  command(0xa7);//--set Negative display 
  delay(3000); 
  command(0xa6);//--set normal display  
  
  er_oled_clear(oled_buf);
  /* display images of bitmap matrix */
  er_oled_bitmap(0, 2, Signal816, 16, 8, oled_buf); 
  er_oled_bitmap(24, 2,Bluetooth88, 8, 8, oled_buf); 
  er_oled_bitmap(40, 2, Msg816, 16, 8, oled_buf); 
  er_oled_bitmap(64, 2, GPRS88, 8, 8, oled_buf); 
  er_oled_bitmap(90, 2, Alarm88, 8, 8, oled_buf); 
  er_oled_bitmap(112, 2, Bat816, 16, 8, oled_buf); 

  er_oled_string(10, 52, "www.oberlab.de", 12, 1, oled_buf); 
 

  er_oled_char3216(0, 16, '1', oled_buf);
  er_oled_char3216(16, 16, '2', oled_buf);
  er_oled_char3216(32, 16, ':', oled_buf);
  er_oled_char3216(48, 16, '3', oled_buf);
  er_oled_char3216(64, 16, '4', oled_buf);
  er_oled_char3216(80, 16, ':', oled_buf);
  er_oled_char3216(96, 16, '5', oled_buf);
  er_oled_char3216(112, 16, '6', oled_buf);

  er_oled_display(oled_buf); 
}

void loop() {

}
