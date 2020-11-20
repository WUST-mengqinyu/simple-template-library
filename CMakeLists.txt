cmake_minimum_required(VERSION 3.17)
project(simple-template-library)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)

add_subdirectory(tests)

FILE(GLOB ALGORITHM_HEADER_FILES ".h" "src/algorithm/*.h")
FILE(GLOB DATA_STRUCTURE_HEADER_FILES ".h" "src/data_structure/*.h")

add_executable(test ${SOURCE_FILES} ${ALGORITHM_HEADER_FILES} ${DATA_STRUCTURE_HEADER_FILES})

#FILE(GLOB TEST_FILES ".cpp" "tests/*.cpp")
#
#set(HEAD src/header.h ${ALGORITHM_HEAD_FILES} ${DATA_STRUCTURE_HEAD_FILES})
#
#add_executable(test ${SOURCE_FILES} ${HEAD})
#target_link_libraries(test gtest gtest_main)