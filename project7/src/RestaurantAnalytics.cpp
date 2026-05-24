#include "../include/RestaurantAnalytics.h"
#include <iostream>
#include <iomanip>
#include <algorithm>

RestaurantAnalytics::RestaurantAnalytics() {}

void RestaurantAnalytics::recordOrder(const Order& order) {
    if (order.getStatus() == OrderStatus::COMPLETED) {
        completedOrders.push_back(order);
        
        for (int i = 0; i < order.getItemCount(); ++i) {
            const OrderItem& item = order.getAllItems()[i];
            std::string itemId = item.getItem().getItemId();
            itemSalesCount[itemId]++;
            itemRevenue[itemId] += item.getSubtotal();
        }
    }
}

DailyStats RestaurantAnalytics::getDailyStats() {
    DailyStats stats;
    stats.totalOrders = completedOrders.size();
    
    for (const auto& order : completedOrders) {
        stats.totalRevenue += order.getTotalAmount();
    }
    
    if (stats.totalOrders > 0) {
        stats.averageOrderValue = stats.totalRevenue / stats.totalOrders;
    }
    
    return stats;
}

MenuAnalytics RestaurantAnalytics::getItemAnalytics(const std::string& itemId) {
    MenuAnalytics analytics;
    analytics.itemName = itemId;
    
    auto salesIt = itemSalesCount.find(itemId);
    if (salesIt != itemSalesCount.end()) {
        analytics.timesSold = salesIt->second;
    }
    
    auto revenueIt = itemRevenue.find(itemId);
    if (revenueIt != itemRevenue.end()) {
        analytics.totalRevenue = revenueIt->second;
    }
    
    return analytics;
}

std::vector<MenuAnalytics> RestaurantAnalytics::getTopSellingItems(int limit) {
    std::vector<MenuAnalytics> items;
    
    for (const auto& pair : itemSalesCount) {
        MenuAnalytics analytics;
        analytics.itemName = pair.first;
        analytics.timesSold = pair.second;
        analytics.totalRevenue = itemRevenue[pair.first];
        items.push_back(analytics);
    }
    
    std::sort(items.begin(), items.end(),
              [](const MenuAnalytics& a, const MenuAnalytics& b) {
                  return a.totalRevenue > b.totalRevenue;
              });
    
    if (items.size() > static_cast<size_t>(limit)) {
        items.resize(limit);
    }
    
    return items;
}

double RestaurantAnalytics::getTotalRevenue() {
    double total = 0.0;
    for (const auto& order : completedOrders) {
        total += order.getTotalAmount();
    }
    return total;
}

double RestaurantAnalytics::getAverageOrderValue() {
    if (completedOrders.empty()) return 0.0;
    return getTotalRevenue() / completedOrders.size();
}

int RestaurantAnalytics::getPeakHour() {
    // Simplified - returns hour based on order count
    return 12;  // Typically lunch hour
}

void RestaurantAnalytics::generateDailyReport() {
    DailyStats stats = getDailyStats();
    
    std::cout << "\n========== DAILY REPORT ==========" << std::endl;
    std::cout << "Total Orders: " << stats.totalOrders << std::endl;
    std::cout << "Total Revenue: ₹" << std::fixed << std::setprecision(2)
              << stats.totalRevenue << std::endl;
    std::cout << "Average Order Value: ₹" << stats.averageOrderValue << std::endl;
    std::cout << "==================================\n" << std::endl;
}

void RestaurantAnalytics::generateMenuReport() {
    std::cout << "\n========== TOP SELLING ITEMS ==========" << std::endl;
    
    auto topItems = getTopSellingItems(5);
    for (size_t i = 0; i < topItems.size(); ++i) {
        std::cout << (i + 1) << ". " << topItems[i].itemName
                  << " - Times Sold: " << topItems[i].timesSold
                  << " | Revenue: ₹" << std::fixed << std::setprecision(2)
                  << topItems[i].totalRevenue << std::endl;
    }
    
    std::cout << "======================================\n" << std::endl;
}

void RestaurantAnalytics::generateRevenueReport() {
    std::cout << "\n========== REVENUE REPORT ==========" << std::endl;
    std::cout << "Total Revenue: ₹" << std::fixed << std::setprecision(2)
              << getTotalRevenue() << std::endl;
    std::cout << "Total Orders Completed: " << completedOrders.size() << std::endl;
    std::cout << "Average per Order: ₹" << getAverageOrderValue() << std::endl;
    std::cout << "====================================\n" << std::endl;
}

void RestaurantAnalytics::displayAnalyticsDashboard() {
    generateDailyReport();
    generateMenuReport();
    generateRevenueReport();
}
