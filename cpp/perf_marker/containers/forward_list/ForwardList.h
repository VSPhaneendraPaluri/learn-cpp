#pragma once

#include "common/defines.h"

#include <forward_list>

class ForwardList
{
public:
  ForwardList() = default;

  void clear();
  void resize(uint32_t size);

  void insertAfter();
  void emplaceAfter();
  void pushFront();
  void emplaceFront();
  void eraseAfterFromTheBeginningInOrder();
  void eraseAfterFromTheBeginningAtRandom(uint32_t* indexArray);
  void popFront();

  static constexpr uint32_t maxItems_{ common::MAX_SIZE };

private:
  std::forward_list<uint32_t> fList_{};
};