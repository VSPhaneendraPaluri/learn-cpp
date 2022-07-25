#pragma once

#include "Vector.h"
#include "random_number_generator/Rng.h"

#include "benchmark/benchmark.h"

static void VectorInsertFromTheBeginningInOrder(benchmark::State& state)
{
  Vector vec{};
  vec.clear();

  for (auto _ : state)
  {
    vec.insertFromTheBeginningInOrder();
    benchmark::DoNotOptimize(vec);
  }
}

static void VectorInsertFromTheEndInOrder(benchmark::State& state)
{
  Vector vec{};
  vec.clear();

  for (auto _ : state)
  {
    vec.insertFromTheEndInOrder();
    benchmark::DoNotOptimize(vec);
  }
}

static void VectorInsertFromTheBeginningAtRandom(benchmark::State& state)
{
  Vector vec{};
  vec.clear();
  vec.resize(Vector::maxItems_);

  for (auto _ : state)
  {
    state.PauseTiming();
    Rng rng{};
    uint32_t indexArray[Vector::maxItems_];
    for (auto index = 0; index < Vector::maxItems_; index++)
    {
      std::size_t random_position = rng.getRandomNumber() % Vector::maxItems_;
      indexArray[index] = random_position;
    }
    state.ResumeTiming();
    vec.insertFromTheBeginningAtRandom(indexArray);
    benchmark::DoNotOptimize(vec);
  }
}

static void VectorInsertFromTheEndAtRandom(benchmark::State& state)
{
  Vector vec{};
  vec.clear();
  vec.resize(Vector::maxItems_);

  for (auto _ : state)
  {
    state.PauseTiming();
    Rng rng{};
    uint32_t indexArray[Vector::maxItems_];
    for (auto index = 0; index < Vector::maxItems_; index++)
    {
      std::size_t random_position = rng.getRandomNumber() % Vector::maxItems_;
      indexArray[index] = random_position;
    }
    state.ResumeTiming();
    vec.insertFromTheEndAtRandom(indexArray);
    benchmark::DoNotOptimize(vec);
  }
}

static void VectorPushBack(benchmark::State& state)
{
  Vector vec{};
  vec.clear();

  for (auto _ : state)
  {
    vec.pushBack();
    benchmark::DoNotOptimize(vec);
  }
}

static void VectorEmplaceBack(benchmark::State& state)
{
  Vector vec{};
  vec.clear();

  for (auto _ : state)
  {
    vec.emplaceBack();
    benchmark::DoNotOptimize(vec);
  }
}

