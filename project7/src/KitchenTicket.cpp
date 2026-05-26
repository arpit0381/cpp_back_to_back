#include "../include/KitchenTicket.h"
#include <iostream>
#include <iomanip>
#include <ctime>
//Start of the program.

KitchenTicket::KitchenTicket() : ticketId(""), orderId(""), tableNumber(0),
                                 status(TicketStatus::RECEIVED), receivedTime(0),
                                 completedTime(0), kitchenStaffName("") {
    receivedTime = std::time(nullptr);
}

KitchenTicket::KitchenTicket(const std::string& tId, const std::string& oId, int tableNum)
    : ticketId(tId), orderId(oId), tableNumber(tableNum), status(TicketStatus::RECEIVED),
      completedTime(0), kitchenStaffName("") {
    receivedTime = std::time(nullptr);
}

void KitchenTicket::addItem(const std::string& description, int quantity) {
    itemDescriptions.push_back(description);
    quantities.push_back(quantity);
}

void KitchenTicket::acknowledgeTicket(const std::string& staffName) {
    status = TicketStatus::ACKNOWLEDGED;
    kitchenStaffName = staffName;
}

void KitchenTicket::startCooking() {
    status = TicketStatus::COOKING;
}

void KitchenTicket::markComplete() {
    status = TicketStatus::COMPLETED;
    completedTime = std::time(nullptr);
}

void KitchenTicket::cancelTicket() {
    status = TicketStatus::CANCELLED;
}

int KitchenTicket::getElapsedTimeSeconds() const {
    if (completedTime > 0) {
        return static_cast<int>(difftime(completedTime, receivedTime));
    }
    return static_cast<int>(difftime(std::time(nullptr), receivedTime));
}

std::string KitchenTicket::getStatusString() const {
    switch (status) {
        case TicketStatus::RECEIVED: return "Received";
        case TicketStatus::ACKNOWLEDGED: return "Acknowledged";
        case TicketStatus::COOKING: return "Cooking";
        case TicketStatus::COMPLETED: return "Completed";
        case TicketStatus::CANCELLED: return "Cancelled";
        default: return "Unknown";
    }
}

void KitchenTicket::displayTicket() const {
    std::cout << "\n" << std::string(50, '-') << std::endl;
    std::cout << "KITCHEN TICKET: " << ticketId << std::endl;
    std::cout << "Order ID: " << orderId << " | Table: " << tableNumber << std::endl;
    std::cout << "Status: " << getStatusString();
    if (!kitchenStaffName.empty()) {
        std::cout << " | Staff: " << kitchenStaffName;
    }
    std::cout << std::endl;
    std::cout << "Time: " << (getElapsedTimeSeconds() / 60) << "m " << (getElapsedTimeSeconds() % 60) << "s" << std::endl;
    std::cout << std::string(50, '-') << std::endl;
    
    for (size_t i = 0; i < itemDescriptions.size(); ++i) {
        std::cout << "• " << itemDescriptions[i] << " x" << quantities[i] << std::endl;
    }
    std::cout << std::string(50, '-') << "\n" << std::endl;
}
//end of the code 
//cpp official 
