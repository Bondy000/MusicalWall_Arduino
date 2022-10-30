#ifndef SONGS_DATA_H
#define SONGS_DATA_H

#define WAIT_NOTE 1000

enum Available_Songs {LittleJonathan, MotherDearest,HowAsongWasBorn,
    ClosedKinderGarden, handsUp, ImStayingMe, Mycandle, Longbeard, GoingTotheShoka,
    IHaveHunokka, HappyBday, AcheerfullBand, MordecaiWentBeforTheKing, MostBeutifulGirl,
    ILoveChocolate, HammerAndNail, AlotOfHappiness,
    NoSong, NumOfSongs};
extern char const *SongName[NumOfSongs];

extern enum Available_Songs curSong;
extern int* curSongArray;
extern int curNote_Pointer;

//A song is ending in a negetive number
extern int littleJonathan_Song[];
extern int purim_Song[];
extern int motherDearest_Song[];
extern int HowAsongWasBorn_song[];
extern int ClosedKinderGarden_song[];
extern int handsUp_song[];
extern int ImStayingMe_song[];
extern int Mycandle_song[];
extern int Longbeard_song[];
extern int GoingTotheShoka_song[];
extern int IHaveHunokka_song[];
extern int HappyBday_song[];
extern int AcheerfullBand_song[];
extern int MordecaiWentBeforTheKing_song[];
extern int MostBeutifulGirl_song[];
extern int ILoveChocolate_song[];
extern int HammerAndNail_song[];
extern int AlotOfHappiness_song[];
#endif