#ifndef MUSICAL_LED_H 
#define MUSICAL_LED_H

#include <FastLED.h>

bool led_Setup();

void led_Rainbow_Pattern();
void led_Play_Pattern(void (*pattern)());

void led_LightLed(int ledPos, CRGB color);
void led_ClearLed(int ledPos);
void led_ClearAllLed();

bool led_CheckInputOn(int input);

void led_LightInput(int input);
void led_ClearInput(int input);

#endif