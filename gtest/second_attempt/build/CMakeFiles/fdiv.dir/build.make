# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/devlx/all/c++/exercises/gtest/second_attempt

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/devlx/all/c++/exercises/gtest/second_attempt/build

# Include any dependencies generated for this target.
include CMakeFiles/fdiv.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/fdiv.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/fdiv.dir/flags.make

CMakeFiles/fdiv.dir/main.cpp.o: CMakeFiles/fdiv.dir/flags.make
CMakeFiles/fdiv.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/devlx/all/c++/exercises/gtest/second_attempt/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/fdiv.dir/main.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/fdiv.dir/main.cpp.o -c /home/devlx/all/c++/exercises/gtest/second_attempt/main.cpp

CMakeFiles/fdiv.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fdiv.dir/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/devlx/all/c++/exercises/gtest/second_attempt/main.cpp > CMakeFiles/fdiv.dir/main.cpp.i

CMakeFiles/fdiv.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fdiv.dir/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/devlx/all/c++/exercises/gtest/second_attempt/main.cpp -o CMakeFiles/fdiv.dir/main.cpp.s

CMakeFiles/fdiv.dir/fdiv.cpp.o: CMakeFiles/fdiv.dir/flags.make
CMakeFiles/fdiv.dir/fdiv.cpp.o: ../fdiv.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/devlx/all/c++/exercises/gtest/second_attempt/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/fdiv.dir/fdiv.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/fdiv.dir/fdiv.cpp.o -c /home/devlx/all/c++/exercises/gtest/second_attempt/fdiv.cpp

CMakeFiles/fdiv.dir/fdiv.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fdiv.dir/fdiv.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/devlx/all/c++/exercises/gtest/second_attempt/fdiv.cpp > CMakeFiles/fdiv.dir/fdiv.cpp.i

CMakeFiles/fdiv.dir/fdiv.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fdiv.dir/fdiv.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/devlx/all/c++/exercises/gtest/second_attempt/fdiv.cpp -o CMakeFiles/fdiv.dir/fdiv.cpp.s

# Object files for target fdiv
fdiv_OBJECTS = \
"CMakeFiles/fdiv.dir/main.cpp.o" \
"CMakeFiles/fdiv.dir/fdiv.cpp.o"

# External object files for target fdiv
fdiv_EXTERNAL_OBJECTS =

libfdiv.a: CMakeFiles/fdiv.dir/main.cpp.o
libfdiv.a: CMakeFiles/fdiv.dir/fdiv.cpp.o
libfdiv.a: CMakeFiles/fdiv.dir/build.make
libfdiv.a: CMakeFiles/fdiv.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/devlx/all/c++/exercises/gtest/second_attempt/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libfdiv.a"
	$(CMAKE_COMMAND) -P CMakeFiles/fdiv.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/fdiv.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/fdiv.dir/build: libfdiv.a

.PHONY : CMakeFiles/fdiv.dir/build

CMakeFiles/fdiv.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/fdiv.dir/cmake_clean.cmake
.PHONY : CMakeFiles/fdiv.dir/clean

CMakeFiles/fdiv.dir/depend:
	cd /home/devlx/all/c++/exercises/gtest/second_attempt/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/devlx/all/c++/exercises/gtest/second_attempt /home/devlx/all/c++/exercises/gtest/second_attempt /home/devlx/all/c++/exercises/gtest/second_attempt/build /home/devlx/all/c++/exercises/gtest/second_attempt/build /home/devlx/all/c++/exercises/gtest/second_attempt/build/CMakeFiles/fdiv.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/fdiv.dir/depend

