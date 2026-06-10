# C++ Basics Guide

A comprehensive introduction to the fundamentals of C++ programming language.
https://github.com/dvm-bitspilani

## Table of Contents

- [Introduction](#introduction)
- [Setting Up Your Environment](#setting-up-your-environment)
- [Basic Syntax](#basic-syntax)
- [Data Types](#data-types)
- [Variables and Constants](#variables-and-constants)
- [Operators](#operators)
- [Control Flow](#control-flow)
- [Functions](#functions)
- [Arrays and Strings](#arrays-and-strings)
- [Pointers and References](#pointers-and-references)
- [Object-Oriented Programming](#object-oriented-programming)
- [Memory Management](#memory-management)
- [Standard Library](#standard-library)
- [Tips and Best Practices](#tips-and-best-practices)

## Introduction

C++ is a powerful, general-purpose programming language created by Bjarne Stroustrup in 1985. It combines:
- Low-level memory manipulation (like C)
- High-level abstraction features (like modern OOP languages)
- Compile-time optimization capabilities

**Why learn C++?**
- High performance and efficiency
- Used in systems software, game engines, embedded systems
- Large standard library
- Extensive community support

## Setting Up Your Environment

### Required Tools

1. **Compiler**: GCC, Clang, or MSVC
   - **Windows**: Install Visual Studio Community or MinGW
   - **macOS**: Install Xcode or Clang
   - **Linux**: Usually pre-installed; install via package manager if needed

2. **Text Editor/IDE**:
   - Visual Studio Code (with C++ extension)
   - Visual Studio Community
   - Code::Blocks
   - CLion

### First Program

```cpp
#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
```

**Compilation and Execution:**
```bash
# Compile
g++ -o hello hello.cpp

# Run
./hello          # Linux/macOS
hello.exe        # Windows
```

## Basic Syntax

### Comments

```cpp
// Single-line comment

/* Multi-line comment
   that spans multiple lines */
```

### Preprocessor Directives

```cpp
#include <iostream>    // Include standard library
#include "myfile.h"    // Include user-defined header
#define MAX 100        // Define constant
```

### Main Function

Every C++ program starts with `main()`:

```cpp
int main() {
    // Program code here
    return 0;  // Return 0 for success
}
```

## Data Types

### Primitive Data Types

| Type | Size | Range | Example |
|------|------|-------|---------|
| `int` | 4 bytes | -2³¹ to 2³¹-1 | `int x = 42;` |
| `float` | 4 bytes | ±3.4×10³⁸ | `float pi = 3.14f;` |
| `double` | 8 bytes | ±1.7×10³⁰⁸ | `double pi = 3.14159;` |
| `char` | 1 byte | -128 to 127 | `char c = 'A';` |
| `bool` | 1 byte | true/false | `bool flag = true;` |
| `short` | 2 bytes | -2¹⁵ to 2¹⁵-1 | `short s = 100;` |
| `long` | 4/8 bytes | varies | `long l = 1000L;` |

### Type Modifiers

```cpp
unsigned int x = 100;    // Only positive values
signed int y = -50;      // Can be positive or negative
const int MAX = 100;     // Constant value
```

## Variables and Constants

### Variable Declaration

```cpp
int age = 25;
double salary = 50000.50;
std::string name = "John Doe";
bool isActive = true;
```

### Constants

```cpp
const int MAX_SIZE = 100;           // Compile-time constant
constexpr int COMPILE_TIME = 50;    // Evaluated at compile-time
#define PI 3.14159                   // Preprocessor constant
```

### Type Inference (C++11+)

```cpp
auto value = 42;           // int
auto price = 19.99;        // double
auto name = "Alice";       // const char*
```

## Operators

### Arithmetic Operators

```cpp
int a = 10, b = 3;
int add = a + b;        // 13
int sub = a - b;        // 7
int mul = a * b;        // 30
int div = a / b;        // 3
int mod = a % b;        // 1
```

### Comparison Operators

```cpp
int x = 5, y = 10;
bool equal = (x == y);           // false
bool notEqual = (x != y);        // true
bool greater = (x > y);          // false
bool less = (x < y);             // true
bool greaterOrEqual = (x >= y);  // false
bool lessOrEqual = (x <= y);     // true
```

### Logical Operators

```cpp
bool a = true, b = false;
bool andResult = (a && b);   // false (AND)
bool orResult = (a || b);    // true (OR)
bool notResult = !a;         // false (NOT)
```

### Assignment Operators

```cpp
int x = 5;
x += 3;   // x = x + 3 (8)
x -= 2;   // x = x - 2 (6)
x *= 2;   // x = x * 2 (12)
x /= 4;   // x = x / 4 (3)
```

## Control Flow

### If-Else Statement

```cpp
int age = 20;

if (age >= 18) {
    std::cout << "You are an adult" << std::endl;
} else if (age >= 13) {
    std::cout << "You are a teenager" << std::endl;
} else {
    std::cout << "You are a child" << std::endl;
}
```

### Switch Statement

```cpp
int day = 3;

switch (day) {
    case 1:
        std::cout << "Monday" << std::endl;
        break;
    case 2:
        std::cout << "Tuesday" << std::endl;
        break;
    case 3:
        std::cout << "Wednesday" << std::endl;
        break;
    default:
        std::cout << "Other day" << std::endl;
}
```

### For Loop

```cpp
// Traditional for loop
for (int i = 0; i < 5; i++) {
    std::cout << i << " ";  // Output: 0 1 2 3 4
}

// Range-based for loop (C++11+)
int arr[] = {1, 2, 3, 4, 5};
for (int num : arr) {
    std::cout << num << " ";  // Output: 1 2 3 4 5
}
```

### While Loop

```cpp
int count = 0;
while (count < 5) {
    std::cout << count << " ";
    count++;
}

// Do-while loop (executes at least once)
int x = 0;
do {
    std::cout << x << " ";
    x++;
} while (x < 3);
```

### Ternary Operator

```cpp
int age = 20;
std::string status = (age >= 18) ? "Adult" : "Minor";
```

## Functions

### Function Declaration and Definition

```cpp
// Declaration (prototype)
int add(int a, int b);

// Definition
int add(int a, int b) {
    return a + b;
}

// Usage
int result = add(5, 3);  // result = 8
```

### Function with Default Parameters

```cpp
void greet(std::string name = "Guest") {
    std::cout << "Hello, " << name << std::endl;
}

greet();              // Output: Hello, Guest
greet("Alice");       // Output: Hello, Alice
```

### Function Overloading

```cpp
int add(int a, int b) {
    return a + b;
}

double add(double a, double b) {
    return a + b;
}

int main() {
    add(5, 3);        // Calls int version
    add(5.5, 3.2);    // Calls double version
}
```

### Pass by Reference

```cpp
void increment(int &x) {
    x++;
}

int main() {
    int value = 5;
    increment(value);
    std::cout << value << std::endl;  // Output: 6
}
```

## Arrays and Strings

### Arrays

```cpp
// Array declaration
int arr[5] = {1, 2, 3, 4, 5};

// Accessing elements
std::cout << arr[0] << std::endl;  // Output: 1

// Array without size (size inferred)
int arr2[] = {10, 20, 30};

// 2D array
int matrix[2][3] = {{1, 2, 3}, {4, 5, 6}};
```

### C-Style Strings

```cpp
char str[20] = "Hello";
char str2[] = "World";
```

### std::string (Recommended)

```cpp
#include <string>

std::string name = "Alice";
std::string greeting = "Hello, " + name;

// String operations
std::cout << name.length() << std::endl;      // Length
std::cout << name[0] << std::endl;            // Access character
name += " Smith";                             // Concatenation
std::string sub = name.substr(0, 5);          // Substring
```

### std::vector (Dynamic Array)

```cpp
#include <vector>

std::vector<int> vec = {1, 2, 3};
vec.push_back(4);           // Add element
vec.pop_back();             // Remove last element
std::cout << vec.size() << std::endl;  // Size
std::cout << vec[0] << std::endl;      // Access element
```

## Pointers and References

### Pointers

```cpp
int x = 10;
int *ptr = &x;  // Pointer to x

std::cout << *ptr << std::endl;   // Dereference: 10
std::cout << ptr << std::endl;    // Address of x
std::cout << &x << std::endl;     // Address of x

*ptr = 20;      // Change value through pointer
std::cout << x << std::endl;      // Output: 20
```

### Pointer Arithmetic

```cpp
int arr[] = {10, 20, 30};
int *ptr = arr;

std::cout << *ptr << std::endl;        // 10
std::cout << *(ptr + 1) << std::endl;  // 20
ptr++;
std::cout << *ptr << std::endl;        // 20
```

### References

```cpp
int x = 10;
int &ref = x;  // Reference to x

ref = 20;
std::cout << x << std::endl;   // Output: 20

// References are like constant pointers
// They must be initialized and cannot be changed
```

### Null Pointers

```cpp
int *ptr = nullptr;  // Null pointer (C++11+)

if (ptr == nullptr) {
    std::cout << "Pointer is null" << std::endl;
}
```

## Object-Oriented Programming

### Classes and Objects

```cpp
class Person {
public:
    std::string name;
    int age;

    // Constructor
    Person(std::string n, int a) : name(n), age(a) {}

    // Member function
    void display() {
        std::cout << name << " is " << age << " years old" << std::endl;
    }
};

int main() {
    Person p1("Alice", 25);
    p1.display();  // Output: Alice is 25 years old
}
```

### Access Modifiers

```cpp
class Car {
private:
    int speed;      // Private: only accessible within class

protected:
    std::string color;  // Protected: accessible in derived classes

public:
    std::string brand;  // Public: accessible from anywhere

    void drive() {
        speed = 100;
    }
};
```

### Inheritance

```cpp
class Vehicle {
public:
    void start() {
        std::cout << "Engine started" << std::endl;
    }
};

class Car : public Vehicle {
public:
    void honk() {
        std::cout << "Honk! Honk!" << std::endl;
    }
};

int main() {
    Car car;
    car.start();  // Inherited from Vehicle
    car.honk();   // Specific to Car
}
```

### Polymorphism (Virtual Functions)

```cpp
class Shape {
public:
    virtual void display() {
        std::cout << "Shape" << std::endl;
    }
    virtual ~Shape() {}  // Virtual destructor
};

class Circle : public Shape {
public:
    void display() override {
        std::cout << "Circle" << std::endl;
    }
};

int main() {
    Shape *shape = new Circle();
    shape->display();  // Output: Circle
    delete shape;
}
```

## Memory Management

### Manual Memory Allocation (new/delete)

```cpp
// Allocate memory
int *ptr = new int;
*ptr = 42;

int *arr = new int[5];  // Array allocation

// Deallocate memory
delete ptr;
delete[] arr;
```

### Smart Pointers (C++11+) - Recommended

```cpp
#include <memory>

// unique_ptr: exclusive ownership
std::unique_ptr<int> ptr1(new int(42));
// Automatic deletion when ptr1 goes out of scope

// shared_ptr: shared ownership
std::shared_ptr<int> ptr2 = std::make_shared<int>(100);
std::shared_ptr<int> ptr3 = ptr2;  // Reference count increases
// Deleted when last shared_ptr is destroyed
```

## Standard Library

### Input/Output

```cpp
#include <iostream>

// Output
std::cout << "Hello, World!" << std::endl;
std::cout << "Value: " << 42 << std::endl;

// Input
int num;
std::cin >> num;

std::string line;
std::getline(std::cin, line);  // Read entire line
```

### Containers

```cpp
#include <vector>
#include <map>
#include <set>

// Vector (dynamic array)
std::vector<int> vec = {1, 2, 3};

// Map (key-value pairs)
std::map<std::string, int> ages;
ages["Alice"] = 25;
ages["Bob"] = 30;

// Set (unique elements)
std::set<int> numbers = {1, 2, 3, 2};  // {1, 2, 3}
```

### Algorithms

```cpp
#include <algorithm>
#include <vector>

std::vector<int> vec = {3, 1, 4, 1, 5};

// Sort
std::sort(vec.begin(), vec.end());

// Find
auto it = std::find(vec.begin(), vec.end(), 4);

// For each
std::for_each(vec.begin(), vec.end(), [](int n) {
    std::cout << n << " ";
});
```

## Tips and Best Practices

### 1. Use Modern C++ Features (C++11 and later)
- Use `auto` for type inference
- Use range-based for loops
- Use smart pointers instead of raw pointers
- Use `nullptr` instead of `NULL`

### 2. Follow Naming Conventions
```cpp
// Good
int userAge;
void calculateTotal();
const int MAX_SIZE = 100;

// Avoid
int ua;
void calc();
int maxsize;
```

### 3. Initialize Variables
```cpp
int x = 0;           // Always initialize
std::string name = "";
std::vector<int> vec;
```

### 4. Avoid Global Variables
```cpp
// Bad
int globalVar = 0;

// Better
int main() {
    int localVar = 0;
}
```

### 5. Use Const Correctly
```cpp
const int MAX = 100;              // Constant value
const int *ptr = &x;              // Pointer to const
int * const ptr2 = &x;            // Const pointer
const int * const ptr3 = &x;      // Const pointer to const
```

### 6. Memory Management
- Always allocate and deallocate the same way
- Use smart pointers when possible
- Avoid memory leaks and dangling pointers

### 7. Error Handling
```cpp
#include <stdexcept>

try {
    if (denominator == 0) {
        throw std::invalid_argument("Division by zero");
    }
} catch (const std::invalid_argument &e) {
    std::cerr << "Error: " << e.what() << std::endl;
}
```

### 8. Comments
```cpp
// Use clear, concise comments
// Explain WHY, not WHAT
// Keep comments up-to-date with code
```

## Resources

- [cppreference.com](https://en.cppreference.com/) - C++ Standard Library Reference
- [cplusplus.com](http://www.cplusplus.com/) - C++ Tutorials and Reference
- [LearnCpp.com](https://www.learncpp.com/) - Free C++ Tutorial Series
- [C++ Standard](https://isocpp.org/) - Official C++ Standards

## Quick Reference

### Compilation Flags

```bash
# Basic compilation
g++ -o program program.cpp

# With warnings
g++ -Wall -o program program.cpp

# Optimize code
g++ -O2 -o program program.cpp

# With debugging symbols
g++ -g -o program program.cpp

# C++17 standard
g++ -std=c++17 -o program program.cpp
```

---

**Happy Coding!** 🚀

For more information and advanced topics, visit the resources listed above.
