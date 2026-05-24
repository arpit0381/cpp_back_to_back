#include "../include/Payment.h"
#include <iostream>
#include <iomanip>

Payment::Payment() : paymentId(""), orderId(""), amount(0.0),
                     method(PaymentMethod::CASH), status(PaymentStatus::PENDING),
                     discountAmount(0.0), finalAmount(0.0), paymentTime(0),
                     transactionReference("") {}

Payment::Payment(const std::string& pId, const std::string& oId, double amount,
                 PaymentMethod method)
    : paymentId(pId), orderId(oId), amount(amount), method(method),
      status(PaymentStatus::PENDING), discountAmount(0.0), finalAmount(amount),
      transactionReference("") {
    paymentTime = std::time(nullptr);
}

void Payment::applyDiscount(double discountPercent) {
    discountAmount = amount * (discountPercent / 100.0);
    finalAmount = amount - discountAmount;
}

void Payment::processPayment() {
    status = PaymentStatus::PROCESSING;
}

void Payment::completePayment(const std::string& transRef) {
    status = PaymentStatus::COMPLETED;
    transactionReference = transRef;
}

void Payment::failPayment() {
    status = PaymentStatus::FAILED;
}

void Payment::refundPayment() {
    status = PaymentStatus::REFUNDED;
}

std::string Payment::getMethodString() const {
    switch (method) {
        case PaymentMethod::CASH: return "Cash";
        case PaymentMethod::CARD: return "Card";
        case PaymentMethod::DIGITAL_WALLET: return "Digital Wallet";
        case PaymentMethod::CHEQUE: return "Cheque";
        default: return "Unknown";
    }
}

std::string Payment::getStatusString() const {
    switch (status) {
        case PaymentStatus::PENDING: return "Pending";
        case PaymentStatus::PROCESSING: return "Processing";
        case PaymentStatus::COMPLETED: return "Completed";
        case PaymentStatus::FAILED: return "Failed";
        case PaymentStatus::REFUNDED: return "Refunded";
        default: return "Unknown";
    }
}

void Payment::displayInfo() const {
    std::cout << "\n=== PAYMENT DETAILS ===" << std::endl;
    std::cout << "Payment ID: " << paymentId << std::endl;
    std::cout << "Order ID: " << orderId << std::endl;
    std::cout << "Amount: ₹" << std::fixed << std::setprecision(2) << amount << std::endl;
    if (discountAmount > 0) {
        std::cout << "Discount: ₹" << discountAmount << std::endl;
        std::cout << "Final Amount: ₹" << finalAmount << std::endl;
    }
    std::cout << "Method: " << getMethodString() << std::endl;
    std::cout << "Status: " << getStatusString() << std::endl;
    if (!transactionReference.empty()) {
        std::cout << "Transaction Ref: " << transactionReference << std::endl;
    }
    std::cout << "======================\n" << std::endl;
}
