#include "BasicFurniture.h"

Chair* BasicFurniture::setChair()
{
  return &chair_;
}

Sofa* BasicFurniture::setSofa()
{
  return &sofa_;
}

Table* BasicFurniture::setTable()
{
  return &table_;
}

bool BasicFurniture::isCostly() const
{
  return false;
}
