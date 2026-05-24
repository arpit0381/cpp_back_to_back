# Project 7: Restaurant Management System

## Overview
A sophisticated C++ application for managing restaurant operations including menu management, table reservations, order processing, kitchen operations, payments, inventory tracking, and advanced analytics. This project demonstrates complex system design, multi-class interactions, and real-world business logic.

## Features

### 1. **Menu Management**
   - Categorized items (Appetizers, Main Courses, Desserts, Beverages, Soups, Salads)
   - Item details: Price, preparation time, calorie count, vegetarian flag
   - Menu display with formatted output
   - Item availability and inventory tracking

### 2. **Table Management**
   - Multiple tables with varying capacities
   - Table locations (Window, Corner, Center, Private, Bar)
   - Status tracking (Available, Occupied, Reserved, Maintenance)
   - Occupancy percentage calculation

### 3. **Order System**
   - Complete order lifecycle (Placed → Confirmed → Cooking → Ready → Served → Completed)
   - Multiple items per order with special requests
   - Order item status tracking
   - Automatic total calculation with tax
   - Order receipt generation

### 4. **Kitchen Operations**
   - Kitchen display system with tickets
   - Ticket status: Received, Acknowledged, Cooking, Completed
   - Time tracking for cooking duration
   - Kitchen staff assignment
   - Pending orders queue

### 5. **Payment Processing**
   - Multiple payment methods (Cash, Card, Digital Wallet, Cheque)
   - Discount application
   - Payment status tracking
   - Transaction reference generation
   - Receipt display

### 6. **Customer Management**
   - Customer registration and profile tracking
   - Loyalty points system
   - VIP customer identification
   - Visit history and spending tracking
   - Customer analytics

### 7. **Inventory Management**
   - Stock level tracking per item
   - Low stock alerts
   - Usage history tracking
   - Minimum stock level management
   - Inventory status reports

### 8. **Advanced Analytics**
   - Daily statistics (orders, revenue, average order value)
   - Top selling items report
   - Revenue analysis
   - Menu performance metrics
   - Occupancy analysis

## Project Structure

```
project7/
├── include/
│   ├── MenuItem.h              # Menu item with categories
│   ├── OrderItem.h             # Item in an order
│   ├── Order.h                 # Order with multiple items
│   ├── Table.h                 # Restaurant table
│   ├── KitchenTicket.h         # Kitchen display ticket
│   ├── Payment.h               # Payment processing
│   ├── Customer.h              # Customer profile
│   ├── Menu.h                  # Menu collection
│   ├── Inventory.h             # Stock management
│   ├── RestaurantAnalytics.h   # Analytics and reporting
│   └── Restaurant.h            # Main management system
├── src/
│   ├── main.cpp                # Interactive CLI application
│   └── [implementation files]
├── build/                      # Build output directory
├── CMakeLists.txt              # Build configuration
└── README.md                   # This file
```

## Key Classes & Responsibilities

| Class | Purpose |
|-------|---------|
| **MenuItem** | Represents a food/beverage item with price, prep time, inventory |
| **OrderItem** | Item in an order with quantity, special requests, status |
| **Order** | Collection of order items with customer and table info |
| **Table** | Restaurant table with capacity and occupancy status |
| **KitchenTicket** | Display system ticket for kitchen staff |
| **Payment** | Payment processing with method and status tracking |
| **Customer** | Customer profile with loyalty and visit history |
| **Menu** | Categorized collection of menu items |
| **Inventory** | Stock tracking and low stock alerts |
| **RestaurantAnalytics** | Analytics, reporting, and business metrics |
| **Restaurant** | Main system coordinating all operations |

## Key Concepts Demonstrated

### OOP Principles
- **Encapsulation**: Private data with public interfaces
- **Composition**: Restaurant contains Tables, Orders, Menu, Inventory
- **Aggregation**: Order contains OrderItems
- **State Management**: Complex status tracking for Orders, Payments, Tables

### Data Structures
- **STL Maps**: Fast lookup for orders, payments, customers
- **STL Vectors**: Dynamic collections for tables, menu items
- **Enums**: Type-safe status and category management

