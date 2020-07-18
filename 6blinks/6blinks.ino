int timer = 110;           // время подачи тока (мс)

void setup() {
  // use a for loop to initialize each pin as an output:
  for (int myPin = 2; myPin < 8; myPin++) {
    pinMode(myPin, OUTPUT);
  }
}

void loop() {
  // цикл от 2 к 8 пину
  for (int myPin = 2; myPin < 8; myPin++) {
    // вкл перебираемый в цикле пин
    digitalWrite(myPin, HIGH);
    delay(timer);
    // выкл перебираемый в цикле пин
    digitalWrite(myPin, LOW);
      }

  // цикл обратный - от 8-го к 2-му пину
  for (int myPin = 7; myPin >= 2; myPin--) {
    // вкл перебираемый в цикле пин
    digitalWrite(myPin, HIGH);
    delay(timer);
    // выкл перебираемый в цикле пин
    digitalWrite(myPin, LOW);
  }
}
