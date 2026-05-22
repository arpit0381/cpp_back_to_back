#include "../include/Account.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <random>
#include <ctime>
#include <algorithm>
#include <fstream>

Account::Account(const std::string& holder, int pin)
    : accountHolder(holder), balance(0.0), pin(pin), isActive(true),
      accountNumber(generateAccountNumber()), accountType("Generic") {}

Account::~Account() {}

std::string Account::generateAccountNumber() {
    static int counter = 1000;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(100000, 999999);
    
    std::stringstream ss;
    ss << "ACC" << counter++ << dis(gen);
    return ss.str();
}

bool Account::verifyPin(int inputPin) const {
    return inputPin == pin;
}

std::string Account::getAccountNumber() const {
    return accountNumber;
}

std::string Account::getAccountHolder() const {
    return accountHolder;
}

double Account::getBalance() const {
    return balance;
}

bool Account::getIsActive() const {
    return isActive;
}

std::string Account::getAccountType() const {
    return accountType;
}

std::vector<std::shared_ptr<Transaction>> Account::getTransactionHistory() const {
    return transactionHistory;
}

bool Account::deposit(double amount, int inputPin) {
    if (!verifyPin(inputPin)) {
        std::cout << "✗ Invalid PIN.\n";
        return false;
    }
    
    if (amount <= 0) {
        std::cout << "✗ Deposit amount must be positive.\n";
        return false;
    }
    
    balance += amount;
    auto transaction = std::make_shared<Transaction>(
        TransactionType::DEPOSIT, amount, "Deposit"
    );
    transactionHistory.push_back(transaction);
    std::cout << "✓ Deposit successful. New balance: $" 
              << std::fixed << std::setprecision(2) << balance << "\n";
    return true;
}

bool Account::withdraw(double amount, int inputPin) {
    if (!verifyPin(inputPin)) {
        std::cout << "✗ Invalid PIN.\n";
        return false;
    }
    
    if (amount <= 0) {
        std::cout << "✗ Withdrawal amount must be positive.\n";
        return false;
    }
    
    if (amount > balance) {
        std::cout << "✗ Insufficient funds. Current balance: $" 
                  << std::fixed << std::setprecision(2) << balance << "\n";
        return false;
    }
    
    balance -= amount;
    auto transaction = std::make_shared<Transaction>(
        TransactionType::WITHDRAWAL, amount, "Withdrawal"
    );
    transactionHistory.push_back(transaction);
    std::cout << "✓ Withdrawal successful. New balance: $" 
              << std::fixed << std::setprecision(2) << balance << "\n";
    return true;
}

bool Account::transfer(double amount, Account& recipient, int inputPin) {
    if (!verifyPin(inputPin)) {
        std::cout << "✗ Invalid PIN.\n";
        return false;
    }
    
    if (amount <= 0) {
        std::cout << "✗ Transfer amount must be positive.\n";
        return false;
    }
    
    if (amount > balance) {
        std::cout << "✗ Insufficient funds for transfer.\n";
        return false;
    }
    
    balance -= amount;
    recipient.balance += amount;
    
    auto sentTransaction = std::make_shared<Transaction>(
        TransactionType::TRANSFER, amount, 
        "Transfer to " + recipient.getAccountNumber()
    );
    auto receivedTransaction = std::make_shared<Transaction>(
        TransactionType::TRANSFER, amount,
        "Transfer from " + accountNumber
    );
    
    transactionHistory.push_back(sentTransaction);
    recipient.transactionHistory.push_back(receivedTransaction);
    
    std::cout << "✓ Transfer successful. Transferred $" 
              << std::fixed << std::setprecision(2) << amount 
              << " to account " << recipient.getAccountNumber() << "\n";
    return true;
}

double Account::calculateInterest() const {
    return 0.0;  // Base class returns 0; derived classes override
}

void Account::applyInterest() {
    double interest = calculateInterest();
    if (interest > 0) {
        balance += interest;
        auto transaction = std::make_shared<Transaction>(
            TransactionType::INTEREST, interest, "Interest earned"
        );
        transactionHistory.push_back(transaction);
        std::cout << "✓ Interest applied: $" << std::fixed << std::setprecision(2) 
                  << interest << "\n";
    }
}

bool Account::changePIN(int oldPin, int newPin) {
    if (!verifyPin(oldPin)) {
        std::cout << "✗ Current PIN is incorrect.\n";
        return false;
    }
    
    if (newPin < 1000 || newPin > 9999) {
        std::cout << "✗ PIN must be a 4-digit number.\n";
        return false;
    }
    
    pin = newPin;
    std::cout << "✓ PIN changed successfully.\n";
    return true;
}

void Account::displayTransactionHistory() const {
    std::cout << "\n========== TRANSACTION HISTORY ==========\n";
    if (transactionHistory.empty()) {
        std::cout << "No transactions yet.\n";
    } else {
        for (const auto& transaction : transactionHistory) {
            transaction->displayTransaction();
        }
    }
    std::cout << "========================================\n";
}

void Account::displayLastNTransactions(int n) const {
    std::cout << "\n========== LAST " << n << " TRANSACTIONS ==========\n";
    int start = std::max(0, static_cast<int>(transactionHistory.size()) - n);
    
    if (transactionHistory.empty()) {
        std::cout << "No transactions yet.\n";
    } else {
        for (size_t i = start; i < transactionHistory.size(); ++i) {
            transactionHistory[i]->displayTransaction();
        }
    }
    std::cout << "==========================================\n";
}

void Account::displayAccountInfo() const {
    std::cout << "\n========== ACCOUNT INFORMATION ==========\n";
    std::cout << "Account Type: " << accountType << "\n";
    std::cout << "Account Number: " << accountNumber << "\n";
    std::cout << "Account Holder: " << accountHolder << "\n";
    std::cout << "Balance: $" << std::fixed << std::setprecision(2) << balance << "\n";
    std::cout << "Status: " << (isActive ? "Active" : "Inactive") << "\n";
    std::cout << "Transactions: " << transactionHistory.size() << "\n";
    std::cout << "========================================\n";
}

std::string Account::toFileFormat() const {
    std::stringstream ss;
    ss << std::fixed << std::setprecision(2);
    ss << accountNumber << "|" << accountHolder << "|" << balance << "|"
       << pin << "|" << accountType << "|" << (isActive ? "1" : "0");
    return ss.str();
}

void Account::loadTransactionsFromFile(const std::string& filename) {
    // Implementation for loading transactions from file
}

void Account::saveTransactionsToFile(const std::string& filename) const {
    // Implementation for saving transactions to file
}
