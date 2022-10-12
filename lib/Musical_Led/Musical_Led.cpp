#include <Arduino.h>
#include "Musical_Led.h"
#include "Data_File.h"
FASTLED_USING_NAMESPACE

uint8_t gHue = 0; // rotating "base color" used by many of the patterns
CRGB leds[LED_ARRAY_NUM_M];

int timer = 0;
int flick_timer = 0;

bool led_Setup(){
    Serial.println("Start Led Setup");
    delay(1000); // 3 second delay for recovery
  
    // tell FastLED about the LED strip configuration
    FastLED.addLeds<LED_TYPE_M,LED_DATA_PIN_M,COLOR_ORDER_M>(leds, LED_ARRAY_NUM_M).setCorrection(TypicalLEDStrip);

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
    fill_rainbow( leds, LED_ARRAY_NUM_M, gHue, 7);
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

void led_LightLed(int ledPos, CRGB color){
    if(ledPos >= 0 && ledPos < LED_ARRAY_NUM_M){
        leds[ledPos] = color;
    }
    FastLED.show();
}
void led_ClearLed(int ledPos){
    led_LightLed(ledPos, CRGB(0,0,0));
}
void led_ClearAllLed(){
    FastLED.clear();
    FastLED.show();
}

//Input can be 1 upto the current instrument inputs
//If 8 inputs -> 1 to 8 is valid
void led_LightInput(int input){
    if(input < 1){
        return;
    }
    if (input > instrumentPhysicalInput[curInstrument_M])
    {
        return;
    }

    if(leds[led_Position_input[curInstrument_M][input - 1]] != CRGB(0,0,0)){
        return;
    }

    int numLed = led_Input_width[curInstrument_M][input - 1];
    for (int i = 0; i < numLed - 1; i++)
    {
        int ledPos = led_Position_input[curInstrument_M][input - 1] + i;
        CRGB ledColorM = led_Color_Input[curInstrument_M][input - 1];
        led_LightLed(ledPos, ledColorM);
    }
    
}
void led_ClearInput(int input){
    if(input < 1 || input > instrumentPhysicalInput[curInstrument_M - 1]){
        return;
    }
    if(leds[led_Position_input[curInstrument_M][input - 1]] != CRGB(0,0,0)){
        return;
    }

    int numLed = led_Input_width[curInstrument_M][input- 1];
    for (int i = 0; i < numLed - 1; i++)
    {
        int ledPos = led_Position_input[curInstrument_M][input - 1] + i;
        CRGB ledColor = CRGB(0, 0, 0);
        led_LightLed(ledPos, ledColor);
    }
}

bool led_CheckInputOn(int input){
    if(leds[led_Position_input[curInstrument_M][input - 1]] != CRGB(0,0,0)){
        return true;
    }
    return false;
}