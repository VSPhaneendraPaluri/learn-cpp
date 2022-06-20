#include "LuxuryFurniture.h"

Chair* LuxuryFurniture::setChair()
{
  return &chair_;
}

Sofa* LuxuryFurniture::setSofa()
{
  return &sofa_;
}

Table* LuxuryFurniture::setTable()
{
  return &table_;
}

bool LuxuryFurniture::isCostly() const
{
  return true;
}
