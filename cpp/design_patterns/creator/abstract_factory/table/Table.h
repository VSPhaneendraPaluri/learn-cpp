#pragma once

#include <stdint.h>

class Table
{
public:
  virtual bool hasMarbleTop() const = 0;
  virtual uint8_t seaterType() const = 0;
};
