cmake_minimum_required(VERSION 3.10)
project(StudentManagementSystem)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add include directories
include_directories(include)

# Source files
set(SOURCES
    src/main.cpp
    src/Student.cpp
    src/StudentManager.cpp
)

# Create executable
add_executable(StudentManager ${SOURCES})

# Compiler flags
if(MSVC)
    target_compile_options(StudentManager PRIVATE /W4)
else()
    target_compile_options(StudentManager PRIVATE -Wall -Wextra -pedantic)
endif()
