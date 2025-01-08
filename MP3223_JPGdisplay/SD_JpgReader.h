#ifndef SD_JPGREADER_H
#define SD_JPGREADER_H

#include <Arduino.h>
#include <SPI.h>
#include <TJpg_Decoder.h>
#include <FS.h>

// Define FILE_NUMBER and FILE_NAME_SIZE_MAX
#define FILE_NUMBER 4
#define FILE_NAME_SIZE_MAX 20

// Forward declaration of TFT_eSPI
extern TFT_eSPI tft;  // Declare TFT object as extern

class SD_JpgReader {
public:
    SD_JpgReader();  // Constructor
    bool begin(uint8_t CS_Pin);
    void setFileNames(const char* fileNames[FILE_NUMBER]);
    void displayImages();
  
private:
    const char* _fileName[FILE_NUMBER];

    bool tft_output(int16_t x, int16_t y, uint16_t w, uint16_t h, uint16_t* bitmap);
};

#endif // SD_JPGREADER_H
