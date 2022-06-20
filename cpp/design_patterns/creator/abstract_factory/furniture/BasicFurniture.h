#pragma once

#include "BasicChair.h"
#include "BasicSofa.h"
#include "BasicTable.h"
#include "Furniture.h"

class BasicFurniture : public Furniture
{
public:
  Chair* setChair() override;
  Sofa* setSofa() override;
  Table* setTable() override;
  bool isCostly() const override;

private:
  BasicChair chair_;
  BasicSofa sofa_;
  BasicTable table_;
};
