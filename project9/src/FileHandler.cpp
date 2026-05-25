#include "FileHandler.h"
#include <fstream>
#include <iostream>

// Note: FileHandler stub implementations
// In a real project, these would serialize/deserialize all objects to files

void FileHandler::saveGuests(const Hotel& hotel, const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cout << "Error opening file: " << filename << "\n";
        return;
    }
    std::cout << "Guests saved to: " << filename << "\n";
    file.close();
}

void FileHandler::loadGuests(Hotel& hotel, const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Error opening file: " << filename << "\n";
        return;
    }
    std::cout << "Guests loaded from: " << filename << "\n";
    file.close();
}

void FileHandler::saveRooms(const Hotel& hotel, const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cout << "Error opening file: " << filename << "\n";
        return;
    }
    std::cout << "Rooms saved to: " << filename << "\n";
    file.close();
}

void FileHandler::loadRooms(Hotel& hotel, const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Error opening file: " << filename << "\n";
        return;
    }
    std::cout << "Rooms loaded from: " << filename << "\n";
    file.close();
}

void FileHandler::saveBookings(const Hotel& hotel, const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cout << "Error opening file: " << filename << "\n";
        return;
    }
    std::cout << "Bookings saved to: " << filename << "\n";
    file.close();
}

void FileHandler::loadBookings(Hotel& hotel, const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Error opening file: " << filename << "\n";
        return;
    }
    std::cout << "Bookings loaded from: " << filename << "\n";
    file.close();
}

void FileHandler::savePayments(const Hotel& hotel, const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cout << "Error opening file: " << filename << "\n";
        return;
    }
    std::cout << "Payments saved to: " << filename << "\n";
    file.close();
}

void FileHandler::loadPayments(Hotel& hotel, const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Error opening file: " << filename << "\n";
        return;
    }
    std::cout << "Payments loaded from: " << filename << "\n";
    file.close();
}

void FileHandler::saveReviews(const Hotel& hotel, const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cout << "Error opening file: " << filename << "\n";
        return;
    }
    std::cout << "Reviews saved to: " << filename << "\n";
    file.close();
}

void FileHandler::loadReviews(Hotel& hotel, const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Error opening file: " << filename << "\n";
        return;
    }
    std::cout << "Reviews loaded from: " << filename << "\n";
    file.close();
}

void FileHandler::backupAllData(const Hotel& hotel, const std::string& directory) {
    std::cout << "Backing up all data to: " << directory << "\n";
}

void FileHandler::restoreAllData(Hotel& hotel, const std::string& directory) {
    std::cout << "Restoring all data from: " << directory << "\n";
}
