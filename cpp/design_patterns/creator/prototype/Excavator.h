#pragma once

#include "Machine.h"

class Excavator : public Machine
{
public:
  Machine* clone() override;
  std::string name() const override;
};
