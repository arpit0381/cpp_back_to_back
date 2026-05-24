cmake_minimum_required(VERSION 3.5)
project(parking_lot)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

file(GLOB SOURCES "src/*.cpp")
add_executable(parking_lot ${SOURCES})
