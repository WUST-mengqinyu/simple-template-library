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
include googletest/CMakeFiles/googletest-shuffle-test_.dir/depend.make

# Include the progress variables for this target.
include googletest/CMakeFiles/googletest-shuffle-test_.dir/progress.make

# Include the compile flags for this target's objects.
include googletest/CMakeFiles/googletest-shuffle-test_.dir/flags.make

googletest/CMakeFiles/googletest-shuffle-test_.dir/test/googletest-shuffle-test_.cc.o: googletest/CMakeFiles/googletest-shuffle-test_.dir/flags.make
googletest/CMakeFiles/googletest-shuffle-test_.dir/test/googletest-shuffle-test_.cc.o: ../googletest/test/googletest-shuffle-test_.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/badcw/code/googletest-release-1.10.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object googletest/CMakeFiles/googletest-shuffle-test_.dir/test/googletest-shuffle-test_.cc.o"
	cd /Users/badcw/code/googletest-release-1.10.0/build/googletest && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/googletest-shuffle-test_.dir/test/googletest-shuffle-test_.cc.o -c /Users/badcw/code/googletest-release-1.10.0/googletest/test/googletest-shuffle-test_.cc

googletest/CMakeFiles/googletest-shuffle-test_.dir/test/googletest-shuffle-test_.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/googletest-shuffle-test_.dir/test/googletest-shuffle-test_.cc.i"
	cd /Users/badcw/code/googletest-release-1.10.0/build/googletest && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/badcw/code/googletest-release-1.10.0/googletest/test/googletest-shuffle-test_.cc > CMakeFiles/googletest-shuffle-test_.dir/test/googletest-shuffle-test_.cc.i

googletest/CMakeFiles/googletest-shuffle-test_.dir/test/googletest-shuffle-test_.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/googletest-shuffle-test_.dir/test/googletest-shuffle-test_.cc.s"
	cd /Users/badcw/code/googletest-release-1.10.0/build/googletest && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/badcw/code/googletest-release-1.10.0/googletest/test/googletest-shuffle-test_.cc -o CMakeFiles/googletest-shuffle-test_.dir/test/googletest-shuffle-test_.cc.s

# Object files for target googletest-shuffle-test_
googletest__shuffle__test__OBJECTS = \
"CMakeFiles/googletest-shuffle-test_.dir/test/googletest-shuffle-test_.cc.o"

# External object files for target googletest-shuffle-test_
googletest__shuffle__test__EXTERNAL_OBJECTS =

googletest/googletest-shuffle-test_: googletest/CMakeFiles/googletest-shuffle-test_.dir/test/googletest-shuffle-test_.cc.o
googletest/googletest-shuffle-test_: googletest/CMakeFiles/googletest-shuffle-test_.dir/build.make
googletest/googletest-shuffle-test_: lib/libgtest.a
googletest/googletest-shuffle-test_: googletest/CMakeFiles/googletest-shuffle-test_.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/badcw/code/googletest-release-1.10.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable googletest-shuffle-test_"
	cd /Users/badcw/code/googletest-release-1.10.0/build/googletest && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/googletest-shuffle-test_.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
googletest/CMakeFiles/googletest-shuffle-test_.dir/build: googletest/googletest-shuffle-test_

.PHONY : googletest/CMakeFiles/googletest-shuffle-test_.dir/build

googletest/CMakeFiles/googletest-shuffle-test_.dir/clean:
	cd /Users/badcw/code/googletest-release-1.10.0/build/googletest && $(CMAKE_COMMAND) -P CMakeFiles/googletest-shuffle-test_.dir/cmake_clean.cmake
.PHONY : googletest/CMakeFiles/googletest-shuffle-test_.dir/clean

googletest/CMakeFiles/googletest-shuffle-test_.dir/depend:
	cd /Users/badcw/code/googletest-release-1.10.0/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/badcw/code/googletest-release-1.10.0 /Users/badcw/code/googletest-release-1.10.0/googletest /Users/badcw/code/googletest-release-1.10.0/build /Users/badcw/code/googletest-release-1.10.0/build/googletest /Users/badcw/code/googletest-release-1.10.0/build/googletest/CMakeFiles/googletest-shuffle-test_.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : googletest/CMakeFiles/googletest-shuffle-test_.dir/depend
