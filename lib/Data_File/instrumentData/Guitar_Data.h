#ifndef GUITAR_DATA_H_ 
#define GUITAR_DATA_H_ 

#include "Data_File.h"

struct instrument instrumentData = 
    {
        "Guitar",
        20,
        8,
        30,
        {(uint8_t)6, (uint8_t)8, (uint8_t)10, (uint8_t)12, (uint8_t)15, (uint8_t)18, (uint8_t)20, (uint8_t)22},
        {Red, Blue, Pink, Purple, Yellow, Green, Brown ,Orange},
        {(uint8_t)2, (uint8_t)2, (uint8_t)2, (uint8_t)2, (uint8_t)2, (uint8_t)2, (uint8_t)2, (uint8_t)2},
        StandAlone,
        NoSong
    };

#endif