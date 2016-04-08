#include "Helper.h"

int mirror(int pin)
{
  int result = 0;

  if ((pin < 7) && ( pin > 1))
  {

    result = 8 - pin;
  }

  if(pin == 1)
    result = 1;
  
  return result;
}

