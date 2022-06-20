#include "Machines.h"

#include <iostream>

int main(int argc, char* argv[])
{
  Machines machines;
  machines.createMachines();
  for (auto machine : machines.getMachines())
  {
    std::cout << "Machine Name: " << machine->name() << std::endl;
  }
  return EXIT_SUCCESS;
}