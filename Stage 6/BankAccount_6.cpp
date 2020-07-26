#include <iostream>
#include <string>

using namespace std;

class BankAccount
{
private:
	int accountNumber;
	double accountBalance;
	const double ANNUAL_INTEREST_RATE = 3;
public:
	void enterAccountData();
	void computeInterest(int);
	void displayAccount();
	int getAccountNumber();
	double getAccountBalance();
	void setAccountBalance(double);
};

void BankAccount::enterAccountData()
{
	do
	{
		cout << "\nEnter Account Number: ";
		cin >> this->accountNumber;
		cin.ignore();

		if (this->accountNumber < 1000 || this->accountNumber > 9999)
		{
			cout << "\nAccount Number should be between 1000 and 9999" << endl;
		}
	} while (this->accountNumber < 1000 || this->accountNumber > 9999);

	do
	{
		cout << "Enter Account Balance: $";
		cin >> this->accountBalance;
		cin.ignore();

		if (this->accountBalance < 0.00)
		{
			cout << "\nAccount balance cannot be negative" << endl;
		}

		if (this->accountBalance > 100000.00)
		{
			cout << "\nAccount balance cannot be over $100,000.00" << endl;
		}
	} while (this->accountBalance < 0.00 || this->accountBalance > 100000.00);
}

void BankAccount::computeInterest(int years)
{
	double interestAmount, startingBalance, endingBalance;

	startingBalance = this->accountBalance;
	interestAmount = this->ANNUAL_INTEREST_RATE;

	cout << "--------------------------------------------" << endl;

	for (int i = 0; i < years; i++)
	{
		endingBalance = startingBalance + (startingBalance * (interestAmount / 100));

		cout << " Ending Balance of Year " << i + 1 << ": $" << endingBalance << endl;

		startingBalance = endingBalance;
	}
}

void BankAccount::displayAccount()
{
	cout << "\nAccount Number: " << this->accountNumber << endl;
	cout << "Account Balance: $" << this->accountBalance << endl;
}

int BankAccount::getAccountNumber()
{
	return this->accountNumber;
}

double BankAccount::getAccountBalance()
{
	return this->accountBalance;
}

void BankAccount::setAccountBalance(double amount)
{
	this->accountBalance = amount;
}


class Transaction
{
private:

public:
	void performTransaction(BankAccount&, BankAccount&, double);
	
	
};

void Transaction::performTransaction(BankAccount &fromAccount, BankAccount &toAccount, double transferAmount)
{
	cout << "\nFrom Account Number: " << fromAccount.getAccountNumber() << endl;
	cout << "From Account Balance: " << fromAccount.getAccountBalance() << endl;
	cout << endl;
	cout << "To Account Number: " << toAccount.getAccountNumber() << endl;
	cout << "To Account Balance: " << fromAccount.getAccountBalance() << endl;

	double fromBalance = fromAccount.getAccountBalance();
	double toBalance = toAccount.getAccountBalance();

	while ((fromBalance - transferAmount) < 0.00)
	{
		if ((fromBalance - transferAmount) < 0.00)
		{
			cout << "\nInsufficient Balance to perform transfer" << endl;
		}
		cout << "Enter Transfer Amount: ";
		cin >> transferAmount;
	}

	if ((fromBalance - transferAmount) <= 10.00)
	{
		cout << "\nTransfer will cause the balance in the first account to drop below $10.00" << endl;
	}

	if ((toBalance + transferAmount) > 100000.00)
	{
		cout << "\nTransfer will cause the balance in the second account to be greater than\n"
			"$100,000.00, which  is the highest amount that is federally insured." << endl;
	}

	double newFromBalance = fromBalance - transferAmount;
	double newToBalance = toBalance + transferAmount;

	fromAccount.setAccountBalance(newFromBalance);
	toAccount.setAccountBalance(newToBalance);

	cout << "\n__________________" << endl;
	cout << "Transfer Completed" << endl;
	cout << "------------------" << endl;
	cout << "Account Number: " << fromAccount.getAccountNumber() << endl;
	cout << "Account Balance: " << fromAccount.getAccountBalance() << endl;
	cout << endl;
	cout << "Account Number: " << toAccount.getAccountNumber() << endl;
	cout << "Account Balance: " << toAccount.getAccountBalance() << endl;

	char input;
	bool rollback = false, inputRepeat = false;
	do
	{
		cout << "\nDo you wish to rollback the transaction ('Y' or 'N'): ";
		cin >> input;

		if (input == 'Y' || input == 'y')
		{
			inputRepeat = true;
			rollback = true;
		}
		else if (input == 'N' || input == 'n')
		{
			inputRepeat = true;
			rollback = false;
		}
		else
		{
			cout << "\nInvalid Entry!!\nPlease Try Again" << endl;
		}
	} while (!inputRepeat);

	if (rollback)
	{
		fromAccount.setAccountBalance(fromBalance);
		toAccount.setAccountBalance(toBalance);

		cout << "\n__________________" << endl;
		cout << "Transaction Rollbacked" << endl;
		cout << "------------------" << endl;
		cout << "Account Number: " << fromAccount.getAccountNumber() << endl;
		cout << "Account Balance: " << fromAccount.getAccountBalance() << endl;
		cout << endl;
		cout << "Account Number: " << toAccount.getAccountNumber() << endl;
		cout << "Account Balance: " << toAccount.getAccountBalance() << endl;
	}

}


