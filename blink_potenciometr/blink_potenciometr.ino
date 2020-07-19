int analogPin = A0;
int ledPin = 9;

void setup() {
  pinMode(ledPin, OUTPUT);
 
  pinMode(analogPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  
  int voltpot; // значение напряжения с потенциометра
  int brightness;  // значение яркости
 
  // считываем напряжение с потенциометра от 0 до 1023
  // пропорциональное углу поворота ручки
  voltpot = analogRead(analogPin);
 
  // в brightness записываем полученное ранее значение voltpot 
  // деленное на 4. 
  
  brightness = voltpot / 4;
 
  // подаем результат на пин светодиода
  analogWrite(ledPin, brightness);

  // выводим результат яркости диода в Serial Monitor, а также в Plotter
  //Serial.println(brightness);
  //delay(10); 
  // Выводим таблицу с информацией о текущих значениях яркости и с потенциометра
  Serial.print("ДАННЫЕ ПИНОВ\t\t");
  Serial.println("Value");
  Serial.print("A0(от потенциометра)\t\t");
  Serial.println(analogRead(A0));
  Serial.print("Пин - 9 (светодиод)\t\t");
  Serial.println(brightness);
  Serial.println("--------");
  delay(1000);


  
}
