# Project 11: University Course Management System

## Overview
A comprehensive course management system for educational institutions. This project demonstrates the management of courses, students, instructors, and grades using object-oriented design principles.

## Features
- **Course Management**: Create and manage university courses
- **Student Management**: Enroll students in courses and track their information
- **Instructor Management**: Manage faculty members and their course assignments
- **Grade Management**: Track and calculate student grades
- **Enrollment System**: Manage student enrollments in courses
- **GPA Calculation**: Calculate student GPA and academic performance
- **Course Statistics**: View course attendance and grade distribution

## Project Structure
```
project11/
├── include/
│   ├── Course.h            # Course class definition
│   ├── Student.h           # Student class definition
│   ├── Instructor.h        # Instructor class definition
│   ├── Grade.h             # Grade class definition
│   └── CourseManager.h     # Central course manager
├── src/
│   ├── Course.cpp          # Course implementation
│   ├── Student.cpp         # Student implementation
│   ├── Instructor.cpp      # Instructor implementation
│   ├── Grade.cpp           # Grade implementation
│   ├── CourseManager.cpp   # Course manager implementation
│   └── main.cpp            # Application entry point
├── build/                  # Build output directory
└── CMakeLists.txt          # CMake configuration
```

## Building
```bash
cd project11
mkdir -p build
cd build
cmake ..
make
```

## Running
```bash
./CourseManager
```

## Key Classes
- **Course**: Represents a university course with code, name, credits, and capacity
- **Student**: Represents a student with ID, name, and enrolled courses
- **Instructor**: Represents a faculty member assigned to courses
- **Grade**: Manages grades and GPA calculations
- **CourseManager**: Central manager for all course, student, and grade operations

## Technologies
- C++17
- CMake
- Standard Library (vector, map, string, algorithm)
