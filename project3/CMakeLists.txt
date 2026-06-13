cmake_minimum_required(VERSION 3.10)
project(LibraryManagementSystem)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(library_system
    src/main.cpp
    src/Book.cpp
    src/Member.cpp
    src/LibraryManager.cpp
)
.............
target_include_directories(library_system PRIVATE ${PROJECT_SOURCE_DIR}/include)

