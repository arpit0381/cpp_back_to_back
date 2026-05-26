cmake_minimum_required(VERSION 3.10)
project(EcommerceProductManager)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add include directories
include_directories(include)

# Source files
set(SOURCES
    src/main.cpp
    src/Product.cpp
    src/Inventory.cpp
    src/ProductManager.cpp
    src/Category.cpp
)

# Create executable
add_executable(ProductManager ${SOURCES})

# Compiler flags
if(MSVC)
    target_compile_options(ProductManager PRIVATE /W4)
else()
    target_compile_options(ProductManager PRIVATE -Wall -Wextra -pedantic)
endif()
