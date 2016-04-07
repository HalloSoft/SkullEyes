#include "Episodes.h"
//#include "Globals.h"
#include "ColorFunctions.h"


const unsigned int timebase = 50;

void hellBlink(NeoPixel* leftEye, NeoPixel* rightEye, ulong duration)
{
  ulong timeSave = millis();
  const int millisecons = duration * 1000;

  while (timeSave + millisecons > millis())
  {

    showRing(rightEye, blue, red);
    showRing(leftEye, blue, red);
    delay(timebase);

    showAll(rightEye, black);
    showAll(leftEye, black);
    delay(timebase);

    showRing(rightEye, blue);
    showRing(leftEye, blue);
    delay(timebase);

    showAll(rightEye, black);
    showAll(leftEye, black);
    delay(timebase);
  }

}

void evilRoll(NeoPixel* leftEye, NeoPixel* rightEye, ulong duration)
{
  ulong timeSave = millis();
  const int millisecons = duration * 1000;
  const unsigned int rotationTimebase = 70;

  while (timeSave + millisecons > millis())
  {

    for (int j = 0; j < 20; ++j)
    {
      for (int i = 1; i < 7; ++i)
      {
        showAll(rightEye, black);
        showAll(leftEye, black);

        rightEye->setPixelColor(i, blue);
        rightEye->setPixelColor(0, green);
        rightEye->show();

        leftEye->setPixelColor(8 - i, blue);
        leftEye->setPixelColor(0, green);
        leftEye->show();
        delay(rotationTimebase);
      }
    }

    for (int j = 0; j < 20; ++j)
    {
      for (int i = 1; i < 7; ++i)
      {
        showAll(rightEye, black);
        showAll(leftEye, black);

        rightEye->setPixelColor(8 - i, green);
        rightEye->setPixelColor(0, blue);
        rightEye->show();

        leftEye->setPixelColor(i, green);
        leftEye->setPixelColor(0, blue);
        leftEye->show();
        delay(rotationTimebase);
      }
    }
  }

  showAll(rightEye, black);
  showAll(leftEye, black);
}

void evilFade(NeoPixel* leftEye, NeoPixel* rightEye, ulong duration)
{
  ulong timeSave = millis();
  //uint32_t fadeColor = blue;
  const int millisecons = duration * 1000;

  while (timeSave + millisecons > millis())
  {
    // Red
    showAll(leftEye, Adafruit_NeoPixel::Color(255, 0, 0));
    showAll(rightEye, Adafruit_NeoPixel::Color(255, 0, 0));
    delay(500);

    for (int i = 255; i >= 0; --i)
    {
      uint32_t fadeColor = Adafruit_NeoPixel::Color(i, 0, 0);
      showAll(leftEye, fadeColor);
      showAll(rightEye, fadeColor);
      delay(2);
    }

    delay(500);

    // Green
    showAll(leftEye, Adafruit_NeoPixel::Color(0, 255, 0));
    showAll(rightEye, Adafruit_NeoPixel::Color(0, 255, 0));
    delay(500);
    
    for (int i = 255; i >= 0; --i)
    {
      uint32_t fadeColor = Adafruit_NeoPixel::Color(0, i, 0);
      showAll(leftEye, fadeColor);
      showAll(rightEye, fadeColor);
      delay(2);
    }

    delay(500);

    // Green
    showAll(leftEye, Adafruit_NeoPixel::Color(0, 0, 255));
    showAll(rightEye, Adafruit_NeoPixel::Color(0, 0, 255));
    delay(500);
    
    for (int i = 255; i >= 0; --i)
    {
      uint32_t fadeColor = Adafruit_NeoPixel::Color(0, 0, i);
      showAll(leftEye, fadeColor);
      showAll(rightEye, fadeColor);
      delay(2);
    }

    delay(500);
  }
}

void ghostlyShimmer(NeoPixel* leftEye, NeoPixel* rightEye, ulong duration)
{
  ulong timeSave = millis();
  byte colorWheel = 0;
  byte helpcounter = 0;
  const int millisecons = duration * 1000;

  while (timeSave + millisecons > millis())
  {
    rightEye->setPixelColor(1, colorFromWheelPosition(colorWheel));
    leftEye->setPixelColor(1, colorFromWheelPosition(colorWheel));
    rightEye->setPixelColor(2, colorFromWheelPosition(colorWheel));
    leftEye->setPixelColor(2, colorFromWheelPosition(colorWheel));
    rightEye->setPixelColor(6, colorFromWheelPosition(colorWheel));
    leftEye->setPixelColor(6, colorFromWheelPosition(colorWheel));
    rightEye->setPixelColor(0, red);
    leftEye->setPixelColor(0, red);
    rightEye->show();
    leftEye->show();

    if (helpcounter % 20 == 0)
      colorWheel++;

    ++helpcounter;
  }
}
