#include <Arduino.h>

#include "Musical_Led.h"
#include "Musical_MP3.h"
#include "Musical_MPR_Sensor.h"
#include "Musical_hc10_BLE_Blutooth.h"

#include "Musical_Modes.h"

#include "Data_File.h"
#include "Songs_Data.h"

void setup() {
  Serial.begin(SOFTWARE_SERIAL_SPEED);

  Serial.println("Setup will take a few seconds...");

  /*if(!mpr_Setup()){
    Serial.println("Error MPR");
    while(1);
  }

  if(!mp3_Setup()){
    Serial.println("Error MP3");
    while(1);
  }*/

  
  /*if(!led_Setup()){
    Serial.println("Error LED");
    while(1);
  }*/

  if(!blutooth_Setup()){
    Serial.println("Error Blutooth");
    while(1);
  }

  delay(500);

  Serial.println("Setup complete");
}

void loop() {  
  musical_Program();
}
