#pragma once
#include "Declarations.h"

void printHeader(string title)
{
	cout << "\n====================================================\n";
	cout << "\t" << title ;
	cout << "\n====================================================\n";
}
char showWelcomeScreen()
{
	char choice;
	cout << "=======================================================\n";
	cout << "||\t\tBANK MANAGEMENT SYSTEM \n||\t    Secure Core Banking Environment \n";
	cout << "=======================================================\n";
	cout << "1-Admin\n2-Client\n3-Exit\n";
	cin >> choice;
	return choice;
}
bool adminLogin()
{
	string name, pass;
	int counter = 2;
	cout << "Please enter username and password\n";
	do 
	{
		cout << "-> name : ";   getline (cin >> ws, name);
		cout << "-> password : ";getline (cin >> ws, pass);
		if (name == adminName && pass == adminPass)
		{
			cout << "Successful Login\n";
			return true;
		}
		else
		{
			if (counter != 0)
			{
				cout << "error !! \n password or name is incorrect\n";
				cout << "You have [" << counter << "] attempts left before being redirected to the Main Menu.\n";
			}
		    else if (counter == 0)
			{
				cout << "Access Denied! 3 failed login attempts reached.\n";
				cout << "Redirecting to the Main Screen... Please wait.\n";
				this_thread::sleep_for(chrono::seconds(3));
				return false;
			}
			counter--;
		}
	} while (true);
}
char adminMenue()
{   
	char choice;
	printHeader("ADMIN MINU");
	cout << "| 1-Create Account\n| 2-Freeze Account\n| 3-Update Account\n| 4-Search Account\n| ";
	cout << "5-View All Accounts\n| | 6-Show Bank Summary\n| 7-logout\n";
	cout << "==================================\n";
	cin >> choice;
	return choice;
}
int clientLogin(long& accountNum)
{
	string PIN;
	int counter = 2;
	int index = -1;
	cout << "please enter account number and PIN\n";
	cout << "-> Account Number : ";  cin >> accountNum;
	do 
	{
		cout << "-> PIN : ";  getline(cin >> ws, PIN);
		for (int i = 0; i < accounts.size(); i++)
		{
			if (accountNum == accounts.at(i).accountNum)
			{
				index = i;
				break;
			}
		}
		if (index != -1)
		{
			if (PIN == accounts.at(index).pin)
			{
				if (isAccountFrozen(index))
				{
					cout << "\t\tAccount is frozen. \nNo transactions can be performed until it is activated\n";
					return -1;
				}
				else
				{
					cout << "--------------------------------------------\n";
					cout << "\t\tsuccessful login\n";
					cout << "--------------------------------------------\n";
					return index;
				}
			}
			else if (counter != 0)
			{
				cout << "Error !! PIN is incorrect\n";
				cout << "You have [" << counter << "] attempts left before being redirected to the Main Menu.\n";
			}

			else if (counter == 0)
			{
				cout << "Maximum attempts reached. Your account has been temporarily blocked.\n";
				cout << "Redirecting to the Main Screen... Please wait.\n";
				accounts.at(index).isActive = 0;
				accounts.at(index).failedPinAttempts++;
				BankInfo.total_Active_Account--;
				BankInfo.total_Frozen_Accounts++;
				this_thread::sleep_for(chrono::seconds(5));
				return -1;
			}
			counter--;
		}
		else
		{
			cout << "Error !! Account not found\n";
			return -1;
		}
		
	} while (true);
}
char clientMenue()
{
	char choice;
	printHeader("CLIENT MENU");
	cout << "| 1-Withdraw Money\n| 2-Deposit Money\n| 3-Transfer Money\n| 4-Display Transaction History\n| ";
	cout << "5-Check Balance\n| 6-logout\n";
	cout << "==================================\n";
	cin >> choice;
	return choice;
}

