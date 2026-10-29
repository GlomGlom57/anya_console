#include "../include/sd_memory.hpp"
#include "../include/external/petit/PF.h"
#include <stdint.h>

FATFS fs;

//  FILE RELATED
uint8_t sd_mount() {
  if (PF.begin(&fs)) return SD_MOUNT_ERROR;
  return SD_MOUNT_OK;
}

void get_files(char files[MAX_FILES_LIST][MAX_FILES_LEN]) {
  FRESULT fres;
  FILINFO finf;
  DIR dir;

  fres = PF.openDirectory(&dir, "/");

  if (fres == FR_OK) {
    uint8_t list_index = 0;
    while (list_index != MAX_FILES_LIST) {
      fres = PF.readDirectory(&dir, &finf);
      if (fres != FR_OK || finf.fname[0] == 0) break;
      if (finf.fattrib & AM_ARC) {
        for (uint8_t i = 0; i < MAX_FILES_LEN; i++) files[list_index][i] = finf.fname[i];
        list_index++;
      }
    }
  }
}

inline uint32_t read4b_file() {
  uint8_t buff[START_SIZE];
  UINT br;
  PF.readFile(buff, START_SIZE, &br);
  return ((uint32_t)buff[0] << 24) | ((uint32_t)buff[1] << 16) |
         ((uint32_t)buff[2] << 8)  | (uint32_t)buff[3];
}

uint16_t read2b_file() {
  uint8_t buff[WSIZE];
  UINT br;
  PF.readFile(buff, WSIZE, &br);
  return ((uint16_t)(uint8_t)buff[0] << 8) | (uint16_t)(uint8_t)buff[1];
}

uint8_t read1b_file() {
  uint8_t buff[BSIZE];
  UINT br;
  PF.readFile(buff, BSIZE, &br);
  return buff[0];
}

//  BUFFER RELATED
void fill_mem(uint8_t mem_buffer[MEM_LEN], uint32_t &first_dir, uint32_t &last_dir) {
  if (first_dir + MEM_LEN < fs.fsize - START_SIZE) last_dir = fs.fsize - START_SIZE;

  PF.seek(first_dir);
  UINT br;
  PF.readFile(mem_buffer, MEM_LEN, &br);
}

uint16_t read2b_buffer(uint8_t mem_buffer[MEM_LEN], uint32_t &file_pos, uint32_t first_dir) {
  const uint8_t buff[2] = { mem_buffer[file_pos - first_dir], mem_buffer[file_pos + 1 - first_dir] };
  file_pos += 2;
  return ((uint16_t)(uint8_t)buff[0] << 8) | (uint16_t)(uint8_t)buff[1];
}

uint8_t read1b_buffer(uint8_t mem_buffer[MEM_LEN], uint32_t &file_pos, uint32_t first_dir) {
  const uint8_t result = mem_buffer[file_pos - first_dir];
  file_pos++;
  return result;
}

//  DONT TOUCH
uint32_t open_file(const char file_path[MAX_FILES_LEN]) {
  PF.open(file_path);
  PF.seek(fs.fsize - START_SIZE);
  const uint32_t start_addr = read4b_file();
  PF.seek(start_addr);

  return start_addr;
}


