#include "../include/Theater.h"
#include <iostream>
#include <algorithm>
#include <sstream>

Theater::Theater() : theaterId(""), theaterName(""), location(""), city(""), operatingHours(0) {}

Theater::Theater(const std::string& id, const std::string& name,
                 const std::string& loc, const std::string& cty)
    : theaterId(id), theaterName(name), location(loc), city(cty), operatingHours(0) {}

void Theater::addScreen(const Screen& screen) {
    screens.push_back(screen);
}

Screen* Theater::getScreen(int index) {
    if (index >= 0 && index < static_cast<int>(screens.size())) {
        return &screens[index];
    }
    return nullptr;
}

Screen* Theater::getScreenById(const std::string& screenId) {
    for (auto& screen : screens) {
        if (screen.getScreenId() == screenId) {
            return &screen;
        }
    }
    return nullptr;
}

void Theater::addMovie(const Movie& movie) {
    movieCatalog[movie.getId()] = movie;
}

Movie* Theater::getMovie(const std::string& movieId) {
    auto it = movieCatalog.find(movieId);
    if (it != movieCatalog.end()) {
        return &it->second;
    }
    return nullptr;
}

std::vector<Movie> Theater::getAllMovies() const {
    std::vector<Movie> movies;
    for (const auto& pair : movieCatalog) {
        movies.push_back(pair.second);
    }
    return movies;
}

void Theater::createShowtime(const std::string& movieId, int screenIndex,
                             const std::string& dateTime, double price) {
    auto it = movieCatalog.find(movieId);
    if (it != movieCatalog.end() && screenIndex >= 0 && screenIndex < static_cast<int>(screens.size())) {
        std::string showtimeId = "ST" + std::to_string(showtimes.size() + 1);
        Showtime newShowtime(showtimeId, it->second, &screens[screenIndex], dateTime, price);
        showtimes.push_back(newShowtime);
        analyticsEngine.recordShowtime(&showtimes.back());
    }
}

std::vector<Showtime> Theater::getShowtimesByMovie(const std::string& movieId) {
    std::vector<Showtime> result;
    for (auto& showtime : showtimes) {
        if (showtime.getMovie().getId() == movieId) {
            result.push_back(showtime);
        }
    }
    return result;
}

std::vector<Showtime> Theater::getShowtimesByDate(const std::string& date) {
    std::vector<Showtime> result;
    for (auto& showtime : showtimes) {
        if (showtime.getShowDateTime().find(date) == 0) {
            result.push_back(showtime);
        }
    }
    return result;
}

Showtime* Theater::getShowtimeById(const std::string& showtimeId) {
    for (auto& showtime : showtimes) {
        if (showtime.getShowtimeId() == showtimeId) {
            return &showtime;
        }
    }
    return nullptr;
}

Booking Theater::createBooking(const std::string& customerId, const std::string& showtimeId,
                               const std::vector<std::pair<int, int>>& seats) {
    std::string bookingId = "BK" + std::to_string(bookings.size() + 1);
    Booking booking(bookingId, customerId);
    
    Showtime* showtime = getShowtimeById(showtimeId);
    if (showtime != nullptr) {
        for (const auto& seat : seats) {
            if (showtime->getScreen()->bookSeat(seat.first, seat.second)) {
                std::string ticketId = "T" + std::to_string(booking.getTicketCount() + 1);
                double price = showtime->getCalculatedPrice();
                Ticket ticket(ticketId, customerId, showtimeId, seat.first, seat.second, price);
                booking.addTicket(ticket);
                showtime->bookTicket();
            }
        }
    }
    
    bookings.push_back(booking);
    analyticsEngine.recordBooking(booking);
    return booking;
}

void Theater::confirmBooking(const std::string& bookingId, const std::string& paymentMethod) {
    for (auto& booking : bookings) {
        if (booking.getBookingId() == bookingId) {
            booking.confirmBooking(paymentMethod);
            return;
        }
    }
}

void Theater::cancelBooking(const std::string& bookingId) {
    for (auto& booking : bookings) {
        if (booking.getBookingId() == bookingId) {
            booking.cancelBooking();
            
            // Release seats
            std::string showtimeId = booking.getTicketCount() > 0 ? 
                                    booking.getTicket(0).getShowtimeId() : "";
            Showtime* showtime = getShowtimeById(showtimeId);
            
            if (showtime != nullptr) {
                for (int i = 0; i < booking.getTicketCount(); ++i) {
                    Ticket& ticket = booking.getTicket(i);
                    showtime->getScreen()->releaseSeat(ticket.getSeatRow(), ticket.getSeatColumn());
                    showtime->cancelTicket();
                }
            }
            return;
        }
    }
}

Booking* Theater::getBooking(const std::string& bookingId) {
    for (auto& booking : bookings) {
        if (booking.getBookingId() == bookingId) {
            return &booking;
        }
    }
    return nullptr;
}

void Theater::generateReport() {
    analyticsEngine.displayAnalyticsDashboard();
}

void Theater::displayDashboard() {
    std::cout << "\n" << std::string(50, '=') << std::endl;
    std::cout << "THEATER MANAGEMENT SYSTEM - DASHBOARD" << std::endl;
    std::cout << std::string(50, '=') << std::endl;
    
    std::cout << "\nTheater: " << theaterName << " (" << theaterId << ")" << std::endl;
    std::cout << "Location: " << location << ", " << city << std::endl;
    std::cout << "Screens: " << screens.size() << " | Movies: " << movieCatalog.size()
              << " | Showtimes: " << showtimes.size() << " | Bookings: " << bookings.size() << std::endl;
    
    std::cout << "\n--- Recent Showtimes ---" << std::endl;
    for (size_t i = 0; i < showtimes.size() && i < 5; ++i) {
        std::cout << (i + 1) << ". " << showtimes[i].getMovie().getTitle()
                  << " at " << showtimes[i].getShowDateTime()
                  << " - Occupancy: " << showtimes[i].getOccupancyPercentage() << "%" << std::endl;
    }
    
    std::cout << std::string(50, '=') << "\n" << std::endl;
}

void Theater::displayInfo() const {
    std::cout << "\n=== THEATER INFORMATION ===" << std::endl;
    std::cout << "Theater ID: " << theaterId << std::endl;
    std::cout << "Name: " << theaterName << std::endl;
    std::cout << "Location: " << location << std::endl;
    std::cout << "City: " << city << std::endl;
    std::cout << "Total Screens: " << screens.size() << std::endl;
    std::cout << "Total Movies: " << movieCatalog.size() << std::endl;
    std::cout << "Total Showtimes: " << showtimes.size() << std::endl;
    std::cout << "============================\n" << std::endl;
}

void Theater::displayAllMovies() const {
    std::cout << "\n========== ALL MOVIES ==========" << std::endl;
    for (const auto& pair : movieCatalog) {
        pair.second.displayInfo();
    }
    std::cout << "===============================\n" << std::endl;
}

void Theater::displayAllShowtimes() const {
    std::cout << "\n========== ALL SHOWTIMES ==========" << std::endl;
    for (const auto& showtime : showtimes) {
        showtime.displayInfo();
    }
    std::cout << "===================================\n" << std::endl;
}
