#include "include/screen.hpp"
#include "include/sd_memory.hpp"
#include "include/vm.hpp"
#include "include/buttons.hpp"

#define SYSTEM_WAIT 500

void setup() {
  delay(SYSTEM_WAIT); // Wait systems to connect
  screen_setup(); // Set screen
  delay(SYSTEM_WAIT); // Wait systems to connect
  const byte sd_output = sd_mount(); // Set microsd

  // Verify microsd
  if (sd_output != SD_MOUNT_OK) show_error(sd_output);
  set_buttons();
}

void menu() {
  byte curr_option = 0;
  char files[MAX_FILES_LIST][MAX_FILES_LEN];

  while (true) {
    get_files(files);
    show_menu(files, curr_option);
    if (digitalRead(BTN_RIGHT) == LOW) curr_option += 1;
    else if (digitalRead(BTN_LEFT) == LOW) curr_option -= 1;
    if (digitalRead(BTN_SELECT) == LOW) break;
    delay(50);
  }

  open_file(files[curr_option]);
}

void loop() {
  menu();
  exec_game();
}
