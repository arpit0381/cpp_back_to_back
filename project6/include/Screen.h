#ifndef SCREEN_H
#define SCREEN_H

#include <string>
#include <vector>
#include "Seat.h"

class Screen {
private:
    std::string screenId;
    std::string screenName;
    int totalRows;
    int totalColumns;
    std::vector<std::vector<Seat>> seatMap;
    double screenQuality;  // 2D, IMAX, 4DX, etc. - represented as multiplier
    bool is3D;
    int totalSeats;
    int availableSeats;

public:
    Screen();
    Screen(const std::string& id, const std::string& name, int rows, int cols,
           double quality = 1.0, bool threeDee = false);

    // Getters
    std::string getScreenId() const { return screenId; }
    std::string getScreenName() const { return screenName; }
    int getTotalRows() const { return totalRows; }
    int getTotalColumns() const { return totalColumns; }
    int getTotalSeats() const { return totalSeats; }
    int getAvailableSeats() const { return availableSeats; }
    double getScreenQuality() const { return screenQuality; }
    bool getIs3D() const { return is3D; }

    // Seat Management
    void initializeSeats(double basePrice);
    Seat& getSeat(int row, int col);
    bool bookSeat(int row, int col);
    bool releaseSeat(int row, int col);
    bool isValidSeat(int row, int col) const;
    int getOccupancyPercentage() const;

    // Display
    void displaySeatMap() const;
    void displayInfo() const;
};

#endif
