#include "../include/Order.h"
#include <iostream>
#include <iomanip>
#include <algorithm>

Order::Order() : orderId(""), tableNumber(0), customerId(""), status(OrderStatus::PLACED),
                 subtotal(0.0), taxAmount(0.0), totalAmount(0.0),
                 orderTime(0), completionTime(0), waiterName(""), estimatedTotalTime(0) {
    orderTime = std::time(nullptr);
}

Order::Order(const std::string& id, int tableNum, const std::string& custId,
             const std::string& waiter)
    : orderId(id), tableNumber(tableNum), customerId(custId), waiterName(waiter),
      status(OrderStatus::PLACED), subtotal(0.0), taxAmount(0.0), totalAmount(0.0),
      completionTime(0), estimatedTotalTime(0) {
    orderTime = std::time(nullptr);
}

void Order::addItem(const OrderItem& item) {
    items.push_back(item);
    calculateTotals();
    estimatedTotalTime = calculateEstimatedTime();
}

void Order::removeItem(int index) {
    if (index >= 0 && index < static_cast<int>(items.size())) {
        items.erase(items.begin() + index);
        calculateTotals();
    }
}

OrderItem& Order::getItem(int index) {
    if (index >= 0 && index < static_cast<int>(items.size())) {
        return items[index];
    }
    throw std::out_of_range("Invalid item index");
}

void Order::confirmOrder() {
    status = OrderStatus::CONFIRMED;
}

void Order::startCooking() {
    status = OrderStatus::COOKING;
}

void Order::markItemReady(int itemIndex) {
    if (itemIndex >= 0 && itemIndex < static_cast<int>(items.size())) {
        items[itemIndex].setStatus(OrderItemStatus::READY);
    }
}

void Order::serveOrder() {
    for (auto& item : items) {
        if (item.getStatus() != OrderItemStatus::CANCELLED) {
            item.setStatus(OrderItemStatus::SERVED);
        }
    }
    status = OrderStatus::SERVED;
}

void Order::completeOrder() {
    status = OrderStatus::COMPLETED;
    completionTime = std::time(nullptr);
}

void Order::cancelOrder() {
    status = OrderStatus::CANCELLED;
    for (auto& item : items) {
        item.setStatus(OrderItemStatus::CANCELLED);
    }
}

void Order::calculateTotals(double taxRate) {
    subtotal = 0.0;
    for (const auto& item : items) {
        subtotal += item.getSubtotal();
    }
    taxAmount = subtotal * taxRate;
    totalAmount = subtotal + taxAmount;
}

int Order::calculateEstimatedTime() {
    int maxTime = 0;
    for (const auto& item : items) {
        if (item.getEstimatedPrepTime() > maxTime) {
            maxTime = item.getEstimatedPrepTime();
        }
    }
    return maxTime;
}

std::string Order::getStatusString() const {
    switch (status) {
        case OrderStatus::PLACED: return "Placed";
        case OrderStatus::CONFIRMED: return "Confirmed";
        case OrderStatus::COOKING: return "Cooking";
        case OrderStatus::READY: return "Ready";
        case OrderStatus::SERVED: return "Served";
        case OrderStatus::COMPLETED: return "Completed";
        case OrderStatus::CANCELLED: return "Cancelled";
        default: return "Unknown";
    }
}

void Order::displayInfo() const {
    std::cout << "\n=== ORDER DETAILS ===" << std::endl;
    std::cout << "Order ID: " << orderId << " | Table: " << tableNumber << std::endl;
    std::cout << "Customer ID: " << customerId << " | Waiter: " << waiterName << std::endl;
    std::cout << "Status: " << getStatusString() << std::endl;
    std::cout << "Items (" << items.size() << "):" << std::endl;
    
    for (const auto& item : items) {
        item.displayInfo();
    }
    
    std::cout << "\nSubtotal: ₹" << std::fixed << std::setprecision(2) << subtotal << std::endl;
    std::cout << "Tax (5%): ₹" << taxAmount << std::endl;
    std::cout << "Total: ₹" << totalAmount << std::endl;
    std::cout << "Estimated Time: " << estimatedTotalTime << " minutes" << std::endl;
    std::cout << "====================\n" << std::endl;
}

void Order::displayReceipt() const {
    std::cout << "\n" << std::string(50, '=') << std::endl;
    std::cout << std::setw(20) << std::right << "ORDER RECEIPT" << std::endl;
    std::cout << std::string(50, '=') << std::endl;
    std::cout << "Order ID: " << orderId << std::endl;
    std::cout << "Table: " << tableNumber << std::endl;
    std::cout << "Customer: " << customerId << std::endl;
    std::cout << std::string(50, '-') << std::endl;
    
    for (const auto& item : items) {
        std::cout << item.getItem().getItemName() << " x" << item.getQuantity()
                  << " ......... ₹" << std::fixed << std::setprecision(2)
                  << item.getSubtotal() << std::endl;
    }
    
    std::cout << std::string(50, '-') << std::endl;
    std::cout << std::right << std::setw(40) << "Subtotal: ₹" << std::setw(8) << subtotal << std::endl;
    std::cout << std::right << std::setw(40) << "Tax (5%): ₹" << std::setw(8) << taxAmount << std::endl;
    std::cout << std::right << std::setw(40) << "Total: ₹" << std::setw(8) << totalAmount << std::endl;
    std::cout << std::string(50, '=') << std::endl << std::endl;
}
