#include "Backhoe.h"

Machine* Backhoe::clone()
{
  return new Backhoe();
}

std::string Backhoe::name() const
{
  return "Backhoe";
}
