#ifndef CATEGORY_H
#define CATEGORY_H

#include <string>
#include <vector>

class Category {
private:
    std::string categoryId;
    std::string categoryName;
    std::string description;
    std::vector<int> productIds;

public:
    Category(const std::string& id, const std::string& name, 
             const std::string& description);
    
    // Getters
    std::string getCategoryId() const;
    std::string getCategoryName() const;
    std::string getDescription() const;
    std::vector<int> getProductIds() const;
    
    // Product operations
    void addProduct(int productId);
    void removeProduct(int productId);
    bool containsProduct(int productId) const;
    int getProductCount() const;
    
    // Display
    void displayCategory() const;
};

#endif // CATEGORY_H
