
#include <Ultrasonic.h>

#define PIN_TRIG 2
#define PIN_ECHO 3
#define MAX_DISTANCE 200 // Константа для определения максимального расстояния, которое мы будем считать корректным.
// Создаем объект, методами которого будем затем пользоваться для получения расстояния.

Ultrasonic ultrasonic(2, 3);
void setup() {
  // Инициализируем взаимодействие по последовательному порту на скорости 9600
  Serial.begin(9600);
}
void loop() {
  // Стартовая задержка, необходимая для корректной работы.
  delay(50);
   
  // Печатаем расстояние в мониторе порта
  int dist_cm = ultrasonic.Ranging(CM); 
//  int dist_2 = 

  
  Serial.print(dist_cm);
  Serial.println(" см");


}

 
