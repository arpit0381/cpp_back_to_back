#pragma once
#include <string>
#include <ctime>

class Ticket {
public:
    Ticket(const std::string &vehiclePlate, int spotId);
    int getId() const;
    std::string getVehiclePlate() const;
    int getSpotId() const;
    std::time_t getEntryTime() const;
    void setExitTime(std::time_t t);
    double getHoursParked() const;
    double calculateFee(double ratePerHour) const;
private:
    int id;
    std::string vehiclePlate;
    int spotId;
    std::time_t entryTime;
    std::time_t exitTime;
    static int nextId;
};
