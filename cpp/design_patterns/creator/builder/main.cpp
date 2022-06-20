#include <iostream>

#include "director/Director.h"
#include "builder/CarBuilder.h"
#include "builder/CarManualBuilder.h"

#include <vector>

int main(int argc, char * argv[])
{
  CarBuilder carBuilder;
  CarManualBuilder carManualBuilder;
  Director director;

  director.setBuilder(&carBuilder);
  director.buildHatchBackCar();

  director.setBuilder(&carManualBuilder);
  director.buildHatchBackCarManual();

  std::vector<CarBuilder> cars = director.getCars();
  std::vector<CarManualBuilder> carManuals = director.getCarManuals();

  std::cout << "Cars Lot: " << cars.size() << std::endl;
  std::cout << "CarManuals Lot: " << carManuals.size() << std::endl;

  return 0;
}