#include "Musical_MP3.h"
#include "DFRobotDFPlayerMini.h"

//TX of MP3 is connected to RX of the Arduino (RX_PIN)
//RX of MP3 is connected to TX of the Arduino (TX_Pin) with 1k Ohm resistor between
SoftwareSerial mp3SoftwareSerial(MP3_TX_TO_ARDUINO_RX_PIN, MP3_RX_TO_ARDUINO__TX_PIN);
DFRobotDFPlayerMini myDFPlayer;

uint8_t curVol = START_VOLUME;

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

bool mp3_ChangeVolume_ByValue(uint8_t volume){
    if(volume < MIN_VOLUME || volume > MAX_VOLUME){
        return false;
    }
    curVol = volume;
    myDFPlayer.volume(curVol);
    return true;
}
void mp3_changeVolume_Up(){
    myDFPlayer.volumeUp();
}
void mp3_changeVolume_Down(){
    myDFPlayer.volumeDown();
}

bool mp3_PlayNote(uint8_t note){
    return mp3_PlayInstrumentNote(getCurInstrument(), note);
}
bool mp3_PlayInstrumentNote(uint8_t playInst, uint8_t note){
    Serial.print("Playing note ");
    Serial.print(note);
    Serial.print(" from instrument ");
    Serial.println((playInst + 1));
    //The folders starts from 1
    myDFPlayer.playFolder(playInst + 1, note);
    delay(500);
    
    return true;
}

bool mp3_PlaySong(uint8_t song){
    Serial.print("Playing song ");
    Serial.print(song);

    myDFPlayer.playFolder(0, song);
    return true;
}

void mp3_stopPlaying(){
    myDFPlayer.stop();
}
uint8_t mp3_getCurrentVolume(){
    return curVol;
}
