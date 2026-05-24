#include "../include/ParkingLot.h"
#include <iostream>

ParkingLot::ParkingLot(int levelCount, int spotsPerSize, double ratePerHour)
    : ratePerHour(ratePerHour) {
    for (int i = 1; i <= levelCount; ++i) levels.push_back(std::make_shared<ParkingLevel>(i, spotsPerSize));
}

int ParkingLot::parkVehicle(const std::shared_ptr<Vehicle> &vehicle) {
    for (auto &lvl : levels) {
        int spotId = -1;
        if (lvl->parkVehicle(vehicle, spotId)) {
            Ticket t(vehicle->getPlate(), spotId);
            int tid = t.getId();
            activeTickets[tid] = t;
            std::cout << "Parked " << vehicle->getPlate() << " at spot " << spotId << ", ticket " << tid << "\n";
            return tid;
        }
    }
    std::cout << "No available spots for vehicle " << vehicle->getPlate() << "\n";
    return -1;
}

double ParkingLot::leaveVehicle(int ticketId) {
    auto it = activeTickets.find(ticketId);
    if (it == activeTickets.end()) return -1.0;
    Ticket &t = it->second;
    t.setExitTime(std::time(nullptr));
    double fee = t.calculateFee(ratePerHour);
    // free the spot
    int spotId = t.getSpotId();
    for (auto &lvl : levels) {
        lvl->leaveSpot(spotId);
    }
    activeTickets.erase(it);
    std::cout << "Ticket " << ticketId << " paid " << fee << "\n";
    return fee;
}

void ParkingLot::displayStatus() const {
    for (auto &lvl : levels) lvl->displayStatus();
    std::cout << "Active tickets: " << activeTickets.size() << "\n";
}
