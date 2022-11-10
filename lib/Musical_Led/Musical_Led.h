#ifndef MUSICAL_LED_H 
#define MUSICAL_LED_H 

#include <FastLED.h>

bool led_Setup();

void led_Rainbow_Pattern();
void led_Play_Pattern(void (*pattern)());

void led_LightLed(uint8_t ledPos, CRGB color);
void led_ClearLed(uint8_t ledPos);
void led_ClearAllLed();

bool led_CheckInputOn(uint8_t input);

void led_LightInput(uint8_t input);
void led_ClearInput(uint8_t input);

void led_LightAll(CRGB color, float miliSec);
#endif