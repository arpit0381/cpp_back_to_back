#ifndef INVENTORY_H
#define INVENTORY_H

#include "Product.h"

class Inventory {
private:
    int productId;
    int quantityOnHand;
    int reorderLevel;
    int reorderQuantity;

public:
    Inventory(int id, int quantity, int reorderLevel, int reorderQuantity);
    
    // Getters
    int getProductId() const;
    int getQuantityOnHand() const;
    int getReorderLevel() const;
    int getReorderQuantity() const;
    
    // Stock operations
    bool addStock(int quantity);
    bool removeStock(int quantity);
    bool isLowStock() const;
    
    // Display
    void displayInventory() const;
};

#endif // INVENTORY_H
