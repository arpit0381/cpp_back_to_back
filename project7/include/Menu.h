#ifndef MENU_H
#define MENU_H

#include <string>
#include <vector>
#include <map>
#include "MenuItem.h"

class Menu {
private:
    std::string menuName;
    std::map<ItemCategory, std::vector<MenuItem>> itemsByCategory;
    std::map<std::string, MenuItem> itemsById;
    double averagePrice;
    int totalItems;

public:
    Menu();
    Menu(const std::string& name);

    // Getters
    std::string getMenuName() const { return menuName; }
    double getAveragePrice() const { return averagePrice; }
    int getTotalItems() const { return totalItems; }

    // Item Management
    void addItem(const MenuItem& item);
    void removeItem(const std::string& itemId);
    MenuItem* getItemById(const std::string& itemId);
    std::vector<MenuItem> getItemsByCategory(ItemCategory category);

    // Calculations
    void calculateAveragePrice();

    // Display
    void displayMenu() const;
    void displayCategory(ItemCategory category) const;
    void displayAllCategories() const;
};

#endif
