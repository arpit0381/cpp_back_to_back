# Advanced Task Management System

## Overview
A professional-grade task management application built in C++17 demonstrating advanced programming concepts, RAII principles, file persistence, and comprehensive task analytics.

## Key Features

### Task Management
- ✅ Create, update, delete, and complete tasks
- 📋 Multiple priority levels (Low, Medium, High, Critical)
- 🏷️ Category-based organization
- 📅 Due date tracking with deadline alerts
- 🔖 Task tagging system
- ⏳ Time tracking and duration estimation

### Advanced Functionality
- 📊 **Analytics Engine**: View productivity statistics and metrics
- 🔍 **Advanced Search**: Find tasks by multiple criteria
- 📁 **Persistent Storage**: Auto-save to JSON file
- 📈 **Progress Tracking**: Completion rates and statistics
- ⚡ **Smart Filtering**: Filter by status, priority, category, and date
- 🎯 **Deadline Management**: Upcoming tasks and overdue alerts

### Architecture Highlights
- **RAII Pattern**: Automatic resource management
- **Smart Pointers**: Memory-safe design
- **STL Containers**: Efficient data structure usage
- **Separation of Concerns**: Clear class responsibilities
- **Error Handling**: Comprehensive validation
- **File I/O**: JSON-based persistence

## Project Structure
```
project4/
├── include/
│   ├── Task.h                 # Task class with full state management
│   ├── TaskManager.h          # Main task collection manager
│   ├── FileHandler.h          # File I/O operations
│   └── AnalyticsEngine.h      # Analytics and statistics
├── src/
│   ├── main.cpp              # Interactive CLI interface
│   ├── Task.cpp
│   ├── TaskManager.cpp
│   ├── FileHandler.cpp
│   └── AnalyticsEngine.cpp
├── CMakeLists.txt
└── README.md
```

## Building the Project
```bash
cd build
cmake ..
cmake --build . --config Release
```

## Running the Application
```bash
./task_manager
```

## Usage Example

The application provides an interactive menu to:
1. **Create Tasks** - Add new tasks with priority, category, and due dates
2. **View Tasks** - Display all tasks with filtering options
3. **Update Tasks** - Modify task details and status
4. **Complete Tasks** - Mark tasks as done with time tracking
5. **Delete Tasks** - Remove completed or unwanted tasks
6. **Search & Filter** - Advanced search by multiple criteria
7. **View Analytics** - Get productivity insights
8. **View Statistics** - See completion rates and metrics

## Technical Highlights

### Modern C++ Features Used
- Smart pointers (`std::unique_ptr`, `std::shared_ptr`)
- STL algorithms and containers
- Exception handling
- RAII pattern
- Move semantics
- String manipulation
- Time utilities
- File I/O

### Data Persistence
- Automatic saving to `tasks.json`
- Loads previous tasks on startup
- Structured data format for easy backup

### Analytics Engine
- Task completion rates
- Priority distribution
- Category statistics
- Overdue task tracking
- Time estimation accuracy
- Productivity trends

## Classes Overview

### Task
Manages individual task state with properties like title, description, priority, category, due date, and completion status.

### TaskManager
Central manager handling task collection operations, filtering, searching, and state management.

### FileHandler
Handles file I/O operations for task persistence using JSON format.

### AnalyticsEngine
Provides statistical analysis and productivity metrics.

## Future Enhancements
- Recurring tasks
- Task dependencies
- Team collaboration
- Cloud sync
- Mobile app integration
