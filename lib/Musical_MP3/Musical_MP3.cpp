#include "Musical_MP3.h"
#include "Data_File.h"

#include "DFRobotDFPlayerMini.h"
//TX of MP3 is connected to RX of the Arduino (RX_PIN)
//RX of MP3 is connected to TX of the Arduino (TX_Pin) with 1k Ohm resistor between
SoftwareSerial mp3SoftwareSerial(MP3_TX_TO_ARDUINO_RX_PIN, MP3_RX_TO_ARDUINO__TX_PIN);
DFRobotDFPlayerMini myDFPlayer;

int curVol = START_VOLUME;

bool mp3_Setup(){
    mp3SoftwareSerial.begin(SOFTWARE_SERIAL_SPEED);
  
  Serial.println();
  Serial.println(F("DFRobot DFPlayer Mini Demo"));
  Serial.println(F("Initializing DFPlayer ... (May take 3~5 seconds)"));
  
  if (!myDFPlayer.begin(mp3SoftwareSerial)) {  //Use softwareSerial to communicate with mp3.
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
    while(true){
      delay(0); // Code to compatible with ESP8266 watch dog.
    }
  }
  Serial.println(F("DFPlayer Mini online."));
  delay(1500);
  return true;
}

bool mp3_ChangeVolume_ByValue(int volume){
    if(volume < MIN_VOLUME || volume > MAX_VOLUME){
      mp3_volumeRangeError();
        return false;
    }
    curVol = volume;
    myDFPlayer.volume(curVol);
    return true;
}
bool mp3_changeVolume_Up(){
    myDFPlayer.volumeUp();
    return mp3_changeVolume_Check();
}
bool mp3_changeVolume_Down(){
    myDFPlayer.volumeDown();
    return mp3_changeVolume_Check();
}

bool mp3_changeVolume_Check(){
  int vol = myDFPlayer.readVolume();
  if(vol != curVol){
    curVol = vol;
    Serial.println("MP3 volume change successful!");
    return true;
  }
  Serial.println("MP3 volume didn't change");
  mp3_volumeRangeError();
  return false;
}

void mp3_volumeRangeError(){
  int maxVol = MAX_VOLUME;
  int minVol = MIN_VOLUME;
  Serial.println(String("Volume exceeded max value of ") + maxVol + " or min value of " + minVol);
}

bool mp3_PlayNote(int note){
    return mp3_PlayInstrumentNote(curInstrument_M, note);
}
bool mp3_PlayInstrumentNote(int insturment, int note){
    Serial.print("Playing note ");
    Serial.print(note);
    Serial.print(" from instrument ");
    Serial.println(insturment);
    //The folders starts from 1
    myDFPlayer.playFolder(insturment + 1, note);
    delay(500);
    
    return true;
}

void mp3_stopPlaying(){
    myDFPlayer.stop();
}
int mp3_getCurrentVolume(){
    return curVol;
}
