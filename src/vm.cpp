#include "../include/vm.hpp"
#include "../include/screen.hpp"
#include "../include/sd_memory.hpp"
#include <Arduino.h>

void exec_game() {
  display_clear();
  display_show();

  unsigned short acumulator = 0;
  DType acumulator_type;

  unsigned char sram[SRAM_SIZE];
  unsigned char sram_pointer = 0;
  bool exit_program = false;

  while (!exit_program) {
    const Opcode opcode = static_cast<Opcode>(read1B());

    if (opcode == JMP) {
      const unsigned short dir = read2B();
      file_seek(dir);
    }
    else if (opcode == PIX_ON || opcode == PIX_OFF) {
      const unsigned char posx = read1B();
      const unsigned char posy = read1B();
      draw_pixel(posx, posy, opcode == PIX_ON);
    }
    else if (opcode == CLEAR) display_clear();
    else if (opcode == SHOW) display_show();

    else if (opcode == WAIT) {
      const unsigned short ms = read2B();
      delay(ms);
    }
    else if (opcode == END) exit_program = true;
  }
}