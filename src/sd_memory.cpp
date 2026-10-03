#include "../include/sd_memory.hpp"
#include "../include/external/PF.h"

FATFS fs;

unsigned char sd_mount() {
  if (PF.begin(&fs)) return SD_MOUNT_ERROR;
  return SD_MOUNT_OK;
}

void get_files(char files[MAX_FILES_LIST][MAX_FILES_LEN]) {
  FRESULT fres;
  FILINFO finf;
  DIR dir;

  fres = PF.openDirectory(&dir, "/");

  if (fres == FR_OK) {
    unsigned char list_index = 0;
    while (list_index != MAX_FILES_LIST) {
      fres = PF.readDirectory(&dir, &finf);
      if (fres != FR_OK || finf.fname[0] == 0) break;
      if (finf.fattrib & AM_ARC) {
        for (unsigned char i = 0; i < MAX_FILES_LEN; i++) files[list_index][i] = finf.fname[i];
        list_index++;
      }
    }
  }
}

void open_file(const char file_path[MAX_FILES_LEN]) {PF.open(file_path);}

void file_seek(const unsigned short dir) {PF.seek(dir);}

unsigned char read1B() {
  unsigned char buff[1];
  UINT br;
  PF.readFile(buff, 1, &br);
  return buff[0];
}

unsigned short read2B() {
  unsigned char buff[2];
  UINT br;
  PF.readFile(buff, 2, &br);
  return ((unsigned short)(unsigned char)buff[0] << 8) | (unsigned short)(unsigned char)buff[1];
}