# 🏦 Bank Management System (Procedural C++)

A comprehensive, terminal-based **Bank Management System** developed entirely in C++. This project demonstrates the power of **Procedural Programming** by managing complex banking workflows without relying on Object-Oriented Programming (No OOP / No Classes). It heavily utilizes structural data types (`structs`), dynamic memory containers (`std::vector`), and efficient reference passing.

---

## ✨ Features

### 👨‍💼 Admin Dashboard
* **Create New Account:** Registers new clients with unique, auto-generated account numbers.
* **Delete Account:** Soft-deletion mechanism to preserve system integrity.
* **Update Account:** Modifies existing user profile data (e.g., Name, Password).
* **View All Accounts:** Displays a tabular report of all active banking profiles.
* **System Summary:** High-level metrics showing total deposits and active profiles.

### 👤 User Portal
* **Secure Login:** Verification of account number and password before any financial execution.
* **Deposit:** Instantly credit funds into the account.
* **Withdraw:** Safely debit funds with strict balance-insufficiency checks.
* **Transfer:** Secure peer-to-peer monetary transfers between accounts.
* **Balance Inquiry:** Real-time financial statement visualization.
* **Transaction History:** Dedicated ledger tracking every deposit, withdrawal, and transfer.

---

## 🛠️ System Architecture & Data Structures

The system architecture focuses on modular design, separation of concerns, and clean data flow.

### Data Schemas
* `Transaction`: Structure holding details for individual actions (type, amount, target, timestamp).
* `BankAccount`: Core structure storing user credentials, balance, and a nested history vector.
* `BankSummary`: System-wide aggregator for real-time statistical reporting.

### Core Architecture Flow
```text
[Main CLI Menu]
   ├── 1. Admin Menu ──> (Requires No Password) ──> Operates on entire Account Vector
   ├── 2. User Menu  ──> [Login Verification]   ──> Passes Specific Index by Reference
   └── 3. System Reports ─────────────────────────> Read-only Global Aggregations
💻 Tech Stack
Language: C++ (C++11 or higher)

Paradigm: Procedural / Structural Programming

Libraries: <iostream>, <vector>, <string>, <iomanip>

🚀 How to Run the Project
Clone the repository to your local machine:

Bash
   git clone [https://github.com/reham-shaaban/Bank-Management-System.git](https://github.com/reham-shaaban/Bank-Management-System.git)
Navigate into the project directory:

Bash
   cd Bank-Management-System
Compile the system using any standard C++ compiler (e.g., g++):

Bash
   g++ main.cpp -o BankSystem
Execute the compiled application:

Bash
   ./BankSystem
