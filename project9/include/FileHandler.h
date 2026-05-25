#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include "Hotel.h"
#include <string>

class FileHandler {
public:
    // Save/Load Guests
    static void saveGuests(const Hotel& hotel, const std::string& filename);
    static void loadGuests(Hotel& hotel, const std::string& filename);
    
    // Save/Load Rooms
    static void saveRooms(const Hotel& hotel, const std::string& filename);
    static void loadRooms(Hotel& hotel, const std::string& filename);
    
    // Save/Load Bookings
    static void saveBookings(const Hotel& hotel, const std::string& filename);
    static void loadBookings(Hotel& hotel, const std::string& filename);
    
    // Save/Load Payments
    static void savePayments(const Hotel& hotel, const std::string& filename);
    static void loadPayments(Hotel& hotel, const std::string& filename);
    
    // Save/Load Reviews
    static void saveReviews(const Hotel& hotel, const std::string& filename);
    static void loadReviews(Hotel& hotel, const std::string& filename);
    
    // Backup all data
    static void backupAllData(const Hotel& hotel, const std::string& directory);
    static void restoreAllData(Hotel& hotel, const std::string& directory);
};

#endif // FILEHANDLER_H
