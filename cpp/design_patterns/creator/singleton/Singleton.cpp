#include "Singleton.h"

Singleton& Singleton::instance()
{
  static Singleton singleton;
  return singleton;
}

void Singleton::incrementCounter()
{
  counter_++;
}

uint8_t Singleton::getCounter() const
{
  return counter_;
}
