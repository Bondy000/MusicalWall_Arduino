#ifndef SAXOPHONE_DATA_H_ 
#define SAXOPHONE_DATA_H_ 

#include "Data_File.h"

struct instrument instrumentData = 
    {
        "Saxophone",
        13,
        4,
        30,
        {(uint8_t)16, (uint8_t)15, (uint8_t)13, (uint8_t)12, 0,0,0,0},
        {Red, Blue, Pink, Purple, 0,0,0,0},
        {(uint8_t)1, (uint8_t)1, (uint8_t)2, (uint8_t)2, 0,0,0,0},
        StandAlone,
        NoSong
    };

#endif