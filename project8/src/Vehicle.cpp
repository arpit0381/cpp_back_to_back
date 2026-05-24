#include "../include/Vehicle.h"

Vehicle::Vehicle(const std::string &plate, VehicleSize size)
    : plate(plate), size(size) {}

std::string Vehicle::getPlate() const { return plate; }

VehicleSize Vehicle::getSize() const { return size; }
