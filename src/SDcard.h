#ifndef SDCARD_H
#define SDCARD_H

#include <Arduino.h> 
#include <SD.h>
#include <FS.h>
#include <TFT_eSPI.h>
#include <SPI.h>

extern TFT_eSPI tft;

int sd_init();

void drawBmp(fs::FS & fs, const char *filename, int16_t x, int16_t y);
void listDir(fs::FS & fs, const char *dirname, uint8_t levels);
void createDir(fs::FS & fs, const char *path);
void readFile(fs::FS & fs, const char *path);
void writeFile(fs::FS & fs, const char *path, const char *message);
void appendFile(fs::FS & fs, const char *path, const char *message);
void renameFile(fs::FS & fs, const char *path1, const char *path2);
void deleteFile(fs::FS & fs, const char *path);
void testFileIO(fs::FS & fs, const char *path);


#endif