void menu(int &choice)
{
	do
	{
		cout << "\n_______________________________" << endl;
		cout << "\t  Main Menu" << endl;
		cout << "-------------------------------" << endl;
		cout << "1 - Create a Bank Account" << endl;
		cout << "2 - View a Bank Account Details" << endl;
		cout << "3 - Compute Interest" << endl;
		cout << "4 - Fund Transfer" << endl;
		cout << "0 - Exit" << endl;
		cout << "Enter your Choice: ";
		cin >> choice;

		if (choice != 0 && choice != 1 && choice != 2 && choice != 3 && choice != 4)
		{
			cout << "\nInvalid Entry!!\nPlease Try Again\n" << endl;
		}
	} while (choice != 0 && choice != 1 && choice != 2 && choice != 3 && choice != 4);
}


void adminLogin()
{
	string admin = "admin", adminPassword = "admin";
	string username, password;
	bool login = false;

	do
	{
		cout << "\nAdministrator Login\n" << endl;
		cout << "Username: ";
		cin >> username;
		cout << "Password: ";
		cin >> password;
		cin.ignore();
		if (username == admin && password == adminPassword)
		{
			cout << "\nLogin Successfull" << endl;
			login = true;
		}
		else
		{
			cout << "\nLogin Unsuccessfull\nPlease try again\n" << endl;
		}
	} while (!login);
}

int getAccountIndex(BankAccount Accounts[], int accountNumber, int count)
{
	int index = -1;
	bool isFound = false;

	for (int i = 0; i < count; i++)
	{
		if (Accounts[i].getAccountNumber() == accountNumber)
		{
			index = i;
			isFound = true;
			break;
		}
	}

	if (!isFound)
	{
		cout << "Account Number not in the system" << endl;
	}

	return index;
}


void main()
{
	BankAccount Accounts[10];

	cout << "Welcome to InterBanking Pty" << endl;

	int choice;
	int count = 0;

	do
	{
		menu(choice);

		switch (choice)
		{
		case 1:
		{
			adminLogin();

			bool repeat = false;
			char input;

			cout << "\n_____________________" << endl;
			cout << "Bank Account Creation" << endl;
			cout << "---------------------" << endl;

			do
			{
				for (int i = 0; i < 10; i++)
				{
					Accounts[i].enterAccountData();
					count++;

					if (i < 9)
					{
						bool inputRepeat = false;
						do
						{
							cout << "\nDo you wish to continue ('Y' or 'N'): ";
							cin >> input;
							if (input == 'Y' || input == 'y')
							{
								inputRepeat = true;
								repeat = false;
							}
							else if (input == 'N' || input == 'n')
							{
								inputRepeat = true;
								repeat = true;
							}
							else
							{
								cout << "\nInvalid Entry!!\nPlease Try Again" << endl;
							}
						} while (!inputRepeat);
					}

					if (repeat)
						break;
				}
				repeat = true;
			} while (!repeat);

			break;
		}
		case 2:
		{
			cout << "\n_______________" << endl;
			cout << "Account Details" << endl;
			cout << "---------------" << endl;

			for (int i = 0; i < count; i++)
			{
				Accounts[i].displayAccount();
			}

			break;
		}
		case 3:
		{
			int years;

			cout << "\n________________" << endl;
			cout << "Compute Interest" << endl;
			cout << "----------------" << endl;

			do
			{
				cout << "Number of years to compute interest for: ";
				cin >> years;

				if (years < 1 || years > 40)
				{
					cout << "\nNumber of years should be between 1 and 40" << endl;
				}
			} while (years < 1 || years > 40);

			for (int i = 0; i < count; i++)
			{
				cout << "____________________________________________" << endl;
				cout << "Account Number: " << Accounts[i].getAccountNumber() << endl;
				Accounts[i].computeInterest(years);
			}

			break;
		}
		case 4:
		{
			cout << "\n_____________" << endl;
			cout << "Fund Transfer" << endl;
			cout << "-------------" << endl;

			int fromAccount, toAccount;
			double transferAmount;
			int fromAccountIndex = -1;
			int toAccountIndex = -1;
			bool isFound = false;
			
			do
			{
				do
				{
					cout << "Enter Account Number to Transfer Fund From: ";
					cin >> fromAccount;
					if (fromAccount < 1000 || fromAccount > 9999)
					{
						cout << "\nInvalid Account Number!!\n" << endl;
					}
				} while (fromAccount < 1000 || fromAccount > 9999);
				
				fromAccountIndex = getAccountIndex(Accounts, fromAccount, count);

				if (fromAccountIndex >= 0 && fromAccountIndex < count)
				{
					isFound = true;
				}
			} while (!isFound);

			isFound = false;
			do
			{
				do
				{
					cout << "Enter Account Number to Transfer Fund To: ";
					cin >> toAccount;
					if (toAccount <= 1000 || toAccount >= 9999)
					{
						cout << "\nInvalid Account Number!!\n" << endl;
					}

					if (fromAccount == toAccount)
					{
						cout << "\nFrom Account Number and To Account Number cannot be same\n" << endl;
					}
				} while ((toAccount <= 1000 || toAccount >= 9999) || (fromAccount == toAccount));

				toAccountIndex = getAccountIndex(Accounts, toAccount, count);

				if (toAccountIndex >= 0 && toAccountIndex < count)
				{
					isFound = true;
				}

			} while (!isFound);

			cout << "Enter Transfer Amount: ";
			cin >> transferAmount;

			Transaction transfer;

			transfer.performTransaction(Accounts[fromAccountIndex], Accounts[toAccountIndex], transferAmount);

			break;
		}
		case 0:
		{
			cout << "\nThank you for using InterBanking Pty.\n" << endl;
			break;
		}
		}

		if (choice == 0)
			break;

	} while (choice != 0);


	system("pause");
}