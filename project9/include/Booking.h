#ifndef BOOKING_H
#define BOOKING_H

#include <string>

class Booking {
private:
    int bookingId;
    int guestId;
    int roomNumber;
    std::string checkInDate;
    std::string checkOutDate;
    int numberOfNights;
    double totalCost;
    bool isActive;

public:
    Booking();
    Booking(int id, int guestId, int roomNumber, 
            const std::string& checkIn, const std::string& checkOut, double cost);
    
    // Getters
    int getBookingId() const;
    int getGuestId() const;
    int getRoomNumber() const;
    std::string getCheckInDate() const;
    std::string getCheckOutDate() const;
    int getNumberOfNights() const;
    double getTotalCost() const;
    bool getIsActive() const;
    
    // Setters
    void setIsActive(bool active);
    void setCheckOutDate(const std::string& date);
    
    // Utilities
    void calculateNights();
    void display() const;
};

#endif // BOOKING_H
