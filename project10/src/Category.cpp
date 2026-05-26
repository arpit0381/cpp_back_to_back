#include "Category.h"
#include <iostream>
#include <algorithm>

Category::Category(const std::string& id, const std::string& name, 
                   const std::string& description)
    : categoryId(id), categoryName(name), description(description) {}

std::string Category::getCategoryId() const {
    return categoryId;
}

std::string Category::getCategoryName() const {
    return categoryName;
}

std::string Category::getDescription() const {
    return description;
}

std::vector<int> Category::getProductIds() const {
    return productIds;
}

void Category::addProduct(int productId) {
    if (!containsProduct(productId)) {
        productIds.push_back(productId);
    }
}

void Category::removeProduct(int productId) {
    auto it = std::find(productIds.begin(), productIds.end(), productId);
    if (it != productIds.end()) {
        productIds.erase(it);
    }
}

bool Category::containsProduct(int productId) const {
    return std::find(productIds.begin(), productIds.end(), productId) != productIds.end();
}

int Category::getProductCount() const {
    return productIds.size();
}

void Category::displayCategory() const {
    std::cout << "Category ID: " << categoryId << std::endl;
    std::cout << "Name: " << categoryName << std::endl;
    std::cout << "Description: " << description << std::endl;
    std::cout << "Product Count: " << productIds.size() << std::endl;
}
