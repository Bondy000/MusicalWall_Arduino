#include "Musical_Modes.h"

#include "Musical_StandAlone/Musical_StandAlone.h"
#include "Musical_Song_StandAlone/Musical_Song_StandAlone.h"

#include "Song_File.h"

#include "Musical_Led.h"
#include "Musical_MP3.h"
#include "Musical_MPR_Sensor.h"
#include "Musical_hc10_BLE_Blutooth.h"

void musical_Program(){
    //testBlutooth();

    bool changeModeToDefault = false;
    switch (getCurMode())
    {
    case StandAlone:
        changeModeToDefault = sa_PlayMode();
        break;
    case StandAlone_Song:
        changeModeToDefault = saS_playMode();
        break;
    
    default:
        changeModeToDefault = true;
        break;
    }
    
    if(changeModeToDefault){
        changeMode(defaultMode);
        saS_resetSong();
    }
}

bool mode_ChangeMode(Available_Mode newMode){
    if(newMode < 0 || newMode > NumOfModes){
        Serial.println("Mode does not exist...");
        return false;
    }
    if(newMode == NumOfModes || getCurMode() == newMode){
        Serial.println("Already in the mode!");
        return false;
    }

    Serial.print("Changing mode from ");
    Serial.print(getName());
    Serial.print(" to mode ");
    changeMode(newMode);

    Serial.println(getName());
    return true;
}
