#include <Arduino.h>
#include <Wire.h>
#include "Adafruit_MPR121.h"
#include "Musical_MPR_Sensor.h"
#include "Data_File.h"

Adafruit_MPR121 cap = Adafruit_MPR121();
uint16_t lasttouched = 0;
uint16_t currtouched = 0;

bool mpr_Setup(){
    Serial.println("Adafruit MPR121 Capacitive Touch sensor test");

    if (!cap.begin()) {
        Serial.println("MPR121 not found, check wiring?");
        return false;
    }

    Serial.println("MPR121 found!");
    delay(1500);
    return true;
}
/*
Checking the mpr inputs and returning the elctorde that is being touched
0 = No touch
*/
int mpr_CheckTouch(){
    currtouched = cap.touched();
  
    int electrode = 0;

    if(currtouched != 0 && currtouched != lasttouched){
        for (uint8_t i = 0; i < MPR_ELECTRODE; i++)
        {
            if(currtouched & _BV(i)){
                electrode = i + 1;
                Serial.print("Electrode ");
                Serial.print(electrode);
                Serial.println(" is touched");
                break;
            }
        }
    }

    lasttouched = currtouched;
    
    delay(3);

    return electrode;
}