#include "Data_File.h"

/*****Start Mode for program*****/
enum Available_Modes curMode = StandAlone_Song;
/********************************/
/*************Current Instrument************/
enum Available_Instruments curInstrument_M = Saxophone_Ins;
/********************************/

char const *ModeName[NumOfModes] = {"No Mode", "Stand Alone", "StandAlone PlaySong"};
char const *InstrumentName[NumOfInstruments] = {"Guitar","Piano", "Saxophone", "Xylophone", "Drum", "Yokileyley"};

int instrumentMaxNotes[NumOfInstruments] = {8, 8, 8, 8, 8, 8};

/*************Start LED Data************/
int instrumentPhysicalInput[NumOfInstruments] = {8, 8, 4, 8, 5, 8};

//Set the positions of the leds based on Inputs (Positions in the led array\strip)
int *led_Position_input[NumOfInstruments] = {
    (int[]){6, 8, 10, 12, 15, 18, 20, 22},  //Guitar_Ins
    (int[]){6, 8, 11, 13, 15, 18, 20, 22},  //Piano_Ins
    (int[]){16, 15, 13, 12},                  //Saxophone_Ins
    (int[]){6, 8, 10, 12, 15, 18, 20, 22},  //Xylophone_Ins
    (int[]){6, 8, 10, 12, 15},              //Drum_Ins
    (int[]){5, 7, 9, 12, 14, 17, 19, 21}    //Yokileyley_Ins
};

//Set the colors for each led
long *led_Color_Input[NumOfInstruments] = {
    (long[]){Red, Blue, Pink, Purple, Yellow, Green, Brown ,Orange},    //Guitar_Ins
    (long[]){Red, Blue, Pink, Purple, Yellow, Green, Brown ,Orange},    //Piano_Ins
    (long[]){Red, Blue, Pink, Purple},                                  //Saxophone_Ins
    (long[]){Red, Blue, Pink, Purple, Yellow, Green, Brown ,Orange},    //Xylophone_Ins
    (long[]){Red, Blue, Pink, Purple, Yellow},                          //Drum_Ins
    (long[]){Red, Blue, Pink, Purple, Yellow, Green, Brown ,Orange}     //Yokileyley_Ins
};

//The width of the 'Button' with LEDS
int *led_Input_width[NumOfInstruments] = {
    (int[]){2, 2, 2, 2, 2, 2, 2, 2},    //Guitar_Ins
    (int[]){2, 2, 1, 2, 2, 1, 1, 2},    //Piano_Ins
    (int[]){1, 1, 2, 2},                //Saxophone_Ins
    (int[]){2, 2, 2, 2, 2, 2, 2, 2},    //Xylophone_Ins
    (int[]){2, 2, 2, 2, 2},             //Drum_Ins
    (int[]){2, 2, 2, 2, 2, 2, 2, 2}     //Yokileyley_Ins
};

/*************End LED Data************/