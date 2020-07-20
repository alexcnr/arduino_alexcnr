#include <NewPing.h>
 
#define TRIGGER_PIN  2
#define ECHO_PIN     3
#define MAX_DISTANCE 400
 
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
 
void setup() {
  Serial.begin(9600);
}
 
void loop() {
  delay(50);
  Serial.print("Distance: ");
  Serial.print(sonar.ping_cm());
 int distance = sonar.ping_cm();
  Serial.println("cm");
}
