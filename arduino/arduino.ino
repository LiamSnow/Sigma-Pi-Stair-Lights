/*
ESP32-DevKitC V4 (esp32-wroom-32d)
3x300 LED WS2812B Strip
*/

#include <Arduino.h>
#include <FastLED.h>

#define NUM_LEDS 900
#define DATA_PIN 23
#define SNAKE_LENGTH 20
#define NUM_SNAKES 14
#define LED_SPLIT 458

CRGB leds[NUM_LEDS];
int snakePos[NUM_SNAKES];

CRGB snakeStartColor = CRGB(200, 255, 200);
CRGB snakeEndColor = CRGB(0, 255, 0);

void setup() {
  FastLED.addLeds<WS2812B, DATA_PIN, RBG>(leds, NUM_LEDS);
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
            if (pos < LED_SPLIT) pos = LED_SPLIT - 1 - pos;

            // leds[pos] = CRGB::Green;
            leds[pos] = interpolateSnakeColor(i);
        }
    }
    
    FastLED.show();
}

CRGB interpolateSnakeColor(int i) {
    float t = (float)i / SNAKE_LENGTH;
    int r = snakeStartColor.r + round((snakeEndColor.r - snakeStartColor.r) * t);
    int g = snakeStartColor.g + round((snakeEndColor.g - snakeStartColor.g) * t);
    int b = snakeStartColor.b + round((snakeEndColor.b - snakeStartColor.b) * t);
    return CRGB(r, g, b);
}