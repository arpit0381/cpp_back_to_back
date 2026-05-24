#include "../include/FileHandler.h"
#include <iostream>
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;

FileHandler::FileHandler() : dataDirectory("./data") {}

FileHandler::FileHandler(const std::string& directory) : dataDirectory(directory) {}

bool FileHandler::ensureDirectoryExists() {
    try {
        if (!fs::exists(dataDirectory)) {
            fs::create_directories(dataDirectory);
        }
        return true;
    } catch (const std::exception& e) {
        std::cerr << "Error creating directory: " << e.what() << std::endl;
        return false;
    }
}

std::string FileHandler::getFullPath(const std::string& filename) {
    return dataDirectory + "/" + filename;
}

bool FileHandler::saveMovies(const std::vector<Movie>& movies, const std::string& filename) {
    if (!ensureDirectoryExists()) return false;
    
    std::ofstream file(getFullPath(filename));
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return false;
    }
    
    file << "MOVIE_DATABASE" << std::endl;
    file << movies.size() << std::endl;
    
    for (const auto& movie : movies) {
        file << movie.getId() << "|" << movie.getTitle() << "|"
             << movie.getGenre() << "|" << movie.getDurationMinutes() << "|"
             << movie.getImdbRating() << "|" << movie.getLanguage() << "|"
             << movie.getReleaseDate() << "|" << movie.getDirector() << std::endl;
    }
    
    file.close();
    std::cout << "Movies saved successfully to " << filename << std::endl;
    return true;
}

std::vector<Movie> FileHandler::loadMovies(const std::string& filename) {
    std::vector<Movie> movies;
    std::ifstream file(getFullPath(filename));
    
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return movies;
    }
    
    std::string header;
    int count;
    file >> header >> count;
    file.ignore();  // Ignore newline
    
    for (int i = 0; i < count; ++i) {
        std::string line;
        std::getline(file, line);
        
        size_t pos = 0;
        std::vector<std::string> parts;
        
        while (pos < line.length()) {
            size_t next_pos = line.find('|', pos);
            if (next_pos == std::string::npos) next_pos = line.length();
            parts.push_back(line.substr(pos, next_pos - pos));
            pos = next_pos + 1;
        }
        
        if (parts.size() == 8) {
            Movie movie(parts[0], parts[1], parts[2], std::stoi(parts[3]),
                       std::stod(parts[4]), parts[5], parts[6], parts[7]);
            movies.push_back(movie);
        }
    }
    
    file.close();
    std::cout << "Movies loaded successfully from " << filename << std::endl;
    return movies;
}

bool FileHandler::saveShowtimes(Theater& theater, const std::string& filename) {
    if (!ensureDirectoryExists()) return false;
    
    std::ofstream file(getFullPath(filename));
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return false;
    }
    
    file << "SHOWTIMES_BACKUP" << std::endl;
    std::cout << "Showtimes backup saved to " << filename << std::endl;
    file.close();
    return true;
}

bool FileHandler::loadShowtimes(Theater& theater, const std::string& filename) {
    std::ifstream file(getFullPath(filename));
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return false;
    }
    
    std::string header;
    file >> header;
    file.close();
    std::cout << "Showtimes loaded from " << filename << std::endl;
    return true;
}

bool FileHandler::saveBookings(const std::vector<Booking>& bookings, const std::string& filename) {
    if (!ensureDirectoryExists()) return false;
    
    std::ofstream file(getFullPath(filename));
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return false;
    }
    
    file << "BOOKINGS_DATABASE" << std::endl;
    file << bookings.size() << std::endl;
    
    for (const auto& booking : bookings) {
        file << booking.getBookingId() << "|" << booking.getCustomerId() << "|"
             << booking.getTotalAmount() << "|" << booking.getTicketCount() << std::endl;
    }
    
    file.close();
    std::cout << "Bookings saved successfully to " << filename << std::endl;
    return true;
}

std::vector<Booking> FileHandler::loadBookings(const std::string& filename) {
    std::vector<Booking> bookings;
    std::ifstream file(getFullPath(filename));
    
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return bookings;
    }
    
    std::string header;
    int count;
    file >> header >> count;
    
    std::cout << "Bookings loaded from " << filename << std::endl;
    file.close();
    return bookings;
}

bool FileHandler::generateBookingReport(const std::vector<Booking>& bookings,
                                        const std::string& filename) {
    if (!ensureDirectoryExists()) return false;
    
    std::ofstream file(getFullPath(filename));
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return false;
    }
    
    file << "=== BOOKING REPORT ===" << std::endl;
    file << "Total Bookings: " << bookings.size() << std::endl;
    file << std::endl;
    
    for (const auto& booking : bookings) {
        file << "Booking ID: " << booking.getBookingId() << std::endl;
        file << "Customer ID: " << booking.getCustomerId() << std::endl;
        file << "Total Amount: " << booking.getTotalAmount() << std::endl;
        file << "Status: " << booking.getStatus() << std::endl;
        file << "---" << std::endl;
    }
    
    file.close();
    std::cout << "Report generated successfully: " << filename << std::endl;
    return true;
}

bool FileHandler::generateRevenueReport(Theater& theater, const std::string& filename) {
    if (!ensureDirectoryExists()) return false;
    
    std::ofstream file(getFullPath(filename));
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return false;
    }
    
    file << "=== REVENUE REPORT ===" << std::endl;
    file << "Theater: " << theater.getTheaterName() << std::endl;
    file << "Generated on: " << __DATE__ << " " << __TIME__ << std::endl;
    file << std::endl;
    
    file.close();
    std::cout << "Revenue report generated: " << filename << std::endl;
    return true;
}
