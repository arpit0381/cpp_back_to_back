#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <ctime>

enum class TransactionType {
    DEPOSIT,
    WITHDRAWAL,
    TRANSFER,
    INTEREST
};

class Transaction {
private:
    std::string transactionId;
    TransactionType type;
    double amount;
    std::string timestamp;
    std::string description;
    
    // Helper methods
    std::string generateTransactionId();
    std::string getCurrentTimestamp();

public:
    Transaction(TransactionType type, double amount, const std::string& description = "");
    
    // Getters
    std::string getTransactionId() const;
    TransactionType getType() const;
    double getAmount() const;
    std::string getTimestamp() const;
    std::string getDescription() const;
    std::string getTypeString() const;
    
    // Display
    void displayTransaction() const;
    std::string toFileFormat() const;
    
    // Static method to parse from file
    static Transaction fromFileFormat(const std::string& line);
};

#endif // TRANSACTION_H
