#pragma once

#include <cstdint>

class BuilderInterface
{
public:
  virtual void reset() = 0;
  virtual void setEngine(uint8_t numberOfCylinders) = 0;
  virtual void setDashBoard(bool isHighEnd) = 0;
  virtual void setReverseCamera(bool isBigDisplay) = 0;
  virtual void setBreakingSystem(bool isAbsAvailable) = 0;
  virtual void setSeats(uint8_t numberOfSeats) = 0;
};
