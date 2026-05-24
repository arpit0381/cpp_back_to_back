#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

class Customer {
private:
    std::string customerId;
    std::string name;
    std::string phoneNumber;
    std::string email;
    int totalVisits;
    int loyaltyPoints;
    double totalSpending;
    bool isVIP;

public:
    Customer();
    Customer(const std::string& id, const std::string& name,
             const std::string& phone, const std::string& email);

    // Getters
    std::string getCustomerId() const { return customerId; }
    std::string getName() const { return name; }
    std::string getPhoneNumber() const { return phoneNumber; }
    std::string getEmail() const { return email; }
    int getTotalVisits() const { return totalVisits; }
    int getLoyaltyPoints() const { return loyaltyPoints; }
    double getTotalSpending() const { return totalSpending; }
    bool getIsVIP() const { return isVIP; }

    // Setters
    void setPhoneNumber(const std::string& phone) { phoneNumber = phone; }
    void setEmail(const std::string& e) { email = e; }

    // Methods
    void recordVisit(double spendAmount);
    void addLoyaltyPoints(int points);
    void redeemLoyaltyPoints(int points);
    void checkVIPStatus();

    // Display
    void displayInfo() const;
};

#endif
