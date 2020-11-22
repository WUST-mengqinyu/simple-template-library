cmake_minimum_required(VERSION 3.17)
project(simple-template-library)

set(CMAKE_CXX_STANDARD 11)
set(SOURCE_FILES main.cpp)

include_directories(simple-template-library)

add_subdirectory(tests)
add_subdirectory(simple-template-library)

add_executable(USE_LIB main.cpp bits/stdc++.h)
target_link_libraries(USE_LIB simple-template-library)
