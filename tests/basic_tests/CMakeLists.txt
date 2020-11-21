include_directories(${gtest-SOURCE-DIR}/include ${gtest-SOURCE-DIR})

FILE(GLOB BASIC_TESTS_FILES ".cpp" "*.cpp")
add_executable(runTests ${BASIC_TESTS_FILES})
#
target_link_libraries(runTests simple-template-library)
target_link_libraries(runTests gtest gtest_main)