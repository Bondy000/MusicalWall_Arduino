#include "Musical_Song_StandAlone.h"

int saS_Timer = TIMER_MAX_MS;

bool saS_isSongDone(){
    int curNote = curSongArray[curNote_Pointer];
    if(curNote < 0){
        return true;
    }
    return false;
}

int saS_calculateKey(int note){
    #ifdef DEBUG
    Serial.println("Note to play: " + note);
    #endif

    int physicalNotes = instrumentPhysicalInput[curInstrument_M - 1];
    int playKey = note / physicalNotes;
    playKey = playKey * physicalNotes;
    playKey = note - playKey;

    #ifdef DEBUG
    Serial.println("Key to press: " + playKey);
    #endif

    return playKey;
}

bool saS_isSongChosen(){
    if(curSong == NoSong){
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
}

void saS_playTTimer(){
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
    curNote_Pointer = 0;
    saS_resetTimer();
}

bool saS_playMode(){
    int pressedKey = 0;
    int playKey = 0;
    bool nextNote = false;

    if(!saS_isSongChosen()){
        Serial.println("No song was chosen, please choose a song!");
        delay(1000);
        
        return true;
    }

    playKey = saS_calculateKey(curSongArray[curNote_Pointer]);
    
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

    if(nextNote){
        curNote_Pointer++;
        mp3_PlayNote(playKey);
        saS_resetTimer();
        led_ClearAllLed();

        delay(500); 
    }

    return false;
}

int getCurSong_Value(){
    return curSong;
}
String getCurSong(){
    return SongName[curSong];
}

bool saS_changeSong(int newSong){
    if(newSong < 0 || newSong >= NumOfSongs){
        Serial.println("Invalid Song");
        return false;
    }
    if(curSong == newSong){
        Serial.println("Already in song... Reset Song.");
        resetSong();
        return false;
    }
    Serial.print("Changing song from ");
    Serial.print(SongName[curSong]);
    Serial.print(" to song ");
    curSong = static_cast<Available_Songs>(newSong);
    Serial.println(SongName[curSong]);
    Serial.println("");

    return true;
}