#include "ProductManager.h"
#include <iostream>
#include <iomanip>

ProductManager::ProductManager() {}

void ProductManager::addProduct(int id, const std::string& name, double price, 
                                 const std::string& category, const std::string& description) {
    products[id] = std::make_unique<Product>(id, name, price, category, description);
    std::cout << "Product added successfully!" << std::endl;
}

bool ProductManager::removeProduct(int productId) {
    auto it = products.find(productId);
    if (it != products.end()) {
        products.erase(it);
        inventories.erase(productId);
        return true;
    }
    return false;
}

Product* ProductManager::getProduct(int productId) {
    auto it = products.find(productId);
    if (it != products.end()) {
        return it->second.get();
    }
    return nullptr;
}

void ProductManager::displayAllProducts() const {
    if (products.empty()) {
        std::cout << "No products in the system." << std::endl;
        return;
    }
    
    std::cout << "\n=== All Products ===" << std::endl;
    for (const auto& [id, product] : products) {
        product->displayProduct();
        std::cout << std::string(40, '-') << std::endl;
    }
}

void ProductManager::addInventory(int productId, int quantity, 
                                   int reorderLevel, int reorderQuantity) {
    if (products.find(productId) != products.end()) {
        inventories[productId] = std::make_unique<Inventory>(productId, quantity, 
                                                              reorderLevel, reorderQuantity);
        std::cout << "Inventory added successfully!" << std::endl;
    } else {
        std::cout << "Product not found!" << std::endl;
    }
}

bool ProductManager::updateStock(int productId, int quantityChange) {
    auto it = inventories.find(productId);
    if (it != inventories.end()) {
        if (quantityChange > 0) {
            return it->second->addStock(quantityChange);
        } else if (quantityChange < 0) {
            return it->second->removeStock(-quantityChange);
        }
    }
    return false;
}

void ProductManager::displayLowStockItems() const {
    std::cout << "\n=== Low Stock Items ===" << std::endl;
    bool found = false;
    
    for (const auto& [id, inventory] : inventories) {
        if (inventory->isLowStock()) {
            auto product = products.find(id);
            if (product != products.end()) {
                std::cout << "Product: " << product->second->getProductName() 
                         << " | Quantity: " << inventory->getQuantityOnHand() << std::endl;
                found = true;
            }
        }
    }
    
    if (!found) {
        std::cout << "No low stock items." << std::endl;
    }
}

void ProductManager::displayAllInventory() const {
    if (inventories.empty()) {
        std::cout << "No inventory records." << std::endl;
        return;
    }
    
    std::cout << "\n=== All Inventory ===" << std::endl;
    for (const auto& [id, inventory] : inventories) {
        inventory->displayInventory();
        std::cout << std::string(40, '-') << std::endl;
    }
}

void ProductManager::addCategory(const std::string& id, const std::string& name, 
                                  const std::string& description) {
    categories[id] = std::make_unique<Category>(id, name, description);
    std::cout << "Category added successfully!" << std::endl;
}

bool ProductManager::addProductToCategory(int productId, const std::string& categoryId) {
    auto cat_it = categories.find(categoryId);
    if (cat_it != categories.end()) {
        cat_it->second->addProduct(productId);
        return true;
    }
    return false;
}

void ProductManager::displayCategory(const std::string& categoryId) const {
    auto it = categories.find(categoryId);
    if (it != categories.end()) {
        std::cout << "\n=== Category Details ===" << std::endl;
        it->second->displayCategory();
    } else {
        std::cout << "Category not found!" << std::endl;
    }
}

void ProductManager::displayAllCategories() const {
    if (categories.empty()) {
        std::cout << "No categories in the system." << std::endl;
        return;
    }
    
    std::cout << "\n=== All Categories ===" << std::endl;
    for (const auto& [id, category] : categories) {
        category->displayCategory();
        std::cout << std::string(40, '-') << std::endl;
    }
}

void ProductManager::searchByPrice(double minPrice, double maxPrice) const {
    std::cout << "\n=== Products by Price Range ($" << minPrice << " - $" 
              << maxPrice << ") ===" << std::endl;
    
    bool found = false;
    for (const auto& [id, product] : products) {
        if (product->getPrice() >= minPrice && product->getPrice() <= maxPrice) {
            std::cout << product->getProductName() << " - $" 
                     << std::fixed << std::setprecision(2) << product->getPrice() << std::endl;
            found = true;
        }
    }
    
    if (!found) {
        std::cout << "No products found in the specified price range." << std::endl;
    }
}

void ProductManager::searchByCategory(const std::string& categoryId) const {
    auto it = categories.find(categoryId);
    if (it != categories.end()) {
        std::cout << "\n=== Products in Category: " << it->second->getCategoryName() << " ===" << std::endl;
        const auto& productIds = it->second->getProductIds();
        
        if (productIds.empty()) {
            std::cout << "No products in this category." << std::endl;
            return;
        }
        
        for (int productId : productIds) {
            auto product = products.find(productId);
            if (product != products.end()) {
                std::cout << product->second->getProductName() << std::endl;
            }
        }
    } else {
        std::cout << "Category not found!" << std::endl;
    }
}

void ProductManager::searchByName(const std::string& productName) const {
    std::cout << "\n=== Search Results for: " << productName << " ===" << std::endl;
    
    bool found = false;
    for (const auto& [id, product] : products) {
        if (product->getProductName().find(productName) != std::string::npos) {
            product->displayProduct();
            std::cout << std::string(40, '-') << std::endl;
            found = true;
        }
    }
    
    if (!found) {
        std::cout << "No products found with that name." << std::endl;
    }
}

int ProductManager::getTotalProducts() const {
    return products.size();
}

double ProductManager::getTotalInventoryValue() const {
    double totalValue = 0.0;
    for (const auto& [id, inventory] : inventories) {
        auto product = products.find(id);
        if (product != products.end()) {
            totalValue += product->second->getPrice() * inventory->getQuantityOnHand();
        }
    }
    return totalValue;
}
