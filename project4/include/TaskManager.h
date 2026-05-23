#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include "Task.h"
#include <vector>
#include <memory>
#include <string>
#include <algorithm>

class TaskManager {
private:
    std::vector<std::unique_ptr<Task>> tasks;

public:
    // Constructor & Destructor
    TaskManager();
    ~TaskManager();

    // Task creation and deletion
    Task* createTask(const std::string& title, const std::string& description,
                     Priority priority, const std::string& category,
                     std::time_t dueDate, int estimatedHours);
    bool deleteTask(int taskId);

    // Task retrieval
    Task* findTaskById(int taskId);
    const Task* findTaskById(int taskId) const;

    // Filtering operations
    std::vector<Task*> filterByStatus(TaskStatus status);
    std::vector<Task*> filterByPriority(Priority priority);
    std::vector<Task*> filterByCategory(const std::string& category);
    std::vector<Task*> filterByTag(const std::string& tag);
    std::vector<Task*> getOverdueTasks();
    std::vector<Task*> getUpcomingTasks(int daysAhead);

    // Search operations
    std::vector<Task*> searchByTitle(const std::string& keyword);
    std::vector<Task*> searchByDescription(const std::string& keyword);

    // Display operations
    void displayAllTasks() const;
    void displayTasksByStatus(TaskStatus status) const;
    void displayTasksByPriority(Priority priority) const;
    void displayTasksByCategory(const std::string& category) const;
    void displayPendingTasks() const;
    void displayCompletedTasks() const;
    void displayOverdueTasks() const;

    // Statistics
    int getTotalTasks() const;
    int getCompletedTasks() const;
    int getPendingTasks() const;
    int getInProgressTasks() const;
    std::vector<std::string> getAllCategories() const;
    double getCompletionRate() const;

    // Sorting
    void sortByDueDate();
    void sortByPriority();
    void sortByCreatedDate();

    // Data access
    const std::vector<std::unique_ptr<Task>>& getTasks() const;
};

#endif // TASKMANAGER_H
