#include "Director.h"

void Director::setBuilder(BuilderInterface* builder)
{
  builder_ = builder;
}

void Director::buildHatchBackCar()
{
  CarBuilder* carBuilder = dynamic_cast<CarBuilder*>(builder_);
  carBuilder->setBreakingSystem(true);
  carBuilder->setDashBoard(true);
  carBuilder->setEngine(4);
  carBuilder->setReverseCamera(true);
  carBuilder->setSeats(4);
  cars_.emplace_back(*carBuilder->getCar());
}

void Director::buildHatchBackCarManual()
{
  CarManualBuilder* carManualBuilder = dynamic_cast<CarManualBuilder*>(builder_);
  carManualBuilder->setBreakingSystem(true);
  carManualBuilder->setDashBoard(true);
  carManualBuilder->setEngine(4);
  carManualBuilder->setReverseCamera(true);
  carManualBuilder->setSeats(4);
  carManuals_.emplace_back(*carManualBuilder->getCarManual());
}

std::vector<CarBuilder> Director::getCars()
{
  return cars_;
}

std::vector<CarManualBuilder> Director::getCarManuals()
{
  return carManuals_;
}
