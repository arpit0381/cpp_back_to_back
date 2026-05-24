#ifndef MENUITEM_H
#define MENUITEM_H

#include <string>
#include <vector>

enum class ItemCategory {
    APPETIZER,
    MAIN_COURSE,
    DESSERT,
    BEVERAGE,
    SOUP,
    SALAD
};

class MenuItem {
private:
    std::string itemId;
    std::string itemName;
    ItemCategory category;
    double price;
    std::string description;
    int preparationTimeMinutes;
    int calorieCount;
    bool isVegetarian;
    bool isAvailable;
    int inventoryCount;

public:
    MenuItem();
    MenuItem(const std::string& id, const std::string& name, ItemCategory cat,
             double price, const std::string& desc, int prepTime, int calories,
             bool veg, int inventory);

    // Getters
    std::string getItemId() const { return itemId; }
    std::string getItemName() const { return itemName; }
    ItemCategory getCategory() const { return category; }
    double getPrice() const { return price; }
    std::string getDescription() const { return description; }
    int getPreparationTime() const { return preparationTimeMinutes; }
    int getCalories() const { return calorieCount; }
    bool getIsVegetarian() const { return isVegetarian; }
    bool getIsAvailable() const { return isAvailable; }
    int getInventoryCount() const { return inventoryCount; }

    // Setters
    void setPrice(double p) { price = p; }
    void setAvailability(bool avail) { isAvailable = avail; }
    void setInventoryCount(int count) { inventoryCount = count; }
    void decrementInventory(int qty) { inventoryCount -= qty; }
    void incrementInventory(int qty) { inventoryCount += qty; }

    // Methods
    std::string getCategoryString() const;
    bool canOrderItem(int quantity) const;

    // Display
    void displayInfo() const;
};

#endif
