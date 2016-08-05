//Old-Physics-Project

#include <LiquidCrystal.h>
#include <Wire.h>
#include "Adafruit_SI1145.h"
//Required libraries to run the device

Adafruit_SI1145 uv = Adafruit_SI1145(); //uv function var.
LiquidCrystal lcd(7, 8, 9, 10, 11 , 12); //LCD pins

void setup()
{ 
  lcd.begin(16, 2);
  lcd.setCursor(0, 1);
  lcd.write("LIGHT: ");
  lcd.setCursor(0, 0);
  lcd.write("UVI:     IR:");

  Serial.begin(9600);
  Serial.println("Adafruit SI1145 test");
  
  if (! uv.begin())
  {
    Serial.println("Si1145 not functional");
    while (1);
  }

  Serial.println("Adafruit SI1145 is fully functional");
}

void loop()
{ 
  float UVindex = uv.readUV(); //Calculate UV index
  UVindex /= 100.0;
  
  lcd.setCursor(6,1);
  lcd.print(uv.readVisible()); //Read visible light
  lcd.setCursor(4,0);
  lcd.print(UVindex); //Read UV index
  lcd.setCursor(12,0);
  lcd.print(uv.readIR()); //Read infrared light
  delay(100);
}
