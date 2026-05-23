#include "TaskManager.h"
#include "FileHandler.h"
#include "AnalyticsEngine.h"
#include <iostream>
#include <ctime>
#include <iomanip>
#include <sstream>

// Utility function to get future time
std::time_t getFutureTime(int daysFromNow) {
    return std::time(nullptr) + (daysFromNow * 24 * 3600);
}

// Utility function to parse priority
Priority getPriorityFromInput() {
    int p;
    std::cout << "Enter priority (1=Low, 2=Medium, 3=High, 4=Critical): ";
    std::cin >> p;
    std::cin.ignore();
    switch (p) {
        case 1: return Priority::LOW;
        case 2: return Priority::MEDIUM;
        case 3: return Priority::HIGH;
        case 4: return Priority::CRITICAL;
        default: return Priority::MEDIUM;
    }
}

void displayMainMenu() {
    std::cout << "\n╔════════════════════════════════════════════════════╗\n";
    std::cout << "║    ADVANCED TASK MANAGEMENT SYSTEM v1.0             ║\n";
    std::cout << "╠════════════════════════════════════════════════════╣\n";
    std::cout << "║  1. Create New Task                                ║\n";
    std::cout << "║  2. View All Tasks                                 ║\n";
    std::cout << "║  3. View Task Details                              ║\n";
    std::cout << "║  4. Update Task                                    ║\n";
    std::cout << "║  5. Complete Task                                  ║\n";
    std::cout << "║  6. Delete Task                                    ║\n";
    std::cout << "║  7. Search Tasks                                   ║\n";
    std::cout << "║  8. View Overdue Tasks                             ║\n";
    std::cout << "║  9. View Upcoming Tasks (7 days)                   ║\n";
    std::cout << "║  10. Filter Tasks                                  ║\n";
    std::cout << "║  11. View Analytics & Statistics                   ║\n";
    std::cout << "║  12. Save Tasks                                    ║\n";
    std::cout << "║  0. Exit                                           ║\n";
    std::cout << "╚════════════════════════════════════════════════════╝\n";
    std::cout << "Enter your choice: ";
}

void displayFilterMenu() {
    std::cout << "\n--- Filter Options ---\n";
    std::cout << "1. By Status\n";
    std::cout << "2. By Priority\n";
    std::cout << "3. By Category\n";
    std::cout << "4. By Tag\n";
    std::cout << "Enter filter choice: ";
}

void displayAnalyticsMenu() {
    std::cout << "\n--- Analytics Options ---\n";
    std::cout << "1. View Productivity Report\n";
    std::cout << "2. View Detailed Analytics\n";
    std::cout << "3. View Category Analysis\n";
    std::cout << "4. Get Recommendations\n";
    std::cout << "Enter analytics choice: ";
}

