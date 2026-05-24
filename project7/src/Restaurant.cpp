#include "../include/Restaurant.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstdlib>

Restaurant::Restaurant() : restaurantId(""), restaurantName(""), location(""),
                           cuisine(""), totalTables(0), taxRate(0.05), menu("Main Menu") {}

Restaurant::Restaurant(const std::string& id, const std::string& name,
                       const std::string& location, const std::string& cuisine, int tables)
    : restaurantId(id), restaurantName(name), location(location), cuisine(cuisine),
      totalTables(tables), taxRate(0.05), menu("Main Menu") {
    initializeTables();
    addMenuItems();
}

void Restaurant::initializeTables() {
    std::vector<std::string> locations = {"Window", "Corner", "Center", "Private", "Bar"};
    int capacity = 2;
    
    for (int i = 1; i <= totalTables; ++i) {
        std::string loc = locations[(i - 1) % locations.size()];
        if (i % 3 == 0) capacity = 4;
        else if (i % 2 == 0) capacity = 3;
        else capacity = 2;
        
        Table table(i, capacity, loc);
        tables.push_back(table);
    }
}

Table* Restaurant::getTable(int tableNumber) {
    for (auto& table : tables) {
        if (table.getTableNumber() == tableNumber) {
            return &table;
        }
    }
    return nullptr;
}

std::vector<Table*> Restaurant::getAvailableTables(int capacity) {
    std::vector<Table*> availableTables;
    for (auto& table : tables) {
        if (table.isAvailable() && table.getCapacity() >= capacity) {
            availableTables.push_back(&table);
        }
    }
    return availableTables;
}

int Restaurant::getOccupancyCount() const {
    int count = 0;
    for (const auto& table : tables) {
        if (table.getStatus() == TableStatus::OCCUPIED) {
            count++;
        }
    }
    return count;
}

double Restaurant::getOccupancyPercentage() const {
    if (totalTables == 0) return 0.0;
    return (static_cast<double>(getOccupancyCount()) / totalTables) * 100.0;
}

void Restaurant::addMenuItems() {
    // Appetizers
    menu.addItem(MenuItem("AP001", "Samosa", ItemCategory::APPETIZER, 80.0, "Crispy potato samosa", 8, 150, true, 50));
    menu.addItem(MenuItem("AP002", "Chicken Wings", ItemCategory::APPETIZER, 150.0, "Spicy chicken wings", 10, 200, false, 40));
    
    // Main Courses
    menu.addItem(MenuItem("MC001", "Butter Chicken", ItemCategory::MAIN_COURSE, 250.0, "Creamy butter chicken curry", 20, 350, false, 30));
    menu.addItem(MenuItem("MC002", "Paneer Tikka Masala", ItemCategory::MAIN_COURSE, 220.0, "Cottage cheese in creamy sauce", 18, 300, true, 35));
    menu.addItem(MenuItem("MC003", "Biryani", ItemCategory::MAIN_COURSE, 200.0, "Fragrant rice and meat", 25, 400, false, 40));
    
    // Desserts
    menu.addItem(MenuItem("DS001", "Gulab Jamun", ItemCategory::DESSERT, 80.0, "Sweet milk solids in syrup", 5, 250, true, 60));
    menu.addItem(MenuItem("DS002", "Cheesecake", ItemCategory::DESSERT, 120.0, "Rich NY style cheesecake", 3, 300, true, 25));
    
    // Beverages
    menu.addItem(MenuItem("BV001", "Mango Lassi", ItemCategory::BEVERAGE, 60.0, "Yogurt based mango drink", 2, 100, true, 100));
    menu.addItem(MenuItem("BV002", "Cola", ItemCategory::BEVERAGE, 50.0, "Coca Cola", 1, 150, true, 200));
    
    // Add items to inventory
    std::vector<MenuItem> allItems = {
        MenuItem("AP001", "Samosa", ItemCategory::APPETIZER, 80.0, "Crispy potato samosa", 8, 150, true, 50),
        MenuItem("AP002", "Chicken Wings", ItemCategory::APPETIZER, 150.0, "Spicy chicken wings", 10, 200, false, 40),
        MenuItem("MC001", "Butter Chicken", ItemCategory::MAIN_COURSE, 250.0, "Creamy butter chicken curry", 20, 350, false, 30),
        MenuItem("MC002", "Paneer Tikka Masala", ItemCategory::MAIN_COURSE, 220.0, "Cottage cheese in creamy sauce", 18, 300, true, 35),
        MenuItem("MC003", "Biryani", ItemCategory::MAIN_COURSE, 200.0, "Fragrant rice and meat", 25, 400, false, 40),
        MenuItem("DS001", "Gulab Jamun", ItemCategory::DESSERT, 80.0, "Sweet milk solids in syrup", 5, 250, true, 60),
        MenuItem("DS002", "Cheesecake", ItemCategory::DESSERT, 120.0, "Rich NY style cheesecake", 3, 300, true, 25),
        MenuItem("BV001", "Mango Lassi", ItemCategory::BEVERAGE, 60.0, "Yogurt based mango drink", 2, 100, true, 100),
        MenuItem("BV002", "Cola", ItemCategory::BEVERAGE, 50.0, "Coca Cola", 1, 150, true, 200)
    };
    
    for (const auto& item : allItems) {
        inventory.addItem(item, 10);
    }
}

