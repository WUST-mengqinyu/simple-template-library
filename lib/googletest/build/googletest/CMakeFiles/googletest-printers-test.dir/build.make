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
include googletest/CMakeFiles/googletest-printers-test.dir/depend.make

# Include the progress variables for this target.
include googletest/CMakeFiles/googletest-printers-test.dir/progress.make

# Include the compile flags for this target's objects.
include googletest/CMakeFiles/googletest-printers-test.dir/flags.make

googletest/CMakeFiles/googletest-printers-test.dir/test/googletest-printers-test.cc.o: googletest/CMakeFiles/googletest-printers-test.dir/flags.make
googletest/CMakeFiles/googletest-printers-test.dir/test/googletest-printers-test.cc.o: ../googletest/test/googletest-printers-test.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/badcw/code/googletest-release-1.10.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object googletest/CMakeFiles/googletest-printers-test.dir/test/googletest-printers-test.cc.o"
	cd /Users/badcw/code/googletest-release-1.10.0/build/googletest && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/googletest-printers-test.dir/test/googletest-printers-test.cc.o -c /Users/badcw/code/googletest-release-1.10.0/googletest/test/googletest-printers-test.cc

googletest/CMakeFiles/googletest-printers-test.dir/test/googletest-printers-test.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/googletest-printers-test.dir/test/googletest-printers-test.cc.i"
	cd /Users/badcw/code/googletest-release-1.10.0/build/googletest && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/badcw/code/googletest-release-1.10.0/googletest/test/googletest-printers-test.cc > CMakeFiles/googletest-printers-test.dir/test/googletest-printers-test.cc.i

googletest/CMakeFiles/googletest-printers-test.dir/test/googletest-printers-test.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/googletest-printers-test.dir/test/googletest-printers-test.cc.s"
	cd /Users/badcw/code/googletest-release-1.10.0/build/googletest && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/badcw/code/googletest-release-1.10.0/googletest/test/googletest-printers-test.cc -o CMakeFiles/googletest-printers-test.dir/test/googletest-printers-test.cc.s

# Object files for target googletest-printers-test
googletest__printers__test_OBJECTS = \
"CMakeFiles/googletest-printers-test.dir/test/googletest-printers-test.cc.o"

# External object files for target googletest-printers-test
googletest__printers__test_EXTERNAL_OBJECTS =

googletest/googletest-printers-test: googletest/CMakeFiles/googletest-printers-test.dir/test/googletest-printers-test.cc.o
googletest/googletest-printers-test: googletest/CMakeFiles/googletest-printers-test.dir/build.make
googletest/googletest-printers-test: lib/libgtest_main.a
googletest/googletest-printers-test: lib/libgtest.a
googletest/googletest-printers-test: googletest/CMakeFiles/googletest-printers-test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/badcw/code/googletest-release-1.10.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable googletest-printers-test"
	cd /Users/badcw/code/googletest-release-1.10.0/build/googletest && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/googletest-printers-test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
googletest/CMakeFiles/googletest-printers-test.dir/build: googletest/googletest-printers-test

.PHONY : googletest/CMakeFiles/googletest-printers-test.dir/build

googletest/CMakeFiles/googletest-printers-test.dir/clean:
	cd /Users/badcw/code/googletest-release-1.10.0/build/googletest && $(CMAKE_COMMAND) -P CMakeFiles/googletest-printers-test.dir/cmake_clean.cmake
.PHONY : googletest/CMakeFiles/googletest-printers-test.dir/clean

googletest/CMakeFiles/googletest-printers-test.dir/depend:
	cd /Users/badcw/code/googletest-release-1.10.0/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/badcw/code/googletest-release-1.10.0 /Users/badcw/code/googletest-release-1.10.0/googletest /Users/badcw/code/googletest-release-1.10.0/build /Users/badcw/code/googletest-release-1.10.0/build/googletest /Users/badcw/code/googletest-release-1.10.0/build/googletest/CMakeFiles/googletest-printers-test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : googletest/CMakeFiles/googletest-printers-test.dir/depend

