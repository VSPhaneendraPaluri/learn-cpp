#pragma once

class Sofa
{
public:
  virtual bool hasArmRests() const = 0;
  virtual bool hasNeckRests() const = 0;
  virtual bool isConfigurable() const = 0;
};
