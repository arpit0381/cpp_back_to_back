#ifndef ORDERITEM_H
#define ORDERITEM_H

#include <string>
#include "MenuItem.h"

enum class OrderItemStatus {
    PENDING,
    COOKING,
    READY,
    SERVED,
    CANCELLED
};

class OrderItem {
private:
    std::string orderItemId;
    MenuItem item;
    int quantity;
    double subtotal;
    OrderItemStatus status;
    std::string specialRequests;
    int estimatedPrepTime;

public:
    OrderItem();
    OrderItem(const std::string& id, const MenuItem& item, int qty,
              const std::string& requests = "");

    // Getters
    std::string getOrderItemId() const { return orderItemId; }
    MenuItem getItem() const { return item; }
    int getQuantity() const { return quantity; }
    double getSubtotal() const { return subtotal; }
    OrderItemStatus getStatus() const { return status; }
    std::string getSpecialRequests() const { return specialRequests; }
    int getEstimatedPrepTime() const { return estimatedPrepTime; }

    // Setters
    void setStatus(OrderItemStatus s) { status = s; }
    void setSpecialRequests(const std::string& req) { specialRequests = req; }

    // Methods
    void calculateSubtotal();
    std::string getStatusString() const;

    // Display
    void displayInfo() const;
};

#endif
