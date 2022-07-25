cmake_minimum_required(VERSION 3.10)

set(PROJECT_NAME containers)

set(
  SOURCES
  common/Defines.h
  deque/Deque.cpp
  deque/Deque.h
  deque/DequeBenchmarker.h
  forward_list/ForwardList.cpp
  forward_list/ForwardList.h
  forward_list/ForwardListBenchmarker.h
  vector/Vector.cpp
  vector/Vector.h
  vector/VectorBenchmarker.h
)

find_package(benchmark)
add_library(${PROJECT_NAME} ${SOURCES})

add_dependencies(${PROJECT_NAME} utilities nuget-restore)

set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER cpp/perf_marker)

# Include and link against SystemC library
target_include_directories(${PROJECT_NAME} PRIVATE ${GOOGLE_BENCHMARK_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME}
  PUBLIC
  ${GOOGLE_BENCHMARK_LIBRARY_DIR}/benchmarkd.lib
  ${GOOGLE_BENCHMARK_LIBRARY_DIR}/benchmark_maind.lib
  ShLwApi.lib
  utilities
)

