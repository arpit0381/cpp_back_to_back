#include "Payment.h"
#include <iostream>
#include <ctime>
#include <sstream>
#include <random>

Payment::Payment() : paymentId(0), bookingId(0), amount(0), 
                     method(PaymentMethod::CREDIT_CARD), 
                     status(PaymentStatus::PENDING), paymentDate(""), transactionId("") {}

Payment::Payment(int id, int bookingId, double amount, PaymentMethod method)
    : paymentId(id), bookingId(bookingId), amount(amount), 
      method(method), status(PaymentStatus::PENDING), transactionId("") {
    // Set current date
    time_t now = time(0);
    tm* timeinfo = localtime(&now);
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", timeinfo);
    paymentDate = buffer;
}

int Payment::getPaymentId() const { return paymentId; }
int Payment::getBookingId() const { return bookingId; }
double Payment::getAmount() const { return amount; }
PaymentMethod Payment::getMethod() const { return method; }
PaymentStatus Payment::getStatus() const { return status; }
std::string Payment::getPaymentDate() const { return paymentDate; }
std::string Payment::getTransactionId() const { return transactionId; }

void Payment::setStatus(PaymentStatus status) { this->status = status; }
void Payment::setPaymentDate(const std::string& date) { this->paymentDate = date; }
void Payment::setTransactionId(const std::string& id) { this->transactionId = id; }

bool Payment::processPayment() {
    if (status == PaymentStatus::PENDING) {
        status = PaymentStatus::COMPLETED;
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(100000, 999999);
        std::string txId = "TXN" + std::to_string(dis(gen));
        transactionId = txId;
        return true;
    }
    return false;
}

void Payment::refund() {
    if (status == PaymentStatus::COMPLETED) {
        status = PaymentStatus::REFUNDED;
    }
}

std::string Payment::getMethodString() const {
    switch(method) {
        case PaymentMethod::CREDIT_CARD: return "Credit Card";
        case PaymentMethod::DEBIT_CARD: return "Debit Card";
        case PaymentMethod::CASH: return "Cash";
        case PaymentMethod::DIGITAL_WALLET: return "Digital Wallet";
        default: return "Unknown";
    }
}

std::string Payment::getStatusString() const {
    switch(status) {
        case PaymentStatus::PENDING: return "Pending";
        case PaymentStatus::COMPLETED: return "Completed";
        case PaymentStatus::FAILED: return "Failed";
        case PaymentStatus::REFUNDED: return "Refunded";
        default: return "Unknown";
    }
}

void Payment::display() const {
    std::cout << "Payment ID: " << paymentId << "\n"
              << "Booking ID: " << bookingId << "\n"
              << "Amount: $" << amount << "\n"
              << "Method: " << getMethodString() << "\n"
              << "Status: " << getStatusString() << "\n"
              << "Date: " << paymentDate << "\n"
              << "Transaction ID: " << transactionId << "\n";
}
