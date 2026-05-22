#ifndef CHECKING_ACCOUNT_H
#define CHECKING_ACCOUNT_H

#include "Account.h"

class CheckingAccount : public Account {
private:
    double monthlyFee;
    bool overdraftProtection;
    double overdraftLimit;      // Maximum allowed overdraft
    
public:
    // Constructor
    CheckingAccount(const std::string& holder, int pin, 
                    double fee = 5.0, bool overdraft = true, double limit = 500.0);
    
    // Overridden methods
    bool withdraw(double amount, int pin) override;
    double calculateInterest() const override;
    void displayAccountInfo() const override;
    std::string toFileFormat() const override;
    
    // Checking-specific methods
    void setMonthlyFee(double fee);
    double getMonthlyFee() const;
    void setOverdraftProtection(bool enabled);
    bool hasOverdraftProtection() const;
    void setOverdraftLimit(double limit);
    double getOverdraftLimit() const;
    
    // Monthly fee application
    void applyMonthlyFee();
    double getAvailableBalance() const;
};

#endif // CHECKING_ACCOUNT_H
