#ifndef COLORS_H
#define COLORS_H

typedef Adafruit_NeoPixel NeoPixel;
typedef unsigned long ulong;

const uint32_t red       = Adafruit_NeoPixel::Color(255, 0, 0); //Red
const uint32_t purple    = Adafruit_NeoPixel::Color(255, 0, 255); //Purple
const uint32_t purplered = Adafruit_NeoPixel::Color(255, 0, 127); //Purple
const uint32_t green     = Adafruit_NeoPixel::Color(0,255,0);
const uint32_t cyan      = Adafruit_NeoPixel::Color(0,255,255);
const uint32_t blue      = Adafruit_NeoPixel::Color(0,0,255);
const uint32_t yellow    = Adafruit_NeoPixel::Color(255,127,0);
const uint32_t black     = Adafruit_NeoPixel::Color(0,0,0);
const uint32_t white     = Adafruit_NeoPixel::Color(255,255,255); 

#endif // COLORS_H
