// Укажем, что к каким пинам подключено
int trigPin = 2; 
int echoPin = 3;  
 
void setup() { 
  Serial.begin (9600); 
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
} 
 
void loop() { 
  int duration, distance;
  // для большей точности установим значение LOW на пине Trig
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2); 
  // Теперь установим высокий уровень на пине Trig
  digitalWrite(trigPin, HIGH);
  // Подождем 10 ms 
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW); 
  // Узнаем длительность высокого сигнала на пине Echo
  duration = pulseIn(echoPin, HIGH); 
  // Рассчитаем расстояние
  distance = duration / 58;
  // Выведем значение в Serial Monitor
  Serial.print(distance); 
  Serial.println(" cm"); 
  delay(100);
}
