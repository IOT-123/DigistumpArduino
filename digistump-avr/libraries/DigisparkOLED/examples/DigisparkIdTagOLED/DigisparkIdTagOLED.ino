#include <avr/sleep.h>
#include <avr/interrupt.h>
#include <DigisparkOLED.h>
#include <Wire.h>

#include "bitmaps.h"

const int _interruptPin = 3;
// sda 0
// scl 2

const char Mandarin[] = { "ni hao" };
const char Spanish[] = { "hola" };
const char English[] = { "hello" };
const char Hindi[] = { "namaste" };
const char Arabic[] = { "marhabaan" };
const char Portuguese[]  = { "   oi   " };
const char Bengali[]  = { "salaam" };
const char Russian[]  = { "zdravstvuyte" };
const char Japanese[]  = { "konnichiwa" };
const char Punjabi[]  = { "sata sri akala" };

bool _interrupted = false;


void setup() {
  oled.begin();
  pinMode(_interruptPin, INPUT);
  digitalWrite(_interruptPin, HIGH);
} // setup

void loop() {
    sleep();
    if (_interrupted){
      displayPage1();
      displayPage2();
      displayPage3();
    }
} // loop

ISR(PCINT0_vect) {
  _interrupted = true;
} // on interrupt

void sleep() {
    GIMSK |= _BV(PCIE);                     // Enable Pin Change Interrupts
    PCMSK |= _BV(PCINT3);                   // Use PB3 as interrupt pin
    ADCSRA &= ~_BV(ADEN);                   // ADC off
    set_sleep_mode(SLEEP_MODE_PWR_DOWN);    // replaces above statement
    sleep_enable();                         // Sets the Sleep Enable bit in the MCUCR Register (SE BIT)
    sei();                                  // Enable interrupts
    sleep_cpu();                            // sleep
    cli();                                  // Disable interrupts
    PCMSK &= ~_BV(PCINT3);                  // Turn off PB3 as interrupt pin
    sleep_disable();                        // Clear SE bit
    sei();                                  // Enable interrupts
} // sleep

void displayPage1(){
  oled.clear(); //all black
//  delay(1000);
  oled.setFont(FONT8X16);
  setDelayText(25, 0, 1000, Mandarin);
  setDelayText(58, 2, 1000, Spanish);
  setDelayText(28, 4, 1000, English);
  setDelayText(45, 6, 1000, Hindi);
  setDelayText(18, 0, 1000, Arabic);
  setDelayText(40, 2, 1000, Portuguese);
  setDelayText(20, 4, 1000, Bengali);
  setDelayText(30, 6, 1000, Russian);
  setDelayText(4, 0, 1000, Japanese);
  setDelayText(0, 2, 1000, Punjabi);  
} // displayPage1

void displayPage2(){
  oled.clear(); 
  oled.setCursor(7, 2); 
  oled.setFont(FONT6X8);
  oled.print(F("I'M")); 
  oled.bitmap(10, 3, 113, 5, name);
  oled.setCursor(49., 7); 
  oled.setFont(FONT6X8);
  oled.print(F("WITH")); 
  delay(3000);
} // displayPage2

void displayPage3(){
  oled.clear(); 
  //usage oled.bitmap(START X IN PIXELS, START Y IN ROWS OF 8 PIXELS, END X IN PIXELS, END Y IN ROWS OF 8 PIXELS, IMAGE ARRAY);
  oled.setCursor(10, 7);
  oled.setFont(FONT6X8);
  oled.print(F("WWW.IOT123.COM.AU")); 
  oled.bitmap(0, 2, 128, 5, logo);
  delay(3000);
} // displayPage3

void setDelayText(int left, int top, int ms, const char* text){
  oled.setCursor(left, top);
  oled.print(text);
  delay(ms);
} // setDelayText

