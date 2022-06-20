cmake_minimum_required(VERSION 3.20)

project(singleton)

set(HEADERS
  Singleton.h
  User1.h
  User2.h
  ReadMe.txt
)

set(SOURCES
  Singleton.cpp
  User1.cpp
  User2.cpp
  main.cpp
)

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})

set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER cpp/design_patterns/creator)