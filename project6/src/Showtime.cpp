#include "../include/Showtime.h"
#include <iostream>

Showtime::Showtime() : showtimeId(""), movie(), screen(nullptr),
                       showDateTime(""), baseTicketPrice(0.0),
                       maxCapacity(0), ticketsBooked(0) {}

Showtime::Showtime(const std::string& id, const Movie& m, Screen* scr,
                   const std::string& dateTime, double price)
    : showtimeId(id), movie(m), screen(scr), showDateTime(dateTime),
      baseTicketPrice(price), ticketsBooked(0) {
    if (screen != nullptr) {
        maxCapacity = screen->getTotalSeats();
    }
}

bool Showtime::bookTicket() {
    if (ticketsBooked < maxCapacity) {
        ticketsBooked++;
        return true;
    }
    return false;
}

bool Showtime::cancelTicket() {
    if (ticketsBooked > 0) {
        ticketsBooked--;
        return true;
    }
    return false;
}

double Showtime::getCalculatedPrice() const {
    if (screen == nullptr) return baseTicketPrice;
    return baseTicketPrice * screen->getScreenQuality();
}

int Showtime::getOccupancyPercentage() const {
    if (maxCapacity == 0) return 0;
    return (ticketsBooked * 100) / maxCapacity;
}

void Showtime::displayInfo() const {
    std::cout << "\n=== SHOWTIME DETAILS ===" << std::endl;
    std::cout << "Showtime ID: " << showtimeId << std::endl;
    std::cout << "Movie: " << movie.getTitle() << std::endl;
    std::cout << "Date & Time: " << showDateTime << std::endl;
    if (screen != nullptr) {
        std::cout << "Screen: " << screen->getScreenName() << std::endl;
        std::cout << "Screen Type: " << (screen->getIs3D() ? "3D" : "2D") << std::endl;
    }
    std::cout << "Base Price: ₹" << baseTicketPrice << std::endl;
    std::cout << "Calculated Price: ₹" << getCalculatedPrice() << std::endl;
    std::cout << "Tickets Booked: " << ticketsBooked << "/" << maxCapacity << std::endl;
    std::cout << "Occupancy: " << getOccupancyPercentage() << "%" << std::endl;
    std::cout << "=======================\n" << std::endl;
}
