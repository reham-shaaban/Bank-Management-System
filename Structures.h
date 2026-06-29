
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm> 
using namespace std;

struct transaction
{
	string transactionID;
	string type;
	double amount;
	string receiverAccountNumber;
	string timestamp;
};

struct bankAccount
{
	// هوية الحساب 
	long accountNum;//
	string accountType;//
	string creationDate; // لتسجيل متى قام العميل بفتح هذا الحساب في البنك لأول مرة 
	bool isActive;
	// بيانات العميل
	string holderName; //
	string phoneNumber;//
	string pin;//
	int  failedPinAttempts = 0;  // لو تعدت 3 مرات يتم تجميد الحساب
	 // الرصيد
	double balance;//
	double dailyLimit;  //  الحد الاقصي للمال اللى ممكن تستخدمه فى اليوم الواحد 
	double dailyWithdrawn = 0.0;  // dailyLimit بيتحدث يوميا لمعرفة 
	string lastWithdrawDate = "";
	// السجل
	vector < transaction > transactions;
};

struct bankSummary
{
	double totalDeposited; //كل اللى دخل البنك ..بيزيد بس
	double totalWithdrawn; // كل اللى خرج من البنك ..و كرقم بيزيد بس 
	double totalTransferred;  // مجموع كل عمليات التحويل
	double totalBalanceInBank;   // الموجود فى البنك حاليا فعليا 
	int total_Active_Account; //كم حساب شغال حالياً
	long int total_Active_Transactions;
	int total_Frozen_Accounts;
	int totalAccounts;
};

int currentUser = 0;
vector <bankAccount> accounts;
