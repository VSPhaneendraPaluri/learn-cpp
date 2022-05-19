cmake_minimum_required(VERSION 3.20)

project(factory)

set(HEADERS
  Cat.h
  Dog.h
  PetSeller.h
  PetInterface.h
  PetType.h
)

set(SOURCES
  Cat.cpp
  Dog.cpp
  main.cpp
  PetSeller.cpp
)

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})

set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER cpp/design_patterns/creator)