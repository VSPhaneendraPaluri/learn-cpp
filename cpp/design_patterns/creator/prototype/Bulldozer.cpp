#include "Bulldozer.h"

Machine* Bulldozer::clone()
{
  return new Bulldozer();
}

std::string Bulldozer::name() const
{
  return "Bulldozer";
}
