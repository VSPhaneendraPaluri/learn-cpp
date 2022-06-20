#pragma once

#include "Machine.h"

class Backhoe : public Machine
{
public:
  Machine* clone() override;
  std::string name() const override;
};
