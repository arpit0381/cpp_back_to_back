#include "AnalyticsEngine.h"
#include <iostream>
#include <iomanip>
#include <algorithm>

TaskStats AnalyticsEngine::generateStatistics(const TaskManager& manager) {
    TaskStats stats;
    stats.totalTasks = manager.getTotalTasks();
    stats.completedTasks = manager.getCompletedTasks();
    stats.pendingTasks = manager.getPendingTasks();
    stats.inProgressTasks = manager.getInProgressTasks();
    stats.cancelledTasks = stats.totalTasks - stats.completedTasks - stats.pendingTasks - stats.inProgressTasks;
    stats.overdueTasks = const_cast<TaskManager&>(manager).getOverdueTasks().size();
    stats.completionRate = manager.getCompletionRate();
    stats.totalEstimatedHours = 0;
    stats.totalActualHours = 0;

    for (const auto& task : manager.getTasks()) {
        stats.totalEstimatedHours += task->getEstimatedHours();
        stats.totalActualHours += task->getActualHours();
    }

    return stats;
}

std::map<std::string, int> AnalyticsEngine::getCategoryDistribution(const TaskManager& manager) {
    std::map<std::string, int> distribution;
    for (const auto& task : manager.getTasks()) {
        distribution[task->getCategory()]++;
    }
    return distribution;
}

std::map<std::string, int> AnalyticsEngine::getPriorityDistribution(const TaskManager& manager) {
    std::map<std::string, int> distribution;
    for (const auto& task : manager.getTasks()) {
        distribution[task->getPriorityString()]++;
    }
    return distribution;
}

std::map<std::string, int> AnalyticsEngine::getStatusDistribution(const TaskManager& manager) {
    std::map<std::string, int> distribution;
    for (const auto& task : manager.getTasks()) {
        distribution[task->getStatusString()]++;
    }
    return distribution;
}

int AnalyticsEngine::getAverageTasksPerCategory(const TaskManager& manager) {
    auto categories = getCategoryDistribution(manager);
    if (categories.empty()) return 0;
    int total = 0;
    for (const auto& cat : categories) {
        total += cat.second;
    }
    return total / categories.size();
}

double AnalyticsEngine::getTimeAccuracy(const TaskManager& manager) {
    int totalEstimated = 0;
    int totalActual = 0;
    for (const auto& task : manager.getTasks()) {
        totalEstimated += task->getEstimatedHours();
        totalActual += task->getActualHours();
    }
    if (totalEstimated == 0) return 0.0;
    return (totalActual * 100.0) / totalEstimated;
}

int AnalyticsEngine::getMostUsedCategory(const TaskManager& manager) {
    auto dist = getCategoryDistribution(manager);
    if (dist.empty()) return -1;
    auto max = std::max_element(dist.begin(), dist.end(),
                               [](const auto& a, const auto& b) { return a.second < b.second; });
    return max->second;
}

Priority AnalyticsEngine::getMostCommonPriority(const TaskManager& manager) {
    auto dist = getPriorityDistribution(manager);
    Priority maxPriority = Priority::LOW;
    int maxCount = 0;
    for (const auto& p : dist) {
        if (p.second > maxCount) {
            maxCount = p.second;
            if (p.first == "CRITICAL") maxPriority = Priority::CRITICAL;
            else if (p.first == "HIGH") maxPriority = Priority::HIGH;
            else if (p.first == "MEDIUM") maxPriority = Priority::MEDIUM;
        }
    }
    return maxPriority;
}

void AnalyticsEngine::displayProductivityReport(const TaskManager& manager) {
    TaskStats stats = generateStatistics(manager);
    
    std::cout << "\n╔════════════════════════════════════════════════════╗\n";
    std::cout << "║        PRODUCTIVITY REPORT                          ║\n";
    std::cout << "╠════════════════════════════════════════════════════╣\n";
    std::cout << "║ Total Tasks:        " << std::setw(27) << stats.totalTasks << " ║\n";
    std::cout << "║ Completed:          " << std::setw(27) << stats.completedTasks << " ║\n";
    std::cout << "║ Pending:            " << std::setw(27) << stats.pendingTasks << " ║\n";
    std::cout << "║ In Progress:        " << std::setw(27) << stats.inProgressTasks << " ║\n";
    std::cout << "║ Overdue:            " << std::setw(27) << stats.overdueTasks << " ║\n";
    std::cout << "║ Completion Rate:    " << std::setw(24) << std::fixed << std::setprecision(1) 
              << stats.completionRate << "% ║\n";
    std::cout << "║ Est. Hours:         " << std::setw(27) << stats.totalEstimatedHours << " ║\n";
    std::cout << "║ Actual Hours:       " << std::setw(27) << stats.totalActualHours << " ║\n";
    std::cout << "╚════════════════════════════════════════════════════╝\n";
}

