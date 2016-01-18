#include "bankAccount.h"
///////////////Bank Account Definitions////////////////////////
bankAccount::bankAccount()
{
	//default constructor
	accountNum = 0;
	balance = 0.0;
}
bankAccount::bankAccount(int account, double money)
{
	//overloaded constructor
	accountNum = account;
	balance = money;
}
void bankAccount::setAccountNum(int account)
{
	//sets account number
	accountNum = account;
}
int bankAccount::getAccountNum()
{
	//gets account number
	return accountNum;
}
void bankAccount::setBalance(double money)
{
	//sets balance
	balance = money;
}
double bankAccount::getBalance()
{
	//gets balance
	return balance;
}
void bankAccount::deposit(double money)
{
	//deposits money into account
	balance = balance + money;
}
void bankAccount::withdraw(double money)
{
	//checks if you can withdraw money then moves into the if statement, if not, then goes to the else if
	if (money <= balance)
	{
		balance = balance - money;
		cout << "You have withdrawn " << money << " dollars" << endl;
		cout << "Your new balance is " << balance;
	}
	else if (money > balance)
	{
		cout << "Insufficant Funds" << endl;
	}
}
void bankAccount::printAccount()
{
	//prints private variables
	cout << "Your account number is " << accountNum << endl;
	cout << "Your balance is " << balance << endl;
}

///////////Checking Account Definitions//////////////////
checkingAccount::checkingAccount()
{
	//default constructor
	bankAccount::setAccountNum(0);
	bankAccount::setBalance(0);
	serviceCharge = 0.0;
	checkRep = " ";
	checkAmount = 0.0;
	sendCheck = ' ';
}
checkingAccount::checkingAccount(int account, double money)
{
	//overloaded constructor
	bankAccount::setAccountNum(account);
	bankAccount::setBalance(money);
	serviceCharge = 0;
	checkRep = " ";
	checkAmount = 0.0;
	sendCheck = ' ';
	minBalance = 0;
	interest = 0.0;
}
void checkingAccount::setInterestRate(double rate)
{
	//sets interest rate
	interest = rate;
}
double checkingAccount::getInterestRate()
{
	//gets interest rate
	return interest;
}
void checkingAccount::setMinBalance(double min)
{
	//sets minimum balance
	minBalance = min;
}
double checkingAccount::getMinBalance()
{
	//gets minimum balance
	return minBalance;
}
void checkingAccount::setServiceCharge(double charge)
{
	//sets service charge
	serviceCharge = charge;
}
double checkingAccount::getServiceChage()
{
	//gets service charge
	return serviceCharge;
}
void checkingAccount::postInterest()
{
	//shows the amount of interest gained on the account for the money
	cout << "Amount of interest yielded on your checking account this month is " << bankAccount::getBalance()*(interest*.01) << endl;
}
void checkingAccount::checkBalance()
{
	//if the balance is below the mimimum balance then the service fee is subtracted from the account balance, if not, programs says the mimimum is met
	if (bankAccount::getBalance() < minBalance)
	{
		cout << "Your checking account balance is below the required minimum balance. You account will be charged a service fee of " << serviceCharge << " dollars." << endl;
		bankAccount::setBalance(bankAccount::getBalance() - serviceCharge);
		cout << "Your new balance is " << bankAccount::getBalance() << ". Please bring your balance to or above the required minimum balance withen the next 3 buisness days." << endl;
	}
	else
		cout << "Required Mimimum is met" << endl;
}
void checkingAccount::writeCheck()
{
	//Asks who you'd like to make the check out to and how much for. Then asks if you're sure you want to send it
	cout << "Enter who you'd like to make this check out to: ";
	getline(cin, checkRep);//gets the whole line (spaces work)
	cout << endl;
	cout << "Enter amount you'd like to make this check out for: ";
	cin >> checkAmount;
	cout << endl;
	cout << "You're about to send " << checkAmount << " dollars to " << checkRep << ". Are you sure you want to send this check (Y/N)";
	cin >> sendCheck;
	if (sendCheck == ('Y' || 'y'))
	{
		cout << "Check Sent";
	}
	else if (sendCheck == ('N' || 'n'))
	{
		cout << "Check Cancelled";
	}
}
void checkingAccount::withdraw(double money)
{
	//checks if you can withdraw money then moves into the if statement, if not, then goes to the else if
	if (money <= bankAccount::getBalance())
	{
		bankAccount::setBalance(bankAccount::getBalance() - money);
		cout << "You have withdrawn " << money << " dollars" << endl;
		cout << "Your new checking account balance is " << bankAccount::getBalance();
	}
	else if (money > bankAccount::getBalance())
	{
		cout << "Insufficant Funds" << endl;
	}
}
void checkingAccount::printAccount()
{
	//prints account information
	cout << "Interest rate for your checking account: " << interest << endl;
	cout << "Minimum balance for your checking account: " << minBalance << endl;
	cout << "Service Charge for your checking account: " << serviceCharge << endl;
	cout << "Checking account number: " << bankAccount::getAccountNum() << endl;
	cout << "Checking account balance: " << bankAccount::getBalance() << endl;
}


////////////////Saving Account Definitions//////////////////

savingAccount::savingAccount()
{
	//default constructor
	bankAccount::setAccountNum(0);
	bankAccount::setBalance(0.0);
	interest = 0.0;
}
savingAccount::savingAccount(int num, double money)
{
	//overloaded constructor
	bankAccount::setAccountNum(num);
	bankAccount::setBalance(money);
	interest = 0.0;
}
void savingAccount::setInterestRate(double rate)
{
	//sets interest rate
	interest = rate;
}
double savingAccount::getInterestRate()
{
	//gets interset rate
	return interest;
}
void savingAccount::postInterst()
{
	//shows the amount of interest gained on the account for the money
	cout << "Amount of interest yielded on your saving account this money is " << bankAccount::getBalance()*(interest*.01) << endl;

}
void savingAccount::deposit(double money)
{
	//deposits money into account
	bankAccount::setBalance(bankAccount::getBalance() + money);
	cout << "You have deposited " << money << " dollars." << endl;
	cout << "Your new balance is " << bankAccount::getBalance() << " dollars" << endl;
}
void savingAccount::withdraw(double money)
{
	//checks if you can withdraw money then moves into the if statement, if not, then goes to the else if
	if (money <= bankAccount::getBalance())
	{
		bankAccount::setBalance(bankAccount::getBalance() - money);
		cout << "You have withdrawn " << money << " dollars" << endl;
		cout << "Your new saving account balance is " << bankAccount::getBalance();
	}
	else if (money > bankAccount::getBalance())
	{
		cout << "Insufficant Funds" << endl;
	}
}
void savingAccount::printAccount()
{
	//prints account information
	cout << "Interest rate for your checking account: " << interest << endl;
	cout << "Checking account number: " << bankAccount::getAccountNum() << endl;
	cout << "Checking account balance: " << bankAccount::getBalance() << endl;
}

