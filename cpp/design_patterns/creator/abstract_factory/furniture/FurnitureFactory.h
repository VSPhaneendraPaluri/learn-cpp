#pragma once

#include "Furniture.h"
#include "FurnitureType.h"

class FurnitureFactory
{
public:
  FurnitureFactory() = delete;
  static Furniture* getFurniture(FurnitureType type);
};

