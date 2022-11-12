 #ifndef S_DATA_H
 #define S_DATA_H

#include <Arduino.h>
#include <stdint.h>

enum Available_Song{
    LittleJonathan, 
    //MotherDearest,
    HowAsongWasBorn,
    //ClosedKinderGarden, 
    handsUp, 
    //ImStayingMe, 
    //Mycandle, 
    Longbeard, 
    GoingTotheShoka,
    IHaveHunokka, 
    HappyBday, 
    AcheerfullBand, 
    //MordecaiWentBeforTheKing, 
    //MostBeutifulGirl,
    ILoveChocolate, 
    HammerAndNail,  
    AlotOfHappiness,
    NoSong, 
    NumOfSongs};

uint8_t* getSongArray(enum Available_Song song);
String getSongName(enum Available_Song song);

#endif