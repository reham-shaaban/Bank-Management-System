#pragma once
#include "Structures.h"
#include "bankOperation.h"

string currentDate()
{
	time_t t = time(0);
	tm* timeInfo = localtime(&t);
	int year = timeInfo->tm_year + 1900;
	int month = timeInfo->tm_mon + 1;
	int day = timeInfo->tm_mday;
	 return to_string(day) + "/" + to_string(month) + "/" + to_string(year);
}
double money()
{
	double amount;
	cout << "amount : "; cin >> amount;
	return amount;
}
bool withdraw()
{
	cout << "\t--- Withdraw Money ---\n";
	long accountNum = promptForAccountNumber();
	int index = findAccountIndex(accountNum);
   // التاكد ان الحساب موجود اولا 
	if (index == -1)  
	{
		cout << "Account not found !!\n";
		return false;
	}
	// طلب ادخال المبلغ
	auto& currentAccount = accounts.at(index);
	double amount = money();
	string todayDate = currentDate();
	//التاكد من صلاحية الحساب لسحب المبلغ
	if (amount > currentAccount.balance)
	{
		cout << "Withdrawal failed! Unsufficiant balance\n";
		return false;
	}
	if (todayDate == currentAccount.lastWithdrawDate)
	{
		if ((amount + currentAccount.dailyWithdrawn) > currentAccount.dailyLimit)
		{
			cout << "Withdrawal failed! Daily limit exceeded\n";
			return false;
		}
	}
	else 
	{
		currentAccount.dailyWithdrawn = 0.0;
		currentAccount.lastWithdrawDate = todayDate;
	}

	currentAccount.balance -= amount;
	currentAccount.dailyWithdrawn += amount;
	
	// تحديث سجل اليوزر
	transaction transactionInfo;
	transactionInfo.amount = amount;
	transactionInfo.type = "Withdraw";
	transactionInfo.transactionID = accountNum * 1000 + currentAccount.transactions.size() + 1;
	transactionInfo.timestamp = currentAccount.lastWithdrawDate;
	currentAccount.transactions.push_back(transactionInfo);
    // تحديث بيانات البنك 
	BankInfo.totalWithdrawn += amount;
	BankInfo.totalBalanceInBank -= amount;
	BankInfo.total_Active_Transactions++;

	cout << "Withdrawal successful!\n";
	cout << "Your new balance : " << currentAccount.balance << endl;
	return true;
}
