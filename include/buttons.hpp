#ifndef BUTTONS_HPP
#define BUTTONS_HPP

#define R1_PIN 5
#define R2_PIN 4
#define R3_PIN 3
#define R4_PIN 2

#define C1_PIN 6
#define C2_PIN 7
#define C3_PIN 8
#define C4_PIN 9

#define ROWS 4
#define COLS 4

#include <stdint.h>

void set_buttons();
void read_buttons(uint16_t &btns, const uint64_t wait);

#endif