#ifndef MUSICAL_MP3_H
#define MUSICAL_MP3_H
#include <Arduino.h>
#include <SoftwareSerial.h>
#include "DFRobotDFPlayerMini.h"

bool mp3_Setup();

bool mp3_ChangeVolume_ByValue(int volume);
bool mp3_changeVolume_Up();
bool mp3_changeVolume_Down();
bool mp3_changeVolume_Check();
void mp3_volumeRangeError();

bool mp3_PlayNote(int note);
bool mp3_PlayInstrumentNote(int insturment, int note);

void mp3_stopPlaying();
int mp3_getCurrentVolume();

#endif