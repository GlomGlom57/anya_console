#include "../include/screen.hpp"
#include "../include/sd_memory.hpp"
#include <SH1106.h>

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

void show_menu(const char files[MAX_FILES_LIST][MAX_FILES_LEN], const unsigned char curr_option) {
  display.clearDisplay();
  display.setCursor(1, 1);

  for (unsigned char i = 0; i < MAX_FILES_LIST; i++) {
    //if (files[i][0] == '\0') break;
    if (i == curr_option) display.drawRect(0, i * RECT_HEIGHT - 1, SCREEN_WIDTH, RECT_HEIGHT, 1);
    else display.println(files[i]);
  }

  display.display();
}

void display_clear() {
  display.clearDisplay();
}

void display_show() {
  display.display();
}

void draw_pixel(const char posx, const char posy, bool enabled) {
  display.drawPixel(posx, posy, enabled);
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