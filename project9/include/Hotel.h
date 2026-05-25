#ifndef HOTEL_H
#define HOTEL_H

#include "Guest.h"
#include "Room.h"
#include "Booking.h"
#include "Payment.h"
#include "Review.h"
#include <vector>
#include <string>

class Hotel {
private:
    std::string hotelName;
    std::string location;
    std::vector<Guest> guests;
    std::vector<Room> rooms;
    std::vector<Booking> bookings;
    std::vector<Payment> payments;
    std::vector<Review> reviews;
    
    int nextGuestId;
    int nextBookingId;
    int nextPaymentId;
    int nextReviewId;

public:
    Hotel(const std::string& name, const std::string& location);
    
    // Guest Management
    void registerGuest(const std::string& name, const std::string& email,
                      const std::string& phone, const std::string& address);
    Guest* findGuest(int guestId);
    void displayAllGuests() const;
    
    // Room Management
    void addRoom(int number, RoomType type, double price, int capacity);
    Room* findRoom(int roomNumber);
    std::vector<Room*> getAvailableRooms() const;
    void displayAllRooms() const;
    
    // Booking Management
    bool createBooking(int guestId, int roomNumber, 
                      const std::string& checkIn, const std::string& checkOut);
    Booking* findBooking(int bookingId);
    void cancelBooking(int bookingId);
    void displayAllBookings() const;
    
    // Payment Management
    bool processPayment(int bookingId, double amount, PaymentMethod method);
    Payment* findPayment(int paymentId);
    void displayAllPayments() const;
    
    // Review Management
    void addReview(int bookingId, int guestId, int roomNumber, 
                  int rating, const std::string& text);
    double getAverageRating() const;
    void displayAllReviews() const;
    
    // Analytics
    double calculateOccupancyRate() const;
    double calculateTotalRevenue() const;
    void displayAnalytics() const;
    
    // General
    void displayHotelInfo() const;
};

#endif // HOTEL_H
