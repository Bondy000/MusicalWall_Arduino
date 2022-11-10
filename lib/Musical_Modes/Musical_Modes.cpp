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
    }
}

bool mode_ChangeMode(Available_Mode newMode){
    if(newMode < 0 || newMode >= NumOfModes){
        Serial.println("Mode does not exist...");
        return false;
    }
    if(getCurMode() == newMode){
        Serial.println("Already in the mode!");
        return false;
    }
    String toPrint = "Changing mode from ";
    toPrint = toPrint + getName();
    toPrint = toPrint + " to mode ";
    toPrint = toPrint + getName();
    /*Serial.print("Changing mode from ");
    Serial.print(ModeName[curMode]);
    Serial.print(" to mode ");*/
    changeMode(newMode);
    //curMode = newMode;
    //Serial.println(ModeName[curMode]);
    Serial.println(toPrint);
    return true;
}
