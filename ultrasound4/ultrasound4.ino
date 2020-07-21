#include <NewPing.h>
#include "Segment.h"
#include "Digit.h"
#include "Display.h"
#include <Arduino.h>
 
#define TRIGGER_PIN  2
#define ECHO_PIN     3
#define MAX_DISTANCE 400

#define flash_pin 13

const byte digit_pins[4] {A1, A2, A3, A4}; 
const byte segment_pins[7] {5, 6, 7, 8, 9, 10, 11}; 
const byte dp_pin = 12;


Display d(digit_pins, segment_pins, dp_pin);
 
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
 
void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(digit_pins[i], OUTPUT);
  }
  for (int i = 0; i < 8; i++) {
    pinMode(segment_pins[i], OUTPUT);
  }
  pinMode(dp_pin, OUTPUT);
  pinMode(flash_pin, OUTPUT);
  digitalWrite(flash_pin, LOW);

  Serial.begin(115200);
}
 
void loop() {
    delay(5);
    
 // Serial.print("Distance: ");
  Serial.print(sonar.ping_cm());
 float distance = sonar.ping_cm();
 // Serial.println(sonar.ping_cm());
 // Serial.print("int distance: "); Serial.println(distance);
char valueChars[4];
  dtostrf(distance, 3, 3, valueChars);
 // Serial.print("valueChars: "); 
 // Serial.println(valueChars);
  delay(1);
  d.print(valueChars);
  if(distance < 10){
    digitalWrite(flash_pin, HIGH);
        } 
  else {
      digitalWrite(flash_pin, LOW);
    
  }
}
