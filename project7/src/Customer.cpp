#include "../include/Customer.h"
#include <iostream>
#include <iomanip>

Customer::Customer() : customerId(""), name(""), phoneNumber(""), email(""),
                       totalVisits(0), loyaltyPoints(0), totalSpending(0.0),
                       isVIP(false) {}

Customer::Customer(const std::string& id, const std::string& name,
                   const std::string& phone, const std::string& email)
    : customerId(id), name(name), phoneNumber(phone), email(email),
      totalVisits(0), loyaltyPoints(0), totalSpending(0.0), isVIP(false) {}

void Customer::recordVisit(double spendAmount) {
    totalVisits++;
    totalSpending += spendAmount;
    addLoyaltyPoints(static_cast<int>(spendAmount / 10));  // 1 point per 10 rupees
    checkVIPStatus();
}

void Customer::addLoyaltyPoints(int points) {
    loyaltyPoints += points;
}

void Customer::redeemLoyaltyPoints(int points) {
    if (loyaltyPoints >= points) {
        loyaltyPoints -= points;
    }
}

void Customer::checkVIPStatus() {
    isVIP = (totalVisits >= 10 || totalSpending >= 5000.0);
}

void Customer::displayInfo() const {
    std::cout << "Customer: " << name << " (" << customerId << ")" << std::endl;
    std::cout << "Phone: " << phoneNumber << " | Email: " << email << std::endl;
    std::cout << "Visits: " << totalVisits << " | Total Spend: ₹" << std::fixed
              << std::setprecision(2) << totalSpending << std::endl;
    std::cout << "Loyalty Points: " << loyaltyPoints << (isVIP ? " [VIP]" : "") << std::endl;
}
