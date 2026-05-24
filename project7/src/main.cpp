#include "../include/Restaurant.h"
#include <iostream>
#include <vector>
#include <map>

void displayMainMenu() {
    std::cout << "\n" << std::string(60, '=') << std::endl;
    std::cout << "RESTAURANT MANAGEMENT SYSTEM" << std::endl;
    std::cout << std::string(60, '=') << std::endl;
    std::cout << "1. View Menu" << std::endl;
    std::cout << "2. Create Order" << std::endl;
    std::cout << "3. Add Item to Order" << std::endl;
    std::cout << "4. Confirm Order" << std::endl;
    std::cout << "5. Send to Kitchen" << std::endl;
    std::cout << "6. Serve Order" << std::endl;
    std::cout << "7. Process Payment" << std::endl;
    std::cout << "8. View Kitchen Queue" << std::endl;
    std::cout << "9. View Table Status" << std::endl;
    std::cout << "10. View Order Status" << std::endl;
    std::cout << "11. Display Dashboard" << std::endl;
    std::cout << "12. Generate Reports" << std::endl;
    std::cout << "13. Inventory Status" << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout << std::string(60, '=') << std::endl;
    std::cout << "Enter choice: ";
}

int main() {
    // Initialize restaurant
    Restaurant restaurant("REST001", "Gourmet Palace", "5th Avenue", "Multi-Cuisine", 10);
    
    // Register some sample customers
    Customer cust1("CUST001", "John Doe", "9876543210", "john@email.com");
    Customer cust2("CUST002", "Jane Smith", "9876543211", "jane@email.com");
    restaurant.registerCustomer(cust1);
    restaurant.registerCustomer(cust2);
    
    int choice;
    bool running = true;
    std::map<std::string, Order*> activeOrders;
    
    while (running) {
        displayMainMenu();
        std::cin >> choice;
        std::cin.ignore();
        
        switch (choice) {
            case 1: {
                // View Menu
                restaurant.getMenu().displayMenu();
                break;
            }
            
            case 2: {
                // Create Order
                std::cout << "\n--- CREATE NEW ORDER ---" << std::endl;
                restaurant.displayTableStatus();
                
                int tableNum;
                std::string customerId;
                std::cout << "Enter Table Number: ";
                std::cin >> tableNum;
                std::cin.ignore();
                std::cout << "Enter Customer ID: ";
                std::getline(std::cin, customerId);
                
                Table* table = restaurant.getTable(tableNum);
                if (table != nullptr && table->isAvailable()) {
                    table->occupyTable(customerId);
                    Order newOrder = restaurant.createOrder(tableNum, customerId);
                    activeOrders[newOrder.getOrderId()] = nullptr;
                    std::cout << "Order created! Order ID: " << newOrder.getOrderId() << std::endl;
                } else {
                    std::cout << "Table not available!\n";
                }
                break;
            }
            
            case 3: {
                // Add Item to Order
                std::cout << "\n--- ADD ITEM TO ORDER ---" << std::endl;
                std::string orderId, itemId;
                int quantity;
                
                std::cout << "Enter Order ID: ";
                std::getline(std::cin, orderId);
                
                restaurant.getMenu().displayMenu();
                
                std::cout << "Enter Item ID: ";
                std::getline(std::cin, itemId);
                std::cout << "Enter Quantity: ";
                std::cin >> quantity;
                std::cin.ignore();
                
                std::string specialRequests;
                std::cout << "Special Requests (if any): ";
                std::getline(std::cin, specialRequests);
                
                restaurant.addItemToOrder(orderId, itemId, quantity, specialRequests);
                std::cout << "Item added to order!\n";
                break;
            }
            
            case 4: {
                // Confirm Order
                std::cout << "\n--- CONFIRM ORDER ---" << std::endl;
                std::string orderId;
                std::cout << "Enter Order ID: ";
                std::getline(std::cin, orderId);
                
                restaurant.confirmOrder(orderId);
                Order* order = restaurant.getOrder(orderId);
                if (order != nullptr) {
                    order->displayInfo();
                }
                break;
            }
            
            case 5: {
                // Send to Kitchen
                std::cout << "\n--- SEND TO KITCHEN ---" << std::endl;
                std::string orderId;
                std::cout << "Enter Order ID: ";
                std::getline(std::cin, orderId);
                
                restaurant.sendToKitchen(orderId);
                std::cout << "Order sent to kitchen!\n";
                break;
            }
            
            case 6: {
                // Serve Order
                std::cout << "\n--- SERVE ORDER ---" << std::endl;
                std::string orderId;
                std::cout << "Enter Order ID: ";
                std::getline(std::cin, orderId);
                
                restaurant.serveOrder(orderId);
                restaurant.completeOrder(orderId);
                
                Order* order = restaurant.getOrder(orderId);
                if (order != nullptr) {
                    order->displayReceipt();
                    
                    // Release table
                    Table* table = restaurant.getTable(order->getTableNumber());
                    if (table != nullptr) {
                        table->releaseTable();
                    }
                }
                break;
            }
            
            case 7: {
                // Process Payment
                std::cout << "\n--- PROCESS PAYMENT ---" << std::endl;
                std::string orderId;
                std::cout << "Enter Order ID: ";
                std::getline(std::cin, orderId);
                
                Order* order = restaurant.getOrder(orderId);
                if (order != nullptr) {
                    std::cout << "Payment Methods: 1=Cash, 2=Card, 3=Wallet, 4=Cheque\n";
                    int method;
                    std::cout << "Select payment method: ";
                    std::cin >> method;
                    std::cin.ignore();
                    
                    PaymentMethod paymentMethod = static_cast<PaymentMethod>(method - 1);
                    Payment payment = restaurant.createPayment(orderId, paymentMethod);
                    restaurant.processPayment(payment.getPaymentId());
                    payment.displayInfo();
                    
                    std::cout << "✓ Payment Completed!\n";
                }
                break;
            }
            
            case 8: {
                // View Kitchen Queue
                restaurant.viewKitchenQueue();
                break;
            }
            
            case 9: {
                // View Table Status
                restaurant.displayTableStatus();
                break;
            }
            
            case 10: {
                // View Order Status
                restaurant.displayOrderStatus();
                break;
            }
            
            case 11: {
                // Display Dashboard
                restaurant.displayDashboard();
                break;
            }
            
            case 12: {
                // Generate Reports
                std::cout << "\n--- GENERATING REPORTS ---\n";
                restaurant.generateReport();
                break;
            }
            
            case 13: {
                // Inventory Status
                restaurant.displayInventoryStatus();
                break;
            }
            
            case 0: {
                std::cout << "\nThank you for using Restaurant Management System!\n\n";
                running = false;
                break;
            }
            
            default:
                std::cout << "Invalid choice! Please try again.\n";
        }
    }
    
    return 0;
}
