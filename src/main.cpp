#include <Arduino.h>

#include <IRremote.h>

#define RECV_PIN 11
#define LIGHT_PIN 9

#include <common_initial.h>
#include "messages.h"
#include "lights.h"

IRrecv irrecv(RECV_PIN);
decode_results results;

struct IRAction {
  unsigned long value;
  uint8_t mode;
};
#define IR_ACTION_SIZE 6
IRAction actions[IR_ACTION_SIZE]= {
  {16738455, 0},
  {16724175, 1},
  {16718055, 2},
  {16743045, 3},
  {16716015, 4},
  {16726215, 5}
};

void setup() {
  initialGeneric();
  DEB_DO_PRINTLN(MSG_START);
  // Init IR
  irrecv.enableIRIn();
  // Start Light
  pinMode(LIGHT_PIN, OUTPUT);
}

void loop() {
  if (irrecv.decode(&results)) {
    results.value;
    for(uint8_t i= 0; i < IR_ACTION_SIZE; i++){
      if(actions[i].value == results.value){
        actualMode = actions[i].mode;
        actualValue = 0;
        refresh = millis();
        Serial.println(actualMode);
      }
    }

    delay(50); // Wait a bit
    irrecv.resume(); // Start a new receive
  }

  if (actualMode == 0) {
    mode_off();
  } else if (actualMode == 1) {
    mode_1();
  } else if (actualMode == 2) {
    mode_2();
  } else if (actualMode == 3) {
    mode_3();
  } else if (actualMode == 4) {
    mode_4();
  }
}
