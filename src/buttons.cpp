#include "../include/buttons.hpp"
#include <Arduino.h>
#include <stdint.h>
#include <Keypad.h>

void read_buttons(uint16_t &btns, const uint64_t wait) {
  const uint64_t last_time = millis();

  while (millis() - last_time < wait) {
    uint8_t bit_index = 0;

    for (uint8_t rows = 0; rows < ROWS; rows++) {
      for (uint8_t cols = 0; cols < COLS; cols++) {
      
      }
    }
  }
}

void set_buttons() {
  pinMode(BTN_RIGHT, INPUT_PULLUP);
  pinMode(BTN_LEFT, INPUT_PULLUP);
  pinMode(BTN_SELECT, INPUT_PULLUP);
}