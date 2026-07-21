#pragma once
#include "Structures.h"

bool showTransactionHistory(int index , const long& accountNum)
{
	const auto& currentAccount = accounts.at(index);
	if (currentAccount.transactions.empty())
	{
		cout << "No transactions found.\n";
		return false;
	}
	cout << "\tTransaction details\n";
	for (const transaction& t : currentAccount.transactions)
	{
		cout << "ID : " << t.transactionID << endl;
		cout << "Type : " << t.type << endl;
		cout << "Amount : " << t.amount << endl;
		cout << "Receiver Acc : " << t.receiverAccountNumber << endl;
		cout << "Date : " << t.timestamp << endl;
		cout << "-----------------------------\n";
    }
	return true;
}

void showAccountDetails(int index)
{
	const auto& currentAccount = accounts.at(index);
	cout << "\tAccount details\n";
	cout << "Name : " << currentAccount.holderName << endl;
	cout << "Account number : " << currentAccount.accountNum << endl;
	cout << "Account type : " << currentAccount.accountType << endl;
	cout << "Balance : " << currentAccount.balance << endl;
	cout << "Creation date : " << currentAccount.creationDate<< endl;
	cout << "Phone number : " << currentAccount.phoneNumber << endl;
	cout << "-----------------------------------\n";
}