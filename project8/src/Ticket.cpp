#include "../include/Ticket.h"

int Ticket::nextId = 1;

Ticket::Ticket(const std::string &vehiclePlate, int spotId)
    : id(nextId++), vehiclePlate(vehiclePlate), spotId(spotId) {
    entryTime = std::time(nullptr);
    exitTime = 0;
}

int Ticket::getId() const { return id; }

std::string Ticket::getVehiclePlate() const { return vehiclePlate; }

int Ticket::getSpotId() const { return spotId; }

std::time_t Ticket::getEntryTime() const { return entryTime; }

void Ticket::setExitTime(std::time_t t) { exitTime = t; }

double Ticket::getHoursParked() const {
    std::time_t end = exitTime ? exitTime : std::time(nullptr);
    double seconds = std::difftime(end, entryTime);
    return seconds / 3600.0;
}

double Ticket::calculateFee(double ratePerHour) const {
    double hours = getHoursParked();
    if (hours < 1.0) hours = 1.0; // minimum charge
    return hours * ratePerHour;
}