### Advanced Features
- **Multi-level Status Tracking**: Orders, Items, Payments, Kitchen Tickets
- **Dynamic Pricing**: Tax calculation, discount application
- **Real-world Business Logic**: Table management, kitchen queue, payments
- **Comprehensive Analytics**: Revenue, popularity, occupancy metrics
- **Time Tracking**: Order preparation time, kitchen timing

## Building the Project

### Prerequisites
- CMake 3.10 or higher
- C++17 compatible compiler

### Build Steps

**On Windows (with Visual Studio):**
```bash
cd project7
mkdir build
cd build
cmake ..
cmake --build . --config Release
```

**On Linux/macOS:**
```bash
cd project7
mkdir build
cd build
cmake ..
make
```

### Running the Application
```bash
./build/bin/restaurant_management    # Linux/macOS
.\build\bin\Release\restaurant_management.exe  # Windows
```

## Usage Workflow

1. **Start**: Restaurant initializes with tables, menu, and customers
2. **Order Creation**: Assign table to customer
3. **Add Items**: Select items from menu with special requests
4. **Confirm**: Finalize order before kitchen
5. **Kitchen**: Send to kitchen, track preparation
6. **Serve**: Mark items ready and serve to table
7. **Payment**: Process payment with selected method
8. **Complete**: Generate receipt and release table

## Menu System

```
1. View Menu              - Display categorized menu
2. Create Order           - Assign table to customer
3. Add Item to Order      - Add menu items to order
4. Confirm Order          - Finalize order details
5. Send to Kitchen        - Start food preparation
6. Serve Order            - Complete and serve
7. Process Payment        - Handle payment
8. View Kitchen Queue     - Monitor kitchen status
9. View Table Status      - See table occupancy
10. View Order Status     - Check active orders
11. Display Dashboard     - Quick system overview
12. Generate Reports      - Analytics & reports
13. Inventory Status      - Stock levels
```

## Sample Data

The system initializes with:
- **10 Tables**: Various capacities (2, 3, 4 seats)
- **Sample Menu**:
  - Appetizers: Samosa, Chicken Wings
  - Main Courses: Butter Chicken, Paneer Tikka Masala, Biryani
  - Desserts: Gulab Jamun, Cheesecake
  - Beverages: Mango Lassi, Cola
- **2 Sample Customers**: Pre-registered for testing

## Advanced Concepts Applied

| Concept | Implementation |
|---------|----------------|
| State Machines | Order/Payment/Kitchen status flows |
| Composite Pattern | Orders contain OrderItems |
| Observer Pattern | Kitchen tickets from orders |
| Strategy Pattern | Different payment methods |
| Factory Pattern | Order/Payment creation |
| Singleton-like | Restaurant instance |

## Learning Outcomes

After completing this project, you should understand:
- Complex multi-class system design
- Real-world business logic implementation
- Order and inventory management systems
- Payment processing workflows
- Kitchen display systems
- Customer loyalty programs
- Analytics and reporting systems
- Time-based tracking and monitoring

## Real-World Applications

This system models real restaurant operations including:
- Point of Sale (POS) systems
- Kitchen Display Systems (KDS)
- Table management software
- Inventory tracking systems
- Customer loyalty programs
- Revenue analytics platforms

## Future Enhancements

1. **Database Integration**: Persistent storage (MySQL, PostgreSQL)
2. **Authentication**: User roles (Admin, Manager, Waiter, Chef)
3. **Reservation System**: Table bookings in advance
4. **Online Ordering**: Third-party delivery integration
5. **Delivery Management**: Order tracking and delivery personnel
6. **Rating System**: Customer reviews and ratings
7. **Promotions**: Coupons, discounts, special offers
8. **Mobile App**: Companion mobile application
9. **Real-time Notifications**: SMS/Email alerts
10. **Advanced Analytics**: Machine learning for demand forecasting

## Notes

- All prices are in INR (₹), easily configurable
- Tax rate is set to 5%, configurable in Restaurant class
- Loyalty points: 1 point per ₹10 spent
- VIP Status: 10+ visits OR ₹5000+ spending
- Kitchen ticket time tracked automatically

---

**Created as part of C++ Back-to-Back Learning Series**

This comprehensive project demonstrates industrial-grade C++ system design suitable for:
- Restaurant chains (POS systems)
- Cloud-based food delivery platforms
- Kitchen automation systems
- Business intelligence dashboards
