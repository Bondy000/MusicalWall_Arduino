#ifndef DATA_FILE_H 
#define DATA_FILE_H 

#include <Arduino.h>
#include <stdint.h>
#include "Song_File.h"
#include "CRGB_Color.h"

//Define to test objects
#define MP3
#define MPR
#define LED
#define BLUTOOTH

//Define the instrument to play
#define GUITAR_INS

enum Available_Mode{No_Mode, StandAlone, StandAlone_Song, NumOfModes};
enum Available_Instruments{Guitar_Ins, Piano_Ins, Saxophone_Ins, Xylophone_Ins, Drum_Ins, Yokileyley_Ins, NumOfInstruments};

#define SOFTWARE_SERIAL_SPEED 9600

struct instrument
{
    String name;
    uint8_t maxNote;
    uint8_t phyInput;
    uint8_t led_Num;
    uint8_t led_PosInput[8];
    uint32_t led_ColInput[8];
    uint8_t led_WidthInput[8];
    enum Available_Mode mode;
    enum Available_Song song;
};


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
#define LED_DATA_PIN_M 13
#define LED_TYPE_M    WS2811 
#define COLOR_ORDER_M GRB

#define LED_BRIGHTNESS_M          96
#define LED_FRAMES_PER_SECOND_M  120

/*************End LED Data************/

String getName();
String getModeName(enum Available_Mode mode);
enum Available_Instruments getCurInstrument();
enum Available_Mode getCurMode();
enum Available_Song getCurSong();

uint8_t getLedPos(uint8_t input);
uint32_t getLedColor(uint8_t input);
uint8_t getLedWidth(uint8_t input);

void changeMode(enum Available_Mode mode);
void changeSong(enum Available_Song song);

uint8_t getLedNum();
uint8_t getMaxNote();
uint8_t getPhyInput();

#endif