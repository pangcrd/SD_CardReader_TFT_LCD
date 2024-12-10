/**************************ESP32 TFT Display SD Card Example Code************************
Version		 :	1.1
Description	 :	The code is currently available based on the course on YouTube: Elecrow, 
				if you have any questions, please refer to the course video: Introduction 
				to ask questions or feedback.
Mod by Pangcrd        
******************************************************************************************/
#include "component.h"

TFT_eSPI tft = TFT_eSPI();

void setup() {
  
  // put your setup code here, to run once:
  Serial.begin(115200);
  //LCD init
  tft.init();


  if (sd_init() == 0)
  {
    Serial.println("TF init success");
    tft.fillScreen(TFT_BLACK);
    tft.setCursor(115, 230);
    tft.println("TF card successfully mounted");
  } else {
    Serial.println("TF init fail");
    tft.fillScreen(TFT_BLACK);
    tft.setCursor(115, 230);
    tft.println("TF card failed to mount");
  }
  tft.printf("Setup done");

  tft.setRotation(0);
  tft.fillScreen(TFT_BLACK);

}

void loop() {
  // put your main code here, to run repeatedly:
    drawBmp(SD, "/anime1.bmp", 0, 0);//display image
    delay(2000);
    drawBmp(SD, "/anime2.bmp", 0, 0);
    delay(2000);
    drawBmp(SD, "/anime3.bmp", 0, 0);
    delay(2000);
    drawBmp(SD, "/anime4.bmp", 0, 0);
    delay(2000);
    drawBmp(SD, "/anime5.bmp", 0, 0);
    delay(2000);
}

