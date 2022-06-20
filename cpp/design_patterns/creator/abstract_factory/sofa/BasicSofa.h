#pragma once

#include "Sofa.h"

class BasicSofa: public Sofa
{
public:
  bool hasArmRests() const override;
  bool hasNeckRests() const override;
  bool isConfigurable() const override;
};
