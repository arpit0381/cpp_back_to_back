cmake_minimum_required(VERSION 3.10)
project(BankingSystem)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add include directories
include_directories(include)

# Source files
set(SOURCES
    src/main.cpp
    src/Transaction.cpp
    src/Account.cpp
    src/SavingsAccount.cpp
    src/CheckingAccount.cpp
    src/Bank.cpp
)

# Create executable
add_executable(BankingSystem ${SOURCES})

# Compiler flags
if(MSVC)
    target_compile_options(BankingSystem PRIVATE /W4)
else()
    target_compile_options(BankingSystem PRIVATE -Wall -Wextra -pedantic)
endif()
