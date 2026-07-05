#pragma once
#include "Structures.h"

char choice;
char showWelcomeScreen()
{
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
			return true;
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
				return false;
			}
			counter--;
		}
	} while (true);
}
void adminMenue()
{
	cout << "==================================\n";
	cout << "|    \tAdmin menue\t\t |\n";
	cout << "==================================\n";
	cout << "| 1-Create Account\n| 2-Freeze Account\n| 3-Update Account\n| 4-Search Account\n| ";
	cout << "5-View All Accounts\n| 6-Delete Account\n| 7-Show Bank Summary\n| 8-logout\n";
	cout << "==================================\n";
}

bool clientLogin()
{
	long accountNum; 
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
				index = i;
		}
		if (index != -1)
		{
			if (PIN == accounts.at(index).pin)
			{
				cout << "--------------------------------------------\n";
				cout << "\t\tsuccessful login\n";
				cout << "--------------------------------------------\n";
				return true;
			}
			else if (counter != 0)
			{
				cout << "Error !! PIN is incorrect\n";
				cout << "You have [" << counter << "] attempts left before being redirected to the Main Menu.\n";
			}

			else if (counter == 0)
			{

				cout << "Access Denied! 3 failed login attempts reached.\n";
				cout << "Redirecting to the Main Screen... Please wait.\n";

				return false;
			}
			counter--;
		}
		else
		{
			cout << "Error !! Account not found\n";
			return false;
		}
		
	} while (true);
}
void clientMenue()
{
	cout << "==================================\n";
	cout << "|    \tClient menue\t\t |\n";
	cout << "==================================\n";
	cout << "| 1-Withdraw Money\n| 2-Deposit Money\n| 3-Transfer Money\n| 4-Display Transaction History\n| ";
	cout << "5-Check Balance\n| 6-logout\n";
	cout << "==================================\n";
}

