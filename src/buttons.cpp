#include "../include/buttons.hpp"
#include <Arduino.h>

void set_buttons() {
  pinMode(BTN_RIGHT, INPUT_PULLUP);
  pinMode(BTN_LEFT, INPUT_PULLUP);
  pinMode(BTN_SELECT, INPUT_PULLUP);
}