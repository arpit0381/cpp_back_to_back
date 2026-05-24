#include "../include/Screen.h"
#include <iostream>

Screen::Screen() : screenId(""), screenName(""), totalRows(0), totalColumns(0),
                   screenQuality(1.0), is3D(false), totalSeats(0), availableSeats(0) {}

Screen::Screen(const std::string& id, const std::string& name, int rows, int cols,
               double quality, bool threeDee)
    : screenId(id), screenName(name), totalRows(rows), totalColumns(cols),
      screenQuality(quality), is3D(threeDee), totalSeats(rows * cols),
      availableSeats(rows * cols) {
    initializeSeats(150.0);
}

void Screen::initializeSeats(double basePrice) {
    seatMap.clear();
    seatMap.resize(totalRows);
    
    for (int i = 0; i < totalRows; ++i) {
        seatMap[i].resize(totalColumns);
        for (int j = 0; j < totalColumns; ++j) {
            seatMap[i][j] = Seat(i, j, basePrice * screenQuality);
        }
    }
    availableSeats = totalSeats;
}

Seat& Screen::getSeat(int row, int col) {
    if (isValidSeat(row, col)) {
        return seatMap[row][col];
    }
    throw std::out_of_range("Invalid seat coordinates");
}

bool Screen::bookSeat(int row, int col) {
    if (isValidSeat(row, col) && seatMap[row][col].isAvailable()) {
        seatMap[row][col].setStatus(SeatStatus::BOOKED);
        availableSeats--;
        return true;
    }
    return false;
}

bool Screen::releaseSeat(int row, int col) {
    if (isValidSeat(row, col) && seatMap[row][col].getStatus() == SeatStatus::BOOKED) {
        seatMap[row][col].setStatus(SeatStatus::AVAILABLE);
        availableSeats++;
        return true;
    }
    return false;
}

bool Screen::isValidSeat(int row, int col) const {
    return row >= 0 && row < totalRows && col >= 0 && col < totalColumns;
}

int Screen::getOccupancyPercentage() const {
    if (totalSeats == 0) return 0;
    return ((totalSeats - availableSeats) * 100) / totalSeats;
}

void Screen::displaySeatMap() const {
    std::cout << "\n=== SEAT MAP: " << screenName << " ===" << std::endl;
    
    // Column headers
    std::cout << "     ";
    for (int j = 0; j < totalColumns; ++j) {
        std::cout << (j + 1) % 10 << " ";
    }
    std::cout << std::endl;
    
    // Seats
    for (int i = 0; i < totalRows; ++i) {
        std::cout << (char)('A' + i) << "   ";
        for (int j = 0; j < totalColumns; ++j) {
            if (seatMap[i][j].isAvailable()) {
                std::cout << "□ ";
            } else if (seatMap[i][j].getStatus() == SeatStatus::BOOKED) {
                std::cout << "■ ";
            } else {
                std::cout << "R ";
            }
        }
        std::cout << std::endl;
    }
    std::cout << "=====================\n" << std::endl;
}

void Screen::displayInfo() const {
    std::cout << "\nScreen: " << screenName << " (" << screenId << ")" << std::endl;
    std::cout << "Capacity: " << totalSeats << " seats (" << totalRows << "x" << totalColumns << ")" << std::endl;
    std::cout << "Type: " << (is3D ? "3D" : "2D") << " - Quality: " << screenQuality << "x" << std::endl;
    std::cout << "Available: " << availableSeats << " | Occupancy: " << getOccupancyPercentage() << "%" << std::endl;
}
