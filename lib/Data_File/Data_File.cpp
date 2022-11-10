#include "Data_File.h"
#include "Song_File.h"

#ifdef GUITAR_INS
#include "instrumentData/Guitar_Data.h"
const Available_Instruments curInstrument = Guitar_Ins;
#endif
#ifdef PIANO_INS
#include "instrumentData/Piano_Data.h"
const Available_Instruments curInstrument = Piano_Ins;
#endif
#ifdef SAXOPHONE_INS
#include "instrumentData/Saxophone_Data.h"
const Available_Instruments curInstrument = Saxophone_Ins;
#endif
#ifdef XYLOPHONE_INS
#include "instrumentData/Xylophone_Data.h"
const Available_Instruments curInstrument = Xylophone_Ins;
#endif
#ifdef DRUM_INS
#include "instrumentData/Drum_Data.h"
const Available_Instruments curInstrument = Drum_Ins;
#endif
#ifdef YOKILEYLEY_INS
#include "instrumentData/Yokileyley_Data.h"
const Available_Instruments curInstrument = Yokileyley_Ins;
#endif


String modeName[NumOfModes] = {"No Mode", "Stand Alone", "Stand Alone Play Song"};

String getName(){
    return instrumentData.name;
}
String getModeName(enum Available_Mode mode){
    return modeName[mode];
}
enum Available_Instruments getCurInstrument(){
    return curInstrument;
}
enum Available_Mode getCurMode(){
    return instrumentData.mode;
}
enum Available_Song getCurSong(){
    return instrumentData.song;
}

uint8_t getLedPos(uint8_t input){
    return instrumentData.led_PosInput[input];
}
uint32_t getLedColor(uint8_t input){
    return instrumentData.led_ColInput[input];
}
uint8_t getLedWidth(uint8_t input){
    return instrumentData.led_WidthInput[input];
}

void changeMode(enum Available_Mode mode){
    instrumentData.mode = mode;
}
void changeSong(enum Available_Song song){
    instrumentData.song = song;
}

uint8_t getLedNum(){
    return instrumentData.led_Num;
}
uint8_t getMaxNote(){
    return instrumentData.maxNote;
}
uint8_t getPhyInput(){
    return instrumentData.phyInput;
}