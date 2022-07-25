#pragma once

#include "common/Defines.h"

#include <stdint.h>
#include <vector>

class Vector
{
public:
  Vector() = default;
  void clear();
  void resize(uint32_t size);

  void insertFromTheBeginningInOrder();
  void insertFromTheEndInOrder();
  void insertFromTheBeginningAtRandom(uint32_t * indexArray);
  void insertFromTheEndAtRandom(uint32_t* indexArray);
  void pushBack();
  void emplaceBack();

  static constexpr uint32_t maxItems_{ common::MAX_SIZE };

private:
  std::vector<uint32_t> vec_{};
};
