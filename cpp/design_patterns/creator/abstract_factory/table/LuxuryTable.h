#pragma once

#include "Table.h"

class LuxuryTable : public Table
{
public:
  bool hasMarbleTop() const override;
  uint8_t seaterType() const override;
};
