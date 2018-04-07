#include <DigisparkOLED.h>
#include <Wire.h>
// ============================================================================

#include "bitmaps.h"


void setup() {
  oled.begin();
}

void loop() {
  oled.clear(); //all black
  delay(1000);

//  oled.setCursor(0, 0); //top left
//  oled.setFont(FONT8X16);
//  oled.print(F("ni hao, hola, hello, namaste, marhabaan, oi, salaam, zdravstvuyte, konnichiwa, sata sri akala")); //wrap strings in F() to save RAM!
//  delay(3000);

oled.setFont(FONT8X16);
oled.setCursor(20, 0);
oled.print(F("ni hao"));
delay(1000);

oled.setCursor(60, 2);
oled.print(F("hola"));
delay(1000);

oled.setCursor(20, 4);
oled.print(F("hello"));
delay(1000);

oled.setCursor(50, 6);
oled.print(F("namaste"));
delay(1000);

oled.setCursor(20, 0);
oled.print(F("marhabaan"));
delay(1000);


oled.setCursor(40, 2);
oled.print(F("   oi   "));
delay(1000);

oled.setCursor(10, 4);
oled.print(F("zdravstvuyte"));
delay(1000);

oled.setCursor(40, 6);
oled.print(F("konnichiwa"));
delay(1000);


oled.setCursor(0, 0);
oled.print(F("sata sri akala"));
delay(1000);



  oled.clear(); 
  oled.setCursor(30, 2); 
  oled.setFont(FONT6X8);
  oled.print(F("I'M")); 
  oled.setCursor(30, 3);
  oled.setFont(FONT8X16);
  oled.print(F("Nic Roche"));
  oled.setCursor(50, 7); 
  oled.setFont(FONT6X8);
  oled.print(F("FROM")); 
  delay(3000);
  
  oled.clear(); 
  //usage oled.bitmap(START X IN PIXELS, START Y IN ROWS OF 8 PIXELS, END X IN PIXELS, END Y IN ROWS OF 8 PIXELS, IMAGE ARRAY);
  oled.setCursor(10, 7);
  oled.setFont(FONT6X8);
  oled.print(F("WWW.IOT123.COM.AU")); 
  oled.bitmap(0, 2, 128, 5, logo);

  delay(3000);
}
