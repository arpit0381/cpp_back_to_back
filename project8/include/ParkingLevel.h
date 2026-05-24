#pragma once
#include <vector>
#include <memory>
#include "ParkingSpot.h"
#include "Vehicle.h"

class ParkingLevel {
public:
    ParkingLevel(int levelNumber, int spotsPerSize);
    int getLevelNumber() const;
    int findAvailableSpot(VehicleSize size) const;
    bool parkVehicle(std::shared_ptr<Vehicle> vehicle, int &outSpotId);
    void leaveSpot(int spotId);
    void displayStatus() const;
private:
    int levelNumber;
    std::vector<std::shared_ptr<ParkingSpot>> spots;
};
