# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/pi/buggy

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pi/buggy/build

# Include any dependencies generated for this target.
include CMakeFiles/buggy.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/buggy.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/buggy.dir/flags.make

CMakeFiles/buggy.dir/src/adafruit-motor-hat-cpp-library/adafruitdcmotor.cpp.o: CMakeFiles/buggy.dir/flags.make
CMakeFiles/buggy.dir/src/adafruit-motor-hat-cpp-library/adafruitdcmotor.cpp.o: ../src/adafruit-motor-hat-cpp-library/adafruitdcmotor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/buggy/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/buggy.dir/src/adafruit-motor-hat-cpp-library/adafruitdcmotor.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/buggy.dir/src/adafruit-motor-hat-cpp-library/adafruitdcmotor.cpp.o -c /home/pi/buggy/src/adafruit-motor-hat-cpp-library/adafruitdcmotor.cpp

CMakeFiles/buggy.dir/src/adafruit-motor-hat-cpp-library/adafruitdcmotor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/buggy.dir/src/adafruit-motor-hat-cpp-library/adafruitdcmotor.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/buggy/src/adafruit-motor-hat-cpp-library/adafruitdcmotor.cpp > CMakeFiles/buggy.dir/src/adafruit-motor-hat-cpp-library/adafruitdcmotor.cpp.i

CMakeFiles/buggy.dir/src/adafruit-motor-hat-cpp-library/adafruitdcmotor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/buggy.dir/src/adafruit-motor-hat-cpp-library/adafruitdcmotor.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/buggy/src/adafruit-motor-hat-cpp-library/adafruitdcmotor.cpp -o CMakeFiles/buggy.dir/src/adafruit-motor-hat-cpp-library/adafruitdcmotor.cpp.s

CMakeFiles/buggy.dir/src/adafruit-motor-hat-cpp-library/adafruitmotorhat.cpp.o: CMakeFiles/buggy.dir/flags.make
CMakeFiles/buggy.dir/src/adafruit-motor-hat-cpp-library/adafruitmotorhat.cpp.o: ../src/adafruit-motor-hat-cpp-library/adafruitmotorhat.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/buggy/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/buggy.dir/src/adafruit-motor-hat-cpp-library/adafruitmotorhat.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/buggy.dir/src/adafruit-motor-hat-cpp-library/adafruitmotorhat.cpp.o -c /home/pi/buggy/src/adafruit-motor-hat-cpp-library/adafruitmotorhat.cpp

CMakeFiles/buggy.dir/src/adafruit-motor-hat-cpp-library/adafruitmotorhat.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/buggy.dir/src/adafruit-motor-hat-cpp-library/adafruitmotorhat.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/buggy/src/adafruit-motor-hat-cpp-library/adafruitmotorhat.cpp > CMakeFiles/buggy.dir/src/adafruit-motor-hat-cpp-library/adafruitmotorhat.cpp.i

CMakeFiles/buggy.dir/src/adafruit-motor-hat-cpp-library/adafruitmotorhat.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/buggy.dir/src/adafruit-motor-hat-cpp-library/adafruitmotorhat.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/buggy/src/adafruit-motor-hat-cpp-library/adafruitmotorhat.cpp -o CMakeFiles/buggy.dir/src/adafruit-motor-hat-cpp-library/adafruitmotorhat.cpp.s

CMakeFiles/buggy.dir/src/adafruit-motor-hat-cpp-library/i2cdevice.cpp.o: CMakeFiles/buggy.dir/flags.make
CMakeFiles/buggy.dir/src/adafruit-motor-hat-cpp-library/i2cdevice.cpp.o: ../src/adafruit-motor-hat-cpp-library/i2cdevice.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/buggy/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/buggy.dir/src/adafruit-motor-hat-cpp-library/i2cdevice.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/buggy.dir/src/adafruit-motor-hat-cpp-library/i2cdevice.cpp.o -c /home/pi/buggy/src/adafruit-motor-hat-cpp-library/i2cdevice.cpp

CMakeFiles/buggy.dir/src/adafruit-motor-hat-cpp-library/i2cdevice.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/buggy.dir/src/adafruit-motor-hat-cpp-library/i2cdevice.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/buggy/src/adafruit-motor-hat-cpp-library/i2cdevice.cpp > CMakeFiles/buggy.dir/src/adafruit-motor-hat-cpp-library/i2cdevice.cpp.i

CMakeFiles/buggy.dir/src/adafruit-motor-hat-cpp-library/i2cdevice.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/buggy.dir/src/adafruit-motor-hat-cpp-library/i2cdevice.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/buggy/src/adafruit-motor-hat-cpp-library/i2cdevice.cpp -o CMakeFiles/buggy.dir/src/adafruit-motor-hat-cpp-library/i2cdevice.cpp.s

