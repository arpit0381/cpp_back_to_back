#include "TaskManager.h"
#include <iostream>
#include <algorithm>

TaskManager::TaskManager() {}

TaskManager::~TaskManager() {}

Task* TaskManager::createTask(const std::string& title, const std::string& description,
                               Priority priority, const std::string& category,
                               std::time_t dueDate, int estimatedHours) {
    auto task = std::make_unique<Task>(title, description, priority, category, dueDate, estimatedHours);
    Task* taskPtr = task.get();
    tasks.push_back(std::move(task));
    std::cout << "Task created successfully with ID: " << taskPtr->getId() << "\n";
    return taskPtr;
}

bool TaskManager::deleteTask(int taskId) {
    auto it = std::find_if(tasks.begin(), tasks.end(),
                          [taskId](const std::unique_ptr<Task>& t) { return t->getId() == taskId; });
    if (it != tasks.end()) {
        tasks.erase(it);
        std::cout << "Task deleted successfully.\n";
        return true;
    }
    std::cout << "Task not found.\n";
    return false;
}

Task* TaskManager::findTaskById(int taskId) {
    auto it = std::find_if(tasks.begin(), tasks.end(),
                          [taskId](const std::unique_ptr<Task>& t) { return t->getId() == taskId; });
    return (it != tasks.end()) ? it->get() : nullptr;
}

const Task* TaskManager::findTaskById(int taskId) const {
    auto it = std::find_if(tasks.begin(), tasks.end(),
                          [taskId](const std::unique_ptr<Task>& t) { return t->getId() == taskId; });
    return (it != tasks.end()) ? it->get() : nullptr;
}

std::vector<Task*> TaskManager::filterByStatus(TaskStatus status) {
    std::vector<Task*> result;
    for (auto& task : tasks) {
        if (task->getStatus() == status) {
            result.push_back(task.get());
        }
    }
    return result;
}

std::vector<Task*> TaskManager::filterByPriority(Priority priority) {
    std::vector<Task*> result;
    for (auto& task : tasks) {
        if (task->getPriority() == priority) {
            result.push_back(task.get());
        }
    }
    return result;
}

std::vector<Task*> TaskManager::filterByCategory(const std::string& category) {
    std::vector<Task*> result;
    for (auto& task : tasks) {
        if (task->getCategory() == category) {
            result.push_back(task.get());
        }
    }
    return result;
}

std::vector<Task*> TaskManager::filterByTag(const std::string& tag) {
    std::vector<Task*> result;
    for (auto& task : tasks) {
        if (task->hasTag(tag)) {
            result.push_back(task.get());
        }
    }
    return result;
}

std::vector<Task*> TaskManager::getOverdueTasks() {
    std::vector<Task*> result;
    for (auto& task : tasks) {
        if (task->isOverdue()) {
            result.push_back(task.get());
        }
    }
    return result;
}

std::vector<Task*> TaskManager::getUpcomingTasks(int daysAhead) {
    std::vector<Task*> result;
    for (auto& task : tasks) {
        int daysUntilDue = task->daysUntilDue();
        if (daysUntilDue >= 0 && daysUntilDue <= daysAhead && !task->isCompleted()) {
            result.push_back(task.get());
        }
    }
    return result;
}

std::vector<Task*> TaskManager::searchByTitle(const std::string& keyword) {
    std::vector<Task*> result;
    for (auto& task : tasks) {
        if (task->getTitle().find(keyword) != std::string::npos) {
            result.push_back(task.get());
        }
    }
    return result;
}

std::vector<Task*> TaskManager::searchByDescription(const std::string& keyword) {
    std::vector<Task*> result;
    for (auto& task : tasks) {
        if (task->getDescription().find(keyword) != std::string::npos) {
            result.push_back(task.get());
        }
    }
    return result;
}

