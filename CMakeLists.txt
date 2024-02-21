cmake_minimum_required(VERSION 3.10)
project(hardcore-ai)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)

# Include directories
include_directories(${PROJECT_SOURCE_DIR})

# Find all .cpp files in the project to compile
file(GLOB_RECURSE SOURCES "*.cpp")

# Define the executable based on the found source files
add_executable(${PROJECT_NAME} ${SOURCES})
