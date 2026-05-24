cmake_minimum_required(VERSION 3.10)
project(RestaurantManagementSystem)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add include directories
include_directories(${PROJECT_SOURCE_DIR}/include)

# Source files
set(SOURCES
    src/main.cpp
    src/MenuItem.cpp
    src/OrderItem.cpp
    src/Order.cpp
    src/Table.cpp
    src/KitchenTicket.cpp
    src/Payment.cpp
    src/Customer.cpp
    src/Menu.cpp
    src/Inventory.cpp
    src/RestaurantAnalytics.cpp
    src/Restaurant.cpp
)

# Create executable
add_executable(restaurant_management ${SOURCES})

# Output directory
set_target_properties(restaurant_management PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

# Add custom build message
add_custom_command(TARGET restaurant_management POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E echo "Build complete! Executable: ${CMAKE_BINARY_DIR}/bin/restaurant_management"
)
