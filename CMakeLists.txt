cmake_minimum_required(VERSION 3.22)
project(learning-cpp)

set(CMAKE_CXX_STANDARD 14)

set_property(GLOBAL PROPERTY USE_FOLDERS TRUE)

include(cmake/conan.cmake)

enable_testing()
find_package(GTest)

add_subdirectory(cpp)