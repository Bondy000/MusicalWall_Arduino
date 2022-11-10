#include "Musical_StandAlone.h"

#include "Musical_Led.h"
#include "Musical_MP3.h"
#include "Musical_MPR_Sensor.h"

bool sa_PlayMode(){
    uint8_t pressedKey = mpr_CheckTouch();
    
    if(pressedKey > 0){
        led_ClearAllLed();
        led_LightInput(pressedKey);
        mp3_PlayNote(pressedKey);
        
        delay(10);
    }

    return false;
}