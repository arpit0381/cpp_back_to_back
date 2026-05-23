#include "Member.h"
#include <iostream>
#include <algorithm>

Member::Member(int id, const std::string& name, const std::string& email)
    : memberId(id), name(name), email(email), maxBooksAllowed(5) {}

int Member::getMemberId() const {
    return memberId;
}

std::string Member::getName() const {
    return name;
}

std::string Member::getEmail() const {
    return email;
}

int Member::getBorrowedBooksCount() const {
    return borrowedBooks.size();
}

int Member::getMaxBooksAllowed() const {
    return maxBooksAllowed;
}

const std::vector<std::string>& Member::getBorrowedBooks() const {
    return borrowedBooks;
}

bool Member::borrowBook(const std::string& isbn) {
    if (canBorrowMore()) {
        borrowedBooks.push_back(isbn);
        return true;
    }
    return false;
}

bool Member::returnBook(const std::string& isbn) {
    auto it = std::find(borrowedBooks.begin(), borrowedBooks.end(), isbn);
    if (it != borrowedBooks.end()) {
        borrowedBooks.erase(it);
        return true;
    }
    return false;
}

bool Member::canBorrowMore() const {
    return borrowedBooks.size() < static_cast<size_t>(maxBooksAllowed);
}

void Member::displayInfo() const {
    std::cout << "\n--- Member Information ---\n";
    std::cout << "Member ID: " << memberId << "\n";
    std::cout << "Name: " << name << "\n";
    std::cout << "Email: " << email << "\n";
    std::cout << "Books Borrowed: " << borrowedBooks.size() << "/" << maxBooksAllowed << "\n";
    
    if (!borrowedBooks.empty()) {
        std::cout << "Borrowed Book ISBNs: ";
        for (const auto& isbn : borrowedBooks) {
            std::cout << isbn << " ";
        }
        std::cout << "\n";
    }
}