int main() {
    TaskManager manager;
    FileHandler fileHandler("tasks.json");
    int choice;

    std::cout << "\n╔════════════════════════════════════════════════════╗\n";
    std::cout << "║         Welcome to Task Management System!          ║\n";
    std::cout << "║              Built with Modern C++17                ║\n";
    std::cout << "╚════════════════════════════════════════════════════╝\n";

    // Create sample tasks for demonstration
    auto tomorrow = getFutureTime(1);
    auto nextWeek = getFutureTime(7);
    auto nextMonth = getFutureTime(30);

    manager.createTask("Complete Project Proposal", "Finish the quarterly project proposal",
                      Priority::HIGH, "Work", nextWeek, 8);
    manager.createTask("Review Code", "Review pull requests from team members",
                      Priority::MEDIUM, "Work", tomorrow, 4);
    manager.createTask("Update Documentation", "Update API documentation for v2.0",
                      Priority::MEDIUM, "Documentation", nextMonth, 6);
    manager.createTask("Bug Fixes", "Fix critical bugs in production",
                      Priority::CRITICAL, "Work", std::time(nullptr) - 3600, 5);

    while (true) {
        displayMainMenu();
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
            case 1: {
                std::string title, desc, category;
                std::cout << "Enter task title: ";
                std::getline(std::cin, title);
                std::cout << "Enter description: ";
                std::getline(std::cin, desc);
                std::cout << "Enter category: ";
                std::getline(std::cin, category);
                Priority priority = getPriorityFromInput();
                int days;
                std::cout << "Enter days until due: ";
                std::cin >> days;
                int hours;
                std::cout << "Enter estimated hours: ";
                std::cin >> hours;
                std::cin.ignore();

                manager.createTask(title, desc, priority, category, getFutureTime(days), hours);
                break;
            }

            case 2: {
                manager.displayAllTasks();
                break;
            }

            case 3: {
                int id;
                std::cout << "Enter task ID: ";
                std::cin >> id;
                std::cin.ignore();
                Task* task = manager.findTaskById(id);
                if (task) {
                    task->displayInfo();
                } else {
                    std::cout << "Task not found.\n";
                }
                break;
            }

            case 4: {
                int id;
                std::cout << "Enter task ID to update: ";
                std::cin >> id;
                std::cin.ignore();
                Task* task = manager.findTaskById(id);
                if (task) {
                    std::cout << "1. Update Title\n2. Update Description\n3. Update Priority\n";
                    int updateChoice;
                    std::cin >> updateChoice;
                    std::cin.ignore();
                    if (updateChoice == 1) {
                        std::string newTitle;
                        std::cout << "New title: ";
                        std::getline(std::cin, newTitle);
                        task->setTitle(newTitle);
                    } else if (updateChoice == 2) {
                        std::string newDesc;
                        std::cout << "New description: ";
                        std::getline(std::cin, newDesc);
                        task->setDescription(newDesc);
                    } else if (updateChoice == 3) {
                        task->setPriority(getPriorityFromInput());
                    }
                    std::cout << "Task updated!\n";
                } else {
                    std::cout << "Task not found.\n";
                }
                break;
            }

            case 5: {
                int id;
                std::cout << "Enter task ID to complete: ";
                std::cin >> id;
                std::cin.ignore();
                Task* task = manager.findTaskById(id);
                if (task) {
                    int hours;
                    std::cout << "Actual hours spent: ";
                    std::cin >> hours;
                    std::cin.ignore();
                    task->setActualHours(hours);
                    task->markCompleted();
                    std::cout << "Task marked as completed!\n";
                } else {
                    std::cout << "Task not found.\n";
                }
                break;
            }

            case 6: {
                int id;
                std::cout << "Enter task ID to delete: ";
                std::cin >> id;
                std::cin.ignore();
                manager.deleteTask(id);
                break;
            }

            case 7: {
                std::string keyword;
                std::cout << "1. Search by title\n2. Search by description\n";
                int searchChoice;
                std::cin >> searchChoice;
                std::cin.ignore();
                std::cout << "Enter search keyword: ";
                std::getline(std::cin, keyword);

                std::vector<Task*> results;
                if (searchChoice == 1) {
                    results = manager.searchByTitle(keyword);
                } else {
                    results = manager.searchByDescription(keyword);
                }

                if (results.empty()) {
                    std::cout << "No results found.\n";
                } else {
                    for (auto task : results) {
                        task->displaySummary();
                    }
                }
                break;
            }

            case 8: {
                manager.displayOverdueTasks();
                break;
            }

            case 9: {
                auto upcoming = manager.getUpcomingTasks(7);
                if (upcoming.empty()) {
                    std::cout << "No upcoming tasks in the next 7 days.\n";
                } else {
                    std::cout << "\nUpcoming Tasks (Next 7 Days):\n";
                    for (auto task : upcoming) {
                        task->displaySummary();
                    }
                }
                break;
            }

            case 10: {
                displayFilterMenu();
                int filterChoice;
                std::cin >> filterChoice;
                std::cin.ignore();

                if (filterChoice == 1) {
                    std::cout << "1. Pending\n2. In Progress\n3. Completed\n";
                    int statusChoice;
                    std::cin >> statusChoice;
                    std::cin.ignore();
                    TaskStatus status = TaskStatus::PENDING;
                    if (statusChoice == 2) status = TaskStatus::IN_PROGRESS;
                    if (statusChoice == 3) status = TaskStatus::COMPLETED;
                    manager.displayTasksByStatus(status);
                } else if (filterChoice == 2) {
                    Priority priority = getPriorityFromInput();
                    manager.displayTasksByPriority(priority);
                } else if (filterChoice == 3) {
                    std::string category;
                    std::cout << "Enter category: ";
                    std::getline(std::cin, category);
                    manager.displayTasksByCategory(category);
                }
                break;
            }

            case 11: {
                displayAnalyticsMenu();
                int analyticsChoice;
                std::cin >> analyticsChoice;
                std::cin.ignore();

                if (analyticsChoice == 1) {
                    AnalyticsEngine::displayProductivityReport(manager);
                } else if (analyticsChoice == 2) {
                    AnalyticsEngine::displayDetailedAnalytics(manager);
                } else if (analyticsChoice == 3) {
                    AnalyticsEngine::displayCategoryAnalysis(manager);
                } else if (analyticsChoice == 4) {
                    AnalyticsEngine::generateRecommendations(manager);
                }
                break;
            }

            case 12: {
                fileHandler.saveTasks(manager);
                break;
            }

            case 0: {
                std::cout << "\n╔════════════════════════════════════════════════════╗\n";
                std::cout << "║     Thank you for using Task Management System!     ║\n";
                std::cout << "║              Have a productive day! 🚀              ║\n";
                std::cout << "╚════════════════════════════════════════════════════╝\n\n";
                return 0;
            }

            default: {
                std::cout << "Invalid choice! Please try again.\n";
            }
        }
    }

    return 0;
}
