// Bank managment system.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "bankOperation.h"
#include "UI.h"
#include "financialOperation.h"
#include "BankSummary.h"
#include "financialOperation.h"

int main()
{
	bool successAL = false;
	long accountNum;
	int index;
	char again;
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
				case '8': cout << "logging out ... \n";
					successAL = false;
					break;
				}
				if (op == '8') break;
				cout << "Do you want to perform another operation? (y/any key):  "; cin >> again;
			}
			break;
		case '2':index = clientLogin(accountNum);
			break;
		case '3':cout << "Exiting system, please wait...\n";
			exit(0);
		default: cout << "Invalid choice .. please try again\n";
			break;
		}
		//----------------------------------------------------------------------


	}
	return 0;
}

