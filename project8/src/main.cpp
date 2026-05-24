#include <iostream>
#include <memory>
#include "../include/Vehicle.h"
#include "../include/ParkingLot.h"

int main() {
    ParkingLot lot(2, 5, 15.0); // 2 levels, 5 spots per size group, rate 15/hr

    auto v1 = std::make_shared<Vehicle>("ABC-123", VehicleSize::COMPACT);
    auto v2 = std::make_shared<Vehicle>("XYZ-999", VehicleSize::LARGE);

    int t1 = lot.parkVehicle(v1);
    int t2 = lot.parkVehicle(v2);

    lot.displayStatus();

    // simulate some time passing (sleep omitted for portability)

    if (t1 != -1) lot.leaveVehicle(t1);

    lot.displayStatus();
    return 0;
}
