#include "../include/StudentManager.h"
#include <iostream>
#include <limits>

void displayMenu() {
    std::cout << "\n========== STUDENT MANAGEMENT SYSTEM ==========\n";
    std::cout << "1. Add Student\n";
    std::cout << "2. Remove Student\n";
    std::cout << "3. Add Grade to Student\n";
    std::cout << "4. Display All Students\n";
    std::cout << "5. Display Student Details\n";
    std::cout << "6. Display Class Statistics\n";
    std::cout << "7. Remove Last Grade from Student\n";
    std::cout << "8. Save Data to File\n";
    std::cout << "9. Load Data from File\n";
    std::cout << "0. Exit\n";
    std::cout << "==============================================\n";
    std::cout << "Enter your choice: ";
}

int main() {
    StudentManager manager;
    int choice;
    bool running = true;

    std::cout << "Welcome to Student Management System!\n";

    while (running) {
        displayMenu();
        
        // Input validation
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "✗ Invalid input. Please enter a number.\n";
            continue;
        }

        int id;
        std::string name, email;
        double grade;

        switch (choice) {
            case 1: {
                std::cout << "Enter student name: ";
                std::cin.ignore();
                std::getline(std::cin, name);
                std::cout << "Enter student email: ";
                std::getline(std::cin, email);
                manager.addStudent(name, email);
                break;
            }

            case 2: {
                std::cout << "Enter student ID to remove: ";
                std::cin >> id;
                manager.removeStudent(id);
                break;
            }

            case 3: {
                std::cout << "Enter student ID: ";
                std::cin >> id;
                std::cout << "Enter grade (0-100): ";
                std::cin >> grade;
                manager.addGradeToStudent(id, grade);
                break;
            }

            case 4: {
                manager.displayAllStudents();
                break;
            }

            case 5: {
                std::cout << "Enter student ID: ";
                std::cin >> id;
                manager.displayStudentDetails(id);
                break;
            }

            case 6: {
                manager.displayStatistics();
                break;
            }

            case 7: {
                std::cout << "Enter student ID: ";
                std::cin >> id;
                manager.removeLastGradeFromStudent(id);
                break;
            }

            case 8: {
                std::cout << "Enter filename to save: ";
                std::cin.ignore();
                std::getline(std::cin, name);
                manager.saveToFile(name);
                break;
            }

            case 9: {
                std::cout << "Enter filename to load: ";
                std::cin.ignore();
                std::getline(std::cin, name);
                manager.loadFromFile(name);
                break;
            }

            case 0: {
                std::cout << "Goodbye!\n";
                running = false;
                break;
            }

            default: {
                std::cout << "✗ Invalid choice. Please try again.\n";
            }
        }
    }

    return 0;
}
