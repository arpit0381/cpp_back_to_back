#ifndef BOOKING_H
#define BOOKING_H

#include <string>
#include <vector>
#include <ctime>
#include "Ticket.h"

enum class BookingStatus {
    PENDING,
    CONFIRMED,
    CANCELLED,
    COMPLETED
};

class Booking {
private:
    std::string bookingId;
    std::string customerId;
    std::vector<Ticket> tickets;
    double totalAmount;
    BookingStatus status;
    std::time_t bookingDateTime;
    std::string paymentMethod;

public:
    Booking();
    Booking(const std::string& bId, const std::string& cId);

    // Getters
    std::string getBookingId() const { return bookingId; }
    std::string getCustomerId() const { return customerId; }
    double getTotalAmount() const { return totalAmount; }
    BookingStatus getStatus() const { return status; }
    int getTicketCount() const { return tickets.size(); }
    std::string getPaymentMethod() const { return paymentMethod; }

    // Ticket Management
    void addTicket(const Ticket& ticket);
    void removeTicket(int index);
    Ticket& getTicket(int index);
    const std::vector<Ticket>& getAllTickets() const { return tickets; }

    // Booking Operations
    void confirmBooking(const std::string& paymentMethod);
    void cancelBooking();
    void completeBooking();
    double calculateTotal();
    std::string getStatusString() const;

    // Display
    void displayInfo() const;
};

#endif
