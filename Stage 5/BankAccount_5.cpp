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
		cout << "0 - Exit" << endl;
		cout << "Enter your Choice: ";
		cin >> choice;

		if (choice != 0 && choice != 1 && choice != 2 && choice != 3)
		{
			cout << "\nInvalid Entry!!\nPlease Try Again\n" << endl;
		}
	} while (choice != 0 && choice != 1 && choice != 2 && choice != 3);
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