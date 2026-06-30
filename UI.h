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
	string name;
	string pass;
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

void AdminMenue()
{
	cout << "==================================\n";
	cout << "|    \tAdmin menue\t\t |\n";
	cout << "==================================\n";
	cout << "| 1-Create Account\n| 2-Freeze Account\n| 3-Update Account\n| 4-Search Account\n| ";
	cout << "5-View All Accounts\n| 6-Delete Account\n| 7-Show Bank Summary\n| 8-logout\n";
	cout << "==================================\n";
}



