#ifndef MUSICAL_MP3_H
#define MUSICAL_MP3_H
#include <Arduino.h>
#include <SoftwareSerial.h>
#include "Data_File.h"

bool mp3_Setup();

bool mp3_ChangeVolume_ByValue(uint8_t volume);
void mp3_changeVolume_Up();
void mp3_changeVolume_Down();

bool mp3_PlayNote(uint8_t note);
bool mp3_PlayInstrumentNote(uint8_t playInst, uint8_t note);

void mp3_stopPlaying();
uint8_t mp3_getCurrentVolume();
bool mp3_PlaySong(uint8_t song);
#endif