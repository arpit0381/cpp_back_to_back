#include "Product.h"
#include <iostream>

Product::Product(int id, const std::string& name, double price, 
                 const std::string& category, const std::string& description)
    : productId(id), productName(name), price(price), 
      category(category), description(description) {}

int Product::getProductId() const {
    return productId;
}

std::string Product::getProductName() const {
    return productName;
}

double Product::getPrice() const {
    return price;
}

std::string Product::getCategory() const {
    return category;
}

std::string Product::getDescription() const {
    return description;
}

void Product::setPrice(double newPrice) {
    if (newPrice > 0) {
        price = newPrice;
    }
}

void Product::setDescription(const std::string& newDescription) {
    description = newDescription;
}

void Product::displayProduct() const {
    std::cout << "Product ID: " << productId << std::endl;
    std::cout << "Name: " << productName << std::endl;
    std::cout << "Price: $" << price << std::endl;
    std::cout << "Category: " << category << std::endl;
    std::cout << "Description: " << description << std::endl;
}
