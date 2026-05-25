#include "Guest.h"
#include <iostream>

Guest::Guest() : guestId(0), name(""), email(""), phoneNumber(""), address(""), totalStays(0) {}

Guest::Guest(int id, const std::string& name, const std::string& email, 
             const std::string& phone, const std::string& address)
    : guestId(id), name(name), email(email), phoneNumber(phone), 
      address(address), totalStays(0) {}

int Guest::getGuestId() const { return guestId; }
std::string Guest::getName() const { return name; }
std::string Guest::getEmail() const { return email; }
std::string Guest::getPhoneNumber() const { return phoneNumber; }
std::string Guest::getAddress() const { return address; }
int Guest::getTotalStays() const { return totalStays; }

void Guest::setEmail(const std::string& email) { this->email = email; }
void Guest::setPhoneNumber(const std::string& phone) { this->phoneNumber = phone; }
void Guest::setAddress(const std::string& address) { this->address = address; }
void Guest::incrementStays() { totalStays++; }

void Guest::display() const {
    std::cout << "Guest ID: " << guestId << "\n"
              << "Name: " << name << "\n"
              << "Email: " << email << "\n"
              << "Phone: " << phoneNumber << "\n"
              << "Address: " << address << "\n"
              << "Total Stays: " << totalStays << "\n";
}
