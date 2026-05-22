#include "../include/Bank.h"
#include <iostream>
#include <limits>
#include <iomanip>

void displayMainMenu() {
    std::cout << "\n========== " << "GLOBAL BANK" << " ==========\n";
    std::cout << "1. Create Savings Account\n";
    std::cout << "2. Create Checking Account\n";
    std::cout << "3. Deposit Money\n";
    std::cout << "4. Withdraw Money\n";
    std::cout << "5. Transfer Money\n";
    std::cout << "6. View Account Information\n";
    std::cout << "7. View Transaction History\n";
    std::cout << "8. View All Accounts\n";
    std::cout << "9. Apply Interest\n";
    std::cout << "10. Apply Monthly Fees\n";
    std::cout << "11. View Bank Statistics\n";
    std::cout << "12. Change PIN\n";
    std::cout << "13. Delete Account\n";
    std::cout << "0. Exit\n";
    std::cout << "====================================\n";
    std::cout << "Enter your choice: ";
}

int main() {
    Bank bank("Global Bank");
    int choice;
    bool running = true;

    std::cout << "Welcome to " << bank.getBankName() << "!\n";

    // Demo data
    std::string acc1 = bank.createSavingsAccount("Alice Johnson", 1234, 0.03, 100.0);
    std::string acc2 = bank.createCheckingAccount("Bob Smith", 5678, 5.0, true, 500.0);
    
    if (!acc1.empty()) {
        bank.deposit(acc1, 5000, 1234);
        bank.deposit(acc1, 2500, 1234);
    }
    if (!acc2.empty()) {
        bank.deposit(acc2, 3000, 5678);
    }

    while (running) {
        displayMainMenu();
        
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "✗ Invalid input. Please enter a number.\n";
            continue;
        }

        std::string accountNumber, toAccountNumber;
        std::string name, email;
        double amount;
        int pin, newPin;

        switch (choice) {
            case 1: {
                std::cout << "Enter account holder name: ";
                std::cin.ignore();
                std::getline(std::cin, name);
                std::cout << "Enter 4-digit PIN: ";
                std::cin >> pin;
                std::cout << "Enter annual interest rate (0.03 for 3%): ";
                double rate;
                std::cin >> rate;
                std::cout << "Enter minimum balance: ";
                double minBal;
                std::cin >> minBal;
                bank.createSavingsAccount(name, pin, rate, minBal);
                break;
            }

            case 2: {
                std::cout << "Enter account holder name: ";
                std::cin.ignore();
                std::getline(std::cin, name);
                std::cout << "Enter 4-digit PIN: ";
                std::cin >> pin;
                std::cout << "Enter monthly fee: ";
                double fee;
                std::cin >> fee;
                std::cout << "Enable overdraft protection? (1=yes, 0=no): ";
                int overdraft;
                std::cin >> overdraft;
                std::cout << "Enter overdraft limit: ";
                double limit;
                std::cin >> limit;
                bank.createCheckingAccount(name, pin, fee, overdraft == 1, limit);
                break;
            }

            case 3: {
                std::cout << "Enter account number: ";
                std::cin.ignore();
                std::getline(std::cin, accountNumber);
                std::cout << "Enter amount to deposit: $";
                std::cin >> amount;
                std::cout << "Enter PIN: ";
                std::cin >> pin;
                bank.deposit(accountNumber, amount, pin);
                break;
            }

            case 4: {
                std::cout << "Enter account number: ";
                std::cin.ignore();
                std::getline(std::cin, accountNumber);
                std::cout << "Enter amount to withdraw: $";
                std::cin >> amount;
                std::cout << "Enter PIN: ";
                std::cin >> pin;
                bank.withdraw(accountNumber, amount, pin);
                break;
            }

            case 5: {
                std::cout << "Enter from account number: ";
                std::cin.ignore();
                std::getline(std::cin, accountNumber);
                std::cout << "Enter to account number: ";
                std::getline(std::cin, toAccountNumber);
                std::cout << "Enter amount to transfer: $";
                std::cin >> amount;
                std::cout << "Enter PIN: ";
                std::cin >> pin;
                bank.transfer(accountNumber, toAccountNumber, amount, pin);
                break;
            }

            case 6: {
                std::cout << "Enter account number: ";
                std::cin.ignore();
                std::getline(std::cin, accountNumber);
                bank.displayAccountInfo(accountNumber);
                break;
            }

            case 7: {
                std::cout << "Enter account number: ";
                std::cin.ignore();
                std::getline(std::cin, accountNumber);
                bank.displayTransactionHistory(accountNumber);
                break;
            }

            case 8: {
                bank.displayAllAccounts();
                break;
            }

            case 9: {
                bank.applyInterestToAllAccounts();
                break;
            }

            case 10: {
                bank.applyMonthlyFeesToAllCheckingAccounts();
                break;
            }

            case 11: {
                std::cout << "\n========== BANK STATISTICS ==========\n";
                std::cout << "Total Accounts: " << bank.getAccountCount() << "\n";
                std::cout << "Total Assets Under Management: $"
                          << std::fixed << std::setprecision(2)
                          << bank.getTotalAssetsUnderManagement() << "\n";
                std::cout << "=====================================\n";
                break;
            }

            case 12: {
                std::cout << "Enter account number: ";
                std::cin.ignore();
                std::getline(std::cin, accountNumber);
                auto account = bank.getAccount(accountNumber);
                if (account) {
                    std::cout << "Enter current PIN: ";
                    std::cin >> pin;
                    std::cout << "Enter new PIN: ";
                    std::cin >> newPin;
                    account->changePIN(pin, newPin);
                } else {
                    std::cout << "✗ Account not found.\n";
                }
                break;
            }

            case 13: {
                std::cout << "Enter account number: ";
                std::cin.ignore();
                std::getline(std::cin, accountNumber);
                std::cout << "Enter PIN: ";
                std::cin >> pin;
                bank.deleteAccount(accountNumber, pin);
                break;
            }

            case 0: {
                std::cout << "Thank you for banking with " << bank.getBankName() << "!\n";
                running = false;
                break;
            }

            default: {
                std::cout << "✗ Invalid choice. Please try again.\n";
            }
        }
    }

    return 0;
}
