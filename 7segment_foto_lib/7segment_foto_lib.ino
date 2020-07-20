#include "Segment.h"
#include "Digit.h"
#include "Display.h"

#include <Arduino.h>

#define pinIn  A0

const byte digit_pins[4] {A1, A2, A3, A4}; 
const byte segment_pins[7] {5, 6, 7, 8, 9, 10, 11}; 
const byte dp_pin = 12;

Display d(digit_pins, segment_pins, dp_pin);

void setup() {
    for (int i = 0; i <= A5; i++) {
    pinMode(i, OUTPUT);
    }
   pinMode(pinIn, INPUT);
  Serial.begin(9600);
   
}

void loop() {
  int value = analogRead(pinIn); 
  
  //Serial.print("value: "); Serial.println(value);
  char valueChars[4];
  dtostrf(value, 3, 1, valueChars);
  Serial.print("valueChars: "); Serial.println(valueChars);

  delay(1);
  d.print(valueChars); 
 }
