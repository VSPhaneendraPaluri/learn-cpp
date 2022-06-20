#include "CarBuilder.h"

CarBuilder::CarBuilder()
{
  reset();
}

void CarBuilder::reset()
{
  carFeature_.reset();
}

void CarBuilder::setEngine(uint8_t numberOfCylinders)
{
  carFeature_.engine_ = numberOfCylinders;
}

void CarBuilder::setDashBoard(bool isHighEnd)
{
  carFeature_.isDashboardAvailable_ = isHighEnd;
}

void CarBuilder::setReverseCamera(bool isBigDisplay)
{
  carFeature_.isBigDisplay_ = isBigDisplay;
}

void CarBuilder::setBreakingSystem(bool isAbsAvailable)
{
  carFeature_.isAbsAvailable_ = isAbsAvailable;
}

void CarBuilder::setSeats(uint8_t numberOfSeats)
{
  carFeature_.numberOfSeats_ = numberOfSeats;
}

CarBuilder* CarBuilder::getCar()
{
  return this;
}
