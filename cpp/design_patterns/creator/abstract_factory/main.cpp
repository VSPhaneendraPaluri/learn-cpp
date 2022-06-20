#include <iostream>

#include "FurnitureType.h"
#include "furniture/Furniture.h"
#include "furniture/FurnitureFactory.h"

#include <vector>

int main(int argc, char * argv[])
{
  std::vector<Furniture*> furnitureSets;
  furnitureSets.emplace_back(FurnitureFactory::getFurniture(FurnitureType::Basic));
  furnitureSets.emplace_back(FurnitureFactory::getFurniture(FurnitureType::Luxury));

  for (auto& furniture : furnitureSets)
  {
    std::cout << "FurnitureSet: Chair: " << furniture->setChair()->hasCushion() << ", " << furniture->setChair()->hasLimbs() << std::endl;
    std::cout << "FurnitureSet: Sofa: " << furniture->setSofa()->hasArmRests() << ", " << furniture->setSofa()->hasNeckRests() << ", " << furniture->setSofa()->isConfigurable() << std::endl;
    std::cout << "FurnitureSet: Table: " << furniture->setTable()->hasMarbleTop() << ", " << std::dec << furniture->setTable()->seaterType() << std::endl;
    std::cout << "FurnitureSet: isCostly: " << furniture->isCostly() << std::endl;
  }

  return 0;
}
