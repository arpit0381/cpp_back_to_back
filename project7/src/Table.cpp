#include "../include/Table.h"
#include <iostream>

Table::Table() : tableNumber(0), capacity(0), status(TableStatus::AVAILABLE),
                 currentCustomerId(""), timeOccupiedMinutes(0), location("") {}

Table::Table(int number, int cap, const std::string& loc)
    : tableNumber(number), capacity(cap), status(TableStatus::AVAILABLE),
      currentCustomerId(""), timeOccupiedMinutes(0), location(loc) {}

void Table::occupyTable(const std::string& customerId) {
    status = TableStatus::OCCUPIED;
    currentCustomerId = customerId;
    timeOccupiedMinutes = 0;
}

void Table::releaseTable() {
    status = TableStatus::AVAILABLE;
    currentCustomerId = "";
    timeOccupiedMinutes = 0;
}

void Table::reserveTable(const std::string& customerId) {
    status = TableStatus::RESERVED;
    currentCustomerId = customerId;
}

void Table::setMaintenance() {
    status = TableStatus::MAINTENANCE;
}

std::string Table::getStatusString() const {
    switch (status) {
        case TableStatus::AVAILABLE: return "Available";
        case TableStatus::OCCUPIED: return "Occupied";
        case TableStatus::RESERVED: return "Reserved";
        case TableStatus::MAINTENANCE: return "Maintenance";
        default: return "Unknown";
    }
}

void Table::displayInfo() const {
    std::cout << "Table " << tableNumber << " (" << location << ") | "
              << "Capacity: " << capacity << " | "
              << "Status: " << getStatusString();
    if (!currentCustomerId.empty()) {
        std::cout << " | Customer: " << currentCustomerId;
    }
    std::cout << std::endl;
}
