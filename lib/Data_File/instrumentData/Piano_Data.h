#ifndef PIANO_DATA_H_ 
#define PIANO_DATA_H_ 

#include "Data_File.h"

struct instrument instrumentData = 
    {
        "Piano",
        20,
        8,
        30,
        {(uint8_t)6, (uint8_t)8, (uint8_t)11, (uint8_t)13, (uint8_t)15, (uint8_t)18, (uint8_t)20, (uint8_t)22},
        {Red, Blue, Pink, Purple, Yellow, Green, Brown ,Orange},
        {(uint8_t)2, (uint8_t)2, (uint8_t)1, (uint8_t)2, (uint8_t)2, (uint8_t)1, (uint8_t)1, (uint8_t)2},
        StandAlone,
        NoSong
    };

#endif