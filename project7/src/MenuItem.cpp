#include "../include/MenuItem.h"
#include <iostream>
#include <iomanip>

MenuItem::MenuItem() : itemId(""), itemName(""), category(ItemCategory::MAIN_COURSE),
                       price(0.0), description(""), preparationTimeMinutes(0),
                       calorieCount(0), isVegetarian(false), isAvailable(true),
                       inventoryCount(0) {}

MenuItem::MenuItem(const std::string& id, const std::string& name, ItemCategory cat,
                   double price, const std::string& desc, int prepTime, int calories,
                   bool veg, int inventory)
    : itemId(id), itemName(name), category(cat), price(price), description(desc),
      preparationTimeMinutes(prepTime), calorieCount(calories), isVegetarian(veg),
      isAvailable(true), inventoryCount(inventory) {}

std::string MenuItem::getCategoryString() const {
    switch (category) {
        case ItemCategory::APPETIZER: return "Appetizer";
        case ItemCategory::MAIN_COURSE: return "Main Course";
        case ItemCategory::DESSERT: return "Dessert";
        case ItemCategory::BEVERAGE: return "Beverage";
        case ItemCategory::SOUP: return "Soup";
        case ItemCategory::SALAD: return "Salad";
        default: return "Unknown";
    }
}

bool MenuItem::canOrderItem(int quantity) const {
    return isAvailable && inventoryCount >= quantity;
}

void MenuItem::displayInfo() const {
    std::cout << std::left << std::setw(15) << itemId
              << std::setw(25) << itemName
              << std::setw(15) << getCategoryString()
              << "₹" << std::setw(8) << std::fixed << std::setprecision(2) << price
              << (isVegetarian ? "VEG" : "NON-VEG")
              << " | " << preparationTimeMinutes << "min"
              << " | Stock: " << inventoryCount << std::endl;
}
