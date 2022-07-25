cmake_minimum_required(VERSION 3.10)

project(runner)

set(
  SOURCES
  main.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

add_dependencies(
  ${PROJECT_NAME}
  nuget-restore
  containers
  utilities
)

set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER cpp/perf_marker)

# Include and link against SystemC library
target_include_directories(${PROJECT_NAME} PRIVATE ${GOOGLE_BENCHMARK_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME}
  PUBLIC
  ${GOOGLE_BENCHMARK_LIBRARY_DIR}/benchmarkd.lib
  ${GOOGLE_BENCHMARK_LIBRARY_DIR}/benchmark_maind.lib
  ShLwApi.lib
  containers
  utilities
)

