#ifndef PRODUCTMANAGER_H
#define PRODUCTMANAGER_H

#include "Product.h"
#include "Inventory.h"
#include "Category.h"
#include <vector>
#include <map>
#include <memory>

class ProductManager {
private:
    std::map<int, std::unique_ptr<Product>> products;
    std::map<int, std::unique_ptr<Inventory>> inventories;
    std::map<std::string, std::unique_ptr<Category>> categories;

public:
    ProductManager();
    
    // Product operations
    void addProduct(int id, const std::string& name, double price, 
                    const std::string& category, const std::string& description);
    bool removeProduct(int productId);
    Product* getProduct(int productId);
    void displayAllProducts() const;
    
    // Inventory operations
    void addInventory(int productId, int quantity, int reorderLevel, int reorderQuantity);
    bool updateStock(int productId, int quantityChange);
    void displayLowStockItems() const;
    void displayAllInventory() const;
    
    // Category operations
    void addCategory(const std::string& id, const std::string& name, 
                     const std::string& description);
    bool addProductToCategory(int productId, const std::string& categoryId);
    void displayCategory(const std::string& categoryId) const;
    void displayAllCategories() const;
    
    // Search operations
    void searchByPrice(double minPrice, double maxPrice) const;
    void searchByCategory(const std::string& categoryId) const;
    void searchByName(const std::string& productName) const;
    
    // Statistics
    int getTotalProducts() const;
    double getTotalInventoryValue() const;
};

#endif // PRODUCTMANAGER_H
