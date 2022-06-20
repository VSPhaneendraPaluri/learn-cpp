#pragma once

#include <string>

class Machine
{
public:
  virtual Machine * clone() = 0;
  virtual std::string name() const = 0;
};
