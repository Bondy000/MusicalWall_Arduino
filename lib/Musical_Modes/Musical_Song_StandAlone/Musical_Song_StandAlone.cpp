#include "Musical_Song_StandAlone.h"

#include "Musical_Led.h"
#include "Musical_MP3.h"
#include "Musical_MPR_Sensor.h"
#include "hofmanCode.h"
#include "Song_File.h"

int saS_Timer = 0;
bool missedKey = false;
bool isZeroDelay = false;

bool playSong = true;
//uint8_t* songPointer = NULL;

/*bool saS_isSongDone(){
    if(songPointer != NULL){
        uint8_t curNote = *songPointer;
        if(curNote == 0xff){
            return true;
        }
    }
    return false;

    //int curNote = curSongArray[curNote_Pointer];
    //if(curNote == 0xff){
    //    return true;
    //}
    //return false;
}*/

uint8_t saS_calculateKey(uint8_t note){
    int physicalNotes = getPhyInput();
    int playKey = note / physicalNotes;
    playKey = playKey * physicalNotes;
    playKey = note - playKey;

    return playKey;
}

/*bool saS_isSongChosen(){
    if(getCurSong() == NoSong){
        return false;
    }
    return true;
}

void saS_resetTimer(){
    saS_Timer = TIMER_MAX_MS;
}

void saS_flickerLedTimer(int ledToCheck){
    int flicker_time = 1;
    if(saS_Timer < TIMER_MAX_MS * (30/100)){
        flicker_time = FLICKER_TIMER_MS / 4;    
    }
    else if(saS_Timer < TIMER_MAX_MS * (70/100)){
        flicker_time = FLICKER_TIMER_MS / 2;
    }
    else if(saS_Timer < TIMER_MAX_MS * (90/100)){
        flicker_time = FLICKER_TIMER_MS;
    }
    else{
        flicker_time = TIMER_MAX_MS;

        led_LightInput(ledToCheck);
    }
    
    if(saS_Timer % flicker_time == 0){
        if(led_CheckInputOn(ledToCheck)){
            led_ClearInput(ledToCheck);
        }
        else{
            led_LightInput(ledToCheck);
        }
    }
}*/

/*void saS_playTTimer(){
    saS_Timer--;
    delay(1);
}

bool saS_isTimerDone(){
    if(saS_Timer <= 0){
        return true;
    }
    return false;
}

void saS_resetSong(){
    songPointer = NULL;
    saS_resetTimer();
}*/

bool saS_playMode(){
    //int pressedKey = 0;
    //int playKey = 0;
    //bool playedNote = true;
    uint8_t noteToPlay = 0;
    uint8_t pressedInput = 0;

    if(!isDataValid()){
        Serial.println("No song was chosen, please choose a song!");
        delay(1000);
        
        return true;
    }

    if(playSong){    
        mp3_PlaySong((uint8_t)getCurSong());
        delay(3000);
        playSong = false;
    }

    if(saS_isTimerFinished()){
        if(missedKey){
            mp3_PlayNote(noteToPlay);
            delay(1500);
        }

        led_ClearAllLed();
        noteToPlay = saS_calculateKey(decipherHofman());
        saS_setTimer(TIMER_MAX_MS);

        missedKey = false;
        isZeroDelay = false;
    }
    
    if(noteToPlay){
        if(noteToPlay == 0xff){
            Serial.println("Song is done, thank you for playing!");
            delay(1500);

            saS_resetSong();

            led_ClearAllLed();
            return true;
        }
        else{
            missedKey = true;
            led_LightInput(noteToPlay);
            
            pressedInput = mpr_CheckTouch();
            if(pressedInput == noteToPlay){
                mp3_PlayNote(noteToPlay);
                delay(1000);

                saS_setTimer(0);
                missedKey = false;
            }
        }
    } else{
        if(!isZeroDelay){
            saS_setTimer(WAIT_NOTE);
            isZeroDelay = true;
        }
    }

    saS_playTimer();
    return false;

    ////
    /*
    if((*songPointer) != 0){
        playKey = saS_calculateKey(*songPointer);

        if(saS_isSongDone()){
            Serial.println("Song is done, thank you for playing!");
            delay(500);

            led_ClearAllLed();
            return true;
        }

        if(saS_isTimerDone()){
            nextNote = true;
        }
        else{
            pressedKey = mpr_CheckTouch();

            if(pressedKey == playKey){
                nextNote = true;
            }
        }

        saS_playTTimer();
        saS_flickerLedTimer(playKey);
    }else{
        delay(WAIT_NOTE);
        nextNote = true;
    }
    if(nextNote){
        mp3_PlayNote(playKey);
        delay(500); 
        saS_resetTimer();
        led_ClearAllLed();
       
        songPointer++;
        nextNote = false;
    }

    return false;*/
}

void saS_resetSong(){
    setDataPointer(getSongArray(getCurSong()));
    saS_setTimer(0);
}
bool saS_isTimerFinished(){
    if(saS_Timer <= 0){
        return true;
    }
    return false;
}
void saS_setTimer(int value){
    saS_Timer = value;
}
void saS_playTimer(){
    delay(1);
    saS_Timer--;
}

/*int getCurSong_Value(){
    return curSong;
}*/
/*String getCurSong(){
    return SongName[curSong];
}*/

bool saS_changeSong(enum Available_Song newSong){
    if(newSong < 0 || newSong > NumOfSongs){
        //Serial.println("Invalid Song");
        return false;
    }

    //Reset Song if getting the NumberOfSongs
    if(newSong == NumOfSongs){
        saS_resetSong();
        return true;
    }

    Available_Song curSong = getCurSong();
    //Changing to the same song does nothing
    if(newSong == curSong){
        return false;
    }
    
    Serial.print("Changing song from ");
    Serial.print(getSongName(curSong));
    Serial.print(" to song ");
    changeSong(newSong);
    Serial.println(getSongName(curSong));
    
    setDataPointer(getSongArray(getCurSong()));

    return true;
}
