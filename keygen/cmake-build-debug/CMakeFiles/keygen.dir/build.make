# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/siyanhu/Documents/forks/EphemeralID/keygen

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/siyanhu/Documents/forks/EphemeralID/keygen/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/keygen.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/keygen.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/keygen.dir/flags.make

CMakeFiles/keygen.dir/main.cpp.o: CMakeFiles/keygen.dir/flags.make
CMakeFiles/keygen.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/siyanhu/Documents/forks/EphemeralID/keygen/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/keygen.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/keygen.dir/main.cpp.o -c /Users/siyanhu/Documents/forks/EphemeralID/keygen/main.cpp

CMakeFiles/keygen.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/keygen.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/siyanhu/Documents/forks/EphemeralID/keygen/main.cpp > CMakeFiles/keygen.dir/main.cpp.i

CMakeFiles/keygen.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/keygen.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/siyanhu/Documents/forks/EphemeralID/keygen/main.cpp -o CMakeFiles/keygen.dir/main.cpp.s

CMakeFiles/keygen.dir/keygen.cpp.o: CMakeFiles/keygen.dir/flags.make
CMakeFiles/keygen.dir/keygen.cpp.o: ../keygen.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/siyanhu/Documents/forks/EphemeralID/keygen/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/keygen.dir/keygen.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/keygen.dir/keygen.cpp.o -c /Users/siyanhu/Documents/forks/EphemeralID/keygen/keygen.cpp

CMakeFiles/keygen.dir/keygen.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/keygen.dir/keygen.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/siyanhu/Documents/forks/EphemeralID/keygen/keygen.cpp > CMakeFiles/keygen.dir/keygen.cpp.i

CMakeFiles/keygen.dir/keygen.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/keygen.dir/keygen.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/siyanhu/Documents/forks/EphemeralID/keygen/keygen.cpp -o CMakeFiles/keygen.dir/keygen.cpp.s

CMakeFiles/keygen.dir/strcompile.cpp.o: CMakeFiles/keygen.dir/flags.make
CMakeFiles/keygen.dir/strcompile.cpp.o: ../strcompile.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/siyanhu/Documents/forks/EphemeralID/keygen/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/keygen.dir/strcompile.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/keygen.dir/strcompile.cpp.o -c /Users/siyanhu/Documents/forks/EphemeralID/keygen/strcompile.cpp

CMakeFiles/keygen.dir/strcompile.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/keygen.dir/strcompile.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/siyanhu/Documents/forks/EphemeralID/keygen/strcompile.cpp > CMakeFiles/keygen.dir/strcompile.cpp.i

CMakeFiles/keygen.dir/strcompile.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/keygen.dir/strcompile.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/siyanhu/Documents/forks/EphemeralID/keygen/strcompile.cpp -o CMakeFiles/keygen.dir/strcompile.cpp.s

# Object files for target keygen
keygen_OBJECTS = \
"CMakeFiles/keygen.dir/main.cpp.o" \
"CMakeFiles/keygen.dir/keygen.cpp.o" \
"CMakeFiles/keygen.dir/strcompile.cpp.o"

# External object files for target keygen
keygen_EXTERNAL_OBJECTS =

keygen: CMakeFiles/keygen.dir/main.cpp.o
keygen: CMakeFiles/keygen.dir/keygen.cpp.o
keygen: CMakeFiles/keygen.dir/strcompile.cpp.o
keygen: CMakeFiles/keygen.dir/build.make
keygen: CMakeFiles/keygen.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/siyanhu/Documents/forks/EphemeralID/keygen/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable keygen"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/keygen.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/keygen.dir/build: keygen

.PHONY : CMakeFiles/keygen.dir/build

CMakeFiles/keygen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/keygen.dir/cmake_clean.cmake
.PHONY : CMakeFiles/keygen.dir/clean

CMakeFiles/keygen.dir/depend:
	cd /Users/siyanhu/Documents/forks/EphemeralID/keygen/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/siyanhu/Documents/forks/EphemeralID/keygen /Users/siyanhu/Documents/forks/EphemeralID/keygen /Users/siyanhu/Documents/forks/EphemeralID/keygen/cmake-build-debug /Users/siyanhu/Documents/forks/EphemeralID/keygen/cmake-build-debug /Users/siyanhu/Documents/forks/EphemeralID/keygen/cmake-build-debug/CMakeFiles/keygen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/keygen.dir/depend

