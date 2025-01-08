
/*ESP32 TFT Display SD Card Example Code*/

#include "component.h"


TFT_eSPI tft = TFT_eSPI();

//Display image from SD card
unsigned long startTime = 0;
int ImageCount = 0;  

void ShowImage(){
  const char* imageFiles[] = {"/anime1.bmp", "/anime2.bmp", "/anime3.bmp", "/anime4.bmp", "/anime5.bmp"};// Add more Image here
  const int totalImages = sizeof(imageFiles) / sizeof(imageFiles[0]);
    unsigned long ImageTime = millis();
    if (ImageTime - startTime >= 2000) { // Delay time per picture
            startTime = ImageTime; 

            drawBmp(SD, imageFiles[ImageCount], 0, 0);
            ImageCount++;// Next picture
            if (ImageCount >= totalImages) {
                ImageCount = 0; 
            }
        }
}

void setup() {
  
  Serial.begin(115200);
  tft.init();
  PinActv();


  if (sd_init() == 0)
  {
    Serial.println("TF init success");
    tft.fillScreen(TFT_BLACK);
    tft.setCursor(0, 0);
    tft.println("TF card successfully mounted");
  } else {
    Serial.println("TF init fail");
    tft.fillScreen(TFT_BLACK);
    tft.setCursor(0, 0);
    tft.println("TF card failed to mount");
  }
  tft.printf("Setup done");

  tft.setRotation(0);
  tft.fillScreen(TFT_BLACK);

}

void loop() {
    ShowImage();
    encoderFunc();
    count();
    BTNLed();
}

