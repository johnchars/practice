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
CMAKE_SOURCE_DIR = /home/cwj/foo_ws/src/practice/glog

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/cwj/foo_ws/src/practice/glog/build

# Include any dependencies generated for this target.
include CMakeFiles/hello_glog.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/hello_glog.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/hello_glog.dir/flags.make

CMakeFiles/hello_glog.dir/src/hello_glog.cc.o: CMakeFiles/hello_glog.dir/flags.make
CMakeFiles/hello_glog.dir/src/hello_glog.cc.o: ../src/hello_glog.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cwj/foo_ws/src/practice/glog/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/hello_glog.dir/src/hello_glog.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hello_glog.dir/src/hello_glog.cc.o -c /home/cwj/foo_ws/src/practice/glog/src/hello_glog.cc

CMakeFiles/hello_glog.dir/src/hello_glog.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hello_glog.dir/src/hello_glog.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cwj/foo_ws/src/practice/glog/src/hello_glog.cc > CMakeFiles/hello_glog.dir/src/hello_glog.cc.i

CMakeFiles/hello_glog.dir/src/hello_glog.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hello_glog.dir/src/hello_glog.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cwj/foo_ws/src/practice/glog/src/hello_glog.cc -o CMakeFiles/hello_glog.dir/src/hello_glog.cc.s

CMakeFiles/hello_glog.dir/src/hello_glog.cc.o.requires:

.PHONY : CMakeFiles/hello_glog.dir/src/hello_glog.cc.o.requires

CMakeFiles/hello_glog.dir/src/hello_glog.cc.o.provides: CMakeFiles/hello_glog.dir/src/hello_glog.cc.o.requires
	$(MAKE) -f CMakeFiles/hello_glog.dir/build.make CMakeFiles/hello_glog.dir/src/hello_glog.cc.o.provides.build
.PHONY : CMakeFiles/hello_glog.dir/src/hello_glog.cc.o.provides

CMakeFiles/hello_glog.dir/src/hello_glog.cc.o.provides.build: CMakeFiles/hello_glog.dir/src/hello_glog.cc.o


# Object files for target hello_glog
hello_glog_OBJECTS = \
"CMakeFiles/hello_glog.dir/src/hello_glog.cc.o"

# External object files for target hello_glog
hello_glog_EXTERNAL_OBJECTS =

hello_glog: CMakeFiles/hello_glog.dir/src/hello_glog.cc.o
hello_glog: CMakeFiles/hello_glog.dir/build.make
hello_glog: /usr/lib/x86_64-linux-gnu/libglog.a
hello_glog: /usr/lib/x86_64-linux-gnu/libgflags.a
hello_glog: /usr/lib/x86_64-linux-gnu/libunwind.so.8.0.1
hello_glog: CMakeFiles/hello_glog.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/cwj/foo_ws/src/practice/glog/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable hello_glog"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hello_glog.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/hello_glog.dir/build: hello_glog

.PHONY : CMakeFiles/hello_glog.dir/build

CMakeFiles/hello_glog.dir/requires: CMakeFiles/hello_glog.dir/src/hello_glog.cc.o.requires

.PHONY : CMakeFiles/hello_glog.dir/requires

CMakeFiles/hello_glog.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/hello_glog.dir/cmake_clean.cmake
.PHONY : CMakeFiles/hello_glog.dir/clean

CMakeFiles/hello_glog.dir/depend:
	cd /home/cwj/foo_ws/src/practice/glog/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/cwj/foo_ws/src/practice/glog /home/cwj/foo_ws/src/practice/glog /home/cwj/foo_ws/src/practice/glog/build /home/cwj/foo_ws/src/practice/glog/build /home/cwj/foo_ws/src/practice/glog/build/CMakeFiles/hello_glog.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/hello_glog.dir/depend
