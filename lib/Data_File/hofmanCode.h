 #ifndef HOFMAN_CODE_H 
 #define HOFMAN_CODE_H 

#include <stdint.h>
#include <Arduino.h>

uint8_t decipherHofman();
void setDataPointer(uint8_t* data);
uint8_t addMask(uint8_t currentValue);
 #endif