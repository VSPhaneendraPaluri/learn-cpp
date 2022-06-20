cmake_minimum_required(VERSION 3.20)

project(abstract_factory)

set(HEADERS
  chair/Chair.h
  chair/BasicChair.h
  chair/LuxuryChair.h
  furniture/Furniture.h
  furniture/BasicFurniture.h
  furniture/LuxuryFurniture.h
  furniture/FurnitureFactory.h
  FurnitureType.h
  sofa/Sofa.h
  sofa/BasicSofa.h
  sofa/LuxurySofa.h
  table/Table.h
  table/BasicTable.h
  table/LuxuryTable.h
  ReadMe.txt
)

set(SOURCES
  chair/BasicChair.cpp
  chair/LuxuryChair.cpp
  furniture/BasicFurniture.cpp
  furniture/LuxuryFurniture.cpp
  furniture/FurnitureFactory.cpp
  sofa/BasicSofa.cpp
  sofa/LuxurySofa.cpp
  table/BasicTable.cpp
  table/LuxuryTable.cpp
  main.cpp
)

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})

set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER cpp/design_patterns/creator)

target_include_directories(${PROJECT_NAME}
  PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}
  chair
  sofa
  table
)