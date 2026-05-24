#ifndef KITCHENTICKET_H
#define KITCHENTICKET_H

#include <string>
#include <vector>
#include <ctime>

enum class TicketStatus {
    RECEIVED,
    ACKNOWLEDGED,
    COOKING,
    COMPLETED,
    CANCELLED
};

class KitchenTicket {
private:
    std::string ticketId;
    std::string orderId;
    int tableNumber;
    std::vector<std::string> itemDescriptions;
    std::vector<int> quantities;
    TicketStatus status;
    std::time_t receivedTime;
    std::time_t completedTime;
    std::string kitchenStaffName;

public:
    KitchenTicket();
    KitchenTicket(const std::string& tId, const std::string& oId, int tableNum);

    // Getters
    std::string getTicketId() const { return ticketId; }
    std::string getOrderId() const { return orderId; }
    int getTableNumber() const { return tableNumber; }
    TicketStatus getStatus() const { return status; }
    std::string getKitchenStaffName() const { return kitchenStaffName; }

    // Methods
    void addItem(const std::string& description, int quantity);
    void acknowledgeTicket(const std::string& staffName);
    void startCooking();
    void markComplete();
    void cancelTicket();
    int getElapsedTimeSeconds() const;
    std::string getStatusString() const;

    // Display
    void displayTicket() const;
};

#endif
