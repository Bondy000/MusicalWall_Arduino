#include "Song_File.h"

String SongName[NumOfSongs] = {
    "Little Jonathan", 
    "Mother Dearest",
    "How A Song Was Born",
    "Closed Kindergarden",
    "hands Up",
    "Im Staying Me",
    "My Candle",
    "Long Beard",
    "Going To The Shoka",
    "I Have Hunokka",
    "Happy Birthday",
    "A Cheerfull Band",
    "Mordecai Went Before The King",
    "Most Beautiful Girl",
    "I Love Chocolate",
    "Hammer And Nail",
    "Alot Of Happiness",
    "No Song"
};


uint8_t littleJonathan_Song[] = {   5, 3, 3, 4, 2,    // יונתן הקטן 1
                                2, 1, 2, 3, 4, 
                                5, 5, 5,
                                5, 3, 3, 4, 2, 2,
                                1, 3, 5, 5, 1,
                                0xff};
uint8_t motherDearest_Song[]={ 2 ,4 ,3 ,4 ,3 ,2 ,4 ,5 ,6 ,0 , 2 ,4 ,3 ,4 ,   //2  אמא יקרה לי
                           3 ,2 ,4 ,5 ,6 ,0 ,6 ,6 ,6 ,4 ,5 ,5 ,5 ,0 ,
                           4 ,4 ,4 ,2 ,3 ,3 ,3 ,6 ,4 ,3 ,2, 6, 4, 3, 2,
                           0xff};
uint8_t HowAsongWasBorn_song[] ={   3, 10, 3, 5,0 ,4,         // 3 איך שיר נולד
                                6, 5,0  ,5, 5, 3, 10 , 3 ,5,
                                4, 5, 4 ,3, 4 ,6, 5,0 , 5  ,                               
                                3, 10, 3, 5,0 , 4,        
                                6, 5,0 , 5, 5, 5, 5, 6, 5,
                                6, 8,0xff
                             };
