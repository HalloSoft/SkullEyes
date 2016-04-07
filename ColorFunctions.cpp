#include "ColorFunctions.h"

void rotate(Adafruit_NeoPixel* strip, int rotateDelay, uint32_t ringColor, uint32_t centerColor, bool erase)
{
  
  if(erase)
  {
    for(int i = 0; i <= 7; i++)
      strip->setPixelColor(i, 0, 0, 0);
  }
  
  strip->setPixelColor(0, centerColor);

   uint16_t pixelCount = strip->numPixels();
  
  for(uint16_t i = 1; i < pixelCount; i++)
  {
    strip->setPixelColor(i, ringColor);
    strip->show();
    delay(rotateDelay);
  }
}

void showAll(Adafruit_NeoPixel* strip, uint32_t color)
{
  uint16_t pixelCount = strip->numPixels();
  
  for(unsigned int i = 0; i < pixelCount; i++)
    strip->setPixelColor(i, color);

  strip->show();
}

void showRing(Adafruit_NeoPixel* strip, uint32_t color, uint32_t innerColor)
{
  uint16_t pixelCount = strip->numPixels();
  
  for(unsigned int i = 1; i < pixelCount; i++)
    strip->setPixelColor(i, color);

  strip->setPixelColor(0, innerColor);
  strip->show();
}

uint32_t colorFromWheelPosition(byte WheelPosition) 
{
    WheelPosition = WheelPosition % 256;
    uint32_t resultColor = 0;
  
    if(WheelPosition < 85) 
    {
        resultColor = Adafruit_NeoPixel::Color(255 - WheelPosition * 3, 0, WheelPosition * 3);
    } 
    else if(WheelPosition < 170) 
    {
        WheelPosition -= 85;
        resultColor = Adafruit_NeoPixel::Color(0, WheelPosition * 3, 255 - WheelPosition * 3);
    } 
    else 
    {
        WheelPosition -= 170;
        resultColor = Adafruit_NeoPixel::Color(WheelPosition * 3, 255 - WheelPosition * 3, 0);
    }
    
    return resultColor;
}
