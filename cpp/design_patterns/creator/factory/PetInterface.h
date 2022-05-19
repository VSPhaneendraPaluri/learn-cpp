#pragma once

#include <cstddef>
#include <string>
#include <memory>

class PetInterface
{
public:
  ~PetInterface() = default;

  virtual bool hasFourLimbs() const = 0;
  virtual bool hasTail() const = 0;
  virtual std::string makesSound() = 0;
};

using PetInterfacePtr = std::shared_ptr<PetInterface>;
