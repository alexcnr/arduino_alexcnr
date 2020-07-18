#define LED_PIN  13
#define LDR_PIN  A0
#define POT_PIN  A1
 
void setup()
{
  pinMode(LED_PIN, OUTPUT);
}
 
void loop()
{
  // считываем уровень освещённости. 
    int lightness = analogRead(LDR_PIN);
 
  // считываем значение с потенциометра, которым мы регулируем
  // пороговое значение между условными темнотой и светом
  int threshold = analogRead(POT_PIN);
 
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