CMakeFiles/buggy.dir/src/adafruit-motor-hat-cpp-library/pwm.cpp.o: CMakeFiles/buggy.dir/flags.make
CMakeFiles/buggy.dir/src/adafruit-motor-hat-cpp-library/pwm.cpp.o: ../src/adafruit-motor-hat-cpp-library/pwm.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/buggy/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/buggy.dir/src/adafruit-motor-hat-cpp-library/pwm.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/buggy.dir/src/adafruit-motor-hat-cpp-library/pwm.cpp.o -c /home/pi/buggy/src/adafruit-motor-hat-cpp-library/pwm.cpp

CMakeFiles/buggy.dir/src/adafruit-motor-hat-cpp-library/pwm.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/buggy.dir/src/adafruit-motor-hat-cpp-library/pwm.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/buggy/src/adafruit-motor-hat-cpp-library/pwm.cpp > CMakeFiles/buggy.dir/src/adafruit-motor-hat-cpp-library/pwm.cpp.i

CMakeFiles/buggy.dir/src/adafruit-motor-hat-cpp-library/pwm.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/buggy.dir/src/adafruit-motor-hat-cpp-library/pwm.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/buggy/src/adafruit-motor-hat-cpp-library/pwm.cpp -o CMakeFiles/buggy.dir/src/adafruit-motor-hat-cpp-library/pwm.cpp.s

CMakeFiles/buggy.dir/src/buggy_driver.cpp.o: CMakeFiles/buggy.dir/flags.make
CMakeFiles/buggy.dir/src/buggy_driver.cpp.o: ../src/buggy_driver.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/buggy/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/buggy.dir/src/buggy_driver.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/buggy.dir/src/buggy_driver.cpp.o -c /home/pi/buggy/src/buggy_driver.cpp

CMakeFiles/buggy.dir/src/buggy_driver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/buggy.dir/src/buggy_driver.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/buggy/src/buggy_driver.cpp > CMakeFiles/buggy.dir/src/buggy_driver.cpp.i

CMakeFiles/buggy.dir/src/buggy_driver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/buggy.dir/src/buggy_driver.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/buggy/src/buggy_driver.cpp -o CMakeFiles/buggy.dir/src/buggy_driver.cpp.s

CMakeFiles/buggy.dir/src/main_a2.cpp.o: CMakeFiles/buggy.dir/flags.make
CMakeFiles/buggy.dir/src/main_a2.cpp.o: ../src/main_a2.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/buggy/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/buggy.dir/src/main_a2.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/buggy.dir/src/main_a2.cpp.o -c /home/pi/buggy/src/main_a2.cpp

CMakeFiles/buggy.dir/src/main_a2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/buggy.dir/src/main_a2.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/buggy/src/main_a2.cpp > CMakeFiles/buggy.dir/src/main_a2.cpp.i

CMakeFiles/buggy.dir/src/main_a2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/buggy.dir/src/main_a2.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/buggy/src/main_a2.cpp -o CMakeFiles/buggy.dir/src/main_a2.cpp.s

# Object files for target buggy
buggy_OBJECTS = \
"CMakeFiles/buggy.dir/src/adafruit-motor-hat-cpp-library/adafruitdcmotor.cpp.o" \
"CMakeFiles/buggy.dir/src/adafruit-motor-hat-cpp-library/adafruitmotorhat.cpp.o" \
"CMakeFiles/buggy.dir/src/adafruit-motor-hat-cpp-library/i2cdevice.cpp.o" \
"CMakeFiles/buggy.dir/src/adafruit-motor-hat-cpp-library/pwm.cpp.o" \
"CMakeFiles/buggy.dir/src/buggy_driver.cpp.o" \
"CMakeFiles/buggy.dir/src/main_a2.cpp.o"

# External object files for target buggy
buggy_EXTERNAL_OBJECTS =

buggy: CMakeFiles/buggy.dir/src/adafruit-motor-hat-cpp-library/adafruitdcmotor.cpp.o
buggy: CMakeFiles/buggy.dir/src/adafruit-motor-hat-cpp-library/adafruitmotorhat.cpp.o
buggy: CMakeFiles/buggy.dir/src/adafruit-motor-hat-cpp-library/i2cdevice.cpp.o
buggy: CMakeFiles/buggy.dir/src/adafruit-motor-hat-cpp-library/pwm.cpp.o
buggy: CMakeFiles/buggy.dir/src/buggy_driver.cpp.o
buggy: CMakeFiles/buggy.dir/src/main_a2.cpp.o
buggy: CMakeFiles/buggy.dir/build.make
buggy: /usr/local/lib/libwiringPi.so
buggy: /usr/lib/arm-linux-gnueabihf/libpthread.so
buggy: CMakeFiles/buggy.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pi/buggy/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable buggy"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/buggy.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/buggy.dir/build: buggy

.PHONY : CMakeFiles/buggy.dir/build

CMakeFiles/buggy.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/buggy.dir/cmake_clean.cmake
.PHONY : CMakeFiles/buggy.dir/clean

CMakeFiles/buggy.dir/depend:
	cd /home/pi/buggy/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pi/buggy /home/pi/buggy /home/pi/buggy/build /home/pi/buggy/build /home/pi/buggy/build/CMakeFiles/buggy.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/buggy.dir/depend

