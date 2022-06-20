#pragma once

#include "Table.h"

class BasicTable : public Table
{
public:
  bool hasMarbleTop() const override;
  uint8_t seaterType() const override;
};
