#ifndef SHOWTIME_H
#define SHOWTIME_H

#include <string>
#include "Movie.h"
#include "Screen.h"

class Showtime {
private:
    std::string showtimeId;
    Movie movie;
    Screen* screen;
    std::string showDateTime;  // Format: "YYYY-MM-DD HH:MM"
    double baseTicketPrice;
    int maxCapacity;
    int ticketsBooked;

public:
    Showtime();
    Showtime(const std::string& id, const Movie& m, Screen* scr,
             const std::string& dateTime, double price);

    // Getters
    std::string getShowtimeId() const { return showtimeId; }
    Movie getMovie() const { return movie; }
    Screen* getScreen() const { return screen; }
    std::string getShowDateTime() const { return showDateTime; }
    double getBaseTicketPrice() const { return baseTicketPrice; }
    int getTicketsBooked() const { return ticketsBooked; }
    int getAvailableTickets() const { return maxCapacity - ticketsBooked; }

    // Methods
    void setScreen(Screen* scr) { screen = scr; maxCapacity = scr->getTotalSeats(); }
    bool bookTicket();
    bool cancelTicket();
    double getCalculatedPrice() const;  // Price with screen quality multiplier
    int getOccupancyPercentage() const;
    bool isShowAvailable() const { return getAvailableTickets() > 0; }

    // Display
    void displayInfo() const;
};

#endif
