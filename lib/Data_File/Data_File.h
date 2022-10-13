#ifndef DATA_FILE_H 
#define DATA_FILE_H

#include "CRGB_Color.h"

//Define to test objects
//#define MP3
//#define MPR
//#define LED
#define BLUTOOTH


enum Available_Modes{No_Mode, StandAlone, StandAlone_Song, NumOfModes};
enum Available_Instruments{Guitar_Ins, Piano_Ins, Saxophone_Ins, Xylophone_Ins, Drum_Ins, Yokileyley_Ins, NumOfInstruments};


extern char const *ModeName[NumOfModes];
extern char const *InstrumentName[NumOfInstruments];
#define SOFTWARE_SERIAL_SPEED 9600

extern int instrumentMaxNotes[NumOfInstruments];

/*****Start Mode for program*****/
extern enum Available_Modes curMode;
/********************************/

/*************Current Instrument************/
extern enum Available_Instruments curInstrument_M;
/*******************************************/


/*************Start MP3 Data************/
//TX of MP3 is connected to RX of the Arduino (RX_PIN)
//RX of MP3 is connected to TX of the Arduino (TX_Pin) with 1k Ohm resistor between
#define MP3_TX_TO_ARDUINO_RX_PIN 10 //Default is 10
#define MP3_RX_TO_ARDUINO__TX_PIN 11

#define MIN_VOLUME 0
#define MAX_VOLUME 30

#define START_VOLUME 15
/*************End MP3 Data************/


/*************Start MPR Data************/
//Number of electrodes in the MPR
#define MPR_ELECTRODE 12

// Default address is 0x5A, if tied to 3.3V its 0x5B
// If tied to SDA its 0x5C and if SCL then 0x5D
#define MPR_ADDRESS 0x5A

enum mprMode{Touch, Release, other};

/*************End MPR Data************/


/*************Start Blutooth_hc06 Data************/
//TX of Blutooth is connected to RX of the Arduino (RX_PIN)
//RX of Blutooth is connected to TX of the Arduino (TX_Pin)
#define BLUTOOTH_TX_TO_ARDUINO_RX_PIN 2
#define BLUTOOTH_RX_TO_ARDUINO__TX_PIN 3


/*************End Blutooth_hc06 Data************/

/*************Start LED Data************/
#define LED_DATA_PIN_M 12
#define LED_TYPE_M    WS2811 
#define COLOR_ORDER_M GRB

#define LED_BRIGHTNESS_M          96
#define LED_FRAMES_PER_SECOND_M  120

#define LED_ARRAY_NUM_M    30

extern int instrumentPhysicalInput[NumOfInstruments];

//Set the positions of the leds based on Inputs (Positions in the led array\strip)
extern int *led_Position_input[NumOfInstruments];

//Set the colors for each led
extern long *led_Color_Input[NumOfInstruments];

//The width of the 'Button' with LEDS
extern int *led_Input_width[NumOfInstruments];

/*************End LED Data************/

#endif