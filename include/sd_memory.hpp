#ifndef SD_MEMORY_HPP
#define SD_MEMORY_HPP

#define SD_MOUNT_ERROR 0
#define SD_MOUNT_OK 1

#define MAX_FILES_LIST 7
#define MAX_FILES_LEN 13

unsigned char sd_mount();
void get_files(char files[MAX_FILES_LIST][MAX_FILES_LEN]);
void open_file(const char file_path[MAX_FILES_LEN]);
void file_seek(const unsigned short dir);
unsigned char read1B();
unsigned short read2B();

#endif