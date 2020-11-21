cmake_minimum_required(VERSION 3.17)
project(simple-template-library)

set(CMAKE_CXX_STANDARD 11)
set(SOURCE_FILES main.cpp)

include_directories(simple-template-library)

add_subdirectory(tests)
add_subdirectory(simple-template-library)

add_executable(USE_LIB main.cpp)
target_link_libraries(USE_LIB simple-template-library)

#FILE(GLOB ALGORITHM_HEADER_FILES ".h" "src/algorithm/*.h")
#FILE(GLOB DATA_STRUCTURE_HEADER_FILES ".h" "src/data_structure/*.h")

#add_executable(test ${SOURCE_FILES} ${ALGORITHM_HEADER_FILES} ${DATA_STRUCTURE_HEADER_FILES})

#FILE(GLOB TEST_FILES ".cpp" "tests/*.cpp")
#
#set(HEAD src/header.h ${ALGORITHM_HEAD_FILES} ${DATA_STRUCTURE_HEAD_FILES})
