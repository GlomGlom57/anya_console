#ifndef VM_HPP
#define VM_HPP

#include <stdint.h>

#define SRAM_SIZE 50
#define MEM_MARGIN 8

// Data Types
#define U8 0x00
#define I8 0x01
#define U16 0x02
#define I16 0x03

//  Opcodes
// Memory
#define LOAD_C 0x00

#define LOAD_I8 0x01
#define LOAD_U8 0x02
#define LOAD_I16 0x03
#define LOAD_U16 0x04
#define LOAD_VAR_DIR 0x05

#define STORE 0x06
#define STORE_VAR_DIR 0x07
#define STORE_TO_DIR 0x08

// Math
#define ADD 0x09
#define SUB 0x0A
#define MPL 0x0B
#define DIV 0x0C

// Jumps
#define JMP 0x0D
#define JMP_P 0x0E
#define JMP_N 0x0F
#define JMP_Z 0x10
#define JMP_NZ 0x11

// Functions
#define CALL 0x12
#define RET 0x13

// Screen
#define CLEAR_W 0x14
#define CLEAR_B 0x15
#define SHOW 0x16
#define PIX_ON 0x17
#define PIX_OFF 0x18

// Game
#define WAIT 0x19 // Wait ms
#define RECV 0x1A // Read keyboard
#define CLEARBT 0x1B // Clear keyboar state
#define END 0x1C // End game

// Keyboard
// What preceeds buttons is the JUMP dir
#define BTR1C1 0x1D
#define BTR1C2 0x1E
#define BTR1C3 0x1F
#define BTR1C4 0x20

#define BTR2C1 0x21
#define BTR2C2 0x22
#define BTR2C3 0x23
#define BTR2C4 0x24

#define BTR3C1 0x25
#define BTR3C2 0x26
#define BTR3C3 0x27
#define BTR3C4 0x28

#define BTR4C1 0x29
#define BTR4C2 0x2A
#define BTR4C3 0x2B
#define BTR4C4 0x2C

// SRAM pointer
#define SRAMP_ADD 0x2D
#define SRAMP_SUB 0x2E

// OTHER ADDS
#define PIX_ON_M 0x2F
#define PIX_OFF_M 0x30

#define PRIORITY_ON 0x31
#define PRIORITY_OFF 0x32

void exec_game(uint32_t &file_pos);

#endif