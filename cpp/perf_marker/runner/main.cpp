#include "vector/VectorBenchmarker.h"
#include "deque/DequeBenchmarker.h"
#include "forward_list/ForwardListBenchmarker.h"

#include <benchmark/benchmark.h>

// Vector
BENCHMARK(VectorInsertFromTheBeginningInOrder)->Iterations(1);
BENCHMARK(VectorInsertFromTheEndInOrder)->Iterations(1);
BENCHMARK(VectorInsertFromTheBeginningAtRandom)->Iterations(1);
BENCHMARK(VectorInsertFromTheEndAtRandom)->Iterations(1);
BENCHMARK(VectorPushBack)->Iterations(1);
BENCHMARK(VectorEmplaceBack)->Iterations(1);

// Deque
BENCHMARK(DequeInsertFromTheBeginningInOrder)->Iterations(1);
BENCHMARK(DequeInsertFromTheEndInOrder)->Iterations(1);
BENCHMARK(DequeInsertFromTheBeginningAtRandom)->Iterations(1);
BENCHMARK(DequeInsertFromTheEndAtRandom)->Iterations(1);
BENCHMARK(DequePushBack)->Iterations(1);
BENCHMARK(DequePushFront)->Iterations(1);
BENCHMARK(DequeEmplaceBack)->Iterations(1);
BENCHMARK(DequeEmplaceFront)->Iterations(1);

// ForwardList
BENCHMARK(ForwardListInsertAfter)->Iterations(1);
BENCHMARK(ForwardListEmplaceAfter)->Iterations(1);
BENCHMARK(ForwardListPushFront)->Iterations(1);
BENCHMARK(ForwardListEmplaceFront)->Iterations(1);
BENCHMARK(ForwardListEraseAfterFromTheBeginningInOrder)->Iterations(1);
BENCHMARK(ForwardListEraseAfterFromTheBeginningAtRandom)->Iterations(1);
BENCHMARK(ForwardListPopFront)->Iterations(1);

BENCHMARK_MAIN();
