#include "SD_JpgReader.h"
#include <TFT_eSPI.h>


#define SD_CS 22  // SD chip select pin

// Create TFT display object
TFT_eSPI tft = TFT_eSPI();
SPIClass MySPI (HSPI);

// Create SD_JpgReader object
SD_JpgReader jpgReader;

const char* fileNames[FILE_NUMBER] = {
    "/tulip.jpg",
    "/game.jpg",
    "/tree.jpg",
    "/flower.jpg"
};



void setup() {
    Serial.begin(115200);
    Serial.println("\n\nTesting SD_JpgReader library");

    // Initialize the SD_JpgReader with the file names
    if (!jpgReader.begin(SD_CS)) {
        Serial.println("Failed to initialize SD_JpgReader.");
        return;
    }

    // Set file names to load
    jpgReader.setFileNames(fileNames);
}

void loop() {
    jpgReader.displayImages();
    
    // Delay between images
    delay(1500);
}
