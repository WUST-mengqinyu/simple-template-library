cmake_minimum_required(VERSION 3.17)
project(simple-template-library)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(lib/googletest)
include_directories(lib/googletest/googletest/include)

set(SOURCE_FILES src/main.cpp)
set(PROJECT_BINARY_DIR bin)

add_executable(test ${SOURCE_FILES})
target_link_libraries(test gtest gtest_main)

add_executable(test_ds_link_list tests/ds_list.cpp data_structure/link_list.h)
target_link_libraries(test_ds_link_list gtest gtest_main)