/*uint8_t ClosedKinderGarden_song[] ={9, 3, 3, 3, 3,0  ,3, 11, 3, 11,   //4 גן סגור 
                                3, 11, 3,0  , 9,
                                3, 3, 3, 3, 3, 3, 3, 11,3,
                                11, 3, 11, 3,0  , 3, 3, 3,0 , 3,3,3 ,11,9,
                                19, 20, 19,
                                0xff
                               };
uint8_t handsUp_song[]={ 3 , 5, 3, 3, 5, 3, 8, 7,      //5 יידים למעלה
                      6 , 5,0  ,4 ,2, 4, 6, 5, 5,
                      5, 4, 3, 2, 1,
                      0xff
                    };
uint8_t ImStayingMe_song[]= { 2 , 2, 5, 5, 11, 11, 3, 0 ,3, 2,  //6 אני נשאר אני 
                         2, 3, 20, 3, 2,0 , 2, 2, 5, 5, 11,
                         3,0 , 3, 2, 2, 3, 20, 3, 2,0 , 2, 2,
                         7 ,7 ,6 ,6 ,5 ,2 ,2 ,8 ,7 ,6 ,0 ,2 ,2 ,
                         6 ,6 ,5 ,5 ,11,2,7,6,5,0 ,0  ,
                         5 ,6 ,7 ,8 ,2 ,2 ,8 ,7 ,6 ,7,
                         0xff
                         };
uint8_t Mycandle_song[]= {3 ,4 ,5 ,6 ,5 ,3 ,4 ,3 ,2 ,4 ,3 ,0  ,         // 7 נר לי דקיק 
                      3, 4, 5, 6, 5, 3, 4, 3, 2, 1,0 , 3, 
                      6, 7, 8, 8, 7, 7, 6,0 , 5, 5, 6, 5, 3, 4, 3, 2, 1,
                      0xff};
uint8_t Longbeard_song[]={1,4,3,2,1,2,3, 4 ,1,0 ,1 ,4 ,3 ,2 ,1 ,2 ,3 , 4 ,1,0 ,  // 8 זקן ארוך לי עד ברכיים
                      1 ,4 ,4 , 5,4 , 5, 6 ,8 ,6,4 ,5 ,5,5 ,6, 5, 4, 8 ,8,
                      0xff};
uint8_t GoingTotheShoka_song[]= {1 ,4 ,5 ,4 ,4 ,3 ,0 ,1 ,1 ,3 ,3 ,2 ,4 ,3 ,2 ,1 ,0 ,          //9 אצא לי השוקה
                             1, 19, 1, 3, 7, 7, 7, 6, 7, 8,0 , 8, 7, 6, 5, 3, 7, 6, 6, 5,
                            0xff};
uint8_t IHaveHunokka_song[] = {1, 4, 4, 5, 6, 4,0 , 1, 4, 4, 5, 6, 4, 0,      //10 חנוכיה לי יש 
                            4, 13, 6, 13, 8, 6,0 , 4, 5, 4, 5, 6, 4,0 , 4, 13, 6, 13, 8, 6,0 , 4, 5, 4, 5, 6, 4,
                            0xff};
uint8_t HappyBday_song[]={ 3 ,3 ,3 ,3 ,2 ,1 ,4 ,4 ,4 ,4 ,3 ,2 ,5 ,    // היום יום הולדת 11
                       5 ,6 ,5 ,4 ,3 ,2 ,3 ,4 ,5,0 , 1,
                       3 ,3 ,3 ,3 ,2 ,1 ,4 ,4 ,4 ,4 ,3 ,2 ,5 ,
                       5 ,6 ,5 ,4 ,3 ,2 ,3 ,2 ,1,
                       0xff };
uint8_t AcheerfullBand_song[]={ 2,3 ,0 ,7 ,5 ,0 ,11 ,3 ,2 ,3 ,3 ,6 ,5,11 ,3 ,11 ,  // מקהלה עליזה 12
                            5 ,11 ,3 ,11 ,11 ,3 ,2 ,20 ,1 ,0 , 1 ,1 ,2 ,3 ,
                            11 ,5 ,6 ,7,0 ,8 , 0,7 ,6 ,5 ,11 ,5 ,
                            0xff};
uint8_t MordecaiWentBeforTheKing_song[]={3 ,3 ,4 ,5 ,6 ,4,0 ,2 ,2 ,3 ,4 ,5 ,3 ,0 ,    // מרדכי יצא מלפני המלך 13
                                     1 ,1 ,2 ,3 ,4 ,2 ,0 ,1 ,20 ,1 ,20 ,19 ,3 ,
                                     3 ,3 ,4 ,5 ,6 ,4,0 ,2 ,2 ,3 ,4 ,5 ,3 ,0 ,
                                     1 ,1 ,2 ,3 ,4 ,2 ,0 ,1 ,20 ,1 ,20 ,19 ,19, 
                                     0xff};
uint8_t MostBeutifulGirl_song[]={3 ,3 ,2 ,2 ,3 ,3 ,2 ,2 ,2 ,0 , 2 ,2 ,2 ,1 ,1 ,1 ,2 ,   // הילדה הכי יפה בגן 14
                             2 ,1 ,1 ,1 ,0 , 1 ,1 ,20 ,20 ,1 ,1 ,20 ,20 ,19 ,0 ,19 ,
                             19 ,18 ,19 ,18 ,20 ,18 ,19 ,0 ,3 ,3 ,3 ,2 ,2 ,3 ,3 ,3 ,
                             2,0 ,1 ,6 ,6 ,5 ,6 ,6 ,5 ,5,0 ,3 ,5 ,5 ,5 ,4 ,2 ,3 ,3 ,2 ,
                             3 ,2 , 1, 1,
                             0xff};
uint8_t ILoveChocolate_song[]={1 ,3 ,3 ,3 ,2 ,1 ,2 ,3 ,0 , 3,3 ,3 ,2 ,1 ,0 , 1 ,3 ,3 ,3 ,2 ,    // אני אוהב שוקולד 15
                           1 ,2 ,3 , 0, 4 ,4 ,3 ,2 , 0 ,1 ,3 ,3 ,3 ,2 ,1 ,2 ,3 , 0, 3,3 ,3 ,
                           3 ,2 ,1 ,2 ,1 ,1 , 0, 1,3,3,3,3, 2,1 ,2 ,1 ,2 ,3 , 0 , 4 ,4 ,4 ,3 ,3 ,2 ,2 ,
                           0xff};
uint8_t HammerAndNail_song[]={1 ,4 ,1 ,4 ,6 ,8 ,13 ,5 , 0, 8 ,6 ,8 ,4 , 0, 6 ,5 ,4 ,3 ,4 ,5 ,   // פטיש מסמר 16
                          1 ,4 ,1 ,4 ,6 ,8 ,13 ,5 , 0,8 ,6 ,4 ,5 ,4 ,3 ,4 ,4 ,
                          0xff};
uint8_t AlotOfHappiness_song[]={1 ,4 ,4 ,5 ,3 ,4 ,3 ,2 ,1 ,1 ,2 ,2 ,3 ,1 ,4 ,6 ,5 ,   //  17 שמחה רבה אביב הגיע פסח בא
                            1 ,4 ,4 ,5 ,3 ,4 ,3 ,2 ,1 ,1 ,2 ,2 ,3 ,1,4 ,4 ,4 ,0 ,
                            4 ,5 ,6 ,4 ,5 ,6 ,4 ,5 ,6 ,6 ,5 ,5 ,6, 4 ,4, 
                            0xff};
*/

