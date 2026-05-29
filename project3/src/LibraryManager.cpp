#include "LibraryManager.h"
#include <iostream>
#include <algorithm>
//just a 

LibraryManager::LibraryManager() : nextMemberId(1001) {}

void LibraryManager::addBook(const std::string& isbn, const std::string& title,
                             const std::string& author, int year, int copies) {
    books.emplace_back(isbn, title, author, year, copies);
    std::cout << "Book added successfully!\n";
}

Book* LibraryManager::findBookByISBN(const std::string& isbn) {
    for (auto& book : books) {
        if (book.getISBN() == isbn) {
            return &book;
        }
    }
    return nullptr;
}

Book* LibraryManager::findBookByTitle(const std::string& title) {
    for (auto& book : books) {
        if (book.getTitle() == title) {
            return &book;
        }
    }
    return nullptr;
}

void LibraryManager::displayAllBooks() const {
    if (books.empty()) {
        std::cout << "No books in the library.\n";
        return;
    }
    std::cout << "\n=== All Books in Library ===\n";
    for (const auto& book : books) {
        book.displayInfo();
    }
}

void LibraryManager::registerMember(const std::string& name, const std::string& email) {
    members.emplace_back(nextMemberId, name, email);
    std::cout << "Member registered successfully! Member ID: " << nextMemberId << "\n";
    nextMemberId++;
}

Member* LibraryManager::findMemberById(int memberId) {
    for (auto& member : members) {
        if (member.getMemberId() == memberId) {
            return &member;
        }
    }
    return nullptr;
}

void LibraryManager::displayAllMembers() const {
    if (members.empty()) {
        std::cout << "No members registered.\n";
        return;
    }
    std::cout << "\n=== All Members ===\n";
    for (const auto& member : members) {
        member.displayInfo();
    }
}

bool LibraryManager::borrowBook(int memberId, const std::string& isbn) {
    Member* member = findMemberById(memberId);
    Book* book = findBookByISBN(isbn);

    if (!member) {
        std::cout << "Member not found!\n";
        return false;
    }

    if (!book) {
        std::cout << "Book not found!\n";
        return false;
    }

    if (!book->isAvailable()) {
        std::cout << "Book is not available!\n";
        return false;
    }

    if (!member->canBorrowMore()) {
        std::cout << "Member has reached maximum borrowing limit!\n";
        return false;
    }

    if (book->borrowBook() && member->borrowBook(isbn)) {
        std::cout << "Book borrowed successfully!\n";
        return true;
    }

    return false;
}

bool LibraryManager::returnBook(int memberId, const std::string& isbn) {
    Member* member = findMemberById(memberId);
    Book* book = findBookByISBN(isbn);

    if (!member) {
        std::cout << "Member not found!\n";
        return false;
    }

    if (!book) {
        std::cout << "Book not found!\n";
        return false;
    }

    if (book->returnBook() && member->returnBook(isbn)) {
        std::cout << "Book returned successfully!\n";
        return true;
    }

    std::cout << "Return failed - member didn't borrow this book!\n";
    return false;
}

void LibraryManager::displayStatistics() const {
    std::cout << "\n=== Library Statistics ===\n";
    std::cout << "Total Books: " << getTotalBooks() << "\n";
    std::cout << "Available Books: " << getAvailableBooks() << "\n";
    std::cout << "Total Members: " << members.size() << "\n";
}

int LibraryManager::getTotalBooks() const {
    return books.size();
}

int LibraryManager::getAvailableBooks() const {
    int count = 0;
    for (const auto& book : books) {
        if (book.isAvailable()) {
            count++;
        }
    }
    return count;
}
//end of the code 
//hehe
