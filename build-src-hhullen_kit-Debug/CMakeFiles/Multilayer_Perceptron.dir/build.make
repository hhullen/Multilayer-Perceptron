# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/hhullen/PROJECTS/github/Multilayer-Perceptron/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/hhullen/PROJECTS/github/Multilayer-Perceptron/build-src-hhullen_kit-Debug

# Include any dependencies generated for this target.
include CMakeFiles/Multilayer_Perceptron.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Multilayer_Perceptron.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Multilayer_Perceptron.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Multilayer_Perceptron.dir/flags.make

CMakeFiles/Multilayer_Perceptron.dir/main.cc.o: CMakeFiles/Multilayer_Perceptron.dir/flags.make
CMakeFiles/Multilayer_Perceptron.dir/main.cc.o: /Users/hhullen/PROJECTS/github/Multilayer-Perceptron/src/main.cc
CMakeFiles/Multilayer_Perceptron.dir/main.cc.o: CMakeFiles/Multilayer_Perceptron.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/hhullen/PROJECTS/github/Multilayer-Perceptron/build-src-hhullen_kit-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Multilayer_Perceptron.dir/main.cc.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Multilayer_Perceptron.dir/main.cc.o -MF CMakeFiles/Multilayer_Perceptron.dir/main.cc.o.d -o CMakeFiles/Multilayer_Perceptron.dir/main.cc.o -c /Users/hhullen/PROJECTS/github/Multilayer-Perceptron/src/main.cc

CMakeFiles/Multilayer_Perceptron.dir/main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Multilayer_Perceptron.dir/main.cc.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/hhullen/PROJECTS/github/Multilayer-Perceptron/src/main.cc > CMakeFiles/Multilayer_Perceptron.dir/main.cc.i

CMakeFiles/Multilayer_Perceptron.dir/main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Multilayer_Perceptron.dir/main.cc.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/hhullen/PROJECTS/github/Multilayer-Perceptron/src/main.cc -o CMakeFiles/Multilayer_Perceptron.dir/main.cc.s

CMakeFiles/Multilayer_Perceptron.dir/MLP/include/matrix/matrix.cc.o: CMakeFiles/Multilayer_Perceptron.dir/flags.make
CMakeFiles/Multilayer_Perceptron.dir/MLP/include/matrix/matrix.cc.o: /Users/hhullen/PROJECTS/github/Multilayer-Perceptron/src/MLP/include/matrix/matrix.cc
CMakeFiles/Multilayer_Perceptron.dir/MLP/include/matrix/matrix.cc.o: CMakeFiles/Multilayer_Perceptron.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/hhullen/PROJECTS/github/Multilayer-Perceptron/build-src-hhullen_kit-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Multilayer_Perceptron.dir/MLP/include/matrix/matrix.cc.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Multilayer_Perceptron.dir/MLP/include/matrix/matrix.cc.o -MF CMakeFiles/Multilayer_Perceptron.dir/MLP/include/matrix/matrix.cc.o.d -o CMakeFiles/Multilayer_Perceptron.dir/MLP/include/matrix/matrix.cc.o -c /Users/hhullen/PROJECTS/github/Multilayer-Perceptron/src/MLP/include/matrix/matrix.cc

CMakeFiles/Multilayer_Perceptron.dir/MLP/include/matrix/matrix.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Multilayer_Perceptron.dir/MLP/include/matrix/matrix.cc.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/hhullen/PROJECTS/github/Multilayer-Perceptron/src/MLP/include/matrix/matrix.cc > CMakeFiles/Multilayer_Perceptron.dir/MLP/include/matrix/matrix.cc.i

CMakeFiles/Multilayer_Perceptron.dir/MLP/include/matrix/matrix.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Multilayer_Perceptron.dir/MLP/include/matrix/matrix.cc.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/hhullen/PROJECTS/github/Multilayer-Perceptron/src/MLP/include/matrix/matrix.cc -o CMakeFiles/Multilayer_Perceptron.dir/MLP/include/matrix/matrix.cc.s

