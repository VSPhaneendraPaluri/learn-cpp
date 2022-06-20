#pragma once

#include "BuilderInterface.h"
#include "CarFeature.h"

class CarBuilder : public BuilderInterface
{
public:
  CarBuilder();
  void reset() override;
  void setEngine(uint8_t numberOfCylinders) override;
  void setDashBoard(bool isHighEnd) override;
  void setReverseCamera(bool isBigDisplay) override;
  void setBreakingSystem(bool isAbsAvailable) override;
  void setSeats(uint8_t numberOfSeats) override;
  CarBuilder* getCar();

private:
  CarFeature carFeature_;
};
