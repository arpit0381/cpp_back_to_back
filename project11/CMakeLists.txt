cmake_minimum_required(VERSION 3.10)
project(UniversityCourseManager)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add include directories
include_directories(include)

# Source files
set(SOURCES
    src/main.cpp
    src/Course.cpp
    src/Student.cpp
    src/Instructor.cpp
    src/Grade.cpp
    src/CourseManager.cpp
)

# Create executable
add_executable(CourseManager ${SOURCES})

# Compiler flags
if(MSVC)
    target_compile_options(CourseManager PRIVATE /W4)
else()
    target_compile_options(CourseManager PRIVATE -Wall -Wextra -pedantic)
endif()
