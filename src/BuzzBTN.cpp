#include "component.h"

#define buzzPin 25
#define UsrBTN1 36
#define UsrBTN2 35

#define LED1 26
#define LED2 23

EncoderRead Encoder(33, 32, 34);  // GPIO pinA,pinB,Button

bool buzzState = false;
unsigned long buzzTimer = 0;

bool led1_state = false; 
bool led2_state = false;

bool btn1State = false;
bool btn2State = false;

void encoderFunc(){
   if (Encoder.encBtn() && !buzzState) {  
    buzzState = true;                   
    buzzTimer = millis();           
    digitalWrite(buzzPin, HIGH);       
    Serial.println("Encoder Pressed!");
  }

  if (buzzState && millis() - buzzTimer >= 500) { 
    digitalWrite(buzzPin, LOW);        
    buzzState = false;                
  }

}
void PinActv() {
    pinMode(buzzPin, OUTPUT);
    pinMode(UsrBTN1, INPUT);
    pinMode(UsrBTN2, INPUT);
    pinMode(LED1,OUTPUT);
    pinMode(LED2,OUTPUT);
}

void BTNLed() {
    bool currentBtn1State = digitalRead(UsrBTN1);
    bool currentBtn2State = digitalRead(UsrBTN2);

    if (currentBtn1State == LOW && btn1State == true) {
        led1_state = !led1_state; 
        digitalWrite(LED1, led1_state ? HIGH : LOW);
    }
    if (currentBtn2State == LOW && btn2State == true) {
        led2_state = !led2_state; 
        digitalWrite(LED2, led2_state ? HIGH : LOW);
    }
}
 void count (){
      static int lastCounter = 0;
    int counter = Encoder.getCounter(); 

    if(counter != lastCounter){
        Serial.println(counter);
        lastCounter = counter;
    }
 }