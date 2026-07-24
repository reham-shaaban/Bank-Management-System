// Bank managment system.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Declarations.h"

int main()
{
	bool successAL;
	bool successCL;
	long accountNum;
	int index;
	char again;
	char keyAnswer;
	// بداية البرنامج
	while (true)
	{
		char choice = showWelcomeScreen();
		switch (choice)
		{
		case '1':successAL = adminLogin();
			again = 'Y';
			while ((again == 'Y' || again == 'y') && successAL)
			{
				char op = adminMenue();
				switch (op)
				{
				case '1': creatAccount();
					break;
				case '2':frozeAccount();
					break;
				case '3':updateAccount();
					break;
				case '4':searchAccount();
					break;
				case '5':viewAllAccounts();
					break;
				case '6':deleteAccount();
					break;
				case '7':displayBankSummary(BankInfo);
					break;
				case '8': cout << "\nlogging out ... \n\n";
					this_thread::sleep_for(chrono::seconds(3));
					successAL = false;
					break;
				default:cout << "Invalid choice !!! \n";
					break;
				}
				if (op == '8') break;
				cout << "\nDo you want to perform another operation? (y/any key):  "; cin >> again;
			}
			break;
		case '2':index = clientLogin(accountNum);
			if (index == -1)   break;
			successCL = true;
			keyAnswer = 'Y';
			while ((keyAnswer == 'Y' || keyAnswer == 'y') && successCL)
			{
				char cmd = clientMenue();
				switch (cmd)
				{
				case '1':withdraw(index, accountNum);
					break;
				case '2':deposit(index, accountNum);
					break;
				case '3':transfer(index, accountNum);
					break;
				case '4':showTransactionHistory(index, accountNum);
					break;
				case '5':showBalance(index);
					break;
				case '6':cout << "logging out ... \n"; successCL = false;
					break;
				default:cout << "Invalid choice\n";
					break;
				}
				if (cmd == '6') break;
				cout << "Do you want to perform another operation? (y/any key):  "; cin >> keyAnswer;
			}
			break;
		case '3':cout << "Exiting system, please wait...\n";
			return 0;
		default: cout << "Invalid choice .. please try again\n";
			break;
		}
	}
	return 0;
}