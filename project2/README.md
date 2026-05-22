# Project 2: Banking System

A comprehensive C++ banking management system demonstrating advanced OOP principles and real-world application design.

## Overview

This project implements a **Banking System** that simulates a real bank with multiple account types, transaction management, and advanced financial features. It showcases:

- **Inheritance & Polymorphism**: Multiple account types with specialized behavior
- **Virtual Functions**: Overridden methods in derived classes
- **Smart Pointers**: Dynamic memory management with `std::shared_ptr`
- **Advanced OOP**: Composition, aggregation, and encapsulation
- **Date/Time Handling**: Transaction timestamping
- **Financial Calculations**: Interest, fees, and balance management
- **File I/O**: Persistent data storage
- **Error Handling**: Comprehensive validation and security

## Project Structure

```
project2/
├── include/
│   ├── Transaction.h          # Transaction class header
│   ├── Account.h              # Base Account class header
│   ├── SavingsAccount.h       # Derived Savings Account header
│   ├── CheckingAccount.h      # Derived Checking Account header
│   └── Bank.h                 # Bank manager class header
├── src/
│   ├── main.cpp               # Main program and user interface
│   ├── Transaction.cpp        # Transaction implementation
│   ├── Account.cpp            # Base Account implementation
│   ├── SavingsAccount.cpp     # Savings Account implementation
│   ├── CheckingAccount.cpp    # Checking Account implementation
│   └── Bank.cpp               # Bank implementation
├── build/                     # Build output directory
├── CMakeLists.txt             # CMake build configuration
└── README.md                  # This file
```

## Architecture

### Class Hierarchy

```
Account (Base Class)
├── SavingsAccount (Derived)
└── CheckingAccount (Derived)

Bank (Manager Class)
└── Contains multiple Account objects

Transaction (Data Class)
└── Represents individual transactions
```

## Classes

### 1. Transaction
**Purpose:** Represent individual financial transactions

**Key Attributes:**
- Transaction ID (auto-generated)
- Type (DEPOSIT, WITHDRAWAL, TRANSFER, INTEREST)
- Amount
- Timestamp
- Description

**Key Methods:**
```cpp
TransactionType getType() const;
double getAmount() const;
std::string getTimestamp() const;
void displayTransaction() const;
```

### 2. Account (Base Class)
**Purpose:** Provide core banking functionality

**Key Attributes:**
- Account number (auto-generated)
- Account holder name
- Balance
- PIN (4-digit security)
- Transaction history
- Active status

**Key Virtual Methods:**
```cpp
virtual bool deposit(double amount, int pin);
virtual bool withdraw(double amount, int pin);
virtual bool transfer(double amount, Account& recipient, int pin);
virtual double calculateInterest() const;
virtual void applyInterest();
virtual void displayAccountInfo() const;
```

**Additional Methods:**
```cpp
bool changePIN(int oldPin, int newPin);
void displayTransactionHistory() const;
void displayLastNTransactions(int n) const;
```

### 3. SavingsAccount (Derived from Account)
**Purpose:** Specialized savings account with interest and restrictions

**Additional Attributes:**
- Interest rate (annual percentage)
- Minimum balance requirement
- Withdrawal limit per month
- Withdrawal counter

**Overridden Methods:**
```cpp
bool withdraw(double amount, int pin) override;
double calculateInterest() const override;
void displayAccountInfo() const override;
```

**Specialized Methods:**
```cpp
void setInterestRate(double rate);
void applyMinimumBalancePenalty();
void resetWithdrawalCount();
```

**Features:**
- Monthly interest calculation
- Withdrawal limits (e.g., 3 withdrawals/month)
- Minimum balance enforcement
- Penalties for balance violations

### 4. CheckingAccount (Derived from Account)
**Purpose:** General-purpose checking account with overdraft support

**Additional Attributes:**
- Monthly service fee
- Overdraft protection (enabled/disabled)
- Overdraft limit (max allowed negative balance)

**Overridden Methods:**
```cpp
bool withdraw(double amount, int pin) override;
double calculateInterest() const override;
void displayAccountInfo() const override;
```

**Specialized Methods:**
```cpp
void setMonthlyFee(double fee);
void setOverdraftProtection(bool enabled);
void applyMonthlyFee();
double getAvailableBalance() const;
```

**Features:**
- Optional overdraft protection
- Monthly service fees
- Minimal interest for positive balances
- Flexible withdrawal limits

### 5. Bank (Manager Class)
**Purpose:** Manage multiple accounts and coordinate banking operations

**Responsibilities:**
- Create and delete accounts
- Process transactions
- Generate reports and statistics
- Apply interest and fees
- Data persistence

**Key Methods:**
```cpp
std::string createSavingsAccount(...);
std::string createCheckingAccount(...);
bool deposit(const std::string& accountNumber, double amount, int pin);
bool withdraw(const std::string& accountNumber, double amount, int pin);
bool transfer(const std::string& fromAcc, const std::string& toAcc, double amount, int pin);
void displayAllAccounts() const;
void applyInterestToAllAccounts();
void applyMonthlyFeesToAllCheckingAccounts();
double getTotalAssetsUnderManagement() const;
```

## Key Features

### 1. Account Management
- Create multiple account types
- Delete accounts (only if empty)
- Manage account PIN security
- View account details

### 2. Transaction Operations
- **Deposit**: Add funds to account
- **Withdraw**: Remove funds with validation
- **Transfer**: Move funds between accounts
- **Interest**: Automatic interest calculation and application
- **Fees**: Monthly service fees for checking accounts

### 3. Security Features
- 4-digit PIN authentication for all operations
- PIN change functionality
- Transaction logging and history
- Account status tracking

