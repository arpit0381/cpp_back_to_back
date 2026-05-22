#ifndef SAVINGS_ACCOUNT_H
#define SAVINGS_ACCOUNT_H

#include "Account.h"

class SavingsAccount : public Account {
private:
    double interestRate;        // Annual interest rate (e.g., 0.03 for 3%)
    double minimumBalance;      // Minimum required balance
    int withdrawalLimit;        // Max withdrawals per month
    int withdrawalCount;        // Current withdrawal count
    
public:
    // Constructor
    SavingsAccount(const std::string& holder, int pin, 
                   double rate = 0.03, double minBalance = 100.0);
    
    // Overridden methods
    bool withdraw(double amount, int pin) override;
    double calculateInterest() const override;
    void displayAccountInfo() const override;
    std::string toFileFormat() const override;
    
    // Savings-specific methods
    void setInterestRate(double rate);
    double getInterestRate() const;
    void setMinimumBalance(double amount);
    double getMinimumBalance() const;
    void resetWithdrawalCount();
    
    // Penalty for falling below minimum balance
    void applyMinimumBalancePenalty();
};

#endif // SAVINGS_ACCOUNT_H
