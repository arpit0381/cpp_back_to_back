#pragma once
#include <string>

enum class VehicleSize { COMPACT, REGULAR, LARGE };

class Vehicle {
public:
    Vehicle(const std::string &plate, VehicleSize size);
    std::string getPlate() const;
    VehicleSize getSize() const;
private:
    std::string plate;
    VehicleSize size;
};
