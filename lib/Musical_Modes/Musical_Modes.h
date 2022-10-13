#ifndef MUSICAL_MODE_H 
#define MUSICAL_MODE_H 
#include "Data_File.h"
#include "Songs_Data.h"

const Available_Modes defaultMode = StandAlone;

void musical_Program();

bool changeMode(int newMode);

String getInstrumentName(int inst_value);
int getInstrumentValue(String inst_Name);

bool decipherCode(String code);
bool readFunction(String code);
bool writeFunction(String code);
int getNumericValue(String code);

String getCurModeName();
String getModeName(int value);
String getCurSongName();
String getSongName(int value);
String getCurInstrumentName();
String getInstrumentName(int value);

#endif