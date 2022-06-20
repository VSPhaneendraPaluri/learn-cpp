#pragma once

#include "Chair.h"

class BasicChair : public Chair
{
public:
  bool hasCushion() const override;
  bool hasLimbs() const override;
};
