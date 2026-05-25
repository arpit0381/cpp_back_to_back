cmake_minimum_required(VERSION 3.10)
project(HotelManagementSystem)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add include directories
include_directories(include)

# Source files
set(SOURCES
    src/main.cpp
    src/Guest.cpp
    src/Room.cpp
    src/Booking.cpp
    src/Hotel.cpp
    src/Payment.cpp
    src/Review.cpp
    src/FileHandler.cpp
)

# Create executable
add_executable(hotel_system ${SOURCES})
