#pragma once

#include <cstdint>

class CarFeature
{
public:

  void reset()
  {
    engine_ = 0x0;
    isDashboardAvailable_ = false;
    isBigDisplay_ = false;
    isAbsAvailable_ = false;
    numberOfSeats_ = 0x0;
  }

  uint8_t engine_{ 0x0 };
  bool isDashboardAvailable_{ false };
  bool isBigDisplay_{ false };
  bool isAbsAvailable_{ false };
  uint8_t numberOfSeats_{ 0x0 };
};
