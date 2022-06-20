#pragma once

#include "Chair.h"
#include "Sofa.h"
#include "Table.h"

class Furniture
{
public:
  virtual Chair* setChair() = 0;
  virtual Sofa* setSofa() = 0;
  virtual Table* setTable() = 0;
  virtual bool isCostly() const = 0;
};
