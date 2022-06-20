#pragma once

#include "CarBuilder.h"
#include "CarManualBuilder.h"

#include <memory>
#include <vector>

class Director
{
public:
  void setBuilder(BuilderInterface* builder);
  void buildHatchBackCar();
  void buildHatchBackCarManual();
  std::vector<CarBuilder> getCars();
  std::vector<CarManualBuilder> getCarManuals();
private:
  std::vector<CarBuilder> cars_{};
  std::vector<CarManualBuilder> carManuals_{};
  BuilderInterface* builder_{ nullptr };
};
