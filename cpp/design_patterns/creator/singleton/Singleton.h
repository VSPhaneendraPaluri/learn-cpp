#pragma once

#include <cstdint>

class Singleton
{
public:
  static Singleton& instance();
  void incrementCounter();
  uint8_t getCounter() const;
private:
  Singleton() = default;
  uint8_t counter_{ 0x0 };
};
