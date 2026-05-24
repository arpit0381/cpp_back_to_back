#ifndef INVENTORY_H
#define INVENTORY_H

#include <string>
#include <map>
#include "MenuItem.h"

struct StockAlert {
    std::string itemId;
    std::string itemName;
    int currentStock;
    int minimumStock;
    bool isLowStock;
};

class Inventory {
private:
    std::map<std::string, MenuItem> stock;
    std::map<std::string, int> minimumStockLevels;
    std::map<std::string, int> usageHistory;

public:
    Inventory();

    // Stock Management
    void addItem(const MenuItem& item, int minimumLevel);
    void updateStock(const std::string& itemId, int quantity);
    int getStockLevel(const std::string& itemId) const;

    // Usage Tracking
    void recordUsage(const std::string& itemId, int quantity);
    int getUsageCount(const std::string& itemId) const;

    // Alerts
    std::vector<StockAlert> getLowStockAlerts();
    bool isItemLowStock(const std::string& itemId) const;

    // Reporting
    void displayInventoryStatus();
    void displayLowStockItems();
};

#endif
