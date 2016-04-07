#include <Adafruit_NeoPixel.h>
#include "Globals.h"
#include "ColorFunctions.h"
#include "Episodes.h"

#include "Callibrate.h"

#define PINRIGHT 3
#define PINLEFT  2
#define PINCOUNT 7

#define EPISODE_TIME 45 // in seconds

const unsigned int timebase = 50;

typedef Adafruit_NeoPixel NeoPixel;

//unsigned long previousTime = 0;

NeoPixel rightEye = NeoPixel(PINCOUNT, PINRIGHT, NEO_GRB + NEO_KHZ800);
NeoPixel leftEye = NeoPixel(PINCOUNT, PINLEFT, NEO_GRB + NEO_KHZ800);


void setup()
{
  //This is for Neopixel Setup
  rightEye.begin();
  leftEye.begin();
  rightEye.show(); // Initialize all pixels to 'off'
  leftEye.show();  // Initialize all pixels to 'off
}

void loop()
{

  rightEye.setBrightness(50);
  leftEye.setBrightness(50);

  ghostlyShimmer(&leftEye, &rightEye, EPISODE_TIME);

  delay(5 * timebase);

  hellBlink(&leftEye, &rightEye, EPISODE_TIME);

  delay(5 * timebase);

  evilRoll(&leftEye, &rightEye, EPISODE_TIME);

  delay(5 * timebase);

  evilFade(&leftEye, &rightEye, EPISODE_TIME);

  delay(5 * timebase);
}


