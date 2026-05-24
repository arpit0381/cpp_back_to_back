#ifndef ORDER_H
#define ORDER_H

#include <string>
#include <vector>
#include <ctime>
#include "OrderItem.h"

enum class OrderStatus {
    PLACED,
    CONFIRMED,
    COOKING,
    READY,
    SERVED,
    COMPLETED,
    CANCELLED
};

class Order {
private:
    std::string orderId;
    int tableNumber;
    std::string customerId;
    std::vector<OrderItem> items;
    OrderStatus status;
    double subtotal;
    double taxAmount;
    double totalAmount;
    std::time_t orderTime;
    std::time_t completionTime;
    std::string waiterName;
    int estimatedTotalTime;

public:
    Order();
    Order(const std::string& id, int tableNum, const std::string& custId,
          const std::string& waiter);

    // Getters
    std::string getOrderId() const { return orderId; }
    int getTableNumber() const { return tableNumber; }
    std::string getCustomerId() const { return customerId; }
    OrderStatus getStatus() const { return status; }
    double getSubtotal() const { return subtotal; }
    double getTaxAmount() const { return taxAmount; }
    double getTotalAmount() const { return totalAmount; }
    int getItemCount() const { return items.size(); }
    std::string getWaiterName() const { return waiterName; }
    int getEstimatedTotalTime() const { return estimatedTotalTime; }

    // Item Management
    void addItem(const OrderItem& item);
    void removeItem(int index);
    OrderItem& getItem(int index);
    const std::vector<OrderItem>& getAllItems() const { return items; }

    // Order Operations
    void confirmOrder();
    void startCooking();
    void markItemReady(int itemIndex);
    void serveOrder();
    void completeOrder();
    void cancelOrder();

    // Calculations
    void calculateTotals(double taxRate = 0.05);
    int calculateEstimatedTime();
    std::string getStatusString() const;

    // Display
    void displayInfo() const;
    void displayReceipt() const;
};

#endif
