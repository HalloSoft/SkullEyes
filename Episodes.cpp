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

  while (timeSave + millisecons > millis())
  {
    for (int j = 0; j < 5; ++j)
    {
      for (int i = 1; i < 7; ++i)
      {
        showAll(rightEye, black);
        showAll(leftEye, black);

        rightEye->setPixelColor(i, green);
        rightEye->setPixelColor(0, yellow);
        rightEye->show();

        leftEye->setPixelColor(7 - i, green);
        leftEye->setPixelColor(0, yellow);
        leftEye->show();
        delay(timebase);
      }
    }

    for (int j = 0; j < 5; ++j)
    {
      for (int i = 1; i < 7; ++i)
      {
        showAll(rightEye, black);
        showAll(leftEye, black);

        rightEye->setPixelColor(7 - i, red);
        rightEye->setPixelColor(0, yellow);
        rightEye->show();

        leftEye->setPixelColor(i, red);
        leftEye->setPixelColor(0, yellow);
        leftEye->show();
        delay(timebase);
      }
    }
  }

  showAll(rightEye, black);
  showAll(leftEye, black);
}

void evilFade(NeoPixel* leftEye, NeoPixel* rightEye, ulong duration)
{
  ulong timeSave = millis();
  uint32_t fadeColor;
  const int millisecons = duration * 1000;

  while (timeSave + millisecons > millis())
  {
    for (int i = 0; i < 256; ++i)
    {
      fadeColor = Adafruit_NeoPixel::Color(i, i / 2, 0);
      showAll(leftEye, fadeColor);
      showAll(rightEye, fadeColor);
      delay(10);
    }
    for (int i = 255; i >= 0; --i)
    {
      fadeColor = Adafruit_NeoPixel::Color(i, i / 2, 0);
      showAll(leftEye, fadeColor);
      showAll(rightEye, fadeColor);
      delay(10);
    }
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
