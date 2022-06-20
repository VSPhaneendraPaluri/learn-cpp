#include "CarManualBuilder.h"

CarManualBuilder::CarManualBuilder()
{
  reset();
}

void CarManualBuilder::reset()
{
  carFeature_.reset();
}

void CarManualBuilder::setEngine(uint8_t numberOfCylinders)
{
  carFeature_.numberOfSeats_ = numberOfCylinders;
}

void CarManualBuilder::setDashBoard(bool isHighEnd)
{
  carFeature_.isDashboardAvailable_ = isHighEnd;
}

void CarManualBuilder::setReverseCamera(bool isBigDisplay)
{
  carFeature_.isBigDisplay_ = isBigDisplay;
}

void CarManualBuilder::setBreakingSystem(bool isAbsAvailable)
{
  carFeature_.isAbsAvailable_ = isAbsAvailable;
}

void CarManualBuilder::setSeats(uint8_t numberOfSeats)
{
  carFeature_.numberOfSeats_ = numberOfSeats;
}

CarManualBuilder* CarManualBuilder::getCarManual()
{
  return this;
}
