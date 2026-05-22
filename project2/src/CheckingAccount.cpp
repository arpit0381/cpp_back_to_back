#include "../include/CheckingAccount.h"
#include <iostream>
#include <iomanip>

CheckingAccount::CheckingAccount(const std::string& holder, int pin,
                                 double fee, bool overdraft, double limit)
    : Account(holder, pin), monthlyFee(fee), overdraftProtection(overdraft),
      overdraftLimit(limit) {
    accountType = "Checking";
}

bool CheckingAccount::withdraw(double amount, int pin) {
    if (!verifyPin(pin)) {
        std::cout << "✗ Invalid PIN.\n";
        return false;
    }
    
    if (amount <= 0) {
        std::cout << "✗ Withdrawal amount must be positive.\n";
        return false;
    }
    
    double availableBalance = getAvailableBalance();
    if (amount > availableBalance) {
        std::cout << "✗ Insufficient funds. Available balance: $"
                  << std::fixed << std::setprecision(2) << availableBalance << "\n";
        return false;
    }
    
    balance -= amount;
    auto transaction = std::make_shared<Transaction>(
        TransactionType::WITHDRAWAL, amount, "Withdrawal"
    );
    transactionHistory.push_back(transaction);
    
    if (balance < 0) {
        std::cout << "⚠ Using overdraft protection. Current balance: $"
                  << std::fixed << std::setprecision(2) << balance << "\n";
    } else {
        std::cout << "✓ Withdrawal successful. New balance: $"
                  << std::fixed << std::setprecision(2) << balance << "\n";
    }
    return true;
}

double CheckingAccount::calculateInterest() const {
    // Checking accounts typically earn minimal interest
    if (balance > 1000) {
        return balance * 0.0005 / 12.0;  // 0.05% APY for balances over $1000
    }
    return 0.0;
}

void CheckingAccount::displayAccountInfo() const {
    Account::displayAccountInfo();
    std::cout << "Monthly Fee: $" << std::fixed << std::setprecision(2) << monthlyFee << "\n";
    std::cout << "Overdraft Protection: " << (overdraftProtection ? "Enabled" : "Disabled") << "\n";
    if (overdraftProtection) {
        std::cout << "Overdraft Limit: $" << overdraftLimit << "\n";
        std::cout << "Available Balance: $" << getAvailableBalance() << "\n";
    }
    std::cout << "========================================\n";
}

std::string CheckingAccount::toFileFormat() const {
    return Account::toFileFormat() + "|CHECKING|" +
           std::to_string(monthlyFee) + "|" +
           (overdraftProtection ? "1" : "0") + "|" +
           std::to_string(overdraftLimit);
}

void CheckingAccount::setMonthlyFee(double fee) {
    if (fee >= 0) {
        monthlyFee = fee;
        std::cout << "✓ Monthly fee updated to $" << std::fixed 
                  << std::setprecision(2) << fee << "\n";
    } else {
        std::cout << "✗ Invalid monthly fee.\n";
    }
}

double CheckingAccount::getMonthlyFee() const {
    return monthlyFee;
}

void CheckingAccount::setOverdraftProtection(bool enabled) {
    overdraftProtection = enabled;
    std::cout << "✓ Overdraft protection " << (enabled ? "enabled" : "disabled") << "\n";
}

bool CheckingAccount::hasOverdraftProtection() const {
    return overdraftProtection;
}

void CheckingAccount::setOverdraftLimit(double limit) {
    if (limit >= 0) {
        overdraftLimit = limit;
        std::cout << "✓ Overdraft limit updated to $" << std::fixed 
                  << std::setprecision(2) << limit << "\n";
    } else {
        std::cout << "✗ Invalid overdraft limit.\n";
    }
}

double CheckingAccount::getOverdraftLimit() const {
    return overdraftLimit;
}

void CheckingAccount::applyMonthlyFee() {
    if (monthlyFee > 0) {
        balance -= monthlyFee;
        auto transaction = std::make_shared<Transaction>(
            TransactionType::WITHDRAWAL, monthlyFee, "Monthly service fee"
        );
        transactionHistory.push_back(transaction);
        std::cout << "✓ Monthly fee of $" << std::fixed << std::setprecision(2)
                  << monthlyFee << " applied to account "
                  << accountNumber << "\n";
    }
}

double CheckingAccount::getAvailableBalance() const {
    if (overdraftProtection) {
        return balance + overdraftLimit;
    }
    return std::max(0.0, balance);
}
