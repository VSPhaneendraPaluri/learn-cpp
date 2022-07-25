#include "Deque.h"
#include <assert.h>

#include <iostream>

void Deque::clear()
{
  deq_.clear();
}

void Deque::resize(uint32_t size)
{
  deq_.clear();
  deq_.resize(size);
}

void Deque::insertFromTheBeginningInOrder()
{
  for (auto index = 0; index < Deque::maxItems_; index++)
  {
    deq_.insert(deq_.begin() + index, index);
  }
}

void Deque::insertFromTheEndInOrder()
{
  for (auto index = 0; index < Deque::maxItems_; index++)
  {
    deq_.insert(deq_.end() - index, index);
  }
}

void Deque::insertFromTheBeginningAtRandom(uint32_t* indexArray)
{
  for (auto index = 0; index < Deque::maxItems_; index++)
  {
    deq_.insert(deq_.begin() + indexArray[index], index);
  }
}

void Deque::insertFromTheEndAtRandom(uint32_t* indexArray)
{
  for (auto index = 0; index < Deque::maxItems_; index++)
  {
    deq_.insert(deq_.end() - indexArray[index], index);
  }
}

void Deque::pushBack()
{
  for (auto index = 0; index < Deque::maxItems_; index++)
  {
    deq_.push_back(index);
  }
}

void Deque::pushFront()
{
  for (auto index = 0; index < Deque::maxItems_; index++)
  {
    deq_.push_front(index);
  }
}

void Deque::emplaceBack()
{
  for (auto index = 0; index < Deque::maxItems_; index++)
  {
    deq_.emplace_back(index);
  }
}

void Deque::emplaceFront()
{
  for (auto index = 0; index < Deque::maxItems_; index++)
  {
    deq_.emplace_front(index);
  }
}
