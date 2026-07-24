#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm> 
#include <chrono>
#include <thread>

using namespace std;

const string adminName = "Admin";
const string adminPass = "1234";

struct transaction
{
	long transactionID;
	string type;
	double amount;
	string receiverAccountNumber;
	string timestamp;
};

struct bankAccount
{
	// هوية الحساب 
	long accountNum;
	string accountType;
	string creationDate; 
	bool isActive;
	// بيانات العميل
	string holderName; 
	string phoneNumber;
	string pin;
	int failedPinAttempts;
	 // الرصيد
	double balance;
	double dailyLimit;   
	double dailyWithdrawn = 0.0; 
	string lastWithdrawDate = "";
	// السجل
	vector < transaction > transactions;
};

struct bankSummary
{
	double totalDeposited; //كل اللى دخل البنك ..بيزيد بس
	double totalWithdrawn; // كل اللى خرج من البنك ..و كرقم بيزيد بس 
	double totalTransferred;  // مجموع كل عمليات التحويل
	double totalBalanceInBank;   // الموجود فى البنك حاليا فعليا 
	int total_Active_Account; //كم حساب شغال حالياً
	long int total_Active_Transactions;
	int total_Frozen_Accounts;
	int totalAccounts;
} BankInfo;

int currentUser = 0;
vector <bankAccount> accounts;
