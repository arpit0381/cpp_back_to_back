#include "Inventory.h"
#include <iostream>

Inventory::Inventory(int id, int quantity, int reorderLevel, int reorderQuantity)
    : productId(id), quantityOnHand(quantity), 
      reorderLevel(reorderLevel), reorderQuantity(reorderQuantity) {}

int Inventory::getProductId() const {
    return productId;
}

int Inventory::getQuantityOnHand() const {
    return quantityOnHand;
}

int Inventory::getReorderLevel() const {
    return reorderLevel;
}

int Inventory::getReorderQuantity() const {
    return reorderQuantity;
}

bool Inventory::addStock(int quantity) {
    if (quantity > 0) {
        quantityOnHand += quantity;
        return true;
    }
    return false;
}

bool Inventory::removeStock(int quantity) {
    if (quantity > 0 && quantity <= quantityOnHand) {
        quantityOnHand -= quantity;
        return true;
    }
    return false;
}

bool Inventory::isLowStock() const {
    return quantityOnHand <= reorderLevel;
}

void Inventory::displayInventory() const {
    std::cout << "Product ID: " << productId << std::endl;
    std::cout << "Quantity On Hand: " << quantityOnHand << std::endl;
    std::cout << "Reorder Level: " << reorderLevel << std::endl;
    std::cout << "Reorder Quantity: " << reorderQuantity << std::endl;
    if (isLowStock()) {
        std::cout << "Status: LOW STOCK" << std::endl;
    } else {
        std::cout << "Status: OK" << std::endl;
    }
}
