#ifndef TASK_H
#define TASK_H

#include <string>
#include <vector>
#include <ctime>
#include <memory>

enum class Priority {
    LOW = 1,
    MEDIUM = 2,
    HIGH = 3,
    CRITICAL = 4
};

enum class TaskStatus {
    PENDING,
    IN_PROGRESS,
    COMPLETED,
    CANCELLED
};

class Task {
private:
    static int nextId;
    int id;
    std::string title;
    std::string description;
    Priority priority;
    TaskStatus status;
    std::string category;
    std::vector<std::string> tags;
    std::time_t createdDate;
    std::time_t dueDate;
    std::time_t completedDate;
    int estimatedHours;
    int actualHours;

public:
    // Constructor
    Task(const std::string& title, const std::string& description,
         Priority priority, const std::string& category,
         std::time_t dueDate, int estimatedHours);

    // Getters
    int getId() const;
    std::string getTitle() const;
    std::string getDescription() const;
    Priority getPriority() const;
    TaskStatus getStatus() const;
    std::string getCategory() const;
    const std::vector<std::string>& getTags() const;
    std::time_t getCreatedDate() const;
    std::time_t getDueDate() const;
    std::time_t getCompletedDate() const;
    int getEstimatedHours() const;
    int getActualHours() const;
    bool isOverdue() const;
    bool isCompleted() const;

    // Setters
    void setTitle(const std::string& newTitle);
    void setDescription(const std::string& newDesc);
    void setPriority(Priority newPriority);
    void setStatus(TaskStatus newStatus);
    void setDueDate(std::time_t newDueDate);
    void setEstimatedHours(int hours);
    void setActualHours(int hours);

    // Tag operations
    void addTag(const std::string& tag);
    void removeTag(const std::string& tag);
    bool hasTag(const std::string& tag) const;

    // Task operations
    void markCompleted();
    void markInProgress();
    void markPending();
    void markCancelled();

    // Display
    void displayInfo() const;
    void displaySummary() const;
    std::string getStatusString() const;
    std::string getPriorityString() const;

    // Utility
    int daysUntilDue() const;
    bool isUrgent() const;
};

#endif // TASK_H
