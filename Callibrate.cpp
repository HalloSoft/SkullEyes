#include "Callibrate.h"

void showLed(Adafruit_NeoPixel* strip, int ledNumber, uint32_t color)
{
    strip->setPixelColor(ledNumber, color);
    strip->show();
    
}