MenuItem* Restaurant::getMenuItem(const std::string& itemId) {
    return menu.getItemById(itemId);
}

Order Restaurant::createOrder(int tableNumber, const std::string& customerId) {
    std::string orderId = "ORD" + std::to_string(orders.size() + 1);
    Order order(orderId, tableNumber, customerId, "Waiter1");
    return order;
}

void Restaurant::addItemToOrder(const std::string& orderId, const std::string& itemId,
                                int quantity, const std::string& specialRequests) {
    auto orderIt = orders.find(orderId);
    if (orderIt != orders.end()) {
        MenuItem* item = getMenuItem(itemId);
        if (item != nullptr && item->canOrderItem(quantity)) {
            std::string orderItemId = orderId + "_" + std::to_string(orderIt->second.getItemCount() + 1);
            OrderItem orderItem(orderItemId, *item, quantity, specialRequests);
            orderIt->second.addItem(orderItem);
        }
    }
}

void Restaurant::confirmOrder(const std::string& orderId) {
    auto it = orders.find(orderId);
    if (it != orders.end()) {
        it->second.confirmOrder();
    }
}

void Restaurant::sendToKitchen(const std::string& orderId) {
    auto it = orders.find(orderId);
    if (it != orders.end()) {
        Order& order = it->second;
        order.startCooking();
        
        std::string ticketId = "KT" + std::to_string(kitchenTickets.size() + 1);
        KitchenTicket ticket(ticketId, orderId, order.getTableNumber());
        
        for (int i = 0; i < order.getItemCount(); ++i) {
            OrderItem& item = order.getItem(i);
            ticket.addItem(item.getItem().getItemName(), item.getQuantity());
        }
        
        kitchenTickets.push_back(ticket);
    }
}

void Restaurant::markOrderReady(const std::string& orderId) {
    auto it = orders.find(orderId);
    if (it != orders.end()) {
        for (int i = 0; i < it->second.getItemCount(); ++i) {
            it->second.markItemReady(i);
        }
    }
}

void Restaurant::serveOrder(const std::string& orderId) {
    auto it = orders.find(orderId);
    if (it != orders.end()) {
        it->second.serveOrder();
    }
}

void Restaurant::completeOrder(const std::string& orderId) {
    auto it = orders.find(orderId);
    if (it != orders.end()) {
        it->second.completeOrder();
        analytics.recordOrder(it->second);
    }
}

Order* Restaurant::getOrder(const std::string& orderId) {
    auto it = orders.find(orderId);
    if (it != orders.end()) {
        return &it->second;
    }
    return nullptr;
}

Payment Restaurant::createPayment(const std::string& orderId, PaymentMethod method) {
    std::string paymentId = "PAY" + std::to_string(payments.size() + 1);
    Order* order = getOrder(orderId);
    
    if (order != nullptr) {
        Payment payment(paymentId, orderId, order->getTotalAmount(), method);
        payments[paymentId] = payment;
        return payment;
    }
    
    return Payment();
}

void Restaurant::processPayment(const std::string& paymentId) {
    auto it = payments.find(paymentId);
    if (it != payments.end()) {
        it->second.processPayment();
        it->second.completePayment("REF" + std::to_string(rand()));
    }
}

