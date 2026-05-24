#include "../include/ParkingLevel.h"
#include <iostream>

ParkingLevel::ParkingLevel(int levelNumber, int spotsPerSize)
    : levelNumber(levelNumber) {
    // create spots: compact, regular, large groups
    int id = levelNumber * 100;
    for (int i = 0; i < spotsPerSize; ++i) spots.push_back(std::make_shared<ParkingSpot>(id++, VehicleSize::COMPACT));
    for (int i = 0; i < spotsPerSize; ++i) spots.push_back(std::make_shared<ParkingSpot>(id++, VehicleSize::REGULAR));
    for (int i = 0; i < spotsPerSize; ++i) spots.push_back(std::make_shared<ParkingSpot>(id++, VehicleSize::LARGE));
}

int ParkingLevel::getLevelNumber() const { return levelNumber; }

int ParkingLevel::findAvailableSpot(VehicleSize size) const {
    for (auto &s : spots) {
        if (!s->isOccupied() && static_cast<int>(s->getSize()) >= static_cast<int>(size)) return s->getId();
    }
    return -1;
}

bool ParkingLevel::parkVehicle(std::shared_ptr<Vehicle> vehicle, int &outSpotId) {
    for (auto &s : spots) {
        if (!s->isOccupied() && static_cast<int>(s->getSize()) >= static_cast<int>(vehicle->getSize())) {
            if (s->park(vehicle)) { outSpotId = s->getId(); return true; }
        }
    }
    return false;
}

void ParkingLevel::leaveSpot(int spotId) {
    for (auto &s : spots) if (s->getId() == spotId) { s->leave(); return; }
}

void ParkingLevel::displayStatus() const {
    int freeCount = 0;
    for (auto &s : spots) if (!s->isOccupied()) ++freeCount;
    std::cout << "Level " << levelNumber << ": " << freeCount << " free of " << spots.size() << " spots\n";
}
