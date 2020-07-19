#define LED_PIN  13
#define LDR_PIN  A0
#define POT_PIN  A1

void setup()
{
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}
 
void loop()
{
  // считываем уровень освещённости. 
    int lightness = analogRead(LDR_PIN);
  
  // считываем значение с потенциометра, которым мы регулируем
  // пороговое значение между условными темнотой и светом
  int threshold = analogRead(POT_PIN);
  
    // Выводим таблицу с информацией о текущих значениях портов
  Serial.print("ДАННЫЕ ПИНОВ\t\t");
  Serial.println("Value");
  Serial.print("A0(от фоторезистора)\t\t");
  Serial.println(analogRead(A0));
  Serial.print("A1(потенциометр)\t\t");
  Serial.println(analogRead(A1));
  Serial.println("--------");
  delay(1000);
 
  // если напряжение от фоторезистора меньше чем от потенциометра, то True
  boolean tooDark = (lightness < threshold);
 
  // 
  if (tooDark) {
    // включаем диод если True, соответственно напряжение 
    digitalWrite(LED_PIN, HIGH);
  } else {
    // выключаем его
    digitalWrite(LED_PIN, LOW);
  }
}
