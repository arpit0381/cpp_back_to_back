#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <string>
#include <vector>
#include <map>
#include "Menu.h"
#include "Table.h"
#include "Order.h"
#include "Payment.h"
#include "Customer.h"
#include "Inventory.h"
#include "KitchenTicket.h"
#include "RestaurantAnalytics.h"

class Restaurant {
private:
    std::string restaurantId;
    std::string restaurantName;
    std::string location;
    std::string cuisine;
    int totalTables;
    double taxRate;

    Menu menu;
    std::vector<Table> tables;
    std::map<std::string, Order> orders;
    std::map<std::string, Payment> payments;
    std::map<std::string, Customer> customers;
    std::vector<KitchenTicket> kitchenTickets;
    Inventory inventory;
    RestaurantAnalytics analytics;

public:
    Restaurant();
    Restaurant(const std::string& id, const std::string& name,
               const std::string& location, const std::string& cuisine, int tables);

    // Getters
    std::string getRestaurantId() const { return restaurantId; }
    std::string getRestaurantName() const { return restaurantName; }
    std::string getLocation() const { return location; }
    std::string getCuisine() const { return cuisine; }
    int getTotalTables() const { return totalTables; }
    Menu& getMenu() { return menu; }

    // Table Management
    void initializeTables();
    Table* getTable(int tableNumber);
    std::vector<Table*> getAvailableTables(int capacity);
    int getOccupancyCount() const;
    double getOccupancyPercentage() const;

    // Menu Management
    void addMenuItems();
    MenuItem* getMenuItem(const std::string& itemId);

    // Order Management
    Order createOrder(int tableNumber, const std::string& customerId);
    void addItemToOrder(const std::string& orderId, const std::string& itemId,
                        int quantity, const std::string& specialRequests = "");
    void confirmOrder(const std::string& orderId);
    void sendToKitchen(const std::string& orderId);
    void markOrderReady(const std::string& orderId);
    void serveOrder(const std::string& orderId);
    void completeOrder(const std::string& orderId);
    Order* getOrder(const std::string& orderId);

    // Payment Management
    Payment createPayment(const std::string& orderId, PaymentMethod method);
    void processPayment(const std::string& paymentId);
    void applyDiscount(const std::string& paymentId, double discountPercent);

    // Customer Management
    void registerCustomer(const Customer& customer);
    Customer* getCustomer(const std::string& customerId);
    void recordCustomerVisit(const std::string& customerId, double amount);

    // Kitchen Operations
    void viewKitchenQueue();
    int getPendingKitchenTickets() const;

    // Inventory Management
    void updateInventory();
    void displayInventoryStatus();

    // Analytics & Reporting
    void generateReport();
    void displayDashboard();
    void displayTableStatus();
    void displayOrderStatus();

    // Display
    void displayInfo() const;
};

#endif
