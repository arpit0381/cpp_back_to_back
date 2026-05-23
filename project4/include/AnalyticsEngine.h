#ifndef ANALYTICSENGINE_H
#define ANALYTICSENGINE_H

#include "TaskManager.h"
#include <map>
#include <string>

struct TaskStats {
    int totalTasks;
    int completedTasks;
    int pendingTasks;
    int inProgressTasks;
    int cancelledTasks;
    int overdueTasks;
    double completionRate;
    int totalEstimatedHours;
    int totalActualHours;
};

class AnalyticsEngine {
public:
    // Statistical methods
    static TaskStats generateStatistics(const TaskManager& manager);
    static std::map<std::string, int> getCategoryDistribution(const TaskManager& manager);
    static std::map<std::string, int> getPriorityDistribution(const TaskManager& manager);
    static std::map<std::string, int> getStatusDistribution(const TaskManager& manager);

    // Analysis methods
    static int getAverageTasksPerCategory(const TaskManager& manager);
    static double getTimeAccuracy(const TaskManager& manager);
    static int getMostUsedCategory(const TaskManager& manager);
    static Priority getMostCommonPriority(const TaskManager& manager);

    // Productivity insights
    static void displayProductivityReport(const TaskManager& manager);
    static void displayDetailedAnalytics(const TaskManager& manager);
    static void displayCategoryAnalysis(const TaskManager& manager);

    // Recommendations
    static void generateRecommendations(const TaskManager& manager);
};

#endif // ANALYTICSENGINE_H
