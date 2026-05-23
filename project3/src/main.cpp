#include "LibraryManager.h"
#include <iostream>
#include <string>

void displayMenu() {
    std::cout << "\n========== Library Management System ==========\n";
    std::cout << "1. Add Book\n";
    std::cout << "2. Register Member\n";
    std::cout << "3. Borrow Book\n";
    std::cout << "4. Return Book\n";
    std::cout << "5. Display All Books\n";
    std::cout << "6. Display All Members\n";
    std::cout << "7. Library Statistics\n";
    std::cout << "8. Exit\n";
    std::cout << "===============================================\n";
    std::cout << "Enter your choice: ";
}

int main() {
    LibraryManager library;
    int choice;
    std::string isbn, title, author, email;
    int year, copies, memberId;

    // Add some sample books
    library.addBook("978-0-13-110362-7", "The C++ Programming Language", 
                   "Bjarne Stroustrup", 2013, 3);
    library.addBook("978-0-201-63361-0", "Design Patterns", 
                   "Gang of Four", 1994, 2);
    library.addBook("978-0-596-00712-6", "Learning C++", 
                   "Various Authors", 2008, 4);

    while (true) {
        displayMenu();
        std::cin >> choice;
        std::cin.ignore(); // Clear newline from input buffer

        switch (choice) {
            case 1: {
                std::cout << "Enter ISBN: ";
                std::getline(std::cin, isbn);
                std::cout << "Enter Title: ";
                std::getline(std::cin, title);
                std::cout << "Enter Author: ";
                std::getline(std::cin, author);
                std::cout << "Enter Year Published: ";
                std::cin >> year;
                std::cout << "Enter Number of Copies: ";
                std::cin >> copies;
                std::cin.ignore();
                library.addBook(isbn, title, author, year, copies);
                break;
            }

            case 2: {
                std::cout << "Enter Name: ";
                std::getline(std::cin, title); // Reuse variable for name
                std::cout << "Enter Email: ";
                std::getline(std::cin, email);
                library.registerMember(title, email);
                break;
            }

            case 3: {
                std::cout << "Enter Member ID: ";
                std::cin >> memberId;
                std::cin.ignore();
                std::cout << "Enter Book ISBN: ";
                std::getline(std::cin, isbn);
                library.borrowBook(memberId, isbn);
                break;
            }

            case 4: {
                std::cout << "Enter Member ID: ";
                std::cin >> memberId;
                std::cin.ignore();
                std::cout << "Enter Book ISBN: ";
                std::getline(std::cin, isbn);
                library.returnBook(memberId, isbn);
                break;
            }

            case 5: {
                library.displayAllBooks();
                break;
            }

            case 6: {
                library.displayAllMembers();
                break;
            }

            case 7: {
                library.displayStatistics();
                break;
            }

            case 8: {
                std::cout << "Thank you for using Library Management System!\n";
                return 0;
            }

            default: {
                std::cout << "Invalid choice! Please try again.\n";
            }
        }
    }

    return 0;
}
