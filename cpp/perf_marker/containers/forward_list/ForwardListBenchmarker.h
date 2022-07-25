#include "ForwardList.h"
#include "random_number_generator/Rng.h"

#include <benchmark/benchmark.h>

static void ForwardListInsertAfter(benchmark::State& state)
{
  ForwardList flist{};
  flist.clear();

  for (auto _ : state)
  {
    flist.insertAfter();
    benchmark::DoNotOptimize(flist);
  }
}

static void ForwardListEmplaceAfter(benchmark::State& state)
{
  ForwardList flist{};
  flist.clear();

  for (auto _ : state)
  {
    flist.emplaceAfter();
    benchmark::DoNotOptimize(flist);
  }
}

static void ForwardListPushFront(benchmark::State& state)
{
  ForwardList flist{};
  flist.clear();

  for (auto _ : state)
  {
    flist.pushFront();
    benchmark::DoNotOptimize(flist);
  }
}

static void ForwardListEmplaceFront(benchmark::State& state)
{
  ForwardList flist{};
  flist.clear();

  for (auto _ : state)
  {
    flist.emplaceFront();
    benchmark::DoNotOptimize(flist);
  }
}

static void ForwardListEraseAfterFromTheBeginningInOrder(benchmark::State& state)
{
  ForwardList flist{};
  flist.clear();
  flist.resize(ForwardList::maxItems_);

  for (auto _ : state)
  {
    flist.eraseAfterFromTheBeginningInOrder();
    benchmark::DoNotOptimize(flist);
  }
}

static void ForwardListEraseAfterFromTheBeginningAtRandom(benchmark::State& state)
{
  ForwardList flist{};
  flist.clear();
  flist.resize(ForwardList::maxItems_);

  for (auto _ : state)
  {
    state.PauseTiming();
    Rng rng{};
    uint32_t indexArray[ForwardList::maxItems_];
    for (auto index = 0; index < ForwardList::maxItems_; index++)
    {
      std::size_t random_position = rng.getRandomNumber() % ForwardList::maxItems_;
      indexArray[index] = random_position;
    }
    state.ResumeTiming();
    //flist.eraseAfterFromTheBeginningAtRandom(indexArray);
    benchmark::DoNotOptimize(flist);
  }
}

static void ForwardListPopFront(benchmark::State& state)
{
  ForwardList flist{};
  flist.clear();
  flist.resize(ForwardList::maxItems_);

  for (auto _ : state)
  {
    flist.popFront();
    benchmark::DoNotOptimize(flist);
  }
}
