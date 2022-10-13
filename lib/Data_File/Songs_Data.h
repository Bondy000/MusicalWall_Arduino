#ifndef SONGS_DATA_H
#define SONGS_DATA_H

enum Available_Songs {LittleJonathan, Purim, MotherDearest, NoSong, NumOfSongs};
extern char const *SongName[NumOfSongs];

extern enum Available_Songs curSong;
extern int* curSongArray;
extern int curNote_Pointer;

//A song is ending in a negetive number
extern int littleJonathan_Song[];
extern int purim_Song[];
extern int motherDearest_Song[];

#endif