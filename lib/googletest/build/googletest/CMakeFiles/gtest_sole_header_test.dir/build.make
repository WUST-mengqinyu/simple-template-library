# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.18.4/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.18.4/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/badcw/code/googletest-release-1.10.0

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/badcw/code/googletest-release-1.10.0/build

# Include any dependencies generated for this target.
include googletest/CMakeFiles/gtest_sole_header_test.dir/depend.make

# Include the progress variables for this target.
include googletest/CMakeFiles/gtest_sole_header_test.dir/progress.make

# Include the compile flags for this target's objects.
include googletest/CMakeFiles/gtest_sole_header_test.dir/flags.make

googletest/CMakeFiles/gtest_sole_header_test.dir/test/gtest_sole_header_test.cc.o: googletest/CMakeFiles/gtest_sole_header_test.dir/flags.make
googletest/CMakeFiles/gtest_sole_header_test.dir/test/gtest_sole_header_test.cc.o: ../googletest/test/gtest_sole_header_test.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/badcw/code/googletest-release-1.10.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object googletest/CMakeFiles/gtest_sole_header_test.dir/test/gtest_sole_header_test.cc.o"
	cd /Users/badcw/code/googletest-release-1.10.0/build/googletest && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gtest_sole_header_test.dir/test/gtest_sole_header_test.cc.o -c /Users/badcw/code/googletest-release-1.10.0/googletest/test/gtest_sole_header_test.cc

googletest/CMakeFiles/gtest_sole_header_test.dir/test/gtest_sole_header_test.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gtest_sole_header_test.dir/test/gtest_sole_header_test.cc.i"
	cd /Users/badcw/code/googletest-release-1.10.0/build/googletest && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/badcw/code/googletest-release-1.10.0/googletest/test/gtest_sole_header_test.cc > CMakeFiles/gtest_sole_header_test.dir/test/gtest_sole_header_test.cc.i

googletest/CMakeFiles/gtest_sole_header_test.dir/test/gtest_sole_header_test.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gtest_sole_header_test.dir/test/gtest_sole_header_test.cc.s"
	cd /Users/badcw/code/googletest-release-1.10.0/build/googletest && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/badcw/code/googletest-release-1.10.0/googletest/test/gtest_sole_header_test.cc -o CMakeFiles/gtest_sole_header_test.dir/test/gtest_sole_header_test.cc.s

# Object files for target gtest_sole_header_test
gtest_sole_header_test_OBJECTS = \
"CMakeFiles/gtest_sole_header_test.dir/test/gtest_sole_header_test.cc.o"

# External object files for target gtest_sole_header_test
gtest_sole_header_test_EXTERNAL_OBJECTS =

googletest/gtest_sole_header_test: googletest/CMakeFiles/gtest_sole_header_test.dir/test/gtest_sole_header_test.cc.o
googletest/gtest_sole_header_test: googletest/CMakeFiles/gtest_sole_header_test.dir/build.make
googletest/gtest_sole_header_test: lib/libgtest_main.a
googletest/gtest_sole_header_test: lib/libgtest.a
googletest/gtest_sole_header_test: googletest/CMakeFiles/gtest_sole_header_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/badcw/code/googletest-release-1.10.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable gtest_sole_header_test"
	cd /Users/badcw/code/googletest-release-1.10.0/build/googletest && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gtest_sole_header_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
googletest/CMakeFiles/gtest_sole_header_test.dir/build: googletest/gtest_sole_header_test

.PHONY : googletest/CMakeFiles/gtest_sole_header_test.dir/build

googletest/CMakeFiles/gtest_sole_header_test.dir/clean:
	cd /Users/badcw/code/googletest-release-1.10.0/build/googletest && $(CMAKE_COMMAND) -P CMakeFiles/gtest_sole_header_test.dir/cmake_clean.cmake
.PHONY : googletest/CMakeFiles/gtest_sole_header_test.dir/clean

googletest/CMakeFiles/gtest_sole_header_test.dir/depend:
	cd /Users/badcw/code/googletest-release-1.10.0/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/badcw/code/googletest-release-1.10.0 /Users/badcw/code/googletest-release-1.10.0/googletest /Users/badcw/code/googletest-release-1.10.0/build /Users/badcw/code/googletest-release-1.10.0/build/googletest /Users/badcw/code/googletest-release-1.10.0/build/googletest/CMakeFiles/gtest_sole_header_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : googletest/CMakeFiles/gtest_sole_header_test.dir/depend

