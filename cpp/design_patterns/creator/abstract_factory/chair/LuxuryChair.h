#pragma once

#include "Chair.h"

class LuxuryChair : public Chair
{
public:
  bool hasCushion() const override;
  bool hasLimbs() const override;
};
