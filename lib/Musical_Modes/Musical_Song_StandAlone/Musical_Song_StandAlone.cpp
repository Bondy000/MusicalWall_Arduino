#include "Musical_Song_StandAlone.h"

#include "Musical_Led.h"
#include "Musical_MP3.h"
#include "Musical_MPR_Sensor.h"
#include "hofmanCode.h"
#include "Song_File.h"

int saS_Timer = 0;
bool missedKey = false;
bool isZeroDelay = false;

uint8_t noteToPlay = 0;
bool playSong = true;

uint8_t saS_calculateKey(uint8_t note){
    int physicalNotes = getPhyInput();
    int playKey = note / physicalNotes;
    playKey = playKey * physicalNotes;
    playKey = note - playKey;

    return playKey;
}

bool saS_playMode(){
    uint8_t pressedInput = 0;

    if(!isDataValid()){
        Serial.println("No song was chosen, please choose a song!");
        delay(1000);
        
        return true;
    }

    if(playSong){    
        mp3_PlaySong(getCurSong());
        delay(4000);
        playSong = false;
    }

    if(saS_isTimerFinished()){
        if(missedKey){
            mp3_PlayNote(noteToPlay);
            delay(1500);
        }

        led_ClearAllLed();
        noteToPlay = decipherHofman();
        saS_setTimer(TIMER_MAX_MS);

        missedKey = false;
        isZeroDelay = false;

        Serial.print("Note to play: ");
        Serial.println(noteToPlay);
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
            uint8_t calKey = saS_calculateKey(noteToPlay);
            pressedInput = mpr_CheckTouch();
            if(pressedInput == calKey){
                mp3_PlayNote(calKey);
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
