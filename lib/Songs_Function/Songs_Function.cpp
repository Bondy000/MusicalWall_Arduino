#include <Arduino.h>
#include "Songs_Function.h"

void resetSong(){
    curSongArray = NULL;
    curSong = NoSong;
    curNote_Pointer = 0;
}

bool changeSong(int song){
    if((song < 0) || (song >= NumOfSongs)){
        return false;
    }
    Serial.print("Change song to ");
    curSong = static_cast<Available_Songs>(song);
    Serial.println(SongName[curSong]);
    Serial.println("");
    switch (song)
    {
    case LittleJonathan:
        curSongArray = littleJonathan_Song;
        break;
    case Purim:
        curSongArray = purim_Song;
        break;
    case MotherDearest:
        curSongArray = motherDearest_Song;
        break;
    default:
        curSong = NoSong;
        curSongArray = NULL;
        return false;
    }
    return true;
}