#include "FurnitureFactory.h"
#include "BasicFurniture.h"
#include "LuxuryFurniture.h"

Furniture* FurnitureFactory::getFurniture(FurnitureType type)
{
  if (type == FurnitureType::Basic)
  {
    return new BasicFurniture();
  }
  else if (type == FurnitureType::Luxury)
  {
    return new LuxuryFurniture();
  }
  else
  {
    return nullptr;
  }
}