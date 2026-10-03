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

void screen_setup();
void show_error(const unsigned char errType);
void show_menu(const char files[MAX_FILES_LIST][MAX_FILES_LEN], const unsigned char currOption);
void display_show();
void display_clear();
void draw_pixel(const char posx, const char posy, bool enabled);

#endif