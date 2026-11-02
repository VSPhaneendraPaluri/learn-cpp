project(sorting_operations)

set(SOURCES
  BubbleSort.cpp
  BubbleSort.h
  Helpers.cpp
  Helpers.h
  InsertionSort.cpp
  InsertionSort.h
  SelectionSort.cpp
  SelectionSort.h
  TSorts.cpp
  TSortsFunctional.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} GTest::gtest_main GTest::gmock)
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER cpp/problem_solving)
add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})
set_tests_properties(${PROJECT_NAME} PROPERTIES TIMEOUT 10)