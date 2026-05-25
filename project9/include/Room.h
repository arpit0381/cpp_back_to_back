#ifndef ROOM_H
#define ROOM_H

#include <string>

enum class RoomType { SINGLE, DOUBLE, SUITE, DELUXE };
enum class RoomStatus { AVAILABLE, OCCUPIED, MAINTENANCE };

class Room {
private:
    int roomNumber;
    RoomType type;
    RoomStatus status;
    double pricePerNight;
    int capacity;
    std::string lastCleaned;

public:
    Room();
    Room(int number, RoomType type, double price, int capacity);
    
    // Getters
    int getRoomNumber() const;
    RoomType getType() const;
    RoomStatus getStatus() const;
    double getPricePerNight() const;
    int getCapacity() const;
    std::string getLastCleaned() const;
    bool isAvailable() const;
    
    // Setters
    void setStatus(RoomStatus status);
    void setLastCleaned(const std::string& date);
    void setPricePerNight(double price);
    
    // Utilities
    std::string getTypeString() const;
    std::string getStatusString() const;
    void display() const;
};

#endif // ROOM_H
