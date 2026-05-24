#include "../include/ParkingSpot.h"

ParkingSpot::ParkingSpot(int id, VehicleSize size)
    : id(id), size(size), occupant(nullptr) {}

int ParkingSpot::getId() const { return id; }

VehicleSize ParkingSpot::getSize() const { return size; }

bool ParkingSpot::isOccupied() const { return occupant != nullptr; }

bool ParkingSpot::park(std::shared_ptr<Vehicle> vehicle) {
    if (isOccupied()) return false;
    // simple size check: allow equal or larger spot
    if (static_cast<int>(vehicle->getSize()) > static_cast<int>(size)) return false;
    occupant = vehicle;
    return true;
}

void ParkingSpot::leave() { occupant = nullptr; }

std::string ParkingSpot::getOccupantPlate() const {
    return occupant ? occupant->getPlate() : std::string();
}
