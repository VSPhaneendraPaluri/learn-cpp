#pragma once

#include "LuxuryChair.h"
#include "LuxurySofa.h"
#include "LuxuryTable.h"
#include "Furniture.h"

class LuxuryFurniture : public Furniture
{
public:
  Chair* setChair() override;
  Sofa* setSofa() override;
  Table* setTable() override;
  bool isCostly() const override;

private:
  LuxuryChair chair_;
  LuxurySofa sofa_;
  LuxuryTable table_;
};
