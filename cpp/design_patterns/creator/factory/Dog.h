#pragma once

#include "PetInterface.h"

#include <string>

class Dog : public PetInterface
{
public:
  Dog() = default;
  ~Dog() = default;

  bool hasFourLimbs() const override;
  bool hasTail() const override;
  std::string makesSound() override;

  std::string getName() const;
};
