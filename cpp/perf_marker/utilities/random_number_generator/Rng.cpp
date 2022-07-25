#include "Rng.h"

uint32_t Rng::getRandomNumber()
{
  return distribution_(randomGenerator_);
}
