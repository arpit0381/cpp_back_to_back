#ifndef TABLE_H
#define TABLE_H

#include <string>

enum class TableStatus {
    AVAILABLE,
    OCCUPIED,
    RESERVED,
    MAINTENANCE
};

class Table {
private:
    int tableNumber;
    int capacity;
    TableStatus status;
    std::string currentCustomerId;
    int timeOccupiedMinutes;
    std::string location;  // e.g., "Window", "Corner", "Center"

public:
    Table();
    Table(int number, int cap, const std::string& loc);

    // Getters
    int getTableNumber() const { return tableNumber; }
    int getCapacity() const { return capacity; }
    TableStatus getStatus() const { return status; }
    std::string getCurrentCustomerId() const { return currentCustomerId; }
    int getTimeOccupiedMinutes() const { return timeOccupiedMinutes; }
    std::string getLocation() const { return location; }

    // Setters
    void setStatus(TableStatus s) { status = s; }
    void setCurrentCustomerId(const std::string& id) { currentCustomerId = id; }
    void setTimeOccupiedMinutes(int time) { timeOccupiedMinutes = time; }

    // Methods
    bool isAvailable() const { return status == TableStatus::AVAILABLE; }
    void occupyTable(const std::string& customerId);
    void releaseTable();
    void reserveTable(const std::string& customerId);
    void setMaintenance();
    std::string getStatusString() const;

    // Display
    void displayInfo() const;
};

#endif
