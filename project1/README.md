# Project 1: Student Management System

A comprehensive C++ application that demonstrates fundamental and intermediate programming concepts.

## Overview

This project implements a **Student Management System** that allows users to manage student records, grades, and generate statistics. It showcases key C++ concepts including:

- **Object-Oriented Programming (OOP)**: Classes, encapsulation, and method organization
- **Memory Management**: Smart pointers (`std::shared_ptr`), dynamic memory
- **Standard Library**: Vectors, algorithms, file I/O, string manipulation
- **Data Structures**: Collections and efficient data management
- **Input Validation**: Safe user input handling
- **File Operations**: Persist and retrieve data

## Project Structure

```
project1/
├── include/
│   ├── Student.h              # Student class header
│   └── StudentManager.h       # StudentManager class header
├── src/
│   ├── main.cpp               # Main program and menu system
│   ├── Student.cpp            # Student class implementation
│   └── StudentManager.cpp     # StudentManager class implementation
├── build/                      # Build output directory
├── CMakeLists.txt             # CMake build configuration
└── README.md                  # This file
```

## Features

### 1. Student Management
- Add new students with name and email
- Remove students by ID
- View all students in the system
- View detailed information for a specific student

### 2. Grade Management
- Add grades to students (validated 0-100)
- Remove the last grade added to a student
- Calculate average grades
- Automatic GPA calculation (4.0 scale)

### 3. Statistics & Reporting
- Display class average
- Identify top-performing student
- Show complete class statistics
- View individual student details

### 4. Data Persistence
- Save student data to file
- Load student data from file
- CSV-like format for easy export/import

## Classes

### Student
**Responsibilities:**
- Store individual student information (ID, name, email)
- Manage grades for a student
- Calculate GPA based on grades

**Key Methods:**
```cpp
void addGrade(double grade);           // Add a grade
void removeLastGrade();                 // Remove last grade
double getAverageGrade() const;         // Calculate average
double getGPA() const;                  // Get GPA
void displayInfo() const;               // Display student info
```

### StudentManager
**Responsibilities:**
- Manage collection of students
- Provide CRUD operations for students
- Generate statistics and reports
- Handle file I/O

**Key Methods:**
```cpp
void addStudent(const std::string& name, const std::string& email);
bool removeStudent(int id);
bool addGradeToStudent(int id, double grade);
void displayAllStudents() const;
void displayStatistics() const;
bool saveToFile(const std::string& filename);
bool loadFromFile(const std::string& filename);
```

## Build Instructions

### Prerequisites
- C++17 compatible compiler (GCC, Clang, MSVC)
- CMake 3.10 or higher

### Compilation

#### Using CMake (Recommended)
```bash
cd project1
mkdir -p build
cd build
cmake ..
cmake --build .
```

#### Using g++ directly (Windows/Linux/macOS)
```bash
cd project1
g++ -std=c++17 -o StudentManager src/main.cpp src/Student.cpp src/StudentManager.cpp -Iinclude
```

#### Using MSVC (Windows)
```bash
cd project1
cl /std:c++17 /Fo.\build\ /Fe.\build\StudentManager.exe src/main.cpp src/Student.cpp src/StudentManager.cpp /Iinclude
```

## Running the Application

### After building with CMake:
```bash
# On Linux/macOS
./build/StudentManager

# On Windows
.\build\Debug\StudentManager.exe
# or
.\build\Release\StudentManager.exe
```

### Direct execution (if built with g++):
```bash
./StudentManager
```

## Usage Example

```
Welcome to Student Management System!

========== STUDENT MANAGEMENT SYSTEM ==========
1. Add Student
2. Remove Student
3. Add Grade to Student
4. Display All Students
5. Display Student Details
6. Display Class Statistics
7. Remove Last Grade from Student
8. Save Data to File
9. Load Data from File
0. Exit
==============================================
Enter your choice: 1
Enter student name: John Doe
Enter student email: john@example.com
✓ Student added successfully with ID: 1

Enter your choice: 3
Enter student ID: 1
Enter grade (0-100): 85
✓ Grade added successfully.

Enter your choice: 6

========== CLASS STATISTICS ==========
Total Students: 1
Class Average: 85.00
Top Student: John Doe (GPA: 3.00)
======================================
```

## Key C++ Concepts Demonstrated

| Concept | Implementation |
|---------|-----------------|
| **Classes** | `Student` and `StudentManager` classes |
| **Encapsulation** | Private members with public getters/setters |
| **Smart Pointers** | `std::shared_ptr` for automatic memory management |
| **Vectors** | `std::vector` for dynamic arrays |
| **Algorithms** | `std::find_if`, `std::max_element` for operations |
| **File I/O** | `std::ifstream`, `std::ofstream` for data persistence |
| **String Handling** | `std::string`, `std::getline`, `std::stringstream` |
| **Error Handling** | Input validation and error checking |
| **Constants** | `const` correctness throughout |
| **Headers** | Proper header guards (#ifndef, #define, #endif) |

## Learning Objectives

By studying this project, you will learn:
1. How to structure C++ programs with multiple classes
2. Best practices for memory management using smart pointers
3. How to use STL containers and algorithms
4. File I/O operations for data persistence
5. Input validation and error handling
6. Menu-driven user interface design
7. Building projects with CMake

## Possible Extensions

- Add search functionality (by name, email)
- Implement sorting (by grade, name, ID)
- Add date tracking for grades
- Create a GUI interface
- Add authentication for different user roles
- Export to different formats (JSON, CSV)
- Add validation rules for email format
- Implement undo/redo functionality

## Compilation Troubleshooting

### Issue: "No such file or directory" errors
**Solution:** Ensure you're running commands from the project1 directory and paths match your OS.

### Issue: Undefined reference errors
**Solution:** Make sure all `.cpp` files are included in the compilation command.

### Issue: CMake not found
**Solution:** Install CMake from https://cmake.org/download/

## License

This is an educational project created as part of the C++ Basics Guide.

---

**Created:** 2026
**C++ Standard:** C++17
**Build System:** CMake
