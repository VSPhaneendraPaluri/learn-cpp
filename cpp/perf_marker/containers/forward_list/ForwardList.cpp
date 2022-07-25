#include "ForwardList.h"

#include <iostream>

void ForwardList::clear()
{
  fList_.clear();
}

void ForwardList::resize(uint32_t size)
{
  fList_.resize(size);
}

void ForwardList::insertAfter()
{
  for (auto index = 0; index < ForwardList::maxItems_; index++)
  {
    fList_.insert_after(fList_.before_begin(), index);
  }
}

void ForwardList::emplaceAfter()
{
  for (auto index = 0; index < ForwardList::maxItems_; index++)
  {
    fList_.emplace_after(fList_.before_begin(), index);
  }
}

void ForwardList::pushFront()
{
  for (auto index = 0; index < ForwardList::maxItems_; index++)
  {
    fList_.push_front(index);
  }
}

void ForwardList::emplaceFront()
{
  for (auto index = 0; index < ForwardList::maxItems_; index++)
  {
    fList_.emplace_front(index);
  }
}

void ForwardList::eraseAfterFromTheBeginningInOrder()
{
  for (auto index = 0; index < ForwardList::maxItems_; index++)
  {
    fList_.erase_after(fList_.before_begin());
  }
}

void ForwardList::eraseAfterFromTheBeginningAtRandom(uint32_t* indexArray)
{
  for (auto index = 0; index < ForwardList::maxItems_; index++)
  {
    auto start = std::next(fList_.before_begin());
    auto stop = std::next(start, indexArray[index] - 1);
    fList_.erase_after(start, stop);
  }
}

void ForwardList::popFront()
{
  for (auto index = 0; index < ForwardList::maxItems_; index++)
  {
    fList_.pop_front();
  }
}
