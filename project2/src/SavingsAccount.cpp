#include "../include/SavingsAccount.h"
#include <iostream>
#include <iomanip>

SavingsAccount::SavingsAccount(const std::string& holder, int pin,
                               double rate, double minBalance)
    : Account(holder, pin), interestRate(rate), minimumBalance(minBalance),
      withdrawalLimit(3), withdrawalCount(0) {
    accountType = "Savings";
}

bool SavingsAccount::withdraw(double amount, int pin) {
    if (withdrawalCount >= withdrawalLimit) {
        std::cout << "✗ Withdrawal limit reached for this month ("
                  << withdrawalLimit << " withdrawals allowed).\n";
        return false;
    }
    
    if (balance - amount < minimumBalance) {
        std::cout << "✗ Withdrawal would fall below minimum balance of $"
                  << std::fixed << std::setprecision(2) << minimumBalance << "\n";
        return false;
    }
    
    bool success = Account::withdraw(amount, pin);
    if (success) {
        withdrawalCount++;
    }
    return success;
}

double SavingsAccount::calculateInterest() const {
    // Simple interest calculation: balance * rate / 12 (monthly)
    return balance * interestRate / 12.0;
}

void SavingsAccount::displayAccountInfo() const {
    Account::displayAccountInfo();
    std::cout << "Interest Rate: " << std::fixed << std::setprecision(2)
              << (interestRate * 100) << "% per annum\n";
    std::cout << "Minimum Balance: $" << minimumBalance << "\n";
    std::cout << "Withdrawal Limit: " << withdrawalLimit << " per month\n";
    std::cout << "Withdrawals This Month: " << withdrawalCount << "\n";
    std::cout << "========================================\n";
}

std::string SavingsAccount::toFileFormat() const {
    return Account::toFileFormat() + "|SAVINGS|" +
           std::to_string(interestRate) + "|" +
           std::to_string(minimumBalance);
}

void SavingsAccount::setInterestRate(double rate) {
    if (rate >= 0 && rate <= 1.0) {
        interestRate = rate;
        std::cout << "✓ Interest rate updated to " << std::fixed 
                  << std::setprecision(2) << (rate * 100) << "%\n";
    } else {
        std::cout << "✗ Invalid interest rate.\n";
    }
}

double SavingsAccount::getInterestRate() const {
    return interestRate;
}

void SavingsAccount::setMinimumBalance(double amount) {
    if (amount >= 0) {
        minimumBalance = amount;
        std::cout << "✓ Minimum balance updated to $" << std::fixed 
                  << std::setprecision(2) << amount << "\n";
    } else {
        std::cout << "✗ Invalid minimum balance.\n";
    }
}

double SavingsAccount::getMinimumBalance() const {
    return minimumBalance;
}

void SavingsAccount::resetWithdrawalCount() {
    withdrawalCount = 0;
}

void SavingsAccount::applyMinimumBalancePenalty() {
    if (balance < minimumBalance) {
        double penalty = 10.0;  // $10 penalty
        balance -= penalty;
        auto transaction = std::make_shared<Transaction>(
            TransactionType::WITHDRAWAL, penalty, "Minimum balance penalty"
        );
        transactionHistory.push_back(transaction);
        std::cout << "⚠ Minimum balance penalty of $" << penalty << " applied.\n";
    }
}
