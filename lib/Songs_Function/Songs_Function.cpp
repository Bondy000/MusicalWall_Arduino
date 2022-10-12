#include <Arduino.h>
#include "Songs_Function.h"

void resetSong(){
    curSongArray = NULL;
    curSong = NoSong;
    curNote_Pointer = 0;
}

bool changeSong(enum Available_Songs song){
    if((song == NoSong) || (song == NumOfSongs)){
        return false;
    }
    Serial.print("Change song to ");
    curSong = song;
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
        break;
    }
    return true;
}