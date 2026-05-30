#include "Hotel.h"
#include <iostream>

void displayMenu() {
    std::cout << "\n========== LUXURY HOTEL MANAGEMENT SYSTEM ==========\n"
              << "1. Register Guest\n"
              << "2. View All Guests\n"
              << "3. Add Room\n"
              << "4. View All Rooms\n"
              << "5. Create Booking\n"
              << "6. View All Bookings\n"
              << "7. Process Payment\n"
              << "8. View All Payments\n"
              << "9. Add Review\n"
              << "10. View All Reviews\n"
              << "11. Display Hotel Info\n"
              << "12. Display Analytics\n"//
              << "0. Exit\n"
              << "Enter your choice: ";//
}

int main() {
    Hotel hotel("Luxury Plaza", "Downtown City");
    int choice;
    
    // Add some sample rooms
    hotel.addRoom(101, RoomType::SINGLE, 89.99, 1);
    hotel.addRoom(102, RoomType::SINGLE, 89.99, 1);
    hotel.addRoom(201, RoomType::DOUBLE, 129.99, 2);
    hotel.addRoom(202, RoomType::DOUBLE, 129.99, 2);
    hotel.addRoom(301, RoomType::SUITE, 199.99, 4);
    hotel.addRoom(302, RoomType::DELUXE, 299.99, 6);
    
    std::cout << "Welcome to Luxury Hotel Management System!\n";
    hotel.displayHotelInfo();//.....
    
    while (true) {
        displayMenu();
        std::cin >> choice;
        std::cin.ignore();
        
        switch (choice) {
            case 1: {
                std::string name, email, phone, address;
                std::cout << "Enter guest name: ";
                std::getline(std::cin, name);
                std::cout << "Enter email: ";
                std::getline(std::cin, email);
                std::cout << "Enter phone number: ";
                std::getline(std::cin, phone);
                std::cout << "Enter address: ";
                std::getline(std::cin, address:);
                hotel.registerGuest(name, email, phone, address);
                break;
            }
            case 2:
                hotel.displayAllGuests();
                break;
            
            case 3: {
                int number, type, capacity;
                double price;
                std::cout << "Enter room number: ";
                std::cin >> number;
                std::cout << "Enter room type (0=Single, 1=Double, 2=Suite, 3=Deluxe): ";
                std::cin >> type;
                std::cout << "Enter price per night: ";
                std::cin >> price;
                std::cout << "Enter capacity: ";
                std::cin >> capacity;
                hotel.addRoom(number, static_cast<RoomType>(type), price, capacity);
                break;
            }
            case 4:
                hotel.displayAllRooms();
                break;
            
            case 5: {
                int guestId, roomNumber;
                std::string checkIn, checkOut;
                std::cout << "Enter guest ID: ";
                std::cin >> guestId;
                std::cout << "Enter room number: ";
                std::cin >> roomNumber;
                std::cin.ignore();
                std::cout << "Enter check-in date (YYYY-MM-DD): ";
                std::getline(std::cin, checkIn);
                std::cout << "Enter check-out date (YYYY-MM-DD): ";
                std::getline(std::cin, checkOut);
                hotel.createBooking(guestId, roomNumber, checkIn, checkOut);
                break;
            }
            case 6:
                hotel.displayAllBookings();
                break;
            
            case 7: {
                int bookingId, method;
                double amount;
                std::cout << "Enter booking ID: ";
                std::cin >> bookingId;
                std::cout << "Enter amount: ";
                std::cin >> amount;
                std::cout << "Enter payment method (0=Credit Card, 1=Debit Card, 2=Cash, 3=Digital Wallet): ";
                std::cin >> method;
                hotel.processPayment(bookingId, amount, static_cast<PaymentMethod>(method));
                break;
            }
            case 8:
                hotel.displayAllPayments();
                break;
            
            case 9: {
                int bookingId, guestId, roomNumber, rating;
                std::string text;
                std::cout << "Enter booking ID: ";
                std::cin >> bookingId;
                std::cout << "Enter guest ID: ";
                std::cin >> guestId;
                std::cout << "Enter room number: ";
                std::cin >> roomNumber;
                std::cout << "Enter rating (1-5 stars): ";
                std::cin >> rating;
                std::cin.ignore();
                std::cout << "Enter review text: ";
                std::getline(std::cin, text);
                hotel.addReview(bookingId, guestId, roomNumber, rating, text);
                break;
            }
            case 10:
                hotel.displayAllReviews();
                break;
            
            case 11:
                hotel.displayHotelInfo();
                break;
            
            case 12:
                hotel.displayAnalytics();
                break;
            
            case 0:
                std::cout << "Thank you for using the Hotel Management System. Goodbye!\n";
                return 0;
            
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }
    
    return 0;
}
