#ifndef SEAT_H
#define SEAT_H

#include <string>

enum class SeatStatus {
    AVAILABLE,
    BOOKED,
    RESERVED,
    MAINTENANCE
};

class Seat {
private:
    int row;
    int column;
    SeatStatus status;
    double price;
    std::string seatNumber;  // e.g., "A1", "B5"

public:
    Seat();
    Seat(int row, int col, double price);

    // Getters
    int getRow() const { return row; }
    int getColumn() const { return column; }
    SeatStatus getStatus() const { return status; }
    double getPrice() const { return price; }
    std::string getSeatNumber() const { return seatNumber; }

    // Setters
    void setStatus(SeatStatus s) { status = s; }
    void setPrice(double p) { price = p; }

    // Methods
    void generateSeatNumber();
    bool isAvailable() const { return status == SeatStatus::AVAILABLE; }
    std::string getStatusString() const;

    // Display
    void displayInfo() const;
};

#endif
