#pragma once
#include "Structures.h"


long promptForAccountNumber()
{
	long accountNum;
	cout << "Please enter the account number you want to search for : ";
	cin >> accountNum;
	return accountNum;
}
int findAccountIndex(long accountNum)
{
	for (int i = 0; i < accounts.size(); i++)
	{
		if (accountNum == accounts.at(i).accountNum)
			return i;
	}
	return -1;
}

string getValidInput(string prompt, string errorMessage, bool (*isValidName)(string& name))
{
	string input;
	while (true)
	{
		cout << prompt;
		getline(cin >> ws, input);

		if (isValidName(input)) return input;
		cout << errorMessage;
	}
}

bool isValidName(string& name)
{
	if (name.length() < 4) return false;
	return all_of(name.begin(), name.end(), [](char c) { return isalpha(c) || isspace(c); });
}
bool isValidPhone(string& phone)
{
	if (phone.length() != 11) return false;
	return all_of(phone.begin(), phone.end(), [](char c) { return isdigit(c); });
}
bool isValidType(string& type)
{
	if (type == "Savings" || type == "Current" || type == "Youth") return true;
	else return false;
}
bool isValidPIN(string& PIN)
{
	if (PIN.length() != 4)  return false;
	return all_of(PIN.begin(), PIN.end(), [](char c) {return isdigit(c); });
}
void showAccountInfo()
{
	const int indexUser = accounts.size() - 1;
	cout << "\t=====================================================\n";
	cout << "\t\t🎉 Account Created Successfully! 🎉\n";
	cout << "\t=====================================================\n";
	cout << "Note: Your bank account has been generated. Please make sure to save your account details for future logins.\n";
	cout << "==========================================\n";
	cout << "| Date : " << accounts.at(indexUser).creationDate << endl;
	cout << "| Name : " << accounts.at(indexUser).holderName << endl;
	cout << "| Account number : " << accounts.at(indexUser).accountNum << endl;
	cout << "| Account type : " << accounts.at(indexUser).accountType << endl;
	cout << "| Balance : " << accounts.at(indexUser).balance << endl;
	cout << "| Daily limit : " << accounts.at(indexUser).dailyLimit << endl;
	cout << "| PIN : " << accounts.at(indexUser).pin << endl;
	cout << "===========================================\n";
}
void creatAccount()
{
	bankAccount clientInfo;
	
	cout << "\t\t\tPlease provide the following details to proceed : \n\n";
	
	clientInfo.holderName = getValidInput("-> username : ", "INVALID username ", isValidName);
	clientInfo.phoneNumber = getValidInput("-> phone number : ", "INVALID phone ", isValidPhone);
	clientInfo.accountType = getValidInput("account type : \n(Savings or Current or Youth)\n-> ", "INVALID type ", isValidType);
	if (clientInfo.accountType == "Savings")  clientInfo.dailyLimit = 50000.0;
	else if (clientInfo.accountType == "Current") clientInfo.dailyLimit = 150000.0;
	else clientInfo.dailyLimit = 10000.0;
	do 
	{
		cout << "-> Balance : "; cin >> clientInfo.balance;
		if (clientInfo.balance < 500)  cout << "Insufficient balance!\n";
	} while (clientInfo.balance < 500);
	clientInfo.pin = getValidInput("-> PIN : ", "INVALID PIN", isValidPIN);
	if (accounts.size() == 0)
		clientInfo.accountNum = rand() % 9000 + 1000;
	else
		clientInfo.accountNum = accounts.back().accountNum + 1;
	time_t t = time(0);
	int year = localtime(&t)->tm_year + 1900;
	int month = localtime(&t)->tm_mon + 1;
	int day = localtime(&t)->tm_mday;
	clientInfo.creationDate = to_string(day) + "/" + to_string(month) + "/" + to_string(year);
	clientInfo.isActive = true;
	//نسخ معلومات الاكونت للفيكتور الاصلي 
	accounts.push_back(clientInfo);
	showAccountInfo(); 
	BankInfo.totalAccounts++;
	BankInfo.totalBalanceInBank += clientInfo.balance;
	BankInfo.totalDeposited += clientInfo.balance;
	BankInfo.total_Active_Account++;
}
void frozeAccount()
{
	long accountNum = promptForAccountNumber();
	int index = findAccountIndex(accountNum);
	if (index == -1)
		cout << "Account not found\n";
	else
	{
		accounts.at(index).isActive = false;
		cout << "Account frozen successfully\n";
		BankInfo.total_Frozen_Accounts++;
		BankInfo.total_Active_Account--;
	}
}
void activateAccount()
{
	long accountNum = promptForAccountNumber();
	int index = findAccountIndex(accountNum);
	if (index == -1)
		cout << "Account not found\n";
	else
	{
		accounts.at(index).isActive = true;
		cout << "Account activated successfully\n";
		BankInfo.total_Active_Account++;
		BankInfo.total_Frozen_Accounts--;
	}
}
bool updateAccount()
{
	char choice;
	double tempDailyLimit;
	long accountNum = promptForAccountNumber();
	int index = findAccountIndex(accountNum);
	if (index == -1)
	{
		cout << "Account not found\n";
		return false;
	}

	while (true)
	{
		cout << "choose from 1 to 5 : \n";
		cout << "1-Update name\n2-Update phone number\n3-Update daily limit\n4-Update account type\n";
		cout << "your choice : ";
		cin >> choice;

		switch (choice)
		{
		case '1':
			accounts.at(index).holderName = getValidInput("new name : ", "INVALID username ", isValidName);
			break;
		case '2':
			accounts.at(index).phoneNumber = getValidInput("new phone : ", "INVALID phone ", isValidPhone);
			break;
		case '3':
			cout << "new daily limit (>= 500): "; cin >> tempDailyLimit;
			if (tempDailyLimit < 500) cout << "Invalid limit\n";
			else accounts.at(index).dailyLimit = tempDailyLimit;
			break;
		case '4':
			accounts.at(index).accountType = getValidInput("new account type : ", "INVALID type ", isValidType);
			break;
		default:
			cout << "Invalid choice\n";
			break;
		}
		cout << "Do you want to make another change? (Y,any key)\n";
		cin >> choice;
		if (choice != 'y' && choice != 'Y')
			break;
	}

	cout << "Account updated successfully !\n";
	return true;
}