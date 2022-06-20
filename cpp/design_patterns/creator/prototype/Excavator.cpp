#include "Excavator.h"

Machine* Excavator::clone()
{
  return new Excavator();
}

std::string Excavator::name() const
{
  return "Excavator";
}
