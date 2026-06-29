
#include "Structures.h"

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


