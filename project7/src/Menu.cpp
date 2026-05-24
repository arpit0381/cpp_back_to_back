#include "../include/Menu.h"
#include <iostream>
#include <iomanip>
#include <iomanip>

Menu::Menu() : menuName(""), averagePrice(0.0), totalItems(0) {}

Menu::Menu(const std::string& name) : menuName(name), averagePrice(0.0), totalItems(0) {}

void Menu::addItem(const MenuItem& item) {
    itemsByCategory[item.getCategory()].push_back(item);
    itemsById[item.getItemId()] = item;
    totalItems++;
    calculateAveragePrice();
}

void Menu::removeItem(const std::string& itemId) {
    auto it = itemsById.find(itemId);
    if (it != itemsById.end()) {
        MenuItem item = it->second;
        itemsById.erase(it);
        
        auto& category = itemsByCategory[item.getCategory()];
        for (auto iter = category.begin(); iter != category.end(); ++iter) {
            if (iter->getItemId() == itemId) {
                category.erase(iter);
                break;
            }
        }
        totalItems--;
        calculateAveragePrice();
    }
}

MenuItem* Menu::getItemById(const std::string& itemId) {
    auto it = itemsById.find(itemId);
    if (it != itemsById.end()) {
        return &it->second;
    }
    return nullptr;
}

std::vector<MenuItem> Menu::getItemsByCategory(ItemCategory category) {
    std::vector<MenuItem> result;
    auto it = itemsByCategory.find(category);
    if (it != itemsByCategory.end()) {
        result = it->second;
    }
    return result;
}

void Menu::calculateAveragePrice() {
    if (totalItems == 0) {
        averagePrice = 0.0;
        return;
    }
    
    double totalPrice = 0.0;
    for (const auto& pair : itemsById) {
        totalPrice += pair.second.getPrice();
    }
    averagePrice = totalPrice / totalItems;
}

void Menu::displayMenu() const {
    std::cout << "\n" << std::string(80, '=') << std::endl;
    std::cout << std::setw(40) << std::right << menuName << std::endl;
    std::cout << std::string(80, '=') << std::endl;
    
    displayAllCategories();
    
    std::cout << std::string(80, '=') << std::endl;
    std::cout << "Total Items: " << totalItems << " | Average Price: ₹" 
              << std::fixed << std::setprecision(2) << averagePrice << std::endl;
    std::cout << std::string(80, '=') << "\n" << std::endl;
}

void Menu::displayCategory(ItemCategory category) const {
    std::cout << "\n--- ";
    switch (category) {
        case ItemCategory::APPETIZER: std::cout << "APPETIZERS"; break;
        case ItemCategory::MAIN_COURSE: std::cout << "MAIN COURSES"; break;
        case ItemCategory::DESSERT: std::cout << "DESSERTS"; break;
        case ItemCategory::BEVERAGE: std::cout << "BEVERAGES"; break;
        case ItemCategory::SOUP: std::cout << "SOUPS"; break;
        case ItemCategory::SALAD: std::cout << "SALADS"; break;
        default: std::cout << "ITEMS"; break;
    }
    std::cout << " ---\n" << std::endl;
    
    auto it = itemsByCategory.find(category);
    if (it != itemsByCategory.end()) {
        for (const auto& item : it->second) {
            item.displayInfo();
        }
    }
}

void Menu::displayAllCategories() const {
    std::cout << std::left << std::setw(15) << "ID"
              << std::setw(25) << "NAME"
              << std::setw(15) << "CATEGORY"
              << std::setw(15) << "PRICE"
              << std::setw(10) << "TYPE"
              << std::setw(15) << "TIME"
              << "STOCK" << std::endl;
    std::cout << std::string(80, '-') << std::endl;
    
    for (const auto& pair : itemsById) {
        pair.second.displayInfo();
    }
}
