#pragma once

#include <stddef.h>
#include <random>
#include <limits>

class Rng
{
public:
  uint32_t getRandomNumber();

private:
  std::random_device rd_;
  std::mt19937 randomGenerator_{ rd_() };
  static constexpr uint32_t minValue_{ std::numeric_limits<uint32_t>::min() };
  static constexpr uint32_t maxValue_{ std::numeric_limits<uint32_t>::max() };
  std::uniform_int_distribution<uint32_t> distribution_{ minValue_, maxValue_ };
};