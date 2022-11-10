#ifndef DRUM_DATA_H_ 
#define DRUM_DATA_H_ 

#include "Data_File.h"

struct instrument instrumentData = 
    {
        "Drum",
        7,
        5,
        30,
        {(uint8_t)6, (uint8_t)8, (uint8_t)10, (uint8_t)12, (uint8_t)15, 0, 0, 0},
        {Red, Blue, Pink, Purple, Yellow, 0, 0, 0},
        {(uint8_t)2, (uint8_t)2, (uint8_t)2, (uint8_t)2, (uint8_t)2, 0, 0, 0},
        StandAlone,
        NoSong
    };

#endif