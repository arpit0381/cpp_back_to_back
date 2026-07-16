#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "Transaction.h"
#include <vector>
#include <string>
#include <memory>

class Account {
protected:
    std::string accountNumber;
    std::string accountHolder;
    double balance;
    std::vector<std::shared_ptr<Transaction>> transactionHistory;
    int pin;
    bool isActive;
    std::string accountType;
    
    // Helper methods///.....................
    std::string generateAccountNumber();
    bool verifyPin(int inputPin) const;

public:
    // Constructor and Destructor
    Account(const std::string& holder, int pin);
    virtual ~Account();
    
    // Getters
    std::string getAccountNumber() const;
    std::string getAccountHolder() const;
    double getBalance() const;
    bool getIsActive() const;
    std::string getAccountType() const;
    std::vector<std::shared_ptr<Transaction>> getTransactionHistory() const;
    
    // Account operations
    virtual bool deposit(double amount, int pin);
    virtual bool withdraw(double amount, int pin);
    virtual bool transfer(double amount, Account& recipient, int pin);
    
    // Interest calculation (virtual for polymorphism)
    virtual double calculateInterest() const;
    virtual void applyInterest();
    
    // PIN management
    bool changePIN(int oldPin, int newPin);
    
    // Transaction history
    void displayTransactionHistory() const;
    void displayLastNTransactions(int n) const;
    
    // Account information
    virtual void displayAccountInfo() const;
    
    // File operations
    virtual std::string toFileFormat() const;
    virtual void loadTransactionsFromFile(const std::string& filename);
    virtual void saveTransactionsToFile(const std::string& filename) const;
};

#endif // ACCOUNT_H
