#ifndef MUSICAL_SONG_STANDALONE_H 
#define MUSICAL_SONG_STANDALONE_H 

#include "Data_File.h"
#include "Song_File.h"

#define TIMER_MAX_MS 10000
#define FLICKER_TIMER_MS 1000
#define WAIT_NOTE 5000

bool saS_playMode();

uint8_t saS_calculateKey(uint8_t note);

bool saS_changeSong(enum Available_Song newSong);

bool saS_isTimerFinished();
void saS_setTimer(int value);
void saS_playTimer();
void saS_resetSong();
#endif