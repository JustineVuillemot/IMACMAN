# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.9

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2017.2.3\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2017.2.3\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Etienne\IMACMAN\IMACMAN

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Etienne\IMACMAN\IMACMAN\cmake-build-debug

# Include any dependencies generated for this target.
include version1/CMakeFiles/version1_Personnage.dir/depend.make

# Include the progress variables for this target.
include version1/CMakeFiles/version1_Personnage.dir/progress.make

# Include the compile flags for this target's objects.
include version1/CMakeFiles/version1_Personnage.dir/flags.make

version1/CMakeFiles/version1_Personnage.dir/Personnage.cpp.obj: version1/CMakeFiles/version1_Personnage.dir/flags.make
version1/CMakeFiles/version1_Personnage.dir/Personnage.cpp.obj: version1/CMakeFiles/version1_Personnage.dir/includes_CXX.rsp
version1/CMakeFiles/version1_Personnage.dir/Personnage.cpp.obj: ../version1/Personnage.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Etienne\IMACMAN\IMACMAN\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object version1/CMakeFiles/version1_Personnage.dir/Personnage.cpp.obj"
	cd /d C:\Users\Etienne\IMACMAN\IMACMAN\cmake-build-debug\version1 && C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\version1_Personnage.dir\Personnage.cpp.obj -c C:\Users\Etienne\IMACMAN\IMACMAN\version1\Personnage.cpp

version1/CMakeFiles/version1_Personnage.dir/Personnage.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/version1_Personnage.dir/Personnage.cpp.i"
	cd /d C:\Users\Etienne\IMACMAN\IMACMAN\cmake-build-debug\version1 && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Etienne\IMACMAN\IMACMAN\version1\Personnage.cpp > CMakeFiles\version1_Personnage.dir\Personnage.cpp.i

version1/CMakeFiles/version1_Personnage.dir/Personnage.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/version1_Personnage.dir/Personnage.cpp.s"
	cd /d C:\Users\Etienne\IMACMAN\IMACMAN\cmake-build-debug\version1 && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Etienne\IMACMAN\IMACMAN\version1\Personnage.cpp -o CMakeFiles\version1_Personnage.dir\Personnage.cpp.s

version1/CMakeFiles/version1_Personnage.dir/Personnage.cpp.obj.requires:

.PHONY : version1/CMakeFiles/version1_Personnage.dir/Personnage.cpp.obj.requires

version1/CMakeFiles/version1_Personnage.dir/Personnage.cpp.obj.provides: version1/CMakeFiles/version1_Personnage.dir/Personnage.cpp.obj.requires
	$(MAKE) -f version1\CMakeFiles\version1_Personnage.dir\build.make version1/CMakeFiles/version1_Personnage.dir/Personnage.cpp.obj.provides.build
.PHONY : version1/CMakeFiles/version1_Personnage.dir/Personnage.cpp.obj.provides

version1/CMakeFiles/version1_Personnage.dir/Personnage.cpp.obj.provides.build: version1/CMakeFiles/version1_Personnage.dir/Personnage.cpp.obj


# Object files for target version1_Personnage
version1_Personnage_OBJECTS = \
"CMakeFiles/version1_Personnage.dir/Personnage.cpp.obj"

# External object files for target version1_Personnage
version1_Personnage_EXTERNAL_OBJECTS =

version1/version1_Personnage.exe: version1/CMakeFiles/version1_Personnage.dir/Personnage.cpp.obj
version1/version1_Personnage.exe: version1/CMakeFiles/version1_Personnage.dir/build.make
version1/version1_Personnage.exe: glimac/libglimac.a
version1/version1_Personnage.exe: version1/CMakeFiles/version1_Personnage.dir/linklibs.rsp
version1/version1_Personnage.exe: version1/CMakeFiles/version1_Personnage.dir/objects1.rsp
version1/version1_Personnage.exe: version1/CMakeFiles/version1_Personnage.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Etienne\IMACMAN\IMACMAN\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable version1_Personnage.exe"
	cd /d C:\Users\Etienne\IMACMAN\IMACMAN\cmake-build-debug\version1 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\version1_Personnage.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
version1/CMakeFiles/version1_Personnage.dir/build: version1/version1_Personnage.exe

.PHONY : version1/CMakeFiles/version1_Personnage.dir/build

version1/CMakeFiles/version1_Personnage.dir/requires: version1/CMakeFiles/version1_Personnage.dir/Personnage.cpp.obj.requires

.PHONY : version1/CMakeFiles/version1_Personnage.dir/requires

version1/CMakeFiles/version1_Personnage.dir/clean:
	cd /d C:\Users\Etienne\IMACMAN\IMACMAN\cmake-build-debug\version1 && $(CMAKE_COMMAND) -P CMakeFiles\version1_Personnage.dir\cmake_clean.cmake
.PHONY : version1/CMakeFiles/version1_Personnage.dir/clean

version1/CMakeFiles/version1_Personnage.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Etienne\IMACMAN\IMACMAN C:\Users\Etienne\IMACMAN\IMACMAN\version1 C:\Users\Etienne\IMACMAN\IMACMAN\cmake-build-debug C:\Users\Etienne\IMACMAN\IMACMAN\cmake-build-debug\version1 C:\Users\Etienne\IMACMAN\IMACMAN\cmake-build-debug\version1\CMakeFiles\version1_Personnage.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : version1/CMakeFiles/version1_Personnage.dir/depend

