#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product {
private:
    int productId;
    std::string productName;
    double price;
    std::string category;
    std::string description;

public:
    Product(int id, const std::string& name, double price, 
            const std::string& category, const std::string& description);
    
    // Getters
    int getProductId() const;
    std::string getProductName() const;
    double getPrice() const;
    std::string getCategory() const;
    std::string getDescription() const;
    
    // Setters
    void setPrice(double newPrice);
    void setDescription(const std::string& newDescription);
    
    // Display
    void displayProduct() const;
};

#endif // PRODUCT_H
