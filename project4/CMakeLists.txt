cmake_minimum_required(VERSION 3.10)
project(TaskManagementSystem)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable all warnings
if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(task_manager
    src/main.cpp
    src/Task.cpp
    src/TaskManager.cpp
    src/FileHandler.cpp
    src/AnalyticsEngine.cpp
)

target_include_directories(task_manager PRIVATE ${PROJECT_SOURCE_DIR}/include)
