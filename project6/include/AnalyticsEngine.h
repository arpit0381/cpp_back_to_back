#ifndef ANALYTICSENGINE_H
#define ANALYTICSENGINE_H

#include <string>
#include <vector>
#include <map>
#include "Booking.h"
#include "Showtime.h"

struct BookingAnalytics {
    int totalBookings = 0;
    double totalRevenue = 0.0;
    double averageBookingValue = 0.0;
    int cancelledBookings = 0;
    double cancellationRate = 0.0;
};

struct ShowtimeAnalytics {
    std::string showtimeId;
    int occupancyPercentage = 0;
    double revenue = 0.0;
    int ticketsSold = 0;
};

struct MovieAnalytics {
    std::string movieId;
    std::string movieTitle;
    int totalShowings = 0;
    int totalTicketsSold = 0;
    double totalRevenue = 0.0;
    double averageOccupancy = 0.0;
};

class AnalyticsEngine {
private:
    std::vector<Booking> bookingHistory;
    std::vector<Showtime*> allShowtimes;
    std::map<std::string, int> moviePopularity;  // movie_id -> ticket_count

public:
    AnalyticsEngine();

    // Data Collection
    void recordBooking(const Booking& booking);
    void recordShowtime(Showtime* showtime);

    // Analytics Calculations
    BookingAnalytics getBookingAnalytics();
    ShowtimeAnalytics getShowtimeAnalytics(const std::string& showtimeId);
    MovieAnalytics getMovieAnalytics(const std::string& movieId);
    std::vector<std::string> getTopMovies(int limit = 5);
    double getDailyRevenue(const std::string& date);

    // Reporting
    void generateBookingReport();
    void generateMovieReport();
    void generateRevenueReport();
    void displayAnalyticsDashboard();
};

#endif
