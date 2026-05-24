#pragma once
#include <string>
#include <memory>
#include "Vehicle.h"

class ParkingSpot {
public:
    ParkingSpot(int id, VehicleSize size);
    int getId() const;
    VehicleSize getSize() const;
    bool isOccupied() const;
    bool park(std::shared_ptr<Vehicle> vehicle);
    void leave();
    std::string getOccupantPlate() const;
private:
    int id;
    VehicleSize size;
    std::shared_ptr<Vehicle> occupant;
};
