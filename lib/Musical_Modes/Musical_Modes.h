#ifndef MUSICAL_MODE_H 
#define MUSICAL_MODE_H 
#include "Data_File.h"
#include "Songs_Data.h"

const Available_Modes defaultMode = StandAlone;

void musical_Program();

bool changeMode(enum Available_Modes newMode);

#endif