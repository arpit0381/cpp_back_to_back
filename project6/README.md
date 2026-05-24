# Project 6: Movie Theater Management System

## Overview
A comprehensive C++ application for managing movie theaters with multiple screens, movies, showtimes, seat booking, and analytics. This project demonstrates advanced OOP concepts, data structures, file handling, and complex system design.

## Features

### 1. **Movie Management**
   - Add and manage movies with details (title, genre, director, duration, rating, language, release date)
   - Movie catalog with retrieval capabilities

### 2. **Theater Infrastructure**
   - Multi-screen theater system
   - Different screen types (2D, 3D, IMAX) with quality multipliers
   - Dynamic seat pricing based on screen quality

### 3. **Seat Management (2D Array System)**
   - 2D seat map for each screen
   - Seat statuses: Available, Booked, Reserved, Maintenance
   - Automatic seat numbering (A1, B5, etc.)
   - Real-time occupancy tracking

### 4. **Showtime System**
   - Create showtimes for movies on specific screens
   - Date and time management
   - Price calculation with screen quality multiplier
   - Occupancy percentage tracking

### 5. **Ticket & Booking System**
   - Individual ticket creation and management
   - Ticket statuses and expiry validation
   - Complete booking system with multiple seats
   - Booking confirmation with payment methods

### 6. **Advanced Analytics**
   - Booking analytics (total revenue, average booking value, cancellation rates)
   - Showtime analytics (occupancy, revenue per showtime)
   - Movie analytics (popularity, average occupancy)
   - Top movies identification
   - Comprehensive reporting dashboard

### 7. **File Handling**
   - Save/load movie database
   - Booking history persistence
   - Report generation (booking reports, revenue reports)

## Project Structure

```
project6/
├── include/
│   ├── Movie.h              # Movie entity
│   ├── Seat.h               # Seat with status management
│   ├── Screen.h             # 2D screen with seats
│   ├── Showtime.h           # Movie showtime on a screen
│   ├── Ticket.h             # Individual ticket
│   ├── Booking.h            # Collection of tickets
│   ├── AnalyticsEngine.h    # Analytics and reporting
│   ├── Theater.h            # Main theater management
│   └── FileHandler.h        # File I/O operations
├── src/
│   ├── main.cpp             # Interactive CLI application
│   └── [implementation files]
├── build/                   # Build output directory
├── CMakeLists.txt           # Build configuration
└── README.md                # This file
```

## Key Concepts Demonstrated

### OOP Principles
- **Encapsulation**: Private data with public getters/setters
- **Inheritance**: Seat status hierarchy (enum-based)
- **Composition**: Theater contains Screens, Showtimes, Bookings
- **Aggregation**: Booking aggregates Tickets

### Data Structures
- **2D Arrays**: Seat maps for screens (`std::vector<std::vector<Seat>>`)
- **STL Collections**: Maps, vectors for efficient data organization
- **Enums**: SeatStatus, BookingStatus, TicketStatus

### Advanced Features
- **Dynamic Pricing**: Screen quality multipliers affect ticket prices
- **State Management**: Complex status tracking for multiple entities
- **Analytics Reporting**: Aggregate data from multiple sources
- **File Persistence**: Database-like operations

## Building the Project

### Prerequisites
- CMake 3.10 or higher
- C++17 compatible compiler (MSVC, GCC, Clang)

### Build Steps

**On Windows (with Visual Studio):**
```bash
cd project6
mkdir build
cd build
cmake ..
cmake --build . --config Release
```

**On Linux/macOS:**
```bash
cd project6
mkdir build
cd build
cmake ..
make
```

### Running the Application
```bash
./build/bin/theater_management    # Linux/macOS
.\build\bin\Release\theater_management.exe  # Windows
```

## Usage Example

```cpp
// Create theater
Theater theater("THR001", "Cineplex", "Downtown", "New York");

// Add screens
Screen screen("SC001", "Screen 1", 8, 10, 1.5, true);  // IMAX 3D
theater.addScreen(screen);

// Add movie
Movie movie("M001", "Inception", "Sci-Fi", 148, 8.8, "English", "2010-07-16", "Nolan");
theater.addMovie(movie);

// Create showtime
theater.createShowtime("M001", 0, "2024-05-25 10:00", 200.0);

// Book tickets
std::vector<std::pair<int, int>> seats = {{0, 1}, {0, 2}};
Booking booking = theater.createBooking("CUST001", "ST1", seats);
theater.confirmBooking(booking.getBookingId(), "Credit Card");

// Generate reports
theater.generateReport();
```

## Menu System

The application provides an interactive menu with options:
1. **Add Movie** - Add new movies to catalog
2. **Create Showtime** - Schedule movie showtimes
3. **Book Tickets** - Create and confirm bookings
4. **View Showtimes** - Display all scheduled showtimes
5. **View Screen Seats** - Display seat maps for all screens
6. **Generate Reports** - View analytics and revenue reports
7. **Display Dashboard** - Quick overview of theater status

## Advanced Concepts Applied

| Concept | Implementation |
|---------|----------------|
| Polymorphism | Seat status enum with string conversion |
| Method Overloading | Multiple constructors for classes |
| Const Correctness | Read-only methods with const keyword |
| STL Containers | Vector, Map for efficient data management |
| Time Management | Ticket expiry with std::time_t |
| Reference Parameters | Efficient data passing |
| Error Handling | Boundary checking and validation |

## Learning Outcomes

After completing this project, you should understand:
- Complex system design with multiple interdependent classes
- 2D data structures and seat mapping algorithms
- Business logic implementation (pricing, booking, analytics)
- File I/O and data persistence
- State management in real-world applications
- Advanced analytics and reporting

## Future Enhancements

1. Database integration (SQLite, MySQL)
2. Email notifications for bookings
3. User authentication system
4. Web API interface (REST)
5. Advanced reporting (PDF export)
6. Loyalty program management
7. Dynamic pricing based on demand
8. Integration with payment gateways

## Notes

- The application uses INR (₹) for currency, easily changeable
- Seat availability is checked in real-time
- Prices are calculated based on screen quality multipliers
- All data is currently stored in memory; implement file persistence for production

---

**Created as part of C++ Back-to-Back Learning Series**
This project combines intermediate to advanced C++ concepts in a realistic, industry-relevant application.
