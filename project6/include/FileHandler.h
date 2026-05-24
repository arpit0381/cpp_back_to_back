#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <string>
#include <vector>
#include "Theater.h"
#include "Movie.h"
#include "Booking.h"

class FileHandler {
private:
    std::string dataDirectory;

public:
    FileHandler();
    FileHandler(const std::string& directory);

    // Movie File Operations
    bool saveMovies(const std::vector<Movie>& movies, const std::string& filename);
    std::vector<Movie> loadMovies(const std::string& filename);

    // Showtime File Operations
    bool saveShowtimes(Theater& theater, const std::string& filename);
    bool loadShowtimes(Theater& theater, const std::string& filename);

    // Booking File Operations
    bool saveBookings(const std::vector<Booking>& bookings, const std::string& filename);
    std::vector<Booking> loadBookings(const std::string& filename);

    // Report Generation
    bool generateBookingReport(const std::vector<Booking>& bookings,
                               const std::string& filename);
    bool generateRevenueReport(Theater& theater, const std::string& filename);

    // Utility Methods
    bool ensureDirectoryExists();
    std::string getFullPath(const std::string& filename);
};

#endif
