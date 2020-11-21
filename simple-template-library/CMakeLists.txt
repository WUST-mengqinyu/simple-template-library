project(simple-template-library)

FILE(GLOB ALGORITHM_HEADER_FILES ".h" "header/algorithm/*.h")
FILE(GLOB DATA_STRUCTURE_HEADER_FILES ".h" "header/data_structure/*.h")
FILE(GLOB ALGORITHM_SOURCE_FILES ".cpp" "src/algorithm/*.cpp")
FILE(GLOB DATA_STRUCTURE_SOURCE_FILES ".cpp" "src/data_structure/*.cpp")
#
add_library(simple-template-library ${ALGORITHM_HEADER_FILES} ${DATA_STRUCTURE_HEADER_FILES} ${ALGORITHM_SOURCE_FILES} ${DATA_STRUCTURE_SOURCE_FILES})