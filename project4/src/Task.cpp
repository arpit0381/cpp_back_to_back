#include "Task.h"
#include <iostream>
#include <ctime>
#include <algorithm>
#include <iomanip>

int Task::nextId = 1000;

Task::Task(const std::string& title, const std::string& description,
           Priority priority, const std::string& category,
           std::time_t dueDate, int estimatedHours)
    : id(nextId++), title(title), description(description),
      priority(priority), status(TaskStatus::PENDING), category(category),
      createdDate(std::time(nullptr)), dueDate(dueDate),
      completedDate(0), estimatedHours(estimatedHours), actualHours(0) {}

int Task::getId() const { return id; }
std::string Task::getTitle() const { return title; }
std::string Task::getDescription() const { return description; }
Priority Task::getPriority() const { return priority; }
TaskStatus Task::getStatus() const { return status; }
std::string Task::getCategory() const { return category; }
const std::vector<std::string>& Task::getTags() const { return tags; }
std::time_t Task::getCreatedDate() const { return createdDate; }
std::time_t Task::getDueDate() const { return dueDate; }
std::time_t Task::getCompletedDate() const { return completedDate; }
int Task::getEstimatedHours() const { return estimatedHours; }
int Task::getActualHours() const { return actualHours; }

bool Task::isCompleted() const { return status == TaskStatus::COMPLETED; }

bool Task::isOverdue() const {
    if (status == TaskStatus::COMPLETED || status == TaskStatus::CANCELLED) {
        return false;
    }
    return std::time(nullptr) > dueDate;
}

void Task::setTitle(const std::string& newTitle) { title = newTitle; }
void Task::setDescription(const std::string& newDesc) { description = newDesc; }
void Task::setPriority(Priority newPriority) { priority = newPriority; }
void Task::setStatus(TaskStatus newStatus) { status = newStatus; }
void Task::setDueDate(std::time_t newDueDate) { dueDate = newDueDate; }
void Task::setEstimatedHours(int hours) { estimatedHours = hours; }
void Task::setActualHours(int hours) { actualHours = hours; }

void Task::addTag(const std::string& tag) {
    if (!hasTag(tag)) {
        tags.push_back(tag);
    }
}

void Task::removeTag(const std::string& tag) {
    auto it = std::find(tags.begin(), tags.end(), tag);
    if (it != tags.end()) {
        tags.erase(it);
    }
}

bool Task::hasTag(const std::string& tag) const {
    return std::find(tags.begin(), tags.end(), tag) != tags.end();
}

void Task::markCompleted() {
    status = TaskStatus::COMPLETED;
    completedDate = std::time(nullptr);
}

void Task::markInProgress() { status = TaskStatus::IN_PROGRESS; }
void Task::markPending() { status = TaskStatus::PENDING; }
void Task::markCancelled() { status = TaskStatus::CANCELLED; }

std::string Task::getStatusString() const {
    switch (status) {
        case TaskStatus::PENDING: return "PENDING";
        case TaskStatus::IN_PROGRESS: return "IN_PROGRESS";
        case TaskStatus::COMPLETED: return "COMPLETED";
        case TaskStatus::CANCELLED: return "CANCELLED";
        default: return "UNKNOWN";
    }
}

std::string Task::getPriorityString() const {
    switch (priority) {
        case Priority::LOW: return "LOW";
        case Priority::MEDIUM: return "MEDIUM";
        case Priority::HIGH: return "HIGH";
        case Priority::CRITICAL: return "CRITICAL";
        default: return "UNKNOWN";
    }
}

int Task::daysUntilDue() const {
    std::time_t now = std::time(nullptr);
    double diff = std::difftime(dueDate, now);
    return static_cast<int>(diff / (24 * 3600));
}

bool Task::isUrgent() const {
    return (priority == Priority::CRITICAL || priority == Priority::HIGH) && !isCompleted();
}

void Task::displayInfo() const {
    std::cout << "\n╔════════════════════════════════════════════════════╗\n";
    std::cout << "║ TASK ID: " << std::setw(37) << id << " ║\n";
    std::cout << "╠════════════════════════════════════════════════════╣\n";
    std::cout << "║ Title: " << std::setw(42) << title.substr(0, 42) << " ║\n";
    std::cout << "║ Description: " << std::setw(35) << description.substr(0, 35) << " ║\n";
    std::cout << "║ Priority: " << std::setw(38) << getPriorityString() << " ║\n";
    std::cout << "║ Status: " << std::setw(40) << getStatusString() << " ║\n";
    std::cout << "║ Category: " << std::setw(38) << category << " ║\n";
    std::cout << "║ Days Until Due: " << std::setw(32) << daysUntilDue() << " ║\n";
    std::cout << "║ Estimated Hours: " << std::setw(30) << estimatedHours << " ║\n";
    std::cout << "║ Actual Hours: " << std::setw(34) << actualHours << " ║\n";
    
    if (!tags.empty()) {
        std::cout << "║ Tags: ";
        for (const auto& tag : tags) {
            std::cout << "[" << tag << "] ";
        }
        std::cout << "\n";
    }
    
    std::cout << "╚════════════════════════════════════════════════════╝\n";
}

void Task::displaySummary() const {
    std::cout << "ID: " << id << " | " << title << " | " << getPriorityString() 
              << " | " << getStatusString() << " | Days Left: " << daysUntilDue() << "\n";
}
