cmake_minimum_required(VERSION 3.17)
project(simple-template-library)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(tests/lib/googletest)
include_directories(tests/lib/googletest/googletest/include)

set(SOURCE_FILES src/main.cpp)
set(PROJECT_BINARY_DIR bin)

FILE(GLOB ALGORITHM_HEAD_FILES "*.h" "algorithm/*.h")
FILE(GLOB DATA_STRUCTURE_HEAD_FILES "*.h" "data_structure/*.h")
FILE(GLOB TEST_FILES ".cpp" "tests/*.cpp")

set(HEAD header.h ${ALGORITHM_HEAD_FILES} ${DATA_STRUCTURE_HEAD_FILES})

add_executable(test ${SOURCE_FILES} ${HEAD})
target_link_libraries(test gtest gtest_main)