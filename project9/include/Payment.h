#ifndef PAYMENT_H
#define PAYMENT_H

#include <string>

enum class PaymentMethod { CREDIT_CARD, DEBIT_CARD, CASH, DIGITAL_WALLET };
enum class PaymentStatus { PENDING, COMPLETED, FAILED, REFUNDED };

class Payment {
private:
    int paymentId;
    int bookingId;
    double amount;
    PaymentMethod method;
    PaymentStatus status;
    std::string paymentDate;
    std::string transactionId;

public:
    Payment();
    Payment(int id, int bookingId, double amount, PaymentMethod method);
    
    // Getters
    int getPaymentId() const;
    int getBookingId() const;
    double getAmount() const;
    PaymentMethod getMethod() const;
    PaymentStatus getStatus() const;
    std::string getPaymentDate() const;
    std::string getTransactionId() const;
    
    // Setters
    void setStatus(PaymentStatus status);
    void setPaymentDate(const std::string& date);
    void setTransactionId(const std::string& id);
    
    // Utilities
    bool processPayment();
    void refund();
    std::string getMethodString() const;
    std::string getStatusString() const;
    void display() const;
};

#endif // PAYMENT_H