CMakeFiles/Multilayer_Perceptron.dir/MLP/Model_module/perceptron.cc.o: CMakeFiles/Multilayer_Perceptron.dir/flags.make
CMakeFiles/Multilayer_Perceptron.dir/MLP/Model_module/perceptron.cc.o: /Users/hhullen/PROJECTS/github/Multilayer-Perceptron/src/MLP/Model_module/perceptron.cc
CMakeFiles/Multilayer_Perceptron.dir/MLP/Model_module/perceptron.cc.o: CMakeFiles/Multilayer_Perceptron.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/hhullen/PROJECTS/github/Multilayer-Perceptron/build-src-hhullen_kit-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Multilayer_Perceptron.dir/MLP/Model_module/perceptron.cc.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Multilayer_Perceptron.dir/MLP/Model_module/perceptron.cc.o -MF CMakeFiles/Multilayer_Perceptron.dir/MLP/Model_module/perceptron.cc.o.d -o CMakeFiles/Multilayer_Perceptron.dir/MLP/Model_module/perceptron.cc.o -c /Users/hhullen/PROJECTS/github/Multilayer-Perceptron/src/MLP/Model_module/perceptron.cc

CMakeFiles/Multilayer_Perceptron.dir/MLP/Model_module/perceptron.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Multilayer_Perceptron.dir/MLP/Model_module/perceptron.cc.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/hhullen/PROJECTS/github/Multilayer-Perceptron/src/MLP/Model_module/perceptron.cc > CMakeFiles/Multilayer_Perceptron.dir/MLP/Model_module/perceptron.cc.i

CMakeFiles/Multilayer_Perceptron.dir/MLP/Model_module/perceptron.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Multilayer_Perceptron.dir/MLP/Model_module/perceptron.cc.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/hhullen/PROJECTS/github/Multilayer-Perceptron/src/MLP/Model_module/perceptron.cc -o CMakeFiles/Multilayer_Perceptron.dir/MLP/Model_module/perceptron.cc.s

# Object files for target Multilayer_Perceptron
Multilayer_Perceptron_OBJECTS = \
"CMakeFiles/Multilayer_Perceptron.dir/main.cc.o" \
"CMakeFiles/Multilayer_Perceptron.dir/MLP/include/matrix/matrix.cc.o" \
"CMakeFiles/Multilayer_Perceptron.dir/MLP/Model_module/perceptron.cc.o"

# External object files for target Multilayer_Perceptron
Multilayer_Perceptron_EXTERNAL_OBJECTS =

Multilayer_Perceptron: CMakeFiles/Multilayer_Perceptron.dir/main.cc.o
Multilayer_Perceptron: CMakeFiles/Multilayer_Perceptron.dir/MLP/include/matrix/matrix.cc.o
Multilayer_Perceptron: CMakeFiles/Multilayer_Perceptron.dir/MLP/Model_module/perceptron.cc.o
Multilayer_Perceptron: CMakeFiles/Multilayer_Perceptron.dir/build.make
Multilayer_Perceptron: CMakeFiles/Multilayer_Perceptron.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/hhullen/PROJECTS/github/Multilayer-Perceptron/build-src-hhullen_kit-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable Multilayer_Perceptron"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Multilayer_Perceptron.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Multilayer_Perceptron.dir/build: Multilayer_Perceptron
.PHONY : CMakeFiles/Multilayer_Perceptron.dir/build

CMakeFiles/Multilayer_Perceptron.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Multilayer_Perceptron.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Multilayer_Perceptron.dir/clean

CMakeFiles/Multilayer_Perceptron.dir/depend:
	cd /Users/hhullen/PROJECTS/github/Multilayer-Perceptron/build-src-hhullen_kit-Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/hhullen/PROJECTS/github/Multilayer-Perceptron/src /Users/hhullen/PROJECTS/github/Multilayer-Perceptron/src /Users/hhullen/PROJECTS/github/Multilayer-Perceptron/build-src-hhullen_kit-Debug /Users/hhullen/PROJECTS/github/Multilayer-Perceptron/build-src-hhullen_kit-Debug /Users/hhullen/PROJECTS/github/Multilayer-Perceptron/build-src-hhullen_kit-Debug/CMakeFiles/Multilayer_Perceptron.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Multilayer_Perceptron.dir/depend

