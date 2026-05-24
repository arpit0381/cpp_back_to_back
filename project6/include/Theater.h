#ifndef THEATER_H
#define THEATER_H

#include <string>
#include <vector>
#include <map>
#include "Movie.h"
#include "Screen.h"
#include "Showtime.h"
#include "Booking.h"
#include "AnalyticsEngine.h"

class Theater {
private:
    std::string theaterId;
    std::string theaterName;
    std::string location;
    std::string city;
    std::vector<Screen> screens;
    std::map<std::string, Movie> movieCatalog;  // movie_id -> Movie
    std::vector<Showtime> showtimes;
    std::vector<Booking> bookings;
    AnalyticsEngine analyticsEngine;
    double operatingHours;

public:
    Theater();
    Theater(const std::string& id, const std::string& name, const std::string& loc,
            const std::string& cty);

    // Getters
    std::string getTheaterId() const { return theaterId; }
    std::string getTheaterName() const { return theaterName; }
    std::string getLocation() const { return location; }
    std::string getCity() const { return city; }
    int getScreenCount() const { return screens.size(); }
    int getMovieCount() const { return movieCatalog.size(); }
    int getShowtimeCount() const { return showtimes.size(); }

    // Screen Management
    void addScreen(const Screen& screen);
    Screen* getScreen(int index);
    Screen* getScreenById(const std::string& screenId);

    // Movie Management
    void addMovie(const Movie& movie);
    Movie* getMovie(const std::string& movieId);
    std::vector<Movie> getAllMovies() const;

    // Showtime Management
    void createShowtime(const std::string& movieId, int screenIndex,
                        const std::string& dateTime, double price);
    std::vector<Showtime> getShowtimesByMovie(const std::string& movieId);
    std::vector<Showtime> getShowtimesByDate(const std::string& date);
    Showtime* getShowtimeById(const std::string& showtimeId);

    // Booking Management
    Booking createBooking(const std::string& customerId, const std::string& showtimeId,
                          const std::vector<std::pair<int, int>>& seats);
    void confirmBooking(const std::string& bookingId, const std::string& paymentMethod);
    void cancelBooking(const std::string& bookingId);
    Booking* getBooking(const std::string& bookingId);

    // Analytics
    void generateReport();
    void displayDashboard();

    // Display
    void displayInfo() const;
    void displayAllMovies() const;
    void displayAllShowtimes() const;
};

#endif
