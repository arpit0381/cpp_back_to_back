#include "Review.h"
#include <iostream>
#include <ctime>

Review::Review() : reviewId(0), bookingId(0), guestId(0), roomNumber(0), 
                   rating(0), reviewText(""), reviewDate("") {}

Review::Review(int id, int bookingId, int guestId, int roomNumber, 
               int rating, const std::string& text)
    : reviewId(id), bookingId(bookingId), guestId(guestId), 
      roomNumber(roomNumber), rating(rating), reviewText(text) {
    // Set current date
    time_t now = time(0);
    tm* timeinfo = localtime(&now);
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", timeinfo);
    reviewDate = buffer;
}

int Review::getReviewId() const { return reviewId; }
int Review::getBookingId() const { return bookingId; }
int Review::getGuestId() const { return guestId; }
int Review::getRoomNumber() const { return roomNumber; }
int Review::getRating() const { return rating; }
std::string Review::getReviewText() const { return reviewText; }
std::string Review::getReviewDate() const { return reviewDate; }

void Review::setRating(int rating) { 
    if (rating >= 1 && rating <= 5) {
        this->rating = rating;
    }
}

void Review::setReviewText(const std::string& text) { this->reviewText = text; }
void Review::setReviewDate(const std::string& date) { this->reviewDate = date; }

bool Review::isValidRating() const {
    return rating >= 1 && rating <= 5;
}

void Review::display() const {
    std::cout << "Review ID: " << reviewId << "\n"
              << "Guest ID: " << guestId << "\n"
              << "Room #" << roomNumber << "\n"
              << "Rating: " << rating << "/5 stars\n"
              << "Review: " << reviewText << "\n"
              << "Date: " << reviewDate << "\n";
}
