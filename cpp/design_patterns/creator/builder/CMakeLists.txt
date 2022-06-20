cmake_minimum_required(VERSION 3.20)

project(builder)

set(HEADERS
  builder/BuilderInterface.h
  builder/CarFeature.h
  builder/CarBuilder.h
  builder/CarManualBuilder.h
  director/Director.h
  ReadMe.txt
)

set(SOURCES
  builder/CarBuilder.cpp
  builder/CarManualBuilder.cpp
  director/Director.cpp
  main.cpp
)

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})

set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER cpp/design_patterns/creator)

target_include_directories(
  ${PROJECT_NAME}
  PRIVATE
  builder
  car
  car_manual
  director
)