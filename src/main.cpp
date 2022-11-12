#include <Arduino.h>

#include "Musical_Led.h"
#include "Musical_MP3.h"
#include "Musical_MPR_Sensor.h"
#include "Musical_hc10_BLE_Blutooth.h"

#include "Musical_Modes.h"

//#include "Song_File.h"
#include "Data_File.h"

//#include "hofmanCode.h"

void setup() {
  Serial.begin(SOFTWARE_SERIAL_SPEED);

  Serial.println("Setup will take a few seconds...");

  #ifdef MPR
  if(!mpr_Setup()){
    Serial.println("Error MPR");
    while(1);
  }
  #endif

  #ifdef MP3
  if(!mp3_Setup()){
    Serial.println("Error MP3");
    while(1);
  }
  #endif
  
  #ifdef LED
  if(!led_Setup()){
    Serial.println("Error LED");
    while(1);
  }
  #endif

  #ifdef BLUTOOTH
  if(!blutooth_Setup()){
    Serial.println("Error Blutooth");
    while(1);
  }
  #endif

  delay(500);

  Serial.println("Setup complete");
}

void loop() { 

 /*if(b){
    int count = 0;
    Serial.println("StartDecipher");
    setDataPointer(h);
    uint8_t x = 0;
    do{
      x = decipherHofman();
      
      Serial.println(x);
      count++;
    } while(x != 0xff);
    Serial.println(count);
    b = false;
  }*/

  musical_Program();
}
