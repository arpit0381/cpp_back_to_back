#ifndef RESTAURANTANALYTICS_H
#define RESTAURANTANALYTICS_H

#include <string>
#include <vector>
#include <map>
#include "Order.h"

struct DailyStats {
    int totalOrders = 0;
    double totalRevenue = 0.0;
    double averageOrderValue = 0.0;
    int totalCustomers = 0;
    double peakHourRevenue = 0.0;
};

struct MenuAnalytics {
    std::string itemName;
    int timesSold = 0;
    double totalRevenue = 0.0;
    double profitMargin = 0.0;
    int avgPrepTime = 0;
};

class RestaurantAnalytics {
private:
    std::vector<Order> completedOrders;
    std::map<std::string, int> itemSalesCount;
    std::map<std::string, double> itemRevenue;

public:
    RestaurantAnalytics();

    // Data Recording
    void recordOrder(const Order& order);

    // Calculations
    DailyStats getDailyStats();
    MenuAnalytics getItemAnalytics(const std::string& itemId);
    std::vector<MenuAnalytics> getTopSellingItems(int limit = 10);
    double getTotalRevenue();
    double getAverageOrderValue();
    int getPeakHour();

    // Reporting
    void generateDailyReport();
    void generateMenuReport();
    void generateRevenueReport();
    void displayAnalyticsDashboard();
};

#endif
