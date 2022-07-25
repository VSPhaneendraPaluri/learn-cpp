#pragma once

#include "Deque.h"
#include "random_number_generator/Rng.h"

#include <benchmark/benchmark.h>

static void DequeInsertFromTheBeginningInOrder(benchmark::State& state)
{
  Deque deq{};
  deq.clear();
  //deq.resize(Deque::maxItems_);

  for (auto _ : state)
  {
    deq.insertFromTheBeginningInOrder();
    benchmark::DoNotOptimize(deq);
  }
}

static void DequeInsertFromTheEndInOrder(benchmark::State& state)
{
  Deque deq{};
  deq.clear();

  for (auto _ : state)
  {
    deq.insertFromTheEndInOrder();
    benchmark::DoNotOptimize(deq);
  }
}

static void DequeInsertFromTheBeginningAtRandom(benchmark::State& state)
{
  Deque deq{};
  deq.clear();
  deq.resize(Deque::maxItems_);

  for (auto _ : state)
  {
    state.PauseTiming();
    Rng rng{};
    uint32_t indexArray[Deque::maxItems_];
    for (auto index = 0; index < Deque::maxItems_; index++)
    {
      std::size_t random_position = rng.getRandomNumber() % Deque::maxItems_;
      indexArray[index] = random_position;
    }
    state.ResumeTiming();
    deq.insertFromTheBeginningAtRandom(indexArray);
    benchmark::DoNotOptimize(deq);
  }
}

static void DequeInsertFromTheEndAtRandom(benchmark::State& state)
{
  Deque deq{};
  deq.clear();
  deq.resize(Deque::maxItems_);

  for (auto _ : state)
  {
    state.PauseTiming();
    Rng rng{};
    uint32_t indexArray[Deque::maxItems_];
    for (auto index = 0; index < Deque::maxItems_; index++)
    {
      std::size_t random_position = rng.getRandomNumber() % Deque::maxItems_;
      indexArray[index] = random_position;
    }
    state.ResumeTiming();
    deq.insertFromTheEndAtRandom(indexArray);
    benchmark::DoNotOptimize(deq);
  }
}

static void DequePushBack(benchmark::State& state)
{
  Deque deq{};
  deq.clear();

  for (auto _ : state)
  {
    deq.pushBack();
    benchmark::DoNotOptimize(deq);
  }
}
static void DequePushFront(benchmark::State& state)
{
  Deque deq{};
  deq.clear();

  for (auto _ : state)
  {
    deq.pushFront();
    benchmark::DoNotOptimize(deq);
  }
}

static void DequeEmplaceBack(benchmark::State& state)
{
  Deque deq{};
  deq.clear();

  for (auto _ : state)
  {
    deq.emplaceBack();
    benchmark::DoNotOptimize(deq);
  }
}

static void DequeEmplaceFront(benchmark::State& state)
{
  Deque deq{};
  deq.clear();

  for (auto _ : state)
  {
    deq.emplaceFront();
    benchmark::DoNotOptimize(deq);
  }
}
