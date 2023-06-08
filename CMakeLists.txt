cmake_minimum_required(VERSION 3.12)
project(buggy)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)

# Include directories
include_directories(include)
include_directories(include/adafruit-motor-hat-cpp-library)

# Source files
file(GLOB_RECURSE SOURCES
    src/main_a2.cpp
    src/buggy_driver.cpp
    src/adafruit-motor-hat-cpp-library/*.cpp
)

# List of files to exclude
# set(EXCLUDED_SOURCES
#     src/main_a1.cpp
#     src/main_a3.cpp
#     src/main_a3.cpp
#     src/test.cpp
#     src/mpu6050_driver.cpp
#     src/mpu6050_main.cpp
# )

# # Remove excluded files from the source list
# list(REMOVE_ITEM SOURCES ${EXCLUDED_SOURCES})


# Find required libraries
find_library(WIRINGPI_LIB wiringPi)
find_library(PTHREAD_LIB pthread)

# Add executable
add_executable(buggy.exe ${SOURCES})

# Link external libraries
target_link_libraries(buggy.exe ${WIRINGPI_LIB} ${PTHREAD_LIB})

# Set the output directory to the build directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)