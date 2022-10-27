#define FASTLED_ESP8266_NODEMCU_PIN_ORDER
#include <Arduino.h>
#include <FastLED.h>

#include "Leaf.h"

// PIN_<leaf #><side a/b>
#define PIN_1A 2
#define PIN_1B 4
#define PIN_2A 18
#define PIN_2B 19
#define PIN_3A 26
#define PIN_3B 25
#define PIN_4A 33
#define PIN_4B 32
#define PIN_5A 13
#define PIN_5B 27

#define NUM_LEAVES 5

int NUM_LEDS[] = {21, 25, 30, 35, 40};
int NUM_LEDS_TOTAL =
    2 * (NUM_LEDS[0] + NUM_LEDS[1] + NUM_LEDS[2] + NUM_LEDS[3] + NUM_LEDS[4]);

Leaf leaves[NUM_LEAVES];
CRGB *leds;

// CRGB colors[] = {CRGB::White, CRGB::Yellow, CRGB::Green, CRGB::Blue,
//                  CRGB::Purple};
CRGB colors[] = {CRGB::Red, CRGB::Blue, CRGB::Green, CRGB::Yellow,
                 CRGB::Purple};

void setup() {
  Serial.begin(115200);
  delay(500);

  leds = new CRGB[NUM_LEDS_TOTAL];

  int offset = 0;
  FastLED.addLeds<NEOPIXEL, PIN_1A>(leds, offset, NUM_LEDS[0]);
  offset += NUM_LEDS[0];
  FastLED.addLeds<NEOPIXEL, PIN_1B>(leds, offset, NUM_LEDS[0]);
  offset += NUM_LEDS[0];
  FastLED.addLeds<NEOPIXEL, PIN_2A>(leds, offset, NUM_LEDS[1]);
  offset += NUM_LEDS[1];
  FastLED.addLeds<NEOPIXEL, PIN_2B>(leds, offset, NUM_LEDS[1]);
  offset += NUM_LEDS[1];
  FastLED.addLeds<NEOPIXEL, PIN_3A>(leds, offset, NUM_LEDS[2]);
  offset += NUM_LEDS[2];
  FastLED.addLeds<NEOPIXEL, PIN_3B>(leds, offset, NUM_LEDS[2]);
  offset += NUM_LEDS[2];
  FastLED.addLeds<NEOPIXEL, PIN_4A>(leds, offset, NUM_LEDS[3]);
  offset += NUM_LEDS[3];
  FastLED.addLeds<NEOPIXEL, PIN_4B>(leds, offset, NUM_LEDS[3]);
  offset += NUM_LEDS[3];
  FastLED.addLeds<NEOPIXEL, PIN_5A>(leds, offset, NUM_LEDS[4]);
  offset += NUM_LEDS[4];
  FastLED.addLeds<NEOPIXEL, PIN_5B>(leds, offset, NUM_LEDS[4]);

  offset = 0;
  for (int leafIndex = 0; leafIndex < NUM_LEAVES; leafIndex++) {
    Leaf leaf = {leafIndex, NUM_LEDS[leafIndex], &leds[offset],
                 &leds[offset + NUM_LEDS[leafIndex]]};

    leaves[leafIndex] = leaf;
    offset += (2 * leaf.numLEDs);
  }

  FastLED.setBrightness(50);
}

void loop() {
  for (int leafIndex = 0; leafIndex < NUM_LEAVES; leafIndex++) {
    leaves[leafIndex].setAll(colors[leafIndex]);
  }
  FastLED.show();
}
