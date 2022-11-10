#include <Arduino.h>
#include "Musical_Led.h"
#include "Data_File.h"
FASTLED_USING_NAMESPACE

uint8_t gHue = 0; // rotating "base color" used by many of the patterns
//CRGB *leds;
CRGB leds[60];

int timer = 0;
int flick_timer = 0;

bool led_Setup(){
    Serial.println("Start Led Setup");
    delay(1000); // 3 second delay for recovery

    uint8_t num = getLedNum();

    FastLED.addLeds<LED_TYPE_M,LED_DATA_PIN_M,COLOR_ORDER_M>(leds, num).setCorrection(TypicalLEDStrip);

    // set master brightness control
    FastLED.setBrightness(LED_BRIGHTNESS_M);

    led_Play_Pattern(led_Rainbow_Pattern);

    Serial.println("Led setup success");
    delay(1500);
    led_ClearAllLed();

    return true;
}

void led_Rainbow_Pattern(){
    // FastLED's built-in rainbow generator
    uint8_t num = getLedNum();
    fill_rainbow( leds, num, gHue, 7);
}
void led_Play_Pattern(void (*pattern)()){
    int delayTime_milis = 10000;
    while(delayTime_milis >= 0){
        if(delayTime_milis % 20 == 0){
            // slowly cycle the "base color" through the pattern
            pattern();
      
            FastLED.show();
            gHue++; 
        }
    
    delay(1);
    delayTime_milis--;
  }
  led_ClearAllLed();  
}

void led_LightLed(uint8_t ledPos, CRGB color){
    uint8_t num = getLedNum();
    if(ledPos >= 0 && ledPos < num){
        leds[ledPos] = color;
    }
    FastLED.show();
}
void led_ClearLed(uint8_t ledPos){
    led_LightLed(ledPos, CRGB(0,0,0));
}
void led_ClearAllLed(){
    FastLED.clear();
    FastLED.show();
}

//Input can be 1 upto the current instrument inputs
//If 8 inputs -> 1 to 8 is valid
void led_LightInput(uint8_t input){
    if(input < 1){
        return;
    }
    if (input > getPhyInput())
    {
        return;
    }

    if(leds[getLedPos(input - 1)] != CRGB(0,0,0)){
        return;
    }

    uint8_t numLed = getLedWidth(input-1);
    for (size_t i = 0; i < numLed; i++)
    {
        uint8_t ledPos = getLedPos(input-1) + i;
        CRGB ledColorM = getLedColor(input-1);
        led_LightLed(ledPos, ledColorM);
    }
    
}
void led_ClearInput(uint8_t input){
    if(input < 1 || input > getPhyInput()){
        return;
    }
    if(leds[getLedPos(input - 1)] != CRGB(0,0,0)){
        return;
    }

    int numLed = getLedWidth(input - 1);
    for (int i = 0; i < numLed - 1; i++)
    {
        uint8_t ledPos = getLedPos(input-1) + i;
        CRGB ledColor = CRGB(0, 0, 0);
        led_LightLed(ledPos, ledColor);
    }
}

bool led_CheckInputOn(uint8_t input){
    if(leds[getLedPos(input - 1)] != CRGB(0,0,0)){
        return true;
    }
    return false;
}

void led_LightAll(CRGB color, float miliSec){
    uint8_t num = getLedNum();
    for (size_t i = 0; i < num; i++)
    {
        leds[i] = color;
    }
    FastLED.show();
    
    delay(miliSec);
    led_ClearAllLed();
}