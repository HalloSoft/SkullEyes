#ifndef EPISODES_H
#define EPISODES_H

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

#include "Globals.h"

void hellBlink(NeoPixel* leftEye, NeoPixel* rightEye, ulong duration);
void evilRoll(NeoPixel* leftEye, NeoPixel* rightEye, ulong duration);
void evilFade(NeoPixel* leftEye, NeoPixel* rightEye, ulong duration);
void ghostlyShimmer(NeoPixel* leftEye, NeoPixel* rightEye, ulong duration);

#endif // EPISODES_H
