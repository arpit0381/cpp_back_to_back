# Hotel Management System

A comprehensive C++ project for managing hotel operations including guest management, room bookings, payments, and guest reviews.

## Features

- **Guest Management**: Register and manage guest information
- **Room Management**: Track rooms with different types and availability
- **Booking System**: Create and manage hotel reservations
- **Payment Processing**: Handle payment transactions with different methods
- **Review System**: Guest reviews and ratings for rooms and services
- **File Persistence**: Save and load data from files
- **Analytics**: Track occupancy rates and revenue

## Project Structure

```
project9/
├── CMakeLists.txt
├── README.md
├── build/              # Build output directory
├── include/            # Header files
│   ├── Guest.h
│   ├── Room.h
│   ├── Booking.h
│   ├── Hotel.h
│   ├── Payment.h
│   ├── Review.h
│   └── FileHandler.h
└── src/                # Implementation files
    ├── main.cpp
    ├── Guest.cpp
    ├── Room.cpp
    ├── Booking.cpp
    ├── Hotel.cpp
    ├── Payment.cpp
    ├── Review.cpp
    └── FileHandler.cpp
```

## Building

```bash
cd project9
mkdir build && cd build
cmake ..
cmake --build .
```

## Running

```bash
./hotel_system
```

## Learning Concepts

- Object-Oriented Programming (OOP)
- Encapsulation and Data Abstraction
- Relationship Management (One-to-Many, Many-to-Many)
- File I/O Operations
- Dynamic Memory Management
- Vector/Collection Management
- Polymorphism with different room types
