#ifndef SCREEN_HPP
#define SCREEN_HPP

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define DEFAULT_TEXT_SIZE 1
#define DEFAULT_TEXT_COLOR 1 // White

#define ERROR_WAIT 500

#define MAX_FILES_LIST 7
#define MAX_FILES_LEN 13
#define RECT_HEIGHT 9

#include <stdint.h>

void screen_setup();
void show_error(const uint8_t errType);
void show_menu(const char files[MAX_FILES_LIST][MAX_FILES_LEN], const uint8_t currOption);
void display_show();
void display_clear();
void display_clearColor(bool is_white);
void draw_pixel(const uint8_t posx, const uint8_t posy, bool enabled);

#endif