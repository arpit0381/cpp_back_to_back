#pragma once
#include <vector>
#include <map>
#include <memory>
#include "ParkingLevel.h"
#include "Ticket.h"

class ParkingLot {
public:
    ParkingLot(int levels, int spotsPerSize, double ratePerHour = 20.0);
    int parkVehicle(const std::shared_ptr<Vehicle> &vehicle);
    double leaveVehicle(int ticketId);
    void displayStatus() const;
private:
    std::vector<std::shared_ptr<ParkingLevel>> levels;
    std::map<int, Ticket> activeTickets;
    double ratePerHour;
};
