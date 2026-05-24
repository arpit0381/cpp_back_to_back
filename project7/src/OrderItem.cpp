#include "../include/OrderItem.h"
#include <iostream>
#include <iomanip>

OrderItem::OrderItem() : orderItemId(""), item(), quantity(0), subtotal(0.0),
                         status(OrderItemStatus::PENDING), specialRequests(""),
                         estimatedPrepTime(0) {}

OrderItem::OrderItem(const std::string& id, const MenuItem& item, int qty,
                     const std::string& requests)
    : orderItemId(id), item(item), quantity(qty), specialRequests(requests),
      status(OrderItemStatus::PENDING) {
    estimatedPrepTime = item.getPreparationTime();
    calculateSubtotal();
}

void OrderItem::calculateSubtotal() {
    subtotal = item.getPrice() * quantity;
}

std::string OrderItem::getStatusString() const {
    switch (status) {
        case OrderItemStatus::PENDING: return "Pending";
        case OrderItemStatus::COOKING: return "Cooking";
        case OrderItemStatus::READY: return "Ready";
        case OrderItemStatus::SERVED: return "Served";
        case OrderItemStatus::CANCELLED: return "Cancelled";
        default: return "Unknown";
    }
}

void OrderItem::displayInfo() const {
    std::cout << "  " << orderItemId << " | " << item.getItemName()
              << " x" << quantity << " = ₹" << std::fixed << std::setprecision(2)
              << subtotal << " | " << getStatusString();
    if (!specialRequests.empty()) {
        std::cout << " | Special: " << specialRequests;
    }
    std::cout << std::endl;
}
