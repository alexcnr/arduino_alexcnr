const int analogPin = A0;    // аналоговый вывод для потенциометра
const int ledPin = 9;       // цифровой вывод для светодиода
const int limitpot = 300;   // лимит1 для показаний потенциометра
const int limitpot2 = 900;   // лимит2 для показаний потенциометра

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // считываем данные с потенциометра
  int analogValue = analogRead(analogPin);

  // Если показания выше чем заданный порог, то включаем светодиод
  if (analogValue > limitpot and analogValue < limitpot2) {
    digitalWrite(ledPin, HIGH);
    Serial.println(analogValue);
  } else {
    digitalWrite(ledPin, LOW); // иначе держим светодиод выключенным
  }

  // выводим показания на Serial monitor
  
  
 // Serial.println(analogValue);
  delay(10);        // задержка для стабильности
}
