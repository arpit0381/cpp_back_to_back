#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {
private:
    std::string isbn;
    std::string title;
    std::string author;
    int yearPublished;
    int availableCopies;
    int totalCopies;

public:
    // Constructor
    Book(const std::string& isbn, const std::string& title, 
         const std::string& author, int year, int copies);

    // Getters
    std::string getISBN() const;
    std::string getTitle() const;
    std::string getAuthor() const;
    int getYearPublished() const;
    int getAvailableCopies() const;
    int getTotalCopies() const;

    // Book operations
    bool borrowBook();
    bool returnBook();
    void displayInfo() const;
    bool isAvailable() const;
};

#endif // BOOK_H
