# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/cwj/foo_ws/src/practice/ubuntu

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/cwj/foo_ws/src/practice/ubuntu/build

# Include any dependencies generated for this target.
include CMakeFiles/test_time.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/test_time.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_time.dir/flags.make

CMakeFiles/test_time.dir/src/test_time.cc.o: CMakeFiles/test_time.dir/flags.make
CMakeFiles/test_time.dir/src/test_time.cc.o: ../src/test_time.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cwj/foo_ws/src/practice/ubuntu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test_time.dir/src/test_time.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_time.dir/src/test_time.cc.o -c /home/cwj/foo_ws/src/practice/ubuntu/src/test_time.cc

CMakeFiles/test_time.dir/src/test_time.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_time.dir/src/test_time.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cwj/foo_ws/src/practice/ubuntu/src/test_time.cc > CMakeFiles/test_time.dir/src/test_time.cc.i

CMakeFiles/test_time.dir/src/test_time.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_time.dir/src/test_time.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cwj/foo_ws/src/practice/ubuntu/src/test_time.cc -o CMakeFiles/test_time.dir/src/test_time.cc.s

CMakeFiles/test_time.dir/src/test_time.cc.o.requires:

.PHONY : CMakeFiles/test_time.dir/src/test_time.cc.o.requires

CMakeFiles/test_time.dir/src/test_time.cc.o.provides: CMakeFiles/test_time.dir/src/test_time.cc.o.requires
	$(MAKE) -f CMakeFiles/test_time.dir/build.make CMakeFiles/test_time.dir/src/test_time.cc.o.provides.build
.PHONY : CMakeFiles/test_time.dir/src/test_time.cc.o.provides

CMakeFiles/test_time.dir/src/test_time.cc.o.provides.build: CMakeFiles/test_time.dir/src/test_time.cc.o


# Object files for target test_time
test_time_OBJECTS = \
"CMakeFiles/test_time.dir/src/test_time.cc.o"

# External object files for target test_time
test_time_EXTERNAL_OBJECTS =

test_time: CMakeFiles/test_time.dir/src/test_time.cc.o
test_time: CMakeFiles/test_time.dir/build.make
test_time: CMakeFiles/test_time.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/cwj/foo_ws/src/practice/ubuntu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test_time"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_time.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test_time.dir/build: test_time

.PHONY : CMakeFiles/test_time.dir/build

CMakeFiles/test_time.dir/requires: CMakeFiles/test_time.dir/src/test_time.cc.o.requires

.PHONY : CMakeFiles/test_time.dir/requires

CMakeFiles/test_time.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test_time.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test_time.dir/clean

CMakeFiles/test_time.dir/depend:
	cd /home/cwj/foo_ws/src/practice/ubuntu/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/cwj/foo_ws/src/practice/ubuntu /home/cwj/foo_ws/src/practice/ubuntu /home/cwj/foo_ws/src/practice/ubuntu/build /home/cwj/foo_ws/src/practice/ubuntu/build /home/cwj/foo_ws/src/practice/ubuntu/build/CMakeFiles/test_time.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test_time.dir/depend

