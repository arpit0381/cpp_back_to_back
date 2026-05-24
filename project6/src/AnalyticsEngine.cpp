#include "../include/AnalyticsEngine.h"
#include <iostream>
#include <iomanip>
#include <algorithm>

AnalyticsEngine::AnalyticsEngine() {}

void AnalyticsEngine::recordBooking(const Booking& booking) {
    bookingHistory.push_back(booking);
}

void AnalyticsEngine::recordShowtime(Showtime* showtime) {
    allShowtimes.push_back(showtime);
}

BookingAnalytics AnalyticsEngine::getBookingAnalytics() {
    BookingAnalytics analytics;
    
    analytics.totalBookings = bookingHistory.size();
    int cancelledCount = 0;
    
    for (const auto& booking : bookingHistory) {
        analytics.totalRevenue += booking.getTotalAmount();
        if (booking.getStatus() == BookingStatus::CANCELLED) {
            cancelledCount++;
        }
    }
    
    analytics.cancelledBookings = cancelledCount;
    
    if (analytics.totalBookings > 0) {
        analytics.averageBookingValue = analytics.totalRevenue / analytics.totalBookings;
        analytics.cancellationRate = (static_cast<double>(cancelledCount) / analytics.totalBookings) * 100;
    }
    
    return analytics;
}

ShowtimeAnalytics AnalyticsEngine::getShowtimeAnalytics(const std::string& showtimeId) {
    ShowtimeAnalytics analytics;
    analytics.showtimeId = showtimeId;
    
    for (auto* showtime : allShowtimes) {
        if (showtime->getShowtimeId() == showtimeId) {
            analytics.occupancyPercentage = showtime->getOccupancyPercentage();
            analytics.ticketsSold = showtime->getTicketsBooked();
            analytics.revenue = showtime->getBaseTicketPrice() * showtime->getTicketsBooked();
            break;
        }
    }
    
    return analytics;
}

MovieAnalytics AnalyticsEngine::getMovieAnalytics(const std::string& movieId) {
    MovieAnalytics analytics;
    analytics.movieId = movieId;
    
    int totalOccupancy = 0;
    int showtimeCount = 0;
    
    for (auto* showtime : allShowtimes) {
        if (showtime->getMovie().getId() == movieId) {
            analytics.movieTitle = showtime->getMovie().getTitle();
            analytics.totalShowings++;
            analytics.totalTicketsSold += showtime->getTicketsBooked();
            analytics.totalRevenue += showtime->getBaseTicketPrice() * showtime->getTicketsBooked();
            totalOccupancy += showtime->getOccupancyPercentage();
            showtimeCount++;
        }
    }
    
    if (showtimeCount > 0) {
        analytics.averageOccupancy = static_cast<double>(totalOccupancy) / showtimeCount;
    }
    
    return analytics;
}

std::vector<std::string> AnalyticsEngine::getTopMovies(int limit) {
    std::vector<std::pair<std::string, int>> movieTickets;
    
    for (auto* showtime : allShowtimes) {
        std::string movieId = showtime->getMovie().getId();
        movieTickets.push_back({movieId, showtime->getTicketsBooked()});
    }
    
    std::sort(movieTickets.begin(), movieTickets.end(),
              [](const auto& a, const auto& b) { return a.second > b.second; });
    
    std::vector<std::string> topMovies;
    for (int i = 0; i < limit && i < static_cast<int>(movieTickets.size()); ++i) {
        topMovies.push_back(movieTickets[i].first);
    }
    
    return topMovies;
}

double AnalyticsEngine::getDailyRevenue(const std::string& date) {
    double revenue = 0.0;
    
    for (const auto& booking : bookingHistory) {
        if (booking.getStatus() != BookingStatus::CANCELLED) {
            revenue += booking.getTotalAmount();
        }
    }
    
    return revenue;
}

void AnalyticsEngine::generateBookingReport() {
    BookingAnalytics analytics = getBookingAnalytics();
    
    std::cout << "\n========== BOOKING ANALYTICS ==========" << std::endl;
    std::cout << "Total Bookings: " << analytics.totalBookings << std::endl;
    std::cout << "Total Revenue: ₹" << std::fixed << std::setprecision(2)
              << analytics.totalRevenue << std::endl;
    std::cout << "Average Booking Value: ₹" << analytics.averageBookingValue << std::endl;
    std::cout << "Cancelled Bookings: " << analytics.cancelledBookings << std::endl;
    std::cout << "Cancellation Rate: " << std::setprecision(2) << analytics.cancellationRate << "%" << std::endl;
    std::cout << "======================================\n" << std::endl;
}

void AnalyticsEngine::generateMovieReport() {
    std::cout << "\n========== MOVIE ANALYTICS ==========" << std::endl;
    
    for (auto* showtime : allShowtimes) {
        MovieAnalytics analytics = getMovieAnalytics(showtime->getMovie().getId());
        std::cout << "Movie: " << analytics.movieTitle << std::endl;
        std::cout << "  Total Showings: " << analytics.totalShowings << std::endl;
        std::cout << "  Tickets Sold: " << analytics.totalTicketsSold << std::endl;
        std::cout << "  Total Revenue: ₹" << std::fixed << std::setprecision(2)
                  << analytics.totalRevenue << std::endl;
        std::cout << "  Average Occupancy: " << analytics.averageOccupancy << "%" << std::endl;
    }
    
    std::cout << "====================================\n" << std::endl;
}

void AnalyticsEngine::generateRevenueReport() {
    std::cout << "\n========== REVENUE REPORT ==========" << std::endl;
    
    double totalRevenue = 0.0;
    for (const auto& booking : bookingHistory) {
        if (booking.getStatus() != BookingStatus::CANCELLED) {
            totalRevenue += booking.getTotalAmount();
        }
    }
    
    std::cout << "Total Revenue (All Bookings): ₹" << std::fixed << std::setprecision(2)
              << totalRevenue << std::endl;
    std::cout << "Complete Bookings: " << bookingHistory.size() << std::endl;
    std::cout << "====================================\n" << std::endl;
}

void AnalyticsEngine::displayAnalyticsDashboard() {
    generateBookingReport();
    generateMovieReport();
    generateRevenueReport();
}
