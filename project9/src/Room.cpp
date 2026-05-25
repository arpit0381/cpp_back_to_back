#include "Room.h"
#include <iostream>

Room::Room() : roomNumber(0), type(RoomType::SINGLE), status(RoomStatus::AVAILABLE), 
              pricePerNight(0), capacity(1), lastCleaned("") {}

Room::Room(int number, RoomType type, double price, int capacity)
    : roomNumber(number), type(type), status(RoomStatus::AVAILABLE), 
      pricePerNight(price), capacity(capacity), lastCleaned("") {}

int Room::getRoomNumber() const { return roomNumber; }
RoomType Room::getType() const { return type; }
RoomStatus Room::getStatus() const { return status; }
double Room::getPricePerNight() const { return pricePerNight; }
int Room::getCapacity() const { return capacity; }
std::string Room::getLastCleaned() const { return lastCleaned; }
bool Room::isAvailable() const { return status == RoomStatus::AVAILABLE; }

void Room::setStatus(RoomStatus status) { this->status = status; }
void Room::setLastCleaned(const std::string& date) { this->lastCleaned = date; }
void Room::setPricePerNight(double price) { this->pricePerNight = price; }

std::string Room::getTypeString() const {
    switch(type) {
        case RoomType::SINGLE: return "Single";
        case RoomType::DOUBLE: return "Double";
        case RoomType::SUITE: return "Suite";
        case RoomType::DELUXE: return "Deluxe";
        default: return "Unknown";
    }
}

std::string Room::getStatusString() const {
    switch(status) {
        case RoomStatus::AVAILABLE: return "Available";
        case RoomStatus::OCCUPIED: return "Occupied";
        case RoomStatus::MAINTENANCE: return "Maintenance";
        default: return "Unknown";
    }
}

void Room::display() const {
    std::cout << "Room #" << roomNumber << " | "
              << "Type: " << getTypeString() << " | "
              << "Status: " << getStatusString() << " | "
              << "Price: $" << pricePerNight << "/night | "
              << "Capacity: " << capacity << "\n";
}
