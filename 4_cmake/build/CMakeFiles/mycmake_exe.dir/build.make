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
CMAKE_SOURCE_DIR = /home/lzp/文档/proj_cpp/4_cmake

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lzp/文档/proj_cpp/4_cmake/build

# Include any dependencies generated for this target.
include CMakeFiles/mycmake_exe.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/mycmake_exe.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mycmake_exe.dir/flags.make

CMakeFiles/mycmake_exe.dir/main.cpp.o: CMakeFiles/mycmake_exe.dir/flags.make
CMakeFiles/mycmake_exe.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lzp/文档/proj_cpp/4_cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/mycmake_exe.dir/main.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mycmake_exe.dir/main.cpp.o -c /home/lzp/文档/proj_cpp/4_cmake/main.cpp

CMakeFiles/mycmake_exe.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mycmake_exe.dir/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lzp/文档/proj_cpp/4_cmake/main.cpp > CMakeFiles/mycmake_exe.dir/main.cpp.i

CMakeFiles/mycmake_exe.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mycmake_exe.dir/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lzp/文档/proj_cpp/4_cmake/main.cpp -o CMakeFiles/mycmake_exe.dir/main.cpp.s

CMakeFiles/mycmake_exe.dir/src/Gun.cpp.o: CMakeFiles/mycmake_exe.dir/flags.make
CMakeFiles/mycmake_exe.dir/src/Gun.cpp.o: ../src/Gun.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lzp/文档/proj_cpp/4_cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/mycmake_exe.dir/src/Gun.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mycmake_exe.dir/src/Gun.cpp.o -c /home/lzp/文档/proj_cpp/4_cmake/src/Gun.cpp

CMakeFiles/mycmake_exe.dir/src/Gun.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mycmake_exe.dir/src/Gun.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lzp/文档/proj_cpp/4_cmake/src/Gun.cpp > CMakeFiles/mycmake_exe.dir/src/Gun.cpp.i

CMakeFiles/mycmake_exe.dir/src/Gun.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mycmake_exe.dir/src/Gun.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lzp/文档/proj_cpp/4_cmake/src/Gun.cpp -o CMakeFiles/mycmake_exe.dir/src/Gun.cpp.s

CMakeFiles/mycmake_exe.dir/src/Soldier.cpp.o: CMakeFiles/mycmake_exe.dir/flags.make
CMakeFiles/mycmake_exe.dir/src/Soldier.cpp.o: ../src/Soldier.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lzp/文档/proj_cpp/4_cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/mycmake_exe.dir/src/Soldier.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mycmake_exe.dir/src/Soldier.cpp.o -c /home/lzp/文档/proj_cpp/4_cmake/src/Soldier.cpp

CMakeFiles/mycmake_exe.dir/src/Soldier.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mycmake_exe.dir/src/Soldier.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lzp/文档/proj_cpp/4_cmake/src/Soldier.cpp > CMakeFiles/mycmake_exe.dir/src/Soldier.cpp.i

CMakeFiles/mycmake_exe.dir/src/Soldier.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mycmake_exe.dir/src/Soldier.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lzp/文档/proj_cpp/4_cmake/src/Soldier.cpp -o CMakeFiles/mycmake_exe.dir/src/Soldier.cpp.s

# Object files for target mycmake_exe
mycmake_exe_OBJECTS = \
"CMakeFiles/mycmake_exe.dir/main.cpp.o" \
"CMakeFiles/mycmake_exe.dir/src/Gun.cpp.o" \
"CMakeFiles/mycmake_exe.dir/src/Soldier.cpp.o"

# External object files for target mycmake_exe
mycmake_exe_EXTERNAL_OBJECTS =

mycmake_exe: CMakeFiles/mycmake_exe.dir/main.cpp.o
mycmake_exe: CMakeFiles/mycmake_exe.dir/src/Gun.cpp.o
mycmake_exe: CMakeFiles/mycmake_exe.dir/src/Soldier.cpp.o
mycmake_exe: CMakeFiles/mycmake_exe.dir/build.make
mycmake_exe: CMakeFiles/mycmake_exe.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lzp/文档/proj_cpp/4_cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable mycmake_exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mycmake_exe.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mycmake_exe.dir/build: mycmake_exe

.PHONY : CMakeFiles/mycmake_exe.dir/build

CMakeFiles/mycmake_exe.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/mycmake_exe.dir/cmake_clean.cmake
.PHONY : CMakeFiles/mycmake_exe.dir/clean

CMakeFiles/mycmake_exe.dir/depend:
	cd /home/lzp/文档/proj_cpp/4_cmake/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lzp/文档/proj_cpp/4_cmake /home/lzp/文档/proj_cpp/4_cmake /home/lzp/文档/proj_cpp/4_cmake/build /home/lzp/文档/proj_cpp/4_cmake/build /home/lzp/文档/proj_cpp/4_cmake/build/CMakeFiles/mycmake_exe.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/mycmake_exe.dir/depend