uint8_t* getSongArray(enum Available_Song song){
    switch (song)
    {
    case LittleJonathan:
        return littleJonathan_Song;
    case MotherDearest:
        return motherDearest_Song;
    case HowAsongWasBorn:
        return HowAsongWasBorn_song;
    /*case ClosedKinderGarden:
        return ClosedKinderGarden_song;
    case handsUp:
        return handsUp_song;
    case ImStayingMe:
        return ImStayingMe_song;
    case Mycandle:
        return Mycandle_song;
    case Longbeard:
        return Longbeard_song;
    case GoingTotheShoka:
        return GoingTotheShoka_song;
    case IHaveHunokka:
        return IHaveHunokka_song;
    case HappyBday:
        return HappyBday_song;
    case AcheerfullBand:
        return AcheerfullBand_song;
    case MordecaiWentBeforTheKing:
        return MordecaiWentBeforTheKing_song;
    case ILoveChocolate:
        return ILoveChocolate_song;
    case HammerAndNail:
        return HammerAndNail_song;
    case AlotOfHappiness:
        return AlotOfHappiness_song;
    case MostBeutifulGirl:
        return MostBeutifulGirl_song;*/
    default:
        return NULL;
    }
}

String getSongName(enum Available_Song song){
    switch (song)
    {
    case LittleJonathan:
        return SongName[LittleJonathan];
    case MotherDearest:
        return SongName[MotherDearest];
    case HowAsongWasBorn:
        return SongName[HowAsongWasBorn];
    case ClosedKinderGarden:
        return SongName[ClosedKinderGarden];
    case handsUp:
        return SongName[handsUp];
    case ImStayingMe:
        return SongName[ImStayingMe];
    case Mycandle:
        return SongName[Mycandle];
    case Longbeard:
        return SongName[Longbeard];
    case GoingTotheShoka:
        return SongName[GoingTotheShoka];
    case IHaveHunokka:
        return SongName[IHaveHunokka];
    case HappyBday:
        return SongName[HappyBday];
    case AcheerfullBand:
        return SongName[AcheerfullBand];
    case MordecaiWentBeforTheKing:
        return SongName[MordecaiWentBeforTheKing];
    case ILoveChocolate:
        return SongName[ILoveChocolate];
    case HammerAndNail:
        return SongName[HammerAndNail];
    case AlotOfHappiness:
        return SongName[AlotOfHappiness];
    case MostBeutifulGirl:
        return SongName[MostBeutifulGirl];
    default:
        return "";
    }
}
