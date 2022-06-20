#pragma once

#include "Sofa.h"

class LuxurySofa : public Sofa
{
public:
  bool hasArmRests() const override;
  bool hasNeckRests() const override;
  bool isConfigurable() const override;
};
