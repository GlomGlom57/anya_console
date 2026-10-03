#ifndef VM_HPP
#define VM_HPP

#define SRAM_SIZE 50

enum DType : unsigned char {
  U8 = 0x00,
  I8 = 0x01,
  U16 = 0x02,
  I16 = 0x03,
};

enum Opcode : unsigned char {
  // Memory
  LOAD_C = 0x00,
  LOAD_I8 = 0x01,
  LOAD_U8 = 0x02,
  LOAD_I16 = 0x03,
  LOAD_U16 = 0x04,
  STORE = 0x05,

  // Math
  ADD = 0x06,
  SUB = 0x07,
  MPL = 0x08,
  DIV = 0x09,

  // Jumps
  JMP = 0x0A,
  JMP_P = 0x0B,
  JMP_N = 0x0C,
  JMP_Z = 0x0D,
  JMP_NZ = 0x0E,

  // Functions
  CALL = 0x0F,
  RET = 0x10,

  // Screen
  CLEAR = 0x11,
  SHOW = 0x12,
  PIX_ON = 0x13,
  PIX_OFF = 0x14,

  // Game
  WAIT = 0x15, // Wait ms
  RECV = 0x16, // Read keyboard
  END = 0x17, // End game
};

void exec_game();

#endif