### 4. Financial Features
- **Interest Calculation**: Automatic compounding
- **Overdraft Protection**: Optional for checking accounts
- **Minimum Balance**: Enforced for savings accounts
- **Withdrawal Limits**: Restricted for savings accounts
- **Monthly Fees**: Applied to checking accounts

### 5. Reporting & Statistics
- Individual account statements
- Transaction history (full or limited)
- Class-level statistics
- Total assets under management

### 6. Data Validation
- PIN validation on all operations
- Amount validation (positive values)
- Balance verification
- Account existence checks

## Build Instructions

### Prerequisites
- C++17 compatible compiler
- CMake 3.10 or higher

### Compilation

#### Using CMake (Recommended)
```bash
cd project2
mkdir -p build
cd build
cmake ..
cmake --build .
```

#### Using g++ (Direct)
```bash
cd project2
g++ -std=c++17 -o BankingSystem src/*.cpp -Iinclude
```

#### Using MSVC
```bash
cd project2
cl /std:c++17 /Fo.\build\ /Fe.\build\BankingSystem.exe src/*.cpp /Iinclude
```

## Running the Application

### After building with CMake:
```bash
# Linux/macOS
./build/BankingSystem

# Windows
.\build\Debug\BankingSystem.exe
# or
.\build\Release\BankingSystem.exe
```

## Usage Example

```
Welcome to Global Bank!
✓ Savings account created successfully!
Account Number: ACC1000895342

✓ Checking account created successfully!
Account Number: ACC1001234567

========== Global Bank ==========
1. Create Savings Account
2. Create Checking Account
3. Deposit Money
...
Enter your choice: 3
Enter account number: ACC1000895342
Enter amount to deposit: $5000
Enter PIN: 1234
✓ Deposit successful. New balance: $5000.00

Enter your choice: 7
Enter account number: ACC1000895342

========== TRANSACTION HISTORY ==========
[2026-05-22 14:30:45] DEPOSIT      | Amount: $5000.00    | ID: TXN0000001234567890
========================================
```

## Advanced C++ Concepts Demonstrated

| Concept | Implementation |
|---------|-----------------|
| **Inheritance** | SavingsAccount & CheckingAccount inherit from Account |
| **Polymorphism** | Virtual functions overridden in derived classes |
| **Virtual Functions** | deposit(), withdraw(), calculateInterest() |
| **Pure Virtual** | Could be implemented for abstract base classes |
| **Smart Pointers** | `std::shared_ptr` for automatic memory management |
| **Composition** | Bank contains Accounts; Accounts contain Transactions |
| **Aggregation** | Transactions aggregated in Account history |
| **Encapsulation** | Private members with public getters/setters |
| **Method Overriding** | Derived classes customize parent behavior |
| **Dynamic Dispatch** | Virtual functions resolved at runtime |
| **Templates** | `std::vector`, `std::find_if`, `std::max_element` |
| **Date/Time** | `std::time`, `std::tm`, `std::put_time` |
| **File I/O** | `std::ifstream`, `std::ofstream` for persistence |
| **String Handling** | `std::stringstream`, `std::getline` |
| **Error Handling** | Validation and error checking throughout |
| **Const Correctness** | Const methods and parameters |

## Learning Outcomes

By studying this project, you will learn:

1. **Inheritance**: How to create derived classes that extend base functionality
2. **Polymorphism**: Using virtual functions for flexible, extensible code
3. **Composition vs. Inheritance**: When and how to use each pattern
4. **Memory Management**: Smart pointers for safe automatic cleanup
5. **Real-world Design**: Modeling complex systems with multiple interdependent classes
6. **Financial Logic**: Interest, fees, and balance calculations
7. **Security Principles**: PIN authentication and access control
8. **Data Persistence**: Saving and loading complex data structures
9. **User Interface**: Menu-driven interactive programs
10. **Extensibility**: How to add new account types or features

## Extension Ideas

### Basic Extensions
- Add account statement export to CSV/PDF
- Implement account search by holder name
- Add transaction filtering by date range
- Create account statements with totals

### Intermediate Extensions
- Add database support (SQLite)
- Implement role-based access (admin, customer, teller)
- Create investment account with stock trading
- Add currency support for international transactions

### Advanced Extensions
- Network banking with client-server architecture
- Web interface using REST API
- Machine learning for fraud detection
- Blockchain-based transaction verification
- Multi-threading for concurrent transactions

## Common Issues & Solutions

### Issue: "undefined reference" errors
**Solution:** Ensure all `.cpp` files are included in compilation.

### Issue: PIN verification failures
**Solution:** Make sure you enter the correct 4-digit PIN used when creating the account.

### Issue: Withdrawal rejected for savings account
**Solution:** Check if you've exceeded the monthly withdrawal limit or fallen below minimum balance.

### Issue: Overdraft not working for checking account
**Solution:** Verify overdraft protection is enabled and balance is within overdraft limit.

## Design Patterns Used

- **Strategy Pattern**: Different withdrawal/deposit strategies for account types
- **Factory Pattern**: Bank creates different account types
- **Observer Pattern**: Transaction history tracks all account changes
- **Composition Pattern**: Bank composes multiple accounts
- **Template Method Pattern**: Account base class defines transaction flow

## Code Quality Features

- Comprehensive input validation
- Clear error messages
- Consistent naming conventions
- Well-organized file structure
- Modular, reusable code
- Comments on complex logic
- Safe memory management with smart pointers

---

**Created:** 2026
**C++ Standard:** C++17
**Build System:** CMake
**Complexity:** Intermediate-Advanced
**Learning Level:** Suitable for intermediate C++ learners
