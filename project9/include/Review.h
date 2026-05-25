#ifndef REVIEW_H
#define REVIEW_H

#include <string>

class Review {
private:
    int reviewId;
    int bookingId;
    int guestId;
    int roomNumber;
    int rating;  // 1-5 stars
    std::string reviewText;
    std::string reviewDate;

public:
    Review();
    Review(int id, int bookingId, int guestId, int roomNumber, 
           int rating, const std::string& text);
    
    // Getters
    int getReviewId() const;
    int getBookingId() const;
    int getGuestId() const;
    int getRoomNumber() const;
    int getRating() const;
    std::string getReviewText() const;
    std::string getReviewDate() const;
    
    // Setters
    void setRating(int rating);
    void setReviewText(const std::string& text);
    void setReviewDate(const std::string& date);
    
    // Utilities
    bool isValidRating() const;
    void display() const;
};

#endif // REVIEW_H
