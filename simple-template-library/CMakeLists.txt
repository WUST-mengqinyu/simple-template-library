project(simple-template-library)

FILE(GLOB ALGORITHM_HEADER_FILES ".h" "header/algorithm/*.h")
FILE(GLOB DATA_STRUCTURE_HEADER_FILES ".h" "header/data_structure/*.h")
FILE(GLOB KERNEL_THINGS_HEADER_FILES ".h" "header/kernel_things/*.h")

FILE(GLOB ALGORITHM_SOURCE_FILES ".cpp" "src/algorithm/*.cpp")
FILE(GLOB DATA_STRUCTURE_SOURCE_FILES ".cpp" "src/data_structure/*.cpp")
FILE(GLOB KERNEL_THINGS_SOURCE_FILES ".cpp" "src/kernel_things/*.cpp")

SET(ALL_HEADERS ${ALGORITHM_HEADER_FILES} ${DATA_STRUCTURE_HEADER_FILES} ${KERNEL_THINGS_HEADER_FILES})
SET(ALL_SOURCES ${ALGORITHM_SOURCE_FILES} ${DATA_STRUCTURE_SOURCE_FILES} ${KERNEL_THINGS_SOURCE_FILES})

add_library(simple-template-library ${ALL_HEADERS} ${ALL_SOURCES} header/test.h)