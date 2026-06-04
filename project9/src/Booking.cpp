#include "Booking.h"
#include <iostream>
//.........
//.........?.....#................
Booking::Booking() : bookingId(0), guestId(0), roomNumber(0), 
                     checkInDate(""), checkOutDate(""), numberOfNights(0), 
                     totalCost(0), isActive(true) {}//........

Booking::Booking(int id, int guestId, int roomNumber, 
                 const std::string& checkIn, const std::string& checkOut, double cost)
    : bookingId(id), guestId(guestId), roomNumber(roomNumber), 
      checkInDate(checkIn), checkOutDate(checkOut), totalCost(cost), isActive(true) {
    calculateNights();
}

int Booking::getBookingId() const { return bookingId; }
int Booking::getGuestId() const { return guestId; }
int Booking::getRoomNumber() const { return roomNumber; }
std::string Booking::getCheckInDate() const { return checkInDate; }
std::string Booking::getCheckOutDate() const { return checkOutDate; }
int Booking::getNumberOfNights() const { return numberOfNights; }
double Booking::getTotalCost() const { return totalCost; }
bool Booking::getIsActive() const { return isActive; }

void Booking::setIsActive(bool active) { this->isActive = active; }
void Booking::setCheckOutDate(const std::string& date) { this->checkOutDate = date; }

void Booking::calculateNights() {
    numberOfNights = 1;  // Simplified calculation
}

void Booking::display() const {
    std::cout << "Booking ID: " << bookingId << "\n"
              << "Guest ID: " << guestId << "\n"
              << "Room #" << roomNumber << "\n"
              << "Check-in: " << checkInDate << "\n"
              << "Check-out: " << checkOutDate << "\n"
              << "Nights: " << numberOfNights << "\n"
              << "Total Cost: $" << totalCost << "\n"
              << "Status: " << (isActive ? "Active" : "Cancelled") << "\n";
}
......//......