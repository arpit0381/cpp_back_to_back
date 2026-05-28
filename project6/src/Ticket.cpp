#include "../include/Ticket.h"
#include <iostream>
#include <ctime>
//start of the code 

Ticket::Ticket() : ticketId(""), customerId(""), showtimeId(""),
                   seatRow(0), seatColumn(0), price(0.0),
                   status(TicketStatus::VALID), bookingTime(0), expiryTime(0) {
    bookingTime = std::time(nullptr);
    expiryTime = bookingTime + (24 * 60 * 60);  // Valid for 24 hours
}

Ticket::Ticket(const std::string& tId, const std::string& cId,
               const std::string& sId, int row, int col, double p)
    : ticketId(tId), customerId(cId), showtimeId(sId),
      seatRow(row), seatColumn(col), price(p),
      status(TicketStatus::VALID) {
    bookingTime = std::time(nullptr);
    expiryTime = bookingTime + (24 * 60 * 60);
}

std::string Ticket::getStatusString() const {
    switch (status) {
        case TicketStatus::VALID: return "Valid";
        case TicketStatus::USED: return "Used";
        case TicketStatus::CANCELLED: return "Cancelled";
        case TicketStatus::EXPIRED: return "Expired";
        default: return "Unknown";
    }
}

bool Ticket::validateTicket() {
    if (isExpired()) {
        status = TicketStatus::EXPIRED;
        return false;
    }
    return status == TicketStatus::VALID;
}

bool Ticket::useTicket() {
    if (validateTicket()) {
        status = TicketStatus::USED;
        return true;
    }
    return false;
}

bool Ticket::cancelTicket() {
    if (status == TicketStatus::VALID) {
        status = TicketStatus::CANCELLED;
        return true;
    }
    return false;
}

bool Ticket::isExpired() const {
    return std::time(nullptr) > expiryTime;
}

void Ticket::displayInfo() const {
    std::cout << "\n=== TICKET INFORMATION ===" << std::endl;
    std::cout << "Ticket ID: " << ticketId << std::endl;
    std::cout << "Customer ID: " << customerId << std::endl;
    std::cout << "Showtime ID: " << showtimeId << std::endl;
    std::cout << "Seat: " << (char)('A' + seatRow) << (seatColumn + 1) << std::endl;
    std::cout << "Price: ₹" << price << std::endl;
    std::cout << "Status: " << getStatusString() << std::endl;
    std::cout << "==========================\n" << std::endl;
}
