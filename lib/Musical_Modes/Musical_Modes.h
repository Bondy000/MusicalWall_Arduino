#ifndef MUSICAL_MODE_H 
#define MUSICAL_MODE_H 
#include <Arduino.h>

#include "Data_File.h"

const Available_Mode defaultMode = StandAlone;

void musical_Program();

bool mode_ChangeMode(Available_Mode newMode);
#endif