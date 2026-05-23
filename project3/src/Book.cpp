#include "Book.h"
#include <iostream>

Book::Book(const std::string& isbn, const std::string& title, 
           const std::string& author, int year, int copies)
    : isbn(isbn), title(title), author(author), yearPublished(year),
      availableCopies(copies), totalCopies(copies) {}

std::string Book::getISBN() const {
    return isbn;
}

std::string Book::getTitle() const {
    return title;
}

std::string Book::getAuthor() const {
    return author;
}

int Book::getYearPublished() const {
    return yearPublished;
}

int Book::getAvailableCopies() const {
    return availableCopies;
}

int Book::getTotalCopies() const {
    return totalCopies;
}

bool Book::borrowBook() {
    if (availableCopies > 0) {
        availableCopies--;
        return true;
    }
    return false;
}

bool Book::returnBook() {
    if (availableCopies < totalCopies) {
        availableCopies++;
        return true;
    }
    return false;
}

bool Book::isAvailable() const {
    return availableCopies > 0;
}

void Book::displayInfo() const {
    std::cout << "\n--- Book Information ---\n";
    std::cout << "ISBN: " << isbn << "\n";
    std::cout << "Title: " << title << "\n";
    std::cout << "Author: " << author << "\n";
    std::cout << "Year Published: " << yearPublished << "\n";
    std::cout << "Available Copies: " << availableCopies << "/" << totalCopies << "\n";
}
