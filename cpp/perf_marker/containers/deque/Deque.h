#pragma once

#include "common/Defines.h"

#include <stdint.h>
#include <deque>

class Deque
{
public:
  Deque() = default;
  void clear();
  void resize(uint32_t size);

  void insertFromTheBeginningInOrder();
  void insertFromTheEndInOrder();
  void insertFromTheBeginningAtRandom(uint32_t* indexArray);
  void insertFromTheEndAtRandom(uint32_t* indexArray);
  void pushBack();
  void pushFront();
  void emplaceBack();
  void emplaceFront();

  static constexpr uint32_t maxItems_{ common::MAX_SIZE };

private:
  std::deque<uint32_t> deq_{};
};
