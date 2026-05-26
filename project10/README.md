# Project 10: E-commerce Product Management System

## Overview
A comprehensive product management system for an e-commerce platform. This project demonstrates the management of products, inventory levels, and product categories using object-oriented design principles.

## Features
- **Product Management**: Create, update, and delete products
- **Inventory Tracking**: Manage stock levels and track inventory changes
- **Category Management**: Organize products into categories
- **Search & Filter**: Find products by name, category, or price range
- **Stock Alerts**: Monitor low stock items

## Project Structure
```
project10/
├── include/
│   ├── Product.h           # Product class definition
│   ├── Inventory.h         # Inventory management
│   ├── ProductManager.h    # Central product manager
│   └── Category.h          # Product category
├── src/
│   ├── Product.cpp         # Product implementation
│   ├── Inventory.cpp       # Inventory implementation
│   ├── ProductManager.cpp  # Product manager implementation
│   ├── Category.cpp        # Category implementation
│   └── main.cpp            # Application entry point
├── build/                  # Build output directory
└── CMakeLists.txt          # CMake configuration
```

## Building
```bash
cd project10
mkdir -p build
cd build
cmake ..
make
```

## Running
```bash
./ProductManager
```

## Key Classes
- **Product**: Represents a product with ID, name, price, and category
- **Inventory**: Manages stock levels and updates
- **Category**: Defines product categories
- **ProductManager**: Central manager for all product operations

## Technologies
- C++17
- CMake
- Standard Library (vector, map, string)
