#pragma once
#include "Structures.h"

void printHeader(string title);
char showWelcomeScreen();
bool adminLogin();
char adminMenue();
int clientLogin(long&);
char clientMenue();
void displayBankSummary(const bankSummary&);
bool showTransactionHistory(int, const long&);
void showAccountDetails(int);
void showBalance(int);
long generateTransactionID(long, const bankAccount&);
double money();
transaction updateTrans(long, double, const string&, const string&, const string&);
bool withdraw(int, const long&);
bool deposit(int, const long&);
bool transfer(int, const long&);
string currentDate();
bool isAccountFrozen(int);
long promptForAccountNumber();
int findAccountIndex(const long&);
string getValidInput(string, string, bool (*isValidName)(string& name));
bool isValidName(string&);
bool isValidPhone(string&);
bool isValidType(string&);
bool isValidPIN(string&);
void creatAccount();
void frozeAccount();
void activateAccount();
bool updateAccount();
void searchAccount();
void viewAllAccounts();
void deleteAccount();