void TaskManager::displayAllTasks() const {
    if (tasks.empty()) {
        std::cout << "No tasks available.\n";
        return;
    }
    std::cout << "\n═══════════════════════════════════════════════════\n";
    std::cout << "                    ALL TASKS\n";
    std::cout << "═══════════════════════════════════════════════════\n";
    for (const auto& task : tasks) {
        task->displaySummary();
    }
}

void TaskManager::displayTasksByStatus(TaskStatus status) const {
    auto result = const_cast<TaskManager*>(this)->filterByStatus(status);
    if (result.empty()) {
        std::cout << "No tasks with this status.\n";
        return;
    }
    std::cout << "\nTasks with status: " << result[0]->getStatusString() << "\n";
    for (auto task : result) {
        task->displaySummary();
    }
}

void TaskManager::displayTasksByPriority(Priority priority) const {
    auto result = const_cast<TaskManager*>(this)->filterByPriority(priority);
    if (result.empty()) {
        std::cout << "No tasks with this priority.\n";
        return;
    }
    std::cout << "\nTasks with priority: " << result[0]->getPriorityString() << "\n";
    for (auto task : result) {
        task->displaySummary();
    }
}

void TaskManager::displayTasksByCategory(const std::string& category) const {
    auto result = const_cast<TaskManager*>(this)->filterByCategory(category);
    if (result.empty()) {
        std::cout << "No tasks in this category.\n";
        return;
    }
    std::cout << "\nTasks in category: " << category << "\n";
    for (auto task : result) {
        task->displaySummary();
    }
}

void TaskManager::displayPendingTasks() const {
    displayTasksByStatus(TaskStatus::PENDING);
}

void TaskManager::displayCompletedTasks() const {
    displayTasksByStatus(TaskStatus::COMPLETED);
}

void TaskManager::displayOverdueTasks() const {
    auto overdue = const_cast<TaskManager*>(this)->getOverdueTasks();
    if (overdue.empty()) {
        std::cout << "No overdue tasks!\n";
        return;
    }
    std::cout << "\nOverdue Tasks:\n";
    for (auto task : overdue) {
        task->displaySummary();
    }
}

int TaskManager::getTotalTasks() const { return tasks.size(); }

int TaskManager::getCompletedTasks() const {
    return std::count_if(tasks.begin(), tasks.end(),
                        [](const std::unique_ptr<Task>& t) { return t->isCompleted(); });
}

int TaskManager::getPendingTasks() const {
    auto result = filterByStatus(TaskStatus::PENDING);
    return result.size();
}

int TaskManager::getInProgressTasks() const {
    auto result = filterByStatus(TaskStatus::IN_PROGRESS);
    return result.size();
}

std::vector<std::string> TaskManager::getAllCategories() const {
    std::vector<std::string> categories;
    for (const auto& task : tasks) {
        if (std::find(categories.begin(), categories.end(), task->getCategory()) == categories.end()) {
            categories.push_back(task->getCategory());
        }
    }
    return categories;
}

double TaskManager::getCompletionRate() const {
    if (tasks.empty()) return 0.0;
    int completed = getCompletedTasks();
    return (completed * 100.0) / tasks.size();
}

void TaskManager::sortByDueDate() {
    std::sort(tasks.begin(), tasks.end(),
             [](const std::unique_ptr<Task>& a, const std::unique_ptr<Task>& b) {
                 return a->getDueDate() < b->getDueDate();
             });
}

void TaskManager::sortByPriority() {
    std::sort(tasks.begin(), tasks.end(),
             [](const std::unique_ptr<Task>& a, const std::unique_ptr<Task>& b) {
                 return static_cast<int>(a->getPriority()) > static_cast<int>(b->getPriority());
             });
}

void TaskManager::sortByCreatedDate() {
    std::sort(tasks.begin(), tasks.end(),
             [](const std::unique_ptr<Task>& a, const std::unique_ptr<Task>& b) {
                 return a->getCreatedDate() > b->getCreatedDate();
             });
}

const std::vector<std::unique_ptr<Task>>& TaskManager::getTasks() const {
    return tasks;
}
