#include "bankAccount.h"

//menu functions
int bankMenu()
{
	int sent = 1;
	int choice = 0;
	while (sent = 1){//Keeps looping until the user enters a corect choice
		cout << "Welcome to Bank" << endl;
		cout << "Please enter which account you'd like to edit." << endl;
		cout << "1. Checking" << endl;
		cout << "2. Saving" << endl;
		cin >> choice;
		cin.sync();

		if (choice < 1 || choice >2)
		{
			cout << "Invalid Choice. Please try again" << endl;
		}
		else
		{
			sent = -1; //changes the sentinal value to terminate the loop
			return choice;
		}

	}
}
int checkingMenu()
{
	int sent = 1;
	int choice = 0;
	while (sent = 1)
	{
		cout << endl;
		cout << endl;
		cout << "Enter the number for the action you'd like to do "<< endl;
		cout << "1. Set Interest Rate" << endl;
		cout << "2. Get Interest Rate" << endl;
		cout << "3. Set Minimum Balance" << endl;
		cout << "4. Get Minimum Balance" << endl;
		cout << "5. Set Service Charge" << endl;
		cout << "6. Get Service Charge" << endl;
		cout << "7. Post Interest" << endl;
		cout << "8. Check If Balance Meets Reqiurment" << endl;
		cout << "9. Write E-Check" << endl;
		cout << "10. Withdraw" << endl;
		cout << "11. Print Account Details" << endl;
		cout << "12. Exit" << endl;
		cin >> choice;
		cin.sync();
		if (choice < 1 || choice >12)
		{
			cout << "Invalid Choice. Try again" << endl;
		}
		else
		{
			sent = -1;
			return choice;
		}
	}
}
int savingMenu()
{
	int sent = 1;
	int choice = 0;
	while (sent = 1)
	{
		cout << endl;
		cout << endl;
		cout << "Enter the number for the action you'd like to do" << endl;
		cout << "1. Set Interest Rate" << endl;
		cout << "2. Get Interest Rate" << endl;
		cout << "3. Post Interest" << endl;
		cout << "4. Deposit" << endl;
		cout << "5. Withdraw" << endl;
		cout << "6. Print Account Details" << endl;
		cout << "7. Exit" << endl;
		cin >> choice;
		cin.sync();
		if (choice < 1 || choice >7)
		{
			cout << "Invalid Choice. Try again" << endl;
		}
		else
		{
			sent = -1;
			return choice;
		}
	}
}


int main()
{
	//declare objects
	checkingAccount *checkAcc = new checkingAccount(1555,100000);
	savingAccount *saveAcc = new savingAccount(266666,15050);
	
	
	//assign the number the user selects from the bank menu to menuChoice
	int menuChoice=bankMenu();

	//Depending on what menuChoice is, the program will come to one of the following if loops
	if (menuChoice == 1)//Checking Account Loop
	{
		int sent = 1; //sentinal value
		//the while loop allows the user to keep selecting from the menu instead of having to run the program over and over for diffrent selections
		while (sent !=-1){
			//checkChoice is assinged the number of the action the user selects from checkingMenu
			int checkChoice = checkingMenu();
			if (checkChoice == 1)
			{
				double rate = 0.0;
				cout << "Enter your interest rate: " << endl;
				cin >> rate;
				cin.sync();
				checkAcc->setInterestRate(rate);
			}
			else if (checkChoice == 2)
			{
				cout << "Your interest Rate is " << checkAcc->getInterestRate() << " percent" << endl;
			}
			else if (checkChoice == 3)
			{
				double min = 0.0;
				cout << "Enter your minimum balance requirement: " << endl;
				cin >> min;
				cin.sync();
				checkAcc->setMinBalance(min);
			}
			else if (checkChoice == 4)
			{
				cout << "Your minimum balance requirment is " << checkAcc->getMinBalance() << endl;
			}
			else if (checkChoice == 5)
			{
				double charge = 0.0;
				cout << "Enter your service charge: " << endl;
				cin >> charge;
				cin.sync();
				checkAcc->setServiceCharge(charge);
			}
			else if (checkChoice == 6)
			{
				cout << "Your service charge is " << checkAcc->getServiceChage() << " dollars" << endl;
			}
			else if (checkChoice == 7)
			{
				checkAcc->postInterest();
			}
			else if (checkChoice == 8)
			{
				checkAcc->checkBalance();
			}
			else if (checkChoice == 9)
			{
				checkAcc->writeCheck();
			}
			else if (checkChoice == 10)
			{
				double money = 0.0;
				cout << "Enter the amount you'd like to withdraw: " << endl;
				cin >> money;
				cin.sync();
				checkAcc->withdraw(money);
			}
			else if (checkChoice == 11)
			{
				checkAcc->printAccount();
			}
			else if (checkChoice == 12)
			{
				//if the user selects the option for escape the sentinal value is changed and the program exits the while loop and terminates
				sent = -1;
			}
		}
	}

	//Saving Account if loop. The same logic is applied to this loop as is the checking account loop above
	else if (menuChoice == 2)
	{
		int sent = 1;
		while (sent != -1)
		{
			int savingChoice = savingMenu();
			if (savingChoice == 1)
			{
				double rate = 0.0;
				cout << "Enter your interest rate: " << endl;
				cin >> rate;
				cin.sync();
				saveAcc->setInterestRate(rate);
			}
			else if (savingChoice == 2)
			{
				cout << "Your interest Rate is " << saveAcc->getInterestRate() << " percent" << endl;
			}
			else if (savingChoice == 3)
			{
				saveAcc->postInterst();
			}
			else if (savingChoice == 4)
			{
				double money = 0.0;
				cout << "Enter amount you'd like to deposit: " << endl;
				cin >> money;
				cin.sync();
				saveAcc->deposit(money);
			}
			else if (savingChoice == 5)
			{
				double money = 0.0;
				cout << "Enter amount you'd like to withdraw: " << endl;
				cin >> money;
				cin.sync();
				saveAcc->withdraw(money);
			}
			else if (savingChoice == 6)
			{
				saveAcc->printAccount();
			}
			else if (savingChoice == 7)
			{
				//if the user selects the option for escape the sentinal value is changed and the program exits the while loop and terminates
				sent = -1;
			}
		}
		
	}



	delete checkAcc;
	delete saveAcc;

	system("PAUSE");
	return 0;
}
