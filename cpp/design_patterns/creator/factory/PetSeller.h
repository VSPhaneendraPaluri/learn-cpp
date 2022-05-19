#pragma once

#include "PetType.h"
#include "PetInterface.h"

#include <cstddef>
#include <string>
#include <memory>

class PetSeller
{
public:
  PetSeller() = delete;
  static PetInterfacePtr bringHomePet(PetType petType);
};
