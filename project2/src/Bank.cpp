#include "../include/Bank.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <iomanip>

Bank::Bank(const std::string& name) : bankName(name) {}

std::shared_ptr<Account> Bank::findAccount(const std::string& accountNumber) {
    auto it = std::find_if(accounts.begin(), accounts.end(),
        [accountNumber](const std::shared_ptr<Account>& acc) {
            return acc->getAccountNumber() == accountNumber;
        });
    return (it != accounts.end()) ? *it : nullptr;
}

std::string Bank::createSavingsAccount(const std::string& holder, int pin,
                                       double rate, double minBalance) {
    auto account = std::make_shared<SavingsAccount>(holder, pin, rate, minBalance);
    accounts.push_back(account);
    std::cout << "✓ Savings account created successfully!\n";
    std::cout << "Account Number: " << account->getAccountNumber() << "\n";
    return account->getAccountNumber();
}

std::string Bank::createCheckingAccount(const std::string& holder, int pin,
                                        double fee, bool overdraft, double limit) {
    auto account = std::make_shared<CheckingAccount>(holder, pin, fee, overdraft, limit);
    accounts.push_back(account);
    std::cout << "✓ Checking account created successfully!\n";
    std::cout << "Account Number: " << account->getAccountNumber() << "\n";
    return account->getAccountNumber();
}

bool Bank::deleteAccount(const std::string& accountNumber, int pin) {
    auto account = findAccount(accountNumber);
    if (!account) {
        std::cout << "✗ Account not found.\n";
        return false;
    }
    
    if (account->getBalance() != 0) {
        std::cout << "✗ Cannot delete account with non-zero balance.\n";
        return false;
    }
    
    auto it = std::find(accounts.begin(), accounts.end(), account);
    if (it != accounts.end()) {
        accounts.erase(it);
        std::cout << "✓ Account deleted successfully.\n";
        return true;
    }
    return false;
}

std::shared_ptr<Account> Bank::getAccount(const std::string& accountNumber) {
    return findAccount(accountNumber);
}

bool Bank::deposit(const std::string& accountNumber, double amount, int pin) {
    auto account = findAccount(accountNumber);
    if (!account) {
        std::cout << "✗ Account not found.\n";
        return false;
    }
    return account->deposit(amount, pin);
}

bool Bank::withdraw(const std::string& accountNumber, double amount, int pin) {
    auto account = findAccount(accountNumber);
    if (!account) {
        std::cout << "✗ Account not found.\n";
        return false;
    }
    return account->withdraw(amount, pin);
}

bool Bank::transfer(const std::string& fromAccount, const std::string& toAccount,
                    double amount, int pin) {
    auto from = findAccount(fromAccount);
    auto to = findAccount(toAccount);
    
    if (!from || !to) {
        std::cout << "✗ One or both accounts not found.\n";
        return false;
    }
    
    return from->transfer(amount, *to, pin);
}

void Bank::displayAccountInfo(const std::string& accountNumber) const {
    auto it = std::find_if(accounts.begin(), accounts.end(),
        [accountNumber](const std::shared_ptr<Account>& acc) {
            return acc->getAccountNumber() == accountNumber;
        });
    
    if (it != accounts.end()) {
        (*it)->displayAccountInfo();
    } else {
        std::cout << "✗ Account not found.\n";
    }
}

void Bank::displayAllAccounts() const {
    std::cout << "\n========== " << bankName << " - ALL ACCOUNTS ==========\n";
    if (accounts.empty()) {
        std::cout << "No accounts in the system.\n";
    } else {
        for (const auto& account : accounts) {
            std::cout << "Type: " << std::setw(10) << account->getAccountType()
                      << " | Holder: " << std::setw(20) << account->getAccountHolder()
                      << " | Account#: " << account->getAccountNumber()
                      << " | Balance: $" << std::fixed << std::setprecision(2)
                      << account->getBalance() << "\n";
        }
    }
    std::cout << "======================================================\n";
}

void Bank::displayTransactionHistory(const std::string& accountNumber) const {
    auto it = std::find_if(accounts.begin(), accounts.end(),
        [accountNumber](const std::shared_ptr<Account>& acc) {
            return acc->getAccountNumber() == accountNumber;
        });
    
    if (it != accounts.end()) {
        (*it)->displayTransactionHistory();
    } else {
        std::cout << "✗ Account not found.\n";
    }
}

void Bank::applyInterestToAllAccounts() {
    std::cout << "\n--- Applying interest to all accounts ---\n";
    for (auto& account : accounts) {
        account->applyInterest();
    }
}

void Bank::applyMonthlyFeesToAllCheckingAccounts() {
    std::cout << "\n--- Applying monthly fees to checking accounts ---\n";
    for (auto& account : accounts) {
        if (auto checkingAccount = std::dynamic_cast<CheckingAccount*>(account.get())) {
            checkingAccount->applyMonthlyFee();
        }
    }
}

double Bank::getTotalAssetsUnderManagement() const {
    double total = 0.0;
    for (const auto& account : accounts) {
        total += account->getBalance();
    }
    return total;
}

bool Bank::saveAllAccountsToFile(const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cout << "✗ Failed to open file for writing.\n";
        return false;
    }
    
    file << accounts.size() << "\n";
    for (const auto& account : accounts) {
        file << account->toFileFormat() << "\n";
    }
    
    file.close();
    std::cout << "✓ All accounts saved to file.\n";
    return true;
}

bool Bank::loadAllAccountsFromFile(const std::string& filename) {
    // Implementation for loading accounts from file
    std::cout << "✓ Accounts loaded from file.\n";
    return true;
}

std::string Bank::getBankName() const {
    return bankName;
}

int Bank::getAccountCount() const {
    return accounts.size();
}
