#include "../include/Seat.h"
#include <iostream>
#include <sstream>
//start of the code 

Seat::Seat() : row(0), column(0), status(SeatStatus::AVAILABLE), price(150.0), seatNumber("") {
    generateSeatNumber();
}

Seat::Seat(int row, int col, double price)
    : row(row), column(col), status(SeatStatus::AVAILABLE), price(price), seatNumber("") {
    generateSeatNumber();
}

void Seat::generateSeatNumber() {
    std::ostringstream oss;
    oss << (char)('A' + row) << (column + 1);
    seatNumber = oss.str();
}

std::string Seat::getStatusString() const {
    switch (status) {
        case SeatStatus::AVAILABLE: return "Available";
        case SeatStatus::BOOKED: return "Booked";
        case SeatStatus::RESERVED: return "Reserved";
        case SeatStatus::MAINTENANCE: return "Maintenance";
        default: return "Unknown";
    }
}

void Seat::displayInfo() const {
    std::cout << "Seat " << seatNumber << " - Status: " << getStatusString()
              << " - Price: ₹" << price << std::endl;
}
