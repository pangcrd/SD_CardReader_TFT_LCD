#include "SD_JpgReader.h"

SD_JpgReader::SD_JpgReader() {
    // Initialize the file names to NULL
    for (int i = 0; i < FILE_NUMBER; i++) {
        _fileName[i] = nullptr;
    }
}

bool SD_JpgReader::begin(uint8_t CS_Pin) {
    pinMode(CS_Pin, OUTPUT);
    digitalWrite(CS_Pin, HIGH);

    if (!SD.begin(chipSelectPin)) {
        Serial.println(F("SD.begin failed!"));
        return false;
    }

    // Initialize the TFT display
    tft.begin();
    tft.setTextColor(0xFFFF, 0x0000);  // White text on black background
    tft.fillScreen(TFT_BLACK);
    tft.setSwapBytes(true);  // Need to swap color bytes (endianess)

    // Set JPG scale (optional, 1, 2, 4, or 8)
    TJpgDec.setJpgScale(1);

    // Set callback for rendering function
    TJpgDec.setCallback([this](int16_t x, int16_t y, uint16_t w, uint16_t h, uint16_t* bitmap) {
        return tft_output(x, y, w, h, bitmap);
    });

    return true;
}

bool SD_JpgReader::tft_output(int16_t x, int16_t y, uint16_t w, uint16_t h, uint16_t* bitmap) {
    // Clip the image if it exceeds the screen boundaries
    if (y >= _mylcd.height()) return 0;
    tft.pushImage(x, y, w, h, bitmap);
    return 1;
}

void SD_JpgReader::setFileNames(const char* fileNames[FILE_NUMBER]) {
    for (int i = 0; i < FILE_NUMBER; i++) {
        _fileName[i] = fileNames[i];
    }
}

void SD_JpgReader::displayImages() {
    uint16_t w = 0, h = 0;
    for (int i = 0; i < FILE_NUMBER; i++) {
        if (_fileName[i] == nullptr) {
            continue; // Skip if no file name is set
        }
        // Get image dimensions
        TJpgDec.getSdJpgSize(&w, &h, _fileName[i]);
        Serial.print("Width = "); Serial.print(w); Serial.print(", Height = "); Serial.println(h);
        
        // Display the image on the TFT
        TJpgDec.drawSdJpg(0, 0, _fileName[i]);
    }
}
