#pragma once

#include "PetInterface.h"

#include <string>

class Cat : public PetInterface
{
public:
  Cat() = default;
  ~Cat() = default;

  bool hasFourLimbs() const override;
  bool hasTail() const override;
  std::string makesSound() override;

  std::string getName() const;
};
