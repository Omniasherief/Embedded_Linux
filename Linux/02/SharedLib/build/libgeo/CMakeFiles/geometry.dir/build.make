# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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
CMAKE_COMMAND = /snap/cmake/1415/bin/cmake

# The command to remove a file.
RM = /snap/cmake/1415/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/omnia/EL/Linux/02/SharedLib

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/omnia/EL/Linux/02/SharedLib/build

# Include any dependencies generated for this target.
include libgeo/CMakeFiles/geometry.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include libgeo/CMakeFiles/geometry.dir/compiler_depend.make

# Include the progress variables for this target.
include libgeo/CMakeFiles/geometry.dir/progress.make

# Include the compile flags for this target's objects.
include libgeo/CMakeFiles/geometry.dir/flags.make

libgeo/CMakeFiles/geometry.dir/geometry.cpp.o: libgeo/CMakeFiles/geometry.dir/flags.make
libgeo/CMakeFiles/geometry.dir/geometry.cpp.o: /home/omnia/EL/Linux/02/SharedLib/libgeo/geometry.cpp
libgeo/CMakeFiles/geometry.dir/geometry.cpp.o: libgeo/CMakeFiles/geometry.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/omnia/EL/Linux/02/SharedLib/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object libgeo/CMakeFiles/geometry.dir/geometry.cpp.o"
	cd /home/omnia/EL/Linux/02/SharedLib/build/libgeo && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT libgeo/CMakeFiles/geometry.dir/geometry.cpp.o -MF CMakeFiles/geometry.dir/geometry.cpp.o.d -o CMakeFiles/geometry.dir/geometry.cpp.o -c /home/omnia/EL/Linux/02/SharedLib/libgeo/geometry.cpp

libgeo/CMakeFiles/geometry.dir/geometry.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/geometry.dir/geometry.cpp.i"
	cd /home/omnia/EL/Linux/02/SharedLib/build/libgeo && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/omnia/EL/Linux/02/SharedLib/libgeo/geometry.cpp > CMakeFiles/geometry.dir/geometry.cpp.i

libgeo/CMakeFiles/geometry.dir/geometry.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/geometry.dir/geometry.cpp.s"
	cd /home/omnia/EL/Linux/02/SharedLib/build/libgeo && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/omnia/EL/Linux/02/SharedLib/libgeo/geometry.cpp -o CMakeFiles/geometry.dir/geometry.cpp.s

# Object files for target geometry
geometry_OBJECTS = \
"CMakeFiles/geometry.dir/geometry.cpp.o"

# External object files for target geometry
geometry_EXTERNAL_OBJECTS =

libgeo/libgeometry.so: libgeo/CMakeFiles/geometry.dir/geometry.cpp.o
libgeo/libgeometry.so: libgeo/CMakeFiles/geometry.dir/build.make
libgeo/libgeometry.so: libgeo/CMakeFiles/geometry.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/omnia/EL/Linux/02/SharedLib/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library libgeometry.so"
	cd /home/omnia/EL/Linux/02/SharedLib/build/libgeo && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/geometry.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
libgeo/CMakeFiles/geometry.dir/build: libgeo/libgeometry.so
.PHONY : libgeo/CMakeFiles/geometry.dir/build

libgeo/CMakeFiles/geometry.dir/clean:
	cd /home/omnia/EL/Linux/02/SharedLib/build/libgeo && $(CMAKE_COMMAND) -P CMakeFiles/geometry.dir/cmake_clean.cmake
.PHONY : libgeo/CMakeFiles/geometry.dir/clean

libgeo/CMakeFiles/geometry.dir/depend:
	cd /home/omnia/EL/Linux/02/SharedLib/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/omnia/EL/Linux/02/SharedLib /home/omnia/EL/Linux/02/SharedLib/libgeo /home/omnia/EL/Linux/02/SharedLib/build /home/omnia/EL/Linux/02/SharedLib/build/libgeo /home/omnia/EL/Linux/02/SharedLib/build/libgeo/CMakeFiles/geometry.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : libgeo/CMakeFiles/geometry.dir/depend
