#include "Musical_StandAlone.h"

bool sa_PlayMode(){
    int pressedKey = mpr_CheckTouch();

    if(pressedKey > 0){
        led_ClearAllLed();
        led_LightInput(pressedKey);
        mp3_PlayNote(pressedKey);
        
        delay(10);
    }

    return false;
}