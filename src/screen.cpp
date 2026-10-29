#include "../include/screen.hpp"
#include "../include/sd_memory.hpp"
#include <SH1106.h>
#include <stdint.h>

SH1106 display;

void screen_setup() {
  // Begin screen
  display.begin();
  display.clearDisplay();
  delay(500);
  display.display();

  display.setTextSize(DEFAULT_TEXT_SIZE);
  display.setTextColor(DEFAULT_TEXT_COLOR);
}

void show_menu(const char files[MAX_FILES_LIST][MAX_FILES_LEN], const uint8_t curr_option) {
  display.clearDisplay();
  display.setCursor(1, 1);

  for (uint8_t i = 0; i < MAX_FILES_LIST; i++) {
    if (i == curr_option) display.drawRect(0, i * RECT_HEIGHT - 1, SCREEN_WIDTH, RECT_HEIGHT, 1);
    else display.println(files[i]);
  }

  display.display();
}

void display_clear() {
  display.clearDisplay();
}

void draw_pixel(const uint8_t posx, const uint8_t posy, const bool enabled) {
  display.drawPixel(posx, posy, enabled);
}

void display_clearColor(bool is_white) {
  for (uint8_t posx = 0; posx < SCREEN_WIDTH; posx++) 
    for (uint8_t posy = 0; posy < SCREEN_HEIGHT; posy++)
      draw_pixel(posx, posy, is_white);
}

void display_show() {
  display.clearDisplay();
  display.display();
}

void show_error(const unsigned char errType) {
  // Show error
  while (true) {
    display.setCursor(0, 0);
    display.print("Error code: ");
    display.println(errType);
    
    display.display();
    delay(ERROR_WAIT);
    display.clearDisplay();
    display.display();
    delay(ERROR_WAIT);
  }
}