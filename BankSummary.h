#pragma once
#include "Declarations.h"

void displayBankSummary(const bankSummary& bankInfo)
{
    cout << "\n========================================\n";
    cout << "\t   BANK GENERAL SUMMARY\n";
    cout << "========================================\n";
    cout << "Total Deposited      : $" << bankInfo.totalDeposited << endl;
    cout << "Total Withdrawn      : $" << bankInfo.totalWithdrawn << endl;
    cout << "Total Transferred    : $" << bankInfo.totalTransferred << endl;
    cout << "Total Bank Balance   : $" << bankInfo.totalBalanceInBank << endl;
    cout << "----------------------------------------\n";
    cout << "Total Accounts       : " << bankInfo.totalAccounts << endl;
    cout << "Active Accounts      : " << bankInfo.total_Active_Account << endl;
    cout << "Frozen Accounts      : " << bankInfo.total_Frozen_Accounts << endl;
    cout << "Active Transactions  : " << bankInfo.total_Active_Transactions << endl;
    cout << "========================================\n\n";
}