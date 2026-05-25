#ifndef GUEST_H
#define GUEST_H

#include <string>

class Guest {
private:
    int guestId;
    std::string name;
    std::string email;
    std::string phoneNumber;
    std::string address;
    int totalStays;

public:
    Guest();
    Guest(int id, const std::string& name, const std::string& email, 
          const std::string& phone, const std::string& address);
    
    // Getters
    int getGuestId() const;
    std::string getName() const;
    std::string getEmail() const;
    std::string getPhoneNumber() const;
    std::string getAddress() const;
    int getTotalStays() const;
    
    // Setters
    void setEmail(const std::string& email);
    void setPhoneNumber(const std::string& phone);
    void setAddress(const std::string& address);
    void incrementStays();
    
    // Display
    void display() const;
};

#endif // GUEST_H
