#ifndef LIBRARYMANAGER_H
#define LIBRARYMANAGER_H

#include <vector>
#include <string>
#include "Book.h"
#include "Member.h"

class LibraryManager {
private:
    std::vector<Book> books;
    std::vector<Member> members;
    int nextMemberId;

public:
    // Constructor
    LibraryManager();

    // Book operations
    void addBook(const std::string& isbn, const std::string& title, 
                 const std::string& author, int year, int copies);
    Book* findBookByISBN(const std::string& isbn);
    Book* findBookByTitle(const std::string& title);
    void displayAllBooks() const;

    // Member operations
    void registerMember(const std::string& name, const std::string& email);
    Member* findMemberById(int memberId);
    void displayAllMembers() const;

    // Transaction operations
    bool borrowBook(int memberId, const std::string& isbn);
    bool returnBook(int memberId, const std::string& isbn);

    // Library statistics
    void displayStatistics() const;
    int getTotalBooks() const;
    int getAvailableBooks() const;
};

#endif // LIBRARYMANAGER_H
