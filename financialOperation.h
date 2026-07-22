#pragma once
#include "Structures.h"
#include "bankOperation.h"

long generateTransactionID(long accountNum ,const bankAccount& currentAccount)
{
	return accountNum * 100 + currentAccount.transactions.size() + 1;
}
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
	cout << "amount : ";
	if (!(cin >> amount) || amount <= 0)
	{
		cin.clear(); cin.ignore(10000, '\n');
		cout << "Error !! You shoud enter positive amount\n";
		return -1;
	}
	return amount;
}
transaction updateTrans(long tID, double amount ,const string& tType,const string& rAccountN ,const string& time)
{
	transaction transactionInfo;
	transactionInfo.amount = amount;
	transactionInfo.receiverAccountNumber = rAccountN;
	transactionInfo.timestamp = time;
	transactionInfo.transactionID = tID;
	transactionInfo.type = tType;
	return transactionInfo;
}
bool withdraw(int index ,const long& accountNum)
{
	printHeader("WITHDRAW MONEY");
	// طلب ادخال المبلغ
	auto& currentAccount = accounts.at(index);
	double amount = money();
	string todayDate = currentDate();
	//----------------------------------
	if (amount == -1)   return false;
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
	long tID = generateTransactionID(accountNum, currentAccount);
	currentAccount.transactions.push_back(updateTrans(tID, amount, "Withdraw", "--", todayDate));
    // تحديث بيانات البنك 
	BankInfo.totalWithdrawn += amount;
	BankInfo.totalBalanceInBank -= amount;
	BankInfo.total_Active_Transactions++;

	cout << "Withdrawal successful!\n";
	cout << "Your new balance : " << currentAccount.balance << endl;
	return true;
}
bool deposit(int index ,const long& accountNum)
{
	printHeader("DEPOSIT MONEY");
	bankAccount& currentAccount = accounts.at(index);
	// طلب ادخال المبلغ
	double amount = money();
	string todayDate = currentDate();
	//--------------------------------
	if (amount == -1)  return false;
	//--------------------------------
	currentAccount.balance += amount;
	// تحديث سجل اليوزر == نجاح العميلة
	long tID = generateTransactionID(accountNum, currentAccount);
	currentAccount.transactions.push_back(updateTrans(tID, amount, "Deposit", "--", todayDate));
	// تحديث بيانات البنك 
	BankInfo.totalDeposited += amount;
	BankInfo.totalBalanceInBank += amount;
	BankInfo.total_Active_Transactions++;

	cout << "Deposit successful!\n";
	cout << "Your new balance : " << currentAccount.balance << endl;
	return true;
}
bool transfer(int index ,const long& accountNum)
{
	printHeader("TRANSFER MONEY");
	cout << "the receiver's details \n";
	long accountNumForReciever = promptForAccountNumber();
	if (accountNumForReciever == accountNum)
	{
		cout << "Transfer failed! You cannot transfer money to your own account.\n";
		return false;
	}
	int indexReciever = findAccountIndex(accountNumForReciever);
	// التاكد ان الحساب المستلم موجود اولا 
	if (indexReciever == -1)
	{
		cout << "Account not found !!\n";
		return false;
	}
	// طلب ادخال المبلغ
	auto& senderAccount = accounts.at(index);
	auto& RecieverAccount = accounts.at(indexReciever);
	double amount = money();
	//--------------------------------
	if (amount == -1)  return false;
	//--------------------------------
	string todayDate = currentDate();
	//التاكد من صلاحية الحساب لسحب المبلغ
	if (amount > senderAccount.balance)
	{
		cout << "Transfer failed! Unsufficiant balance\n";
		return false;
	}
	if (todayDate == senderAccount.lastWithdrawDate)
	{
		if ((amount + senderAccount.dailyWithdrawn) > senderAccount.dailyLimit)
		{
			cout << "Transfer failed! Daily limit exceeded\n";
			return false;
		}
	}
	else
	{
		senderAccount.dailyWithdrawn = 0.0;
		senderAccount.lastWithdrawDate = todayDate;
	}

	senderAccount.balance -= amount;
	senderAccount.dailyWithdrawn += amount;
	RecieverAccount.balance += amount;
	// تحديث سجل الراسل 
	long tID = generateTransactionID(accountNum, senderAccount);
	senderAccount.transactions.push_back(updateTrans(tID, amount, "Transfer to",to_string(accountNumForReciever),todayDate));
	// تحديث سجل المستلم
	long tR_ID = generateTransactionID(accountNumForReciever, RecieverAccount);
	RecieverAccount.transactions.push_back(updateTrans(tR_ID, amount, "Transfer from", to_string(accountNum), todayDate));
   //تحديث سجل البنك 
	BankInfo.totalTransferred += amount;
	BankInfo.total_Active_Transactions++;

	cout << "Transfer successful!\n";
	cout << "Your new balance : " << senderAccount.balance << endl;
	return true;
}
