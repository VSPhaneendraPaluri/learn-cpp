cmake_minimum_required(VERSION 3.10)

set(PROJECT_NAME utilities)

set(
  SOURCES
  random_number_generator/Rng.cpp
  random_number_generator/Rng.h
)

add_library(${PROJECT_NAME} ${SOURCES})

set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER cpp/perf_marker)
