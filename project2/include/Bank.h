#ifndef BANK_H
#define BANK_H

#include "Account.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"
#include <vector>
#include <memory>

class Bank {
private:
    std::string bankName;
    std::vector<std::shared_ptr<Account>> accounts;
    
    // Helper methods
    std::shared_ptr<Account> findAccount(const std::string& accountNumber);

public:
    // Constructor
    Bank(const std::string& name);
    
    // Account management
    std::string createSavingsAccount(const std::string& holder, int pin, 
                                     double rate = 0.03, double minBalance = 100.0);
    std::string createCheckingAccount(const std::string& holder, int pin, 
                                      double fee = 5.0, bool overdraft = true, 
                                      double limit = 500.0);
    
    bool deleteAccount(const std::string& accountNumber, int pin);
    std::shared_ptr<Account> getAccount(const std::string& accountNumber);
    
    // Transaction operations
    bool deposit(const std::string& accountNumber, double amount, int pin);
    bool withdraw(const std::string& accountNumber, double amount, int pin);
    bool transfer(const std::string& fromAccount, const std::string& toAccount, 
                  double amount, int pin);
    
    // Account information
    void displayAccountInfo(const std::string& accountNumber) const;
    void displayAllAccounts() const;
    void displayTransactionHistory(const std::string& accountNumber) const;
    
    // Administrative functions
    void applyInterestToAllAccounts();
    void applyMonthlyFeesToAllCheckingAccounts();
    double getTotalAssetsUnderManagement() const;
    
    // File operations
    bool saveAllAccountsToFile(const std::string& filename);
    bool loadAllAccountsFromFile(const std::string& filename);
    
    // Bank information
    std::string getBankName() const;
    int getAccountCount() const;
};

#endif // BANK_H
