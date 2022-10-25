#include <Arduino.h>
#include "Songs_Data.h"

char const *SongName[NumOfSongs] = {
    "Little Jonathan", 
    "Purim", 
    "Mother Dearest",
    "No Song Chosen"
};

enum Available_Songs curSong = LittleJonathan;
int* curSongArray = littleJonathan_Song;
int curNote_Pointer = 0;

//A song is ending in a negetive number
int littleJonathan_Song[] = {   5, 3, 3, 4, 2,
                                2, 1, 2, 3, 4, 
                                5, 5, 5, 
                                -1};
int purim_Song[] = {    4, 5, 4, 4, 5,
                        4, 4, 5, 4, 5,
                        4, 3, 2,
                        -1};
int motherDearest_Song[] = {    3, 5, 4, 5, 4,
                                3, 5, 6, 7, 3,
                                5, 4, 5, 4, 3,
                                5, 6, 7,
                                -1};