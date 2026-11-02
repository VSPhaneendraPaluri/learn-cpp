cmake_minimum_required(VERSION 3.16)
project(codingchallenges VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the build type." FORCE)
endif()

set(PROJECT_CXX_SOURCES
  "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/cache_impl/cache.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/encode_decode_puzzles/decode.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/register_impl/register.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/string_puzzles/string_puzzles.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/test_scripts/test.cpp"
)

add_executable(codingchallenges ${PROJECT_CXX_SOURCES})

target_include_directories(codingchallenges PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}"
  "${CMAKE_CURRENT_SOURCE_DIR}/cache_impl"
  "${CMAKE_CURRENT_SOURCE_DIR}/encode_decode_puzzles"
  "${CMAKE_CURRENT_SOURCE_DIR}/register_impl"
  "${CMAKE_CURRENT_SOURCE_DIR}/string_puzzles"
  "${CMAKE_CURRENT_SOURCE_DIR}/test_scripts"
)

add_test(NAME codingchallenges COMMAND codingchallenges)
set_tests_properties(codingchallenges PROPERTIES TIMEOUT 10)