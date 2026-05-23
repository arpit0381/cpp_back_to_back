# Library Management System

## Overview
A comprehensive C++ library management system that demonstrates object-oriented programming principles including encapsulation, inheritance, and data management.

## Features
- **Book Management**: Add, search, and track books with ISBN, title, author, and availability
- **Member Management**: Register members and track their borrowed books
- **Borrowing System**: Borrow and return books with availability checks
- **Library Statistics**: View total books, available books, and member information
- **Search Functionality**: Find books by title or author

## Project Structure
```
project3/
├── include/
│   ├── Book.h
│   ├── Member.h
│   └── LibraryManager.h
├── src/
│   ├── main.cpp
│   ├── Book.cpp
│   ├── Member.cpp
│   └── LibraryManager.cpp
├── CMakeLists.txt
└── README.md
```

## Classes

### Book
Represents a book in the library with properties like ISBN, title, author, year, and available copies.

### Member
Represents a library member with ability to borrow and return books.

### LibraryManager
Main manager class that handles library operations like adding books, registering members, and processing transactions.

## Building the Project
```bash
cd build
cmake ..
cmake --build .
```

## Running the Application
```bash
./library_system
```

## Usage Example
The program provides a menu-driven interface to:
1. Add books to the library
2. Register new members
3. Borrow books
4. Return books
5. Search for books
6. View library statistics
