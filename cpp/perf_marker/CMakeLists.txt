cmake_minimum_required(VERSION 3.10)

include_directories(${CMAKE_CURRENT_LIST_DIR}/containers)
include_directories(${CMAKE_CURRENT_LIST_DIR}/utilities)

add_subdirectory(containers)
add_subdirectory(utilities)
add_subdirectory(runner)