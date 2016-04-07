#ifndef COLORSHOW_H
#define COLORSHOW_H

#include <Adafruit_NeoPixel.h>

void rotate(Adafruit_NeoPixel* strip, int rotateDelay, uint32_t ringColor, uint32_t centerColor, bool erase = false);
void showAll(Adafruit_NeoPixel* strip, uint32_t color);
void showRing(Adafruit_NeoPixel* strip, uint32_t color, uint32_t innerColor = 0);
uint32_t colorFromWheelPosition(byte WheelPosition);



#endif // COLORSHOW_H
