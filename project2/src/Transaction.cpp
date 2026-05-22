#include "../include/Transaction.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <random>
#include <ctime>

Transaction::Transaction(TransactionType type, double amount, const std::string& description)
    : type(type), amount(amount), description(description), 
      timestamp(getCurrentTimestamp()), transactionId(generateTransactionId()) {}

std::string Transaction::generateTransactionId() {
    static int counter = 0;
    std::time_t now = std::time(nullptr);
    std::stringstream ss;
    ss << "TXN" << std::setfill('0') << std::setw(6) << (counter++) 
       << std::setw(10) << static_cast<long>(now);
    return ss.str();
}

std::string Transaction::getCurrentTimestamp() {
    std::time_t now = std::time(nullptr);
    std::tm* timeinfo = std::localtime(&now);
    
    std::stringstream ss;
    ss << std::put_time(timeinfo, "%Y-%m-%d %H:%M:%S");
    return ss.str();
}

std::string Transaction::getTransactionId() const {
    return transactionId;
}

TransactionType Transaction::getType() const {
    return type;
}

double Transaction::getAmount() const {
    return amount;
}

std::string Transaction::getTimestamp() const {
    return timestamp;
}

std::string Transaction::getDescription() const {
    return description;
}

std::string Transaction::getTypeString() const {
    switch (type) {
        case TransactionType::DEPOSIT:
            return "DEPOSIT";
        case TransactionType::WITHDRAWAL:
            return "WITHDRAWAL";
        case TransactionType::TRANSFER:
            return "TRANSFER";
        case TransactionType::INTEREST:
            return "INTEREST";
        default:
            return "UNKNOWN";
    }
}

void Transaction::displayTransaction() const {
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "[" << timestamp << "] " 
              << std::left << std::setw(12) << getTypeString() 
              << "| Amount: $" << std::setw(10) << amount
              << "| ID: " << transactionId << "\n";
    if (!description.empty()) {
        std::cout << "  Description: " << description << "\n";
    }
}

std::string Transaction::toFileFormat() const {
    std::stringstream ss;
    ss << std::fixed << std::setprecision(2);
    ss << transactionId << "|" << getTypeString() << "|" << amount << "|"
       << timestamp << "|" << description;
    return ss.str();
}

Transaction Transaction::fromFileFormat(const std::string& line) {
    std::stringstream ss(line);
    std::string typeStr, idStr, amountStr, tsStr, desc;
    
    // Parse the file format
    std::getline(ss, idStr, '|');
    std::getline(ss, typeStr, '|');
    std::getline(ss, amountStr, '|');
    std::getline(ss, tsStr, '|');
    std::getline(ss, desc, '|');
    
    TransactionType type = TransactionType::DEPOSIT;
    if (typeStr == "WITHDRAWAL") type = TransactionType::WITHDRAWAL;
    else if (typeStr == "TRANSFER") type = TransactionType::TRANSFER;
    else if (typeStr == "INTEREST") type = TransactionType::INTEREST;
    
    double amount = std::stod(amountStr);
    return Transaction(type, amount, desc);
}
