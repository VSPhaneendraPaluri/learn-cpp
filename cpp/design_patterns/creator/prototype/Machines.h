#pragma once

#include "Machine.h"

#include <vector>

class Machines
{
public:

  enum class MachineTypes : uint8_t
  {
    Backhoe = 0,
    Bulldozer = 1,
    Excavator = 2,
    End
  };

  void createMachines();
  std::vector<Machine*> getMachines();
  std::vector<Machine*> machines_;
};
