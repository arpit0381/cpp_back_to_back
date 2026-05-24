cmake_minimum_required(VERSION 3.10)
project(MovieTheaterManagement)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add include directories
include_directories(${PROJECT_SOURCE_DIR}/include)

# Source files
set(SOURCES
    src/main.cpp
    src/Movie.cpp
    src/Seat.cpp
    src/Screen.cpp
    src/Showtime.cpp
    src/Ticket.cpp
    src/Booking.cpp
    src/AnalyticsEngine.cpp
    src/Theater.cpp
    src/FileHandler.cpp
)

# Create executable
add_executable(theater_management ${SOURCES})

# Optional: For Windows, you might need filesystem library
if(WIN32)
    target_link_libraries(theater_management)
endif()

# Output directory
set_target_properties(theater_management PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

# Add custom build message
add_custom_command(TARGET theater_management POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E echo "Build complete! Executable: ${CMAKE_BINARY_DIR}/bin/theater_management"
)
