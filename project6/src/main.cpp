#include "../include/Theater.h"
#include "../include/FileHandler.h"
#include <iostream>
#include <vector>

void displayMainMenu() {
    std::cout << "\n" << std::string(50, '=') << std::endl;
    std::cout << "MOVIE THEATER MANAGEMENT SYSTEM" << std::endl;
    std::cout << std::string(50, '=') << std::endl;
    std::cout << "1. Add Movie" << std::endl;
    std::cout << "2. Create Showtime" << std::endl;
    std::cout << "3. Book Tickets" << std::endl;
    std::cout << "4. View Showtimes" << std::endl;
    std::cout << "5. View Screen Seats" << std::endl;
    std::cout << "6. Generate Reports" << std::endl;
    std::cout << "7. Display Dashboard" << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout << std::string(50, '=') << std::endl;
    std::cout << "Enter choice: ";
}

int main() {
    Theater theater("THRTR001", "Cineplex Royal", "Downtown", "New York");
    FileHandler fileHandler("./theater_data");
    
    // Initialize screens
    Screen screen1("SC001", "Screen 1 - IMAX 3D", 8, 10, 1.5, true);
    Screen screen2("SC002", "Screen 2 - Premium", 6, 8, 1.2, false);
    Screen screen3("SC003", "Screen 3 - Economy", 4, 6, 1.0, false);
    
    theater.addScreen(screen1);
    theater.addScreen(screen2);
    theater.addScreen(screen3);
    
    // Add movies
    Movie movie1("M001", "The Dark Knight", "Action/Crime", 152, 9.0, "English", "2008-07-18", "Christopher Nolan");
    Movie movie2("M002", "Inception", "Sci-Fi/Thriller", 148, 8.8, "English", "2010-07-16", "Christopher Nolan");
    Movie movie3("M003", "Interstellar", "Sci-Fi/Drama", 169, 8.6, "English", "2014-11-07", "Christopher Nolan");
    Movie movie4("M004", "The Avengers", "Action/Adventure", 143, 8.0, "English", "2012-05-04", "Joss Whedon");
    
    theater.addMovie(movie1);
    theater.addMovie(movie2);
    theater.addMovie(movie3);
    theater.addMovie(movie4);
    
    // Create some initial showtimes
    theater.createShowtime("M001", 0, "2024-05-25 10:00", 200.0);
    theater.createShowtime("M001", 0, "2024-05-25 13:30", 200.0);
    theater.createShowtime("M002", 1, "2024-05-25 15:00", 180.0);
    theater.createShowtime("M003", 2, "2024-05-25 17:00", 150.0);
    
    int choice;
    bool running = true;
    
    while (running) {
        displayMainMenu();
        std::cin >> choice;
        std::cin.ignore();  // Clear input buffer
        
        switch (choice) {
            case 1: {
                // Add Movie
                std::cout << "\n--- ADD NEW MOVIE ---" << std::endl;
                std::string id, title, genre, language, releaseDate, director;
                int duration;
                double rating;
                
                std::cout << "Movie ID: ";
                std::getline(std::cin, id);
                std::cout << "Title: ";
                std::getline(std::cin, title);
                std::cout << "Genre: ";
                std::getline(std::cin, genre);
                std::cout << "Duration (minutes): ";
                std::cin >> duration;
                std::cout << "IMDB Rating (0-10): ";
                std::cin >> rating;
                std::cin.ignore();
                std::cout << "Language: ";
                std::getline(std::cin, language);
                std::cout << "Release Date (YYYY-MM-DD): ";
                std::getline(std::cin, releaseDate);
                std::cout << "Director: ";
                std::getline(std::cin, director);
                
                Movie newMovie(id, title, genre, duration, rating, language, releaseDate, director);
                theater.addMovie(newMovie);
                std::cout << "Movie added successfully!\n" << std::endl;
                break;
            }
            
            case 2: {
                // Create Showtime
                std::cout << "\n--- CREATE SHOWTIME ---" << std::endl;
                theater.displayAllMovies();
                
                std::string movieId, dateTime;
                int screenIndex;
                double price;
                
                std::cout << "Enter Movie ID: ";
                std::getline(std::cin, movieId);
                std::cout << "Enter Screen Index (0-" << (theater.getScreenCount() - 1) << "): ";
                std::cin >> screenIndex;
                std::cin.ignore();
                std::cout << "Enter Date & Time (YYYY-MM-DD HH:MM): ";
                std::getline(std::cin, dateTime);
                std::cout << "Enter Base Ticket Price: ";
                std::cin >> price;
                std::cin.ignore();
                
                theater.createShowtime(movieId, screenIndex, dateTime, price);
                std::cout << "Showtime created successfully!\n" << std::endl;
                break;
            }
            
            case 3: {
                // Book Tickets
                std::cout << "\n--- BOOK TICKETS ---" << std::endl;
                theater.displayAllShowtimes();
                
                std::string customerId, showtimeId;
                std::cout << "Enter Customer ID: ";
                std::getline(std::cin, customerId);
                std::cout << "Enter Showtime ID: ";
                std::getline(std::cin, showtimeId);
                
                Showtime* showtime = theater.getShowtimeById(showtimeId);
                if (showtime != nullptr) {
                    showtime->getScreen()->displaySeatMap();
                    
                    int numSeats;
                    std::cout << "How many seats to book? ";
                    std::cin >> numSeats;
                    std::cin.ignore();
                    
                    std::vector<std::pair<int, int>> seats;
                    for (int i = 0; i < numSeats; ++i) {
                        int row, col;
                        std::cout << "Seat " << (i + 1) << " - Row (0-" << (showtime->getScreen()->getTotalRows() - 1)
                                  << "): ";
                        std::cin >> row;
                        std::cout << "Column (0-" << (showtime->getScreen()->getTotalColumns() - 1) << "): ";
                        std::cin >> col;
                        std::cin.ignore();
                        
                        if (showtime->getScreen()->isValidSeat(row, col)) {
                            seats.push_back({row, col});
                        } else {
                            std::cout << "Invalid seat!\n";
                            i--;
                        }
                    }
                    
                    Booking booking = theater.createBooking(customerId, showtimeId, seats);
                    std::cout << "\nBooking created! ID: " << booking.getBookingId() << std::endl;
                    std::cout << "Total Amount: ₹" << booking.getTotalAmount() << std::endl;
                    
                    std::string paymentMethod;
                    std::cout << "Enter Payment Method: ";
                    std::getline(std::cin, paymentMethod);
                    
                    theater.confirmBooking(booking.getBookingId(), paymentMethod);
                    std::cout << "Booking confirmed!\n" << std::endl;
                    booking.displayInfo();
                } else {
                    std::cout << "Showtime not found!\n" << std::endl;
                }
                break;
            }
            
            case 4: {
                // View Showtimes
                theater.displayAllShowtimes();
                break;
            }
            
            case 5: {
                // View Screen Seats
                std::cout << "\n--- VIEW SCREEN SEATS ---" << std::endl;
                for (int i = 0; i < theater.getScreenCount(); ++i) {
                    theater.getScreen(i)->displaySeatMap();
                }
                break;
            }
            
            case 6: {
                // Generate Reports
                std::cout << "\n--- GENERATING REPORTS ---\n" << std::endl;
                theater.generateReport();
                break;
            }
            
            case 7: {
                // Display Dashboard
                theater.displayDashboard();
                break;
            }
            
            case 0: {
                std::cout << "\nThank you for using Theater Management System!\n" << std::endl;
                running = false;
                break;
            }
            
            default:
                std::cout << "Invalid choice! Please try again.\n" << std::endl;
        }
    }
    
    return 0;
}
// end of the code 
