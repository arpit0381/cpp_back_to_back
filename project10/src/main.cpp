#include "ProductManager.h"
#include <iostream>
#include <iomanip>

void displayMenu() {
    std::cout << "\n========== E-Commerce Product Manager ==========" << std::endl;
    std::cout << "1. Add Product" << std::endl;
    std::cout << "2. Remove Product" << std::endl;
    std::cout << "3. Add Inventory" << std::endl;
    std::cout << "4. Update Stock" << std::endl;
    std::cout << "5. Add Category" << std::endl;
    std::cout << "6. Add Product to Category" << std::endl;
    std::cout << "7. Display All Products" << std::endl;
    std::cout << "8. Display All Categories" << std::endl;
    std::cout << "9. Display Inventory" << std::endl;
    std::cout << "10. Display Low Stock Items" << std::endl;
    std::cout << "11. Search by Price Range" << std::endl;
    std::cout << "12. Search by Category" << std::endl;
    std::cout << "13. Search by Name" << std::endl;
    std::cout << "14. Display Category Details" << std::endl;
    std::cout << "15. Display Statistics" << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout << "================================================" << std::endl;
    std::cout << "Enter your choice: ";
}

int main() {
    ProductManager manager;
    int choice;
    
    // Add some sample data
    manager.addProduct(1, "Laptop", 999.99, "Electronics", "High-performance laptop");
    manager.addProduct(2, "Desk Chair", 199.99, "Furniture", "Ergonomic office chair");
    manager.addProduct(3, "USB Cable", 9.99, "Electronics", "USB-C charging cable");
    manager.addProduct(4, "Monitor Stand", 49.99, "Furniture", "Adjustable monitor stand");
    manager.addProduct(5, "Keyboard", 79.99, "Electronics", "Mechanical gaming keyboard");
    
    // Add categories
    manager.addCategory("ELEC", "Electronics", "Electronic devices and accessories");
    manager.addCategory("FURN", "Furniture", "Office and home furniture");
    
    // Add products to categories
    manager.addProductToCategory(1, "ELEC");
    manager.addProductToCategory(3, "ELEC");
    manager.addProductToCategory(5, "ELEC");
    manager.addProductToCategory(2, "FURN");
    manager.addProductToCategory(4, "FURN");
    
    // Add inventory
    manager.addInventory(1, 15, 5, 10);
    manager.addInventory(2, 8, 3, 5);
    manager.addInventory(3, 2, 10, 20);  // Low stock
    manager.addInventory(4, 12, 4, 8);
    manager.addInventory(5, 25, 5, 15);
    
    while (true) {
        displayMenu();
        std::cin >> choice;
        std::cin.ignore();
        
        switch (choice) {
            case 1: {
                int id;
                std::string name, category, description;
                double price;
                
                std::cout << "Enter Product ID: ";
                std::cin >> id;
                std::cin.ignore();
                std::cout << "Enter Product Name: ";
                std::getline(std::cin, name);
                std::cout << "Enter Price: ";
                std::cin >> price;
                std::cin.ignore();
                std::cout << "Enter Category: ";
                std::getline(std::cin, category);
                std::cout << "Enter Description: ";
                std::getline(std::cin, description);
                
                manager.addProduct(id, name, price, category, description);
                break;
            }
            
            case 2: {
                int id;
                std::cout << "Enter Product ID to remove: ";
                std::cin >> id;
                
                if (manager.removeProduct(id)) {
                    std::cout << "Product removed successfully!" << std::endl;
                } else {
                    std::cout << "Product not found!" << std::endl;
                }
                break;
            }
            
            case 3: {
                int id, qty, reorder, reorderQty;
                std::cout << "Enter Product ID: ";
                std::cin >> id;
                std::cout << "Enter Initial Quantity: ";
                std::cin >> qty;
                std::cout << "Enter Reorder Level: ";
                std::cin >> reorder;
                std::cout << "Enter Reorder Quantity: ";
                std::cin >> reorderQty;
                
                manager.addInventory(id, qty, reorder, reorderQty);
                break;
            }
            
            case 4: {
                int id, change;
                std::cout << "Enter Product ID: ";
                std::cin >> id;
                std::cout << "Enter quantity change (positive to add, negative to remove): ";
                std::cin >> change;
                
                if (manager.updateStock(id, change)) {
                    std::cout << "Stock updated successfully!" << std::endl;
                } else {
                    std::cout << "Stock update failed!" << std::endl;
                }
                break;
            }
            
            case 5: {
                std::string id, name, description;
                std::cout << "Enter Category ID: ";
                std::getline(std::cin, id);
                std::cout << "Enter Category Name: ";
                std::getline(std::cin, name);
                std::cout << "Enter Category Description: ";
                std::getline(std::cin, description);
                
                manager.addCategory(id, name, description);
                break;
            }
            
            case 6: {
                int productId;
                std::string categoryId;
                std::cout << "Enter Product ID: ";
                std::cin >> productId;
                std::cin.ignore();
                std::cout << "Enter Category ID: ";
                std::getline(std::cin, categoryId);
                
                if (manager.addProductToCategory(productId, categoryId)) {
                    std::cout << "Product added to category!" << std::endl;
                } else {
                    std::cout << "Failed to add product to category!" << std::endl;
                }
                break;
            }
            
            case 7:
                manager.displayAllProducts();
                break;
            
            case 8:
                manager.displayAllCategories();
                break;
            
            case 9:
                manager.displayAllInventory();
                break;
            
            case 10:
                manager.displayLowStockItems();
                break;
            
            case 11: {
                double minPrice, maxPrice;
                std::cout << "Enter minimum price: ";
                std::cin >> minPrice;
                std::cout << "Enter maximum price: ";
                std::cin >> maxPrice;
                
                manager.searchByPrice(minPrice, maxPrice);
                break;
            }
            
            case 12: {
                std::string categoryId;
                std::cin.ignore();
                std::cout << "Enter Category ID: ";
                std::getline(std::cin, categoryId);
                
                manager.searchByCategory(categoryId);
                break;
            }
            
            case 13: {
                std::string productName;
                std::cin.ignore();
                std::cout << "Enter Product Name (or part of it): ";
                std::getline(std::cin, productName);
                
                manager.searchByName(productName);
                break;
            }
            
            case 14: {
                std::string categoryId;
                std::cin.ignore();
                std::cout << "Enter Category ID: ";
                std::getline(std::cin, categoryId);
                
                manager.displayCategory(categoryId);
                break;
            }
            
            case 15: {
                std::cout << "\n=== System Statistics ===" << std::endl;
                std::cout << "Total Products: " << manager.getTotalProducts() << std::endl;
                std::cout << "Total Inventory Value: $" << std::fixed << std::setprecision(2) 
                         << manager.getTotalInventoryValue() << std::endl;
                break;
            }
            
            case 0:
                std::cout << "Exiting... Thank you!" << std::endl;
                return 0;
            
            default:
                std::cout << "Invalid choice! Please try again." << std::endl;
        }
    }
    
    return 0;
}
