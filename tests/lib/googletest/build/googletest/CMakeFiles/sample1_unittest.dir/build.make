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
include googletest/CMakeFiles/sample1_unittest.dir/depend.make

# Include the progress variables for this target.
include googletest/CMakeFiles/sample1_unittest.dir/progress.make

# Include the compile flags for this target's objects.
include googletest/CMakeFiles/sample1_unittest.dir/flags.make

googletest/CMakeFiles/sample1_unittest.dir/samples/sample1_unittest.cc.o: googletest/CMakeFiles/sample1_unittest.dir/flags.make
googletest/CMakeFiles/sample1_unittest.dir/samples/sample1_unittest.cc.o: ../googletest/samples/sample1_unittest.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/badcw/code/googletest-release-1.10.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object googletest/CMakeFiles/sample1_unittest.dir/samples/sample1_unittest.cc.o"
	cd /Users/badcw/code/googletest-release-1.10.0/build/googletest && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sample1_unittest.dir/samples/sample1_unittest.cc.o -c /Users/badcw/code/googletest-release-1.10.0/googletest/samples/sample1_unittest.cc

googletest/CMakeFiles/sample1_unittest.dir/samples/sample1_unittest.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sample1_unittest.dir/samples/sample1_unittest.cc.i"
	cd /Users/badcw/code/googletest-release-1.10.0/build/googletest && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/badcw/code/googletest-release-1.10.0/googletest/samples/sample1_unittest.cc > CMakeFiles/sample1_unittest.dir/samples/sample1_unittest.cc.i

googletest/CMakeFiles/sample1_unittest.dir/samples/sample1_unittest.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sample1_unittest.dir/samples/sample1_unittest.cc.s"
	cd /Users/badcw/code/googletest-release-1.10.0/build/googletest && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/badcw/code/googletest-release-1.10.0/googletest/samples/sample1_unittest.cc -o CMakeFiles/sample1_unittest.dir/samples/sample1_unittest.cc.s

googletest/CMakeFiles/sample1_unittest.dir/samples/sample1.cc.o: googletest/CMakeFiles/sample1_unittest.dir/flags.make
googletest/CMakeFiles/sample1_unittest.dir/samples/sample1.cc.o: ../googletest/samples/sample1.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/badcw/code/googletest-release-1.10.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object googletest/CMakeFiles/sample1_unittest.dir/samples/sample1.cc.o"
	cd /Users/badcw/code/googletest-release-1.10.0/build/googletest && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sample1_unittest.dir/samples/sample1.cc.o -c /Users/badcw/code/googletest-release-1.10.0/googletest/samples/sample1.cc

googletest/CMakeFiles/sample1_unittest.dir/samples/sample1.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sample1_unittest.dir/samples/sample1.cc.i"
	cd /Users/badcw/code/googletest-release-1.10.0/build/googletest && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/badcw/code/googletest-release-1.10.0/googletest/samples/sample1.cc > CMakeFiles/sample1_unittest.dir/samples/sample1.cc.i

googletest/CMakeFiles/sample1_unittest.dir/samples/sample1.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sample1_unittest.dir/samples/sample1.cc.s"
	cd /Users/badcw/code/googletest-release-1.10.0/build/googletest && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/badcw/code/googletest-release-1.10.0/googletest/samples/sample1.cc -o CMakeFiles/sample1_unittest.dir/samples/sample1.cc.s

# Object files for target sample1_unittest
sample1_unittest_OBJECTS = \
"CMakeFiles/sample1_unittest.dir/samples/sample1_unittest.cc.o" \
"CMakeFiles/sample1_unittest.dir/samples/sample1.cc.o"

# External object files for target sample1_unittest
sample1_unittest_EXTERNAL_OBJECTS =

googletest/sample1_unittest: googletest/CMakeFiles/sample1_unittest.dir/samples/sample1_unittest.cc.o
googletest/sample1_unittest: googletest/CMakeFiles/sample1_unittest.dir/samples/sample1.cc.o
googletest/sample1_unittest: googletest/CMakeFiles/sample1_unittest.dir/build.make
googletest/sample1_unittest: lib/libgtest_main.a
googletest/sample1_unittest: lib/libgtest.a
googletest/sample1_unittest: googletest/CMakeFiles/sample1_unittest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/badcw/code/googletest-release-1.10.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable sample1_unittest"
	cd /Users/badcw/code/googletest-release-1.10.0/build/googletest && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sample1_unittest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
googletest/CMakeFiles/sample1_unittest.dir/build: googletest/sample1_unittest

.PHONY : googletest/CMakeFiles/sample1_unittest.dir/build

googletest/CMakeFiles/sample1_unittest.dir/clean:
	cd /Users/badcw/code/googletest-release-1.10.0/build/googletest && $(CMAKE_COMMAND) -P CMakeFiles/sample1_unittest.dir/cmake_clean.cmake
.PHONY : googletest/CMakeFiles/sample1_unittest.dir/clean

googletest/CMakeFiles/sample1_unittest.dir/depend:
	cd /Users/badcw/code/googletest-release-1.10.0/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/badcw/code/googletest-release-1.10.0 /Users/badcw/code/googletest-release-1.10.0/googletest /Users/badcw/code/googletest-release-1.10.0/build /Users/badcw/code/googletest-release-1.10.0/build/googletest /Users/badcw/code/googletest-release-1.10.0/build/googletest/CMakeFiles/sample1_unittest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : googletest/CMakeFiles/sample1_unittest.dir/depend
