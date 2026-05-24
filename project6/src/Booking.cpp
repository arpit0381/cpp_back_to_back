#include "../include/Booking.h"
#include <iostream>
#include <iomanip>

Booking::Booking() : bookingId(""), customerId(""), totalAmount(0.0),
                     status(BookingStatus::PENDING), bookingDateTime(0),
                     paymentMethod("") {
    bookingDateTime = std::time(nullptr);
}

Booking::Booking(const std::string& bId, const std::string& cId)
    : bookingId(bId), customerId(cId), totalAmount(0.0),
      status(BookingStatus::PENDING), paymentMethod("") {
    bookingDateTime = std::time(nullptr);
}

void Booking::addTicket(const Ticket& ticket) {
    tickets.push_back(ticket);
    totalAmount += ticket.getPrice();
}

void Booking::removeTicket(int index) {
    if (index >= 0 && index < static_cast<int>(tickets.size())) {
        totalAmount -= tickets[index].getPrice();
        tickets.erase(tickets.begin() + index);
    }
}

Ticket& Booking::getTicket(int index) {
    if (index >= 0 && index < static_cast<int>(tickets.size())) {
        return tickets[index];
    }
    throw std::out_of_range("Invalid ticket index");
}

void Booking::confirmBooking(const std::string& method) {
    status = BookingStatus::CONFIRMED;
    paymentMethod = method;
}

void Booking::cancelBooking() {
    if (status == BookingStatus::PENDING || status == BookingStatus::CONFIRMED) {
        status = BookingStatus::CANCELLED;
    }
}

void Booking::completeBooking() {
    status = BookingStatus::COMPLETED;
}

double Booking::calculateTotal() {
    totalAmount = 0.0;
    for (const auto& ticket : tickets) {
        totalAmount += ticket.getPrice();
    }
    return totalAmount;
}

std::string Booking::getStatusString() const {
    switch (status) {
        case BookingStatus::PENDING: return "Pending";
        case BookingStatus::CONFIRMED: return "Confirmed";
        case BookingStatus::CANCELLED: return "Cancelled";
        case BookingStatus::COMPLETED: return "Completed";
        default: return "Unknown";
    }
}

void Booking::displayInfo() const {
    std::cout << "\n=== BOOKING INFORMATION ===" << std::endl;
    std::cout << "Booking ID: " << bookingId << std::endl;
    std::cout << "Customer ID: " << customerId << std::endl;
    std::cout << "Total Tickets: " << tickets.size() << std::endl;
    std::cout << "Total Amount: ₹" << std::fixed << std::setprecision(2) << totalAmount << std::endl;
    std::cout << "Status: " << getStatusString() << std::endl;
    std::cout << "Payment Method: " << (paymentMethod.empty() ? "Not specified" : paymentMethod) << std::endl;
    
    std::cout << "\nTickets:" << std::endl;
    for (size_t i = 0; i < tickets.size(); ++i) {
        std::cout << "  " << (i + 1) << ". " << tickets[i].getTicketId() << " - "
                  << tickets[i].getStatusString() << std::endl;
    }
    std::cout << "===========================\n" << std::endl;
}
