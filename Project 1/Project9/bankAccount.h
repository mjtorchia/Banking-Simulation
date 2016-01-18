#ifndef bankAccount_H
#define bankAccount_H
#include <iostream>
#include <string>
using namespace std;

class bankAccount
{
private:
	int accountNum;
	double balance;
public:
	bankAccount();//default sets everything to zero
	bankAccount(int, double);//overloaded sets account number and balance
	virtual void setAccountNum(int);//sets account number
	virtual int getAccountNum();//retrieve account number
	virtual void setBalance(double); //sets balance
	virtual double getBalance();//retrieve balance
	virtual void deposit(double);//deposit money
	virtual void withdraw(double);//withdraw money;
	virtual void printAccount();//print the account information

};
class checkingAccount : public bankAccount
{
private:
	double interest;
	double minBalance;
	double serviceCharge;
	//int checkingAccountNum;
	//double checkingBalance;
	string checkRep;
	double checkAmount;
	char sendCheck;
public:
	checkingAccount();//default sets everything to zero
	checkingAccount(int,double);//overloaded to set account number and balance
	void setInterestRate(double);//sets interest rate
	double getInterestRate();//retrieve interst rate
	void setMinBalance(double);// set min balance
	double getMinBalance();//retrieve min balance
	void setServiceCharge(double);//set service charge
	double getServiceChage();//retrieve service charge
	void postInterest();//
	void checkBalance();//check to see if the balance if more than the min balance required
	void writeCheck();//
	void withdraw(double);//withdraw money from checking account
	void printAccount();//print account information

};
class savingAccount : public bankAccount
{
private:
	double interest;
	//int savingAccountNum;
	//double savingBalance;
public:
	savingAccount();//default sets everything to zero
	savingAccount(int, double);//overloaded to set account number and balance
	void setInterestRate(double);//sets interest rate
	double getInterestRate();//retrieve interst rate
	void postInterst();
	void deposit(double);
	void withdraw(double);
	void printAccount();

};

#endif