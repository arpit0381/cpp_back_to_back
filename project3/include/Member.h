#ifndef MEMBER_H
#define MEMBER_H

#include <string>
#include <vector>

class Member {
private:
    int memberId;
    std::string name;
    std::string email;
    std::vector<std::string> borrowedBooks; // Store ISBNs of borrowed books
    int maxBooksAllowed;

public:
    // Constructor
    Member(int id, const std::string& name, const std::string& email);

    // Getters
    int getMemberId() const;
    std::string getName() const;
    std::string getEmail() const;
    int getBorrowedBooksCount() const;
    int getMaxBooksAllowed() const;
    const std::vector<std::string>& getBorrowedBooks() const;

    // Member operations
    bool borrowBook(const std::string& isbn);
    bool returnBook(const std::string& isbn);
    bool canBorrowMore() const;
    void displayInfo() const;
};

#endif // MEMBER_H
