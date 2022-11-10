#ifndef YOKILEYLEY_DATA_H_ 
#define YOKILEYLEY_DATA_H_ 

#include "Data_File.h"

struct instrument instrumentData = 
    {
        "Yokileyley",
        13,
        8,
        30,
        {(uint8_t)5, (uint8_t)7, (uint8_t)9, (uint8_t)12, (uint8_t)14, (uint8_t)17, (uint8_t)19, (uint8_t)21},
        {Red, Blue, Pink, Purple, Yellow, Green, Brown ,Orange},
        {(uint8_t)2, (uint8_t)2, (uint8_t)2, (uint8_t)2, (uint8_t)2, (uint8_t)2, (uint8_t)2, (uint8_t)2},
        StandAlone,
        NoSong
    };

#endif