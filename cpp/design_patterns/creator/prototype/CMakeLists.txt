cmake_minimum_required(VERSION 3.20)

project(prototype)

set(HEADERS
  Backhoe.h
  Bulldozer.h
  Excavator.h
  Machine.h
  Machines.h
  ReadMe.txt
)

set(SOURCES
  Backhoe.cpp
  Bulldozer.cpp
  Excavator.cpp
  Machines.cpp
  main.cpp
)

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})

set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER cpp/design_patterns/creator)