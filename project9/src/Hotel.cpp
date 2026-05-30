#include "Hotel.h"
#include <iostream>
#include <algorithm>
//......
//.......

Hotel::Hotel(const std::string& name, const std::string& location)
    : hotelName(name), location(location), nextGuestId(1001), nextBookingId(1), 
      nextPaymentId(1), nextReviewId(1) {}

// Guest Management
void Hotel::registerGuest(const std::string& name, const std::string& email,
                         const std::string& phone, const std::string& address) {
    Guest newGuest(nextGuestId++, name, email, phone, address);
    guests.push_back(newGuest);
    std::cout << "Guest registered successfully. Guest ID: " << newGuest.getGuestId() << "\n";
}

Guest* Hotel::findGuest(int guestId) {
    for (auto& guest : guests) {
        if (guest.getGuestId() == guestId) {
            return &guest;
        }
    }
    return nullptr;
}

void Hotel::displayAllGuests() const {
    if (guests.empty()) {
        std::cout << "No guests registered.\n";
        return;
    }
    std::cout << "\n===== ALL GUESTS =====\n";
    for (const auto& guest : guests) {
        guest.display();
        std::cout << "---\n";
    }
}

// Room Management
void Hotel::addRoom(int number, RoomType type, double price, int capacity) {
    Room newRoom(number, type, price, capacity);
    rooms.push_back(newRoom);
    std::cout << "Room added successfully.\n";
}

Room* Hotel::findRoom(int roomNumber) {
    for (auto& room : rooms) {
        if (room.getRoomNumber() == roomNumber) {
            return &room;
        }
    }
    return nullptr;
}

std::vector<Room*> Hotel::getAvailableRooms() const {
    std::vector<Room*> available;
    for (auto& room : rooms) {
        if (room.isAvailable()) {
            available.push_back(const_cast<Room*>(&room));
        }
    }
    return available;
}

void Hotel::displayAllRooms() const {
    if (rooms.empty()) {
        std::cout << "No rooms in the hotel.\n";
        return;
    }
    std::cout << "\n===== ALL ROOMS =====\n";
    for (const auto& room : rooms) {
        room.display();
    }
}

// Booking Management
bool Hotel::createBooking(int guestId, int roomNumber, 
                         const std::string& checkIn, const std::string& checkOut) {
    Guest* guest = findGuest(guestId);
    Room* room = findRoom(roomNumber);
    
    if (!guest || !room) {
        std::cout << "Invalid guest ID or room number.\n";
        return false;
    }
    
    if (!room->isAvailable()) {
        std::cout << "Room is not available.\n";
        return false;
    }
    
    double cost = room->getPricePerNight() * 1;  // 1 night for simplicity
    Booking newBooking(nextBookingId++, guestId, roomNumber, checkIn, checkOut, cost);
    bookings.push_back(newBooking);
    
    room->setStatus(RoomStatus::OCCUPIED);
    guest->incrementStays();
    
    std::cout << "Booking created successfully. Booking ID: " << newBooking.getBookingId() << "\n";
    return true;
}

Booking* Hotel::findBooking(int bookingId) {
    for (auto& booking : bookings) {
        if (booking.getBookingId() == bookingId) {
            return &booking;
        }
    }
    return nullptr;
}

void Hotel::cancelBooking(int bookingId) {
    Booking* booking = findBooking(bookingId);
    if (booking) {
        booking->setIsActive(false);
        Room* room = findRoom(booking->getRoomNumber());
        if (room) {
            room->setStatus(RoomStatus::AVAILABLE);
        }
        std::cout << "Booking cancelled.\n";
    }
}

void Hotel::displayAllBookings() const {
    if (bookings.empty()) {
        std::cout << "No bookings found.\n";
        return;
    }
    std::cout << "\n===== ALL BOOKINGS =====\n";
    for (const auto& booking : bookings) {
        booking.display();
        std::cout << "---\n";
    }
}

// Payment Management
bool Hotel::processPayment(int bookingId, double amount, PaymentMethod method) {
    Booking* booking = findBooking(bookingId);
    if (!booking) {
        std::cout << "Booking not found.\n";
        return false;
    }
    
    Payment newPayment(nextPaymentId++, bookingId, amount, method);
    if (newPayment.processPayment()) {
        payments.push_back(newPayment);
        std::cout << "Payment processed successfully. Payment ID: " << newPayment.getPaymentId() << "\n";
        return true;
    }
    return false;
}

Payment* Hotel::findPayment(int paymentId) {
    for (auto& payment : payments) {
        if (payment.getPaymentId() == paymentId) {
            return &payment;
        }
    }
    return nullptr;
}

void Hotel::displayAllPayments() const {
    if (payments.empty()) {
        std::cout << "No payments found.\n";
        return;
    }
    std::cout << "\n===== ALL PAYMENTS =====\n";
    for (const auto& payment : payments) {
        payment.display();
        std::cout << "---\n";
    }
}

// Review Management
void Hotel::addReview(int bookingId, int guestId, int roomNumber, 
                     int rating, const std::string& text) {
    if (rating < 1 || rating > 5) {
        std::cout << "Invalid rating. Please use 1-5 stars.\n";
        return;
    }
    
    Review newReview(nextReviewId++, bookingId, guestId, roomNumber, rating, text);
    reviews.push_back(newReview);
    std::cout << "Review added successfully.\n";
}

double Hotel::getAverageRating() const {
    if (reviews.empty()) return 0;
    
    double sum = 0;
    for (const auto& review : reviews) {
        sum += review.getRating();
    }
    return sum / reviews.size();
}

void Hotel::displayAllReviews() const {
    if (reviews.empty()) {
        std::cout << "No reviews found.\n";
        return;
    }
    std::cout << "\n===== ALL REVIEWS =====\n";
    for (const auto& review : reviews) {
        review.display();
        std::cout << "---\n";
    }
}

// Analytics
double Hotel::calculateOccupancyRate() const {
    if (rooms.empty()) return 0;
    
    int occupied = 0;
    for (const auto& room : rooms) {
        if (room.getStatus() == RoomStatus::OCCUPIED) {
            occupied++;
        }
    }
    return (occupied * 100.0) / rooms.size();
}

double Hotel::calculateTotalRevenue() const {
    double revenue = 0;
    for (const auto& payment : payments) {
        if (payment.getStatus() == PaymentStatus::COMPLETED) {
            revenue += payment.getAmount();
        }
    }
    return revenue;
}

void Hotel::displayAnalytics() const {
    std::cout << "\n===== HOTEL ANALYTICS =====\n"
              << "Total Guests: " << guests.size() << "\n"
              << "Total Rooms: " << rooms.size() << "\n"
              << "Total Bookings: " << bookings.size() << "\n"
              << "Occupancy Rate: " << calculateOccupancyRate() << "%\n"
              << "Total Revenue: $" << calculateTotalRevenue() << "\n"
              << "Average Rating: " << getAverageRating() << "/5\n";
}

void Hotel::displayHotelInfo() const {
    std::cout << "\n===== " << hotelName << " =====\n"
              << "Location: " << location << "\n"
              << "Total Rooms: " << rooms.size() << "\n"
              << "Registered Guests: " << guests.size() << "\n";
}

//hhehhhhh....
