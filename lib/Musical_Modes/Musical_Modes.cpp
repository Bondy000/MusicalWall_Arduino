#include <Arduino.h>
#include "Musical_Modes.h"

#include "Musical_StandAlone/Musical_StandAlone.h"
#include "Musical_Song_StandAlone/Musical_Song_StandAlone.h"

#include "Musical_Led.h"
#include "Musical_MP3.h"
#include "Musical_MPR_Sensor.h"
#include "Musical_hc10_BLE_Blutooth.h"

#include "Songs_Data.h"
#include "Songs_Function.h"
#include "Data_File.h"

void musical_Program(){
    //testBlutooth();

    bool changeModeToDefault = false;
    switch (curMode)
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

bool changeMode(int newMode){
    if(newMode < 0 || newMode >= NumOfModes){
        Serial.println("Mode does not exist...");
        return false;
    }
    if(curMode == newMode){
        Serial.println("Already in the mode!");
        return false;
    }
    Serial.print("Changing mode from ");
    Serial.print(ModeName[curMode]);
    Serial.print(" to mode ");
    curMode = static_cast<Available_Modes>(newMode);
    Serial.println(ModeName[curMode]);
    Serial.println("");
    return true;
}

//Decipher Given Blutooth Message
/*
Function (First Byte): R = Read, W = Write
To what(Second byte): M = Mode , S = Song , I = Instrument, E = Error
Numerical Value (Rest of message)
if numeric value is 0 -> R function = Current , W function = Reset

For example:
RM1 = Read Mode 1 -> Sending the name of Mode 1 that is Stand Alone
RS0 = Read Song 0 -> Sending Current played Song
WM0 = Write Mode 0 -> Reset the device Mode
WS2 = Write Song 2 -> Changing the Song to the second Song
*/

bool decipherCode(String code){
    switch (code.charAt(0))
    {
    case 'R':
    case 'r':
        return readFunction(code);
    case 'W':
    case 'w':
        return writeFunction(code);
    default:
        Serial.println("Invlaid Function...");
        return false;
    }
}

bool readFunction(String code){
    int value = getNumericValue(code);
    String data = "null";
    switch (code.charAt(1))
    {
    case 'M':
    case 'm':
        if(value == 0){
            data = getCurModeName();
        }else{
            data = getModeName(value - 1);
        }
    case 'S':
    case 's':
        if(value == 0){
            data = getCurSongName();
        }else{
            data = getSongName(value - 1);
        }
    case 'I':
    case 'i':
        if(value == 0){
            data = getCurInstrumentName();
        }else{
            data = getInstrumentName(value - 1);
        }
    case 'E':
    case 'e':
        data = "null";
    default:
        Serial.println("Invalid Function...");
        return false;
    }
    if(data.compareTo("null") != 0){
        while(!writeData(data));
        return true;
    }
    return false;
}
bool writeFunction(String code){
    int value = getNumericValue(code);
    String data = "null";
    switch (code.charAt(1))
    {
    case 'M':
    case 'm':
        if(value == 0){
            return changeMode(No_Mode);
        }else{
            return changeMode(value - 1);
        }
    case 'S':
    case 's':
        if(value == 0){
            resetSong();
            return true;
        }else{
            return changeSong(value - 1);
        }
    default:
        Serial.println("Invalid Function...");
        return false;
    }   
}

int getNumericValue(String code){
    unsigned int pointer = 2;
    int value = 0;
    while (code.charAt(pointer) >= '0' && code.charAt(pointer) <= '9')
    {
        value = value * 10 + (code.charAt(pointer) - '0');
        pointer++;
    }
    
    return value;
}

String getCurModeName(){
    return ModeName[curMode];
}
String getModeName(int value){
    if(value < 0 || value >= NumOfModes){
        return "null";
    }
    return ModeName[value];
}
String getCurSongName(){
    return SongName[curSong];
}
String getSongName(int value){
    if(value < 0 || value >= NumOfSongs){
        return "null";
    }
    return SongName[value];
}
String getCurInstrumentName(){
    return InstrumentName[curInstrument_M];
}
String getInstrumentName(int value){
    if(value < 0 || value >= NumOfInstruments){
        return "null";
    }
    return InstrumentName[value];
}