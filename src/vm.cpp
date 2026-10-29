#include <Arduino.h>
#include "../include/buttons.hpp"
#include "../include/vm.hpp"
#include "../include/screen.hpp"
#include "../include/sd_memory.hpp"

#include <stdint.h>

void exec_game(uint32_t &file_pos) {
  // SD Memory
  uint8_t mem_buffer[MEM_LEN];
  uint32_t first_dir = file_pos;
  uint32_t last_dir = file_pos;
  
  fill_mem(mem_buffer, first_dir, last_dir);

  // ALU
  uint16_t acumulator = 0;
  uint8_t acumulator_type;
  bool priority = false;

  // SRAM
  uint8_t sram[SRAM_SIZE];
  uint8_t sram_pointer = 0;
  uint8_t frame = 0;

  // Other
  uint16_t btns = 0;
  bool exit = false;

  display_clear();
  display_show();

  while (!exit) {
    // Refill mem buffer if its necessary
    if (file_pos > first_dir + MEM_LEN - MEM_MARGIN) {
      first_dir = last_dir - MEM_MARGIN;
      fill_mem(mem_buffer, file_pos, last_dir);
    } 
    else if (file_pos < first_dir) { // In case of jumps or calls
      first_dir = file_pos;
      fill_mem(mem_buffer, file_pos, last_dir);
    }

    const uint8_t opcode = read1b_buffer(mem_buffer[MEM_LEN], file_pos, first_dir);

    switch (opcode) {
      // Memory
      case LOAD_C:
        break;
      
      case LOAD_U8:
      case LOAD_I8:
      case LOAD_U16:
      case LOAD_I16:
        break;

      case STORE:
        break;

      case ADD:
      case SUB:
      case MPL:
      case DIV:
        break;

      // Jumps
      case JMP:
        break;
      
      case JMP_P:
      case JMP_N:
      case JMP_NZ:
      case JMP_Z:
        break;

      // Screen
      case CLEAR_W:
      case CLEAR_B:
        display_clearColor(opcode == CLEAR_W);
        break;
      case SHOW:
        display_show();
        break;
      
      case PIX_ON:
      case PIX_OFF: {
        const uint8_t posx = read1b_buffer(mem_buffer, file_pos, first_dir);
        const uint8_t posy = read1b_buffer(mem_buffer, file_pos, first_dir);

        draw_pixel(posx, posy, opcode == PIX_ON);
        break;
      }

      case PIX_ON_M:
      case PIX_OFF_M: {
        const uint8_t posx_dir = read1b_buffer(mem_buffer, file_pos, first_dir);
        const uint8_t posy_dir = read1b_buffer(mem_buffer, file_pos, first_dir);

        const uint8_t posx = sram[frame + posx_dir];
        const uint8_t posy = sram[frame + posy_dir];

        draw_pixel(posx, posy, opcode == PIX_ON);
        break;
      }

      // Game
      case WAIT: {
        const uint16_t ms = read2b_buffer(mem_buffer, file_pos, first_dir);
        delay(ms);
        break;
      }

      case RECV: {
        const uint64_t ms = read2b_buffer(mem_buffer, file_pos, first_dir);
        //read_buttons(btns, ms);
        read_buttons(btns, ms);
        break;
      }

      case CLEARBT:
        btns = 0;
        break;

      case END:
        exit = true;
        break;

      // SRAM
      case SRAMP_ADD:
      case SRAMP_SUB:
        const uint8_t n = read1b_buffer(mem_buffer, file_pos, first_dir);
        if (opcode == SRAMP_ADD) sram_pointer += n; 
        else sram_pointer -= n;

        break;

      case PRIORITY_ON:
      case PRIORITY_OFF:
        priority = opcode == PRIORITY_ON;
        break;

      // Buttons
      default:
        break;
    }
  }
}