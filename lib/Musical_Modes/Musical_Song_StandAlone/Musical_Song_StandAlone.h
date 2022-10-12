#ifndef MUSICAL_SONG_STANDALONE_H 
#define MUSICAL_SONG_STANDALONE_H 

#include "Musical_Led.h"
#include "Musical_MP3.h"
#include "Musical_MPR_Sensor.h"

#include "Songs_Data.h"
#include "Songs_Function.h"

#include "Data_File.h"

#define TIMER_MAX_MS 10000
#define FLICKER_TIMER_MS 1000

bool saS_playMode();

bool saS_isSongDone();
bool saS_isSongChosen();
void saS_resetSong();

void saS_resetTimer();
void saS_playTTimer();
bool saS_isTimerDone();

void saS_flickerLedTimer(int ledToCheck);

int saS_calculateKey(int note);


#endif