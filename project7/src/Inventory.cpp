#include "../include/Inventory.h"
#include <iostream>
#include <iomanip>

Inventory::Inventory() {}

void Inventory::addItem(const MenuItem& item, int minimumLevel) {
    stock[item.getItemId()] = item;
    minimumStockLevels[item.getItemId()] = minimumLevel;
}

void Inventory::updateStock(const std::string& itemId, int quantity) {
    auto it = stock.find(itemId);
    if (it != stock.end()) {
        it->second.setInventoryCount(quantity);
    }
}

int Inventory::getStockLevel(const std::string& itemId) const {
    auto it = stock.find(itemId);
    if (it != stock.end()) {
        return it->second.getInventoryCount();
    }
    return 0;
}

void Inventory::recordUsage(const std::string& itemId, int quantity) {
    usageHistory[itemId] += quantity;
    auto it = stock.find(itemId);
    if (it != stock.end()) {
        it->second.decrementInventory(quantity);
    }
}

int Inventory::getUsageCount(const std::string& itemId) const {
    auto it = usageHistory.find(itemId);
    if (it != usageHistory.end()) {
        return it->second;
    }
    return 0;
}

std::vector<StockAlert> Inventory::getLowStockAlerts() {
    std::vector<StockAlert> alerts;
    
    for (const auto& pair : minimumStockLevels) {
        int currentStock = getStockLevel(pair.first);
        if (currentStock <= pair.second) {
            StockAlert alert;
            alert.itemId = pair.first;
            auto it = stock.find(pair.first);
            if (it != stock.end()) {
                alert.itemName = it->second.getItemName();
            }
            alert.currentStock = currentStock;
            alert.minimumStock = pair.second;
            alert.isLowStock = true;
            alerts.push_back(alert);
        }
    }
    
    return alerts;
}

bool Inventory::isItemLowStock(const std::string& itemId) const {
    int current = getStockLevel(itemId);
    auto it = minimumStockLevels.find(itemId);
    if (it != minimumStockLevels.end()) {
        return current <= it->second;
    }
    return false;
}

void Inventory::displayInventoryStatus() {
    std::cout << "\n=== INVENTORY STATUS ===" << std::endl;
    std::cout << std::left << std::setw(15) << "Item ID"
              << std::setw(25) << "Item Name"
              << std::setw(10) << "Current"
              << std::setw(10) << "Minimum"
              << "Status" << std::endl;
    std::cout << std::string(70, '-') << std::endl;
    
    for (const auto& pair : stock) {
        int current = pair.second.getInventoryCount();
        auto minIt = minimumStockLevels.find(pair.first);
        int minimum = (minIt != minimumStockLevels.end()) ? minIt->second : 0;
        
        std::cout << std::left << std::setw(15) << pair.first
                  << std::setw(25) << pair.second.getItemName()
                  << std::setw(10) << current
                  << std::setw(10) << minimum
                  << (current <= minimum ? "LOW STOCK" : "OK") << std::endl;
    }
}

void Inventory::displayLowStockItems() {
    std::vector<StockAlert> alerts = getLowStockAlerts();
    
    if (alerts.empty()) {
        std::cout << "\nNo low stock items!\n" << std::endl;
        return;
    }
    
    std::cout << "\n=== LOW STOCK ALERTS ===" << std::endl;
    for (const auto& alert : alerts) {
        std::cout << "⚠ " << alert.itemName << " (" << alert.itemId << ")"
                  << " - Current: " << alert.currentStock
                  << ", Minimum: " << alert.minimumStock << std::endl;
    }
    std::cout << std::endl;
}
