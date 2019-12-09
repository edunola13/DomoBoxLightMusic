uint8_t actualMode = 0;
uint8_t actualValue = 0;
long refresh = 0;

void mode_off() {
  actualValue = 0;
  analogWrite(LIGHT_PIN, actualValue);
}

void mode_1() {
  actualValue = 255;
  analogWrite(LIGHT_PIN, actualValue);
}

void mode_2() {
  if (refresh < millis()) {
    refresh = millis() + 1000;
    int value = actualValue;
    if (value == 0) {
      value = 255;
    } else {
      value = 0;
    }
    actualValue = value;
    analogWrite(LIGHT_PIN, actualValue);
  }
}

void mode_3() {
  if (refresh < millis()) {
    refresh = millis() + 3000;
    int value = actualValue;
    if (value == 0) {
      value = 255;
    } else {
      value = 0;
    }
    actualValue = value;
    analogWrite(LIGHT_PIN, actualValue);
  }
}

void mode_4() {
  if (refresh < millis()) {
    refresh = millis() + 1000;
    int value = actualValue + 50;
    if (value > 255) {
      value = 0;
    }
    actualValue = value;
    analogWrite(LIGHT_PIN, actualValue);
  }
}
