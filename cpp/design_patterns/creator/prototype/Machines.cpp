#include "Machines.h"
#include "Backhoe.h"
#include "Bulldozer.h"
#include "Excavator.h"

#include <iostream>

void Machines::createMachines()
{
  auto end = static_cast<uint8_t>(MachineTypes::End);
  for(uint8_t index = 0; index < end; index++)
  {
    switch (index)
    {
      case 0:
      {
        Backhoe* backhoe = new Backhoe;
        machines_.emplace_back(backhoe->clone());
        break;
      }
      case 1:
      {
        Bulldozer* bulldozer = new Bulldozer;
        machines_.emplace_back(bulldozer->clone());
        break;
      }
      case 2:
      {
        Excavator* excavator = new Excavator;
        machines_.emplace_back(excavator->clone());
        break;
      }
      default:
        break;
    }
  }
}

std::vector<Machine*> Machines::getMachines()
{
  return machines_;
}
