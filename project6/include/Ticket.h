#ifndef TICKET_H
#define TICKET_H

#include <string>
#include <ctime>
#include "Showtime.h"

enum class TicketStatus {
    VALID,
    USED,
    CANCELLED,
    EXPIRED
};

class Ticket {
private:
    std::string ticketId;
    std::string customerId;
    std::string showtimeId;
    int seatRow;
    int seatColumn;
    double price;
    TicketStatus status;
    std::time_t bookingTime;
    std::time_t expiryTime;

public:
    Ticket();
    Ticket(const std::string& tId, const std::string& cId,
           const std::string& sId, int row, int col, double p);

    // Getters
    std::string getTicketId() const { return ticketId; }
    std::string getCustomerId() const { return customerId; }
    std::string getShowtimeId() const { return showtimeId; }
    int getSeatRow() const { return seatRow; }
    int getSeatColumn() const { return seatColumn; }
    double getPrice() const { return price; }
    TicketStatus getStatus() const { return status; }
    std::string getStatusString() const;

    // Setters
    void setStatus(TicketStatus s) { status = s; }

    // Methods
    bool validateTicket();
    bool useTicket();
    bool cancelTicket();
    bool isExpired() const;

    // Display
    void displayInfo() const;
};

#endif
