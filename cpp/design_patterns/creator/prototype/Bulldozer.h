#pragma once

#include "Machine.h"

class Bulldozer : public Machine
{
public:
  Machine* clone() override;
  std::string name() const override;
};
