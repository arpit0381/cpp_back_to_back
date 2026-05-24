#ifndef PAYMENT_H
#define PAYMENT_H

#include <string>
#include <ctime>

enum class PaymentMethod {
    CASH,
    CARD,
    DIGITAL_WALLET,
    CHEQUE
};

enum class PaymentStatus {
    PENDING,
    PROCESSING,
    COMPLETED,
    FAILED,
    REFUNDED
};

class Payment {
private:
    std::string paymentId;
    std::string orderId;
    double amount;
    PaymentMethod method;
    PaymentStatus status;
    double discountAmount;
    double finalAmount;
    std::time_t paymentTime;
    std::string transactionReference;

public:
    Payment();
    Payment(const std::string& pId, const std::string& oId, double amount,
            PaymentMethod method);

    // Getters
    std::string getPaymentId() const { return paymentId; }
    std::string getOrderId() const { return orderId; }
    double getAmount() const { return amount; }
    PaymentMethod getMethod() const { return method; }
    PaymentStatus getStatus() const { return status; }
    double getDiscountAmount() const { return discountAmount; }
    double getFinalAmount() const { return finalAmount; }
    std::string getTransactionReference() const { return transactionReference; }

    // Methods
    void applyDiscount(double discountPercent);
    void processPayment();
    void completePayment(const std::string& transRef);
    void failPayment();
    void refundPayment();
    std::string getMethodString() const;
    std::string getStatusString() const;

    // Display
    void displayInfo() const;
};

#endif