void Restaurant::applyDiscount(const std::string& paymentId, double discountPercent) {
    auto it = payments.find(paymentId);
    if (it != payments.end()) {
        it->second.applyDiscount(discountPercent);
    }
}

void Restaurant::registerCustomer(const Customer& customer) {
    customers[customer.getCustomerId()] = customer;
}

Customer* Restaurant::getCustomer(const std::string& customerId) {
    auto it = customers.find(customerId);
    if (it != customers.end()) {
        return &it->second;
    }
    return nullptr;
}

void Restaurant::recordCustomerVisit(const std::string& customerId, double amount) {
    auto it = customers.find(customerId);
    if (it != customers.end()) {
        it->second.recordVisit(amount);
    }
}

void Restaurant::viewKitchenQueue() {
    std::cout << "\n=== KITCHEN QUEUE ===" << std::endl;
    if (kitchenTickets.empty()) {
        std::cout << "No pending tickets!\n" << std::endl;
        return;
    }
    
    for (const auto& ticket : kitchenTickets) {
        if (ticket.getStatus() != TicketStatus::COMPLETED && 
            ticket.getStatus() != TicketStatus::CANCELLED) {
            ticket.displayTicket();
        }
    }
}

int Restaurant::getPendingKitchenTickets() const {
    int count = 0;
    for (const auto& ticket : kitchenTickets) {
        if (ticket.getStatus() == TicketStatus::RECEIVED || 
            ticket.getStatus() == TicketStatus::COOKING) {
            count++;
        }
    }
    return count;
}

void Restaurant::updateInventory() {
    // Update inventory based on completed orders
}

void Restaurant::displayInventoryStatus() {
    inventory.displayInventoryStatus();
}

void Restaurant::generateReport() {
    analytics.displayAnalyticsDashboard();
}

void Restaurant::displayDashboard() {
    std::cout << "\n" << std::string(60, '=') << std::endl;
    std::cout << "RESTAURANT MANAGEMENT SYSTEM - DASHBOARD" << std::endl;
    std::cout << std::string(60, '=') << std::endl;
    
    std::cout << "\n📍 " << restaurantName << " (" << location << ")" << std::endl;
    std::cout << "   Cuisine: " << cuisine << std::endl;
    
    std::cout << "\n📊 LIVE STATUS:" << std::endl;
    std::cout << "   Tables: " << getOccupancyCount() << "/" << totalTables 
              << " occupied (" << std::fixed << std::setprecision(1) 
              << getOccupancyPercentage() << "%)" << std::endl;
    std::cout << "   Active Orders: " << orders.size() << std::endl;
    std::cout << "   Kitchen Queue: " << getPendingKitchenTickets() << " tickets" << std::endl;
    std::cout << "   Registered Customers: " << customers.size() << std::endl;
    
    std::cout << "\n" << std::string(60, '=') << "\n" << std::endl;
}

void Restaurant::displayTableStatus() {
    std::cout << "\n=== TABLE STATUS ===" << std::endl;
    for (const auto& table : tables) {
        table.displayInfo();
    }
    std::cout << std::endl;
}

void Restaurant::displayOrderStatus() {
    std::cout << "\n=== ACTIVE ORDERS ===" << std::endl;
    for (const auto& pair : orders) {
        if (pair.second.getStatus() != OrderStatus::COMPLETED) {
            std::cout << "Table " << pair.second.getTableNumber() << " - "
                      << pair.second.getStatusString() << " - Items: "
                      << pair.second.getItemCount() << " - Total: ₹"
                      << std::fixed << std::setprecision(2) 
                      << pair.second.getTotalAmount() << std::endl;
        }
    }
    std::cout << std::endl;
}

void Restaurant::displayInfo() const {
    std::cout << "\n=== RESTAURANT INFORMATION ===" << std::endl;
    std::cout << "Restaurant ID: " << restaurantId << std::endl;
    std::cout << "Name: " << restaurantName << std::endl;
    std::cout << "Location: " << location << std::endl;
    std::cout << "Cuisine: " << cuisine << std::endl;
    std::cout << "Total Tables: " << totalTables << std::endl;
    std::cout << "==============================\n" << std::endl;
}
