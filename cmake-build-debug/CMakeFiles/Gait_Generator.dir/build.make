# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/duoduo06/CLionProjects/Gait_Generator

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/duoduo06/CLionProjects/Gait_Generator/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Gait_Generator.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Gait_Generator.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Gait_Generator.dir/flags.make

CMakeFiles/Gait_Generator.dir/main.cpp.o: CMakeFiles/Gait_Generator.dir/flags.make
CMakeFiles/Gait_Generator.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/duoduo06/CLionProjects/Gait_Generator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Gait_Generator.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Gait_Generator.dir/main.cpp.o -c /Users/duoduo06/CLionProjects/Gait_Generator/main.cpp

CMakeFiles/Gait_Generator.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Gait_Generator.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/duoduo06/CLionProjects/Gait_Generator/main.cpp > CMakeFiles/Gait_Generator.dir/main.cpp.i

CMakeFiles/Gait_Generator.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Gait_Generator.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/duoduo06/CLionProjects/Gait_Generator/main.cpp -o CMakeFiles/Gait_Generator.dir/main.cpp.s

CMakeFiles/Gait_Generator.dir/Gait_generator.cpp.o: CMakeFiles/Gait_Generator.dir/flags.make
CMakeFiles/Gait_Generator.dir/Gait_generator.cpp.o: ../Gait_generator.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/duoduo06/CLionProjects/Gait_Generator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Gait_Generator.dir/Gait_generator.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Gait_Generator.dir/Gait_generator.cpp.o -c /Users/duoduo06/CLionProjects/Gait_Generator/Gait_generator.cpp

CMakeFiles/Gait_Generator.dir/Gait_generator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Gait_Generator.dir/Gait_generator.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/duoduo06/CLionProjects/Gait_Generator/Gait_generator.cpp > CMakeFiles/Gait_Generator.dir/Gait_generator.cpp.i

CMakeFiles/Gait_Generator.dir/Gait_generator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Gait_Generator.dir/Gait_generator.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/duoduo06/CLionProjects/Gait_Generator/Gait_generator.cpp -o CMakeFiles/Gait_Generator.dir/Gait_generator.cpp.s

# Object files for target Gait_Generator
Gait_Generator_OBJECTS = \
"CMakeFiles/Gait_Generator.dir/main.cpp.o" \
"CMakeFiles/Gait_Generator.dir/Gait_generator.cpp.o"

# External object files for target Gait_Generator
Gait_Generator_EXTERNAL_OBJECTS =

Gait_Generator: CMakeFiles/Gait_Generator.dir/main.cpp.o
Gait_Generator: CMakeFiles/Gait_Generator.dir/Gait_generator.cpp.o
Gait_Generator: CMakeFiles/Gait_Generator.dir/build.make
Gait_Generator: CMakeFiles/Gait_Generator.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/duoduo06/CLionProjects/Gait_Generator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Gait_Generator"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Gait_Generator.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Gait_Generator.dir/build: Gait_Generator

.PHONY : CMakeFiles/Gait_Generator.dir/build

CMakeFiles/Gait_Generator.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Gait_Generator.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Gait_Generator.dir/clean

CMakeFiles/Gait_Generator.dir/depend:
	cd /Users/duoduo06/CLionProjects/Gait_Generator/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/duoduo06/CLionProjects/Gait_Generator /Users/duoduo06/CLionProjects/Gait_Generator /Users/duoduo06/CLionProjects/Gait_Generator/cmake-build-debug /Users/duoduo06/CLionProjects/Gait_Generator/cmake-build-debug /Users/duoduo06/CLionProjects/Gait_Generator/cmake-build-debug/CMakeFiles/Gait_Generator.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Gait_Generator.dir/depend

