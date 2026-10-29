#ifndef SD_MEMORY_HPP
#define SD_MEMORY_HPP

#define SD_MOUNT_ERROR 0
#define SD_MOUNT_OK 1

#define MAX_FILES_LIST 7
#define MAX_FILES_LEN 13

#define MEM_LEN 120
#define BSIZE 1
#define WSIZE 2

#define START_SIZE 4

#include <stdint.h>

// Before game
uint8_t sd_mount();
void get_files(char files[MAX_FILES_LIST][MAX_FILES_LEN]);
uint32_t open_file(const char file_path[MAX_FILES_LEN]);

// In game
void fill_mem(uint8_t mem_buffer[MEM_LEN], uint32_t &first_dir, uint32_t &last_dir);
uint8_t read1b_buffer(uint8_t mem_buffer[MEM_LEN], uint32_t &file_pos, uint32_t first_dir);
uint16_t read2b_buffer(uint8_t mem_buffer[MEM_LEN], uint32_t &file_pos, uint32_t first_dir);

#endif