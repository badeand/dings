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
CMAKE_COMMAND = "/Users/badeand/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/193.6015.37/CLion.app/Contents/bin/cmake/mac/bin/cmake"

# The command to remove a file.
RM = "/Users/badeand/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/193.6015.37/CLion.app/Contents/bin/cmake/mac/bin/cmake" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/badeand/dev/dings/experiments/joystick/firmware

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/badeand/dev/dings/experiments/joystick/firmware/cmake-build-megaatmega1280

# Include any dependencies generated for this target.
include CMakeFiles/firmware.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/firmware.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/firmware.dir/flags.make

CMakeFiles/firmware.dir/.pio/libdeps/megaatmega1280/LedControl_ID914/src/LedControl.cpp.o: CMakeFiles/firmware.dir/flags.make
CMakeFiles/firmware.dir/.pio/libdeps/megaatmega1280/LedControl_ID914/src/LedControl.cpp.o: ../.pio/libdeps/megaatmega1280/LedControl_ID914/src/LedControl.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/badeand/dev/dings/experiments/joystick/firmware/cmake-build-megaatmega1280/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/firmware.dir/.pio/libdeps/megaatmega1280/LedControl_ID914/src/LedControl.cpp.o"
	/Users/badeand/.platformio/packages/toolchain-atmelavr/bin/avr-g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/firmware.dir/.pio/libdeps/megaatmega1280/LedControl_ID914/src/LedControl.cpp.o -c /Users/badeand/dev/dings/experiments/joystick/firmware/.pio/libdeps/megaatmega1280/LedControl_ID914/src/LedControl.cpp

CMakeFiles/firmware.dir/.pio/libdeps/megaatmega1280/LedControl_ID914/src/LedControl.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/firmware.dir/.pio/libdeps/megaatmega1280/LedControl_ID914/src/LedControl.cpp.i"
	/Users/badeand/.platformio/packages/toolchain-atmelavr/bin/avr-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/badeand/dev/dings/experiments/joystick/firmware/.pio/libdeps/megaatmega1280/LedControl_ID914/src/LedControl.cpp > CMakeFiles/firmware.dir/.pio/libdeps/megaatmega1280/LedControl_ID914/src/LedControl.cpp.i

CMakeFiles/firmware.dir/.pio/libdeps/megaatmega1280/LedControl_ID914/src/LedControl.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/firmware.dir/.pio/libdeps/megaatmega1280/LedControl_ID914/src/LedControl.cpp.s"
	/Users/badeand/.platformio/packages/toolchain-atmelavr/bin/avr-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/badeand/dev/dings/experiments/joystick/firmware/.pio/libdeps/megaatmega1280/LedControl_ID914/src/LedControl.cpp -o CMakeFiles/firmware.dir/.pio/libdeps/megaatmega1280/LedControl_ID914/src/LedControl.cpp.s

CMakeFiles/firmware.dir/src/main.cpp.o: CMakeFiles/firmware.dir/flags.make
CMakeFiles/firmware.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/badeand/dev/dings/experiments/joystick/firmware/cmake-build-megaatmega1280/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/firmware.dir/src/main.cpp.o"
	/Users/badeand/.platformio/packages/toolchain-atmelavr/bin/avr-g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/firmware.dir/src/main.cpp.o -c /Users/badeand/dev/dings/experiments/joystick/firmware/src/main.cpp

CMakeFiles/firmware.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/firmware.dir/src/main.cpp.i"
	/Users/badeand/.platformio/packages/toolchain-atmelavr/bin/avr-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/badeand/dev/dings/experiments/joystick/firmware/src/main.cpp > CMakeFiles/firmware.dir/src/main.cpp.i

CMakeFiles/firmware.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/firmware.dir/src/main.cpp.s"
	/Users/badeand/.platformio/packages/toolchain-atmelavr/bin/avr-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/badeand/dev/dings/experiments/joystick/firmware/src/main.cpp -o CMakeFiles/firmware.dir/src/main.cpp.s

# Object files for target firmware
firmware_OBJECTS = \
"CMakeFiles/firmware.dir/.pio/libdeps/megaatmega1280/LedControl_ID914/src/LedControl.cpp.o" \
"CMakeFiles/firmware.dir/src/main.cpp.o"

# External object files for target firmware
firmware_EXTERNAL_OBJECTS =

firmware: CMakeFiles/firmware.dir/.pio/libdeps/megaatmega1280/LedControl_ID914/src/LedControl.cpp.o
firmware: CMakeFiles/firmware.dir/src/main.cpp.o
firmware: CMakeFiles/firmware.dir/build.make
firmware: CMakeFiles/firmware.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/badeand/dev/dings/experiments/joystick/firmware/cmake-build-megaatmega1280/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable firmware"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/firmware.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/firmware.dir/build: firmware

.PHONY : CMakeFiles/firmware.dir/build

CMakeFiles/firmware.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/firmware.dir/cmake_clean.cmake
.PHONY : CMakeFiles/firmware.dir/clean

CMakeFiles/firmware.dir/depend:
	cd /Users/badeand/dev/dings/experiments/joystick/firmware/cmake-build-megaatmega1280 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/badeand/dev/dings/experiments/joystick/firmware /Users/badeand/dev/dings/experiments/joystick/firmware /Users/badeand/dev/dings/experiments/joystick/firmware/cmake-build-megaatmega1280 /Users/badeand/dev/dings/experiments/joystick/firmware/cmake-build-megaatmega1280 /Users/badeand/dev/dings/experiments/joystick/firmware/cmake-build-megaatmega1280/CMakeFiles/firmware.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/firmware.dir/depend