void AnalyticsEngine::displayDetailedAnalytics(const TaskManager& manager) {
    TaskStats stats = generateStatistics(manager);
    
    std::cout << "\n═══════════════════════════════════════════════════\n";
    std::cout << "         DETAILED ANALYTICS DASHBOARD\n";
    std::cout << "═══════════════════════════════════════════════════\n";
    
    // Priority Distribution
    std::cout << "\nPriority Distribution:\n";
    auto priorityDist = getPriorityDistribution(manager);
    for (const auto& p : priorityDist) {
        int width = (p.second * 40) / std::max(1, stats.totalTasks);
        std::cout << "  " << std::setw(10) << p.first << ": [";
        for (int i = 0; i < width; ++i) std::cout << "█";
        std::cout << "] " << p.second << "\n";
    }

    // Status Distribution
    std::cout << "\nStatus Distribution:\n";
    auto statusDist = getStatusDistribution(manager);
    for (const auto& s : statusDist) {
        int width = (s.second * 40) / std::max(1, stats.totalTasks);
        std::cout << "  " << std::setw(12) << s.first << ": [";
        for (int i = 0; i < width; ++i) std::cout << "█";
        std::cout << "] " << s.second << "\n";
    }

    // Time Metrics
    std::cout << "\nTime Metrics:\n";
    std::cout << "  Total Estimated: " << stats.totalEstimatedHours << " hours\n";
    std::cout << "  Total Actual:    " << stats.totalActualHours << " hours\n";
    double accuracy = getTimeAccuracy(manager);
    std::cout << "  Time Accuracy:   " << std::fixed << std::setprecision(1) << accuracy << "%\n";
}

void AnalyticsEngine::displayCategoryAnalysis(const TaskManager& manager) {
    std::cout << "\n═══════════════════════════════════════════════════\n";
    std::cout << "         CATEGORY ANALYSIS\n";
    std::cout << "═══════════════════════════════════════════════════\n";
    
    auto categoryDist = getCategoryDistribution(manager);
    int totalTasks = manager.getTotalTasks();

    for (const auto& cat : categoryDist) {
        double percentage = (cat.second * 100.0) / totalTasks;
        std::cout << "\n  Category: " << cat.first << "\n";
        std::cout << "  Tasks: " << cat.second << " (" << std::fixed << std::setprecision(1) << percentage << "%)\n";
    }
}

void AnalyticsEngine::generateRecommendations(const TaskManager& manager) {
    TaskStats stats = generateStatistics(manager);
    
    std::cout << "\n═══════════════════════════════════════════════════\n";
    std::cout << "         PRODUCTIVITY RECOMMENDATIONS\n";
    std::cout << "═══════════════════════════════════════════════════\n";
    
    if (stats.overdueTasks > 0) {
        std::cout << "⚠️  You have " << stats.overdueTasks << " overdue task(s)! Focus on these first.\n";
    }
    
    if (stats.pendingTasks > 5) {
        std::cout << "⚠️  High pending tasks count. Consider prioritizing or delegating.\n";
    }
    
    if (stats.completionRate < 50) {
        std::cout << "📊 Completion rate is low. Break down large tasks into smaller ones.\n";
    } else if (stats.completionRate > 80) {
        std::cout << "✅ Excellent completion rate! Keep up the good work!\n";
    }
    
    double accuracy = getTimeAccuracy(manager);
    if (accuracy > 120) {
        std::cout << "⏱️  Tasks are taking longer than estimated. Review your estimates.\n";
    } else if (accuracy < 80) {
        std::cout << "⚡ You're completing tasks faster than estimated. Great efficiency!\n";
    }
}
