#include <Arduino.h>
#include <FastLED.h>

#define NUM_LEDS 900
#define DATA_PIN 23
#define SNAKE_LENGTH 50
#define NUM_SNAKES 7

CRGB leds[NUM_LEDS];
int snakePos[NUM_SNAKES];

void setup() {
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
  for (int i = 0; i < NUM_SNAKES; i++) {
    snakePos[i] = (NUM_LEDS / NUM_SNAKES) * i;
  }
}

void loop() {
  for (int i = 0; i < NUM_SNAKES; i++) {
    snakePos[i] = (snakePos[i] + 3) % NUM_LEDS;
  }
  displaySnakes();
  delay(1);
}

void displaySnakes() {
    fill_solid(leds, NUM_LEDS, CRGB::Black);
    
    for (int j = 0; j < NUM_SNAKES; j++) {
        //draw each snake
        for (int i = 0; i < SNAKE_LENGTH; i++) {
            int pos = (snakePos[j] + i) % NUM_LEDS;
            // leds[pos] = CRGB::Green;
            leds[pos] = CRGB(100, round(((float)i / SNAKE_LENGTH) * 255), 50);
            // leds[pos] = CHSV(round(((float)i / SNAKE_LENGTH) * 255), 255, 255);
        }
    }
    
    FastLED.show();
}