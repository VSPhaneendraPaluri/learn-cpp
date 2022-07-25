#include "Vector.h"
#include <assert.h>

#include <iostream>

void Vector::clear()
{
  vec_.clear();
}

void Vector::resize(uint32_t size)
{
  vec_.resize(size);
  assert(vec_.capacity() == vec_.size(), "Vector capacity != size");
}

void Vector::insertFromTheBeginningInOrder()
{
  for (auto index = 0; index < Vector::maxItems_; index++)
  {
    vec_.insert(vec_.begin() + index, index);
  }
}

void Vector::insertFromTheEndInOrder()
{
  for (auto index = 0; index < Vector::maxItems_; index++)
  {
    vec_.insert(vec_.end() - index, index);
  }
}

void Vector::insertFromTheBeginningAtRandom(uint32_t* indexArray)
{
  for (auto index = 0; index < Vector::maxItems_; index++)
  {
    vec_.insert(vec_.begin() + indexArray[index], index);
  }
}

void Vector::insertFromTheEndAtRandom(uint32_t* indexArray)
{
  for (auto index = 0; index < Vector::maxItems_; index++)
  {
    vec_.insert(vec_.end() - indexArray[index], index);
  }
}

void Vector::pushBack()
{
  for (auto index = 0; index < Vector::maxItems_; index++)
  {
    vec_.push_back(index);
  }
}

void Vector::emplaceBack()
{
  for (auto index = 0; index < Vector::maxItems_; index++)
  {
    vec_.emplace_back(index);
  }
}
