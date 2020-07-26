#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

struct BankAccount
{
	int accountNumber;
	double accountBalance;
	double annualInterestRate;
};

void menu(int&);
void adminLogin();
BankAccount enterAccountData(bool&);
void dataPersistency(BankAccount);
void displayAccount(int);
void computeInterest(int);


void main()
{
	cout << "Welcome to InterBanking Pty" << endl;

	int choice;

	do
	{
		menu(choice);

		switch (choice)
		{
		case 1:
		{
			adminLogin();

			BankAccount Account;
			bool repeat = false;

			cout << "\n_____________________" << endl;
			cout << "Bank Account Creation" << endl;
			cout << "---------------------" << endl;

			do
			{
				cout << "\nEnter account details, enter 0 to stop." << endl;
				Account = enterAccountData(repeat);
				if (Account.accountNumber != 0)
					dataPersistency(Account);
			} while (!repeat);

			break;
		}
		case 2:
		{
			int acnum;

			cout << "\n____________________" << endl;
			cout << "Your Account Details" << endl;
			cout << "--------------------" << endl;

			cout << "\nEnter Account Number: ";
			cin >> acnum;
			displayAccount(acnum);

			break;
		}
		case 3:
		{
			int acnum;

			cout << "\n________________" << endl;
			cout << "Compute Interest" << endl;
			cout << "----------------" << endl;

			cout << "\nEnter Account Number: ";
			cin >> acnum;
			computeInterest(acnum);

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


void dataPersistency(BankAccount Account)
{
	int acnumber = Account.accountNumber;
	string fileName = static_cast<ostringstream*>(&(ostringstream() << acnumber))->str();

	ofstream readFile;
	readFile.open(fileName + " Account Details.txt");
	readFile << "Account Number: " << Account.accountNumber << endl;
	readFile << "Account Balance: $ " << Account.accountBalance << endl;
	readFile << "Annual Interest Rate: " << Account.annualInterestRate << endl;
	readFile.close();
}


BankAccount enterAccountData(bool &repeat)
{
	BankAccount Account;

	do
	{
		cout << "\nEnter Account Number: ";
		cin >> Account.accountNumber;
		cin.ignore();

		if (Account.accountNumber == 0)
		{
			repeat = true;
			return BankAccount();
		}

		if (Account.accountNumber < 1000 || Account.accountNumber > 9999)
		{
			cout << "\nAccount Number should be between 1000 and 9999" << endl;
		}
	} while (Account.accountNumber < 1000 || Account.accountNumber > 9999);

	do
	{
		cout << "Enter Account Balance: $ ";
		cin >> Account.accountBalance;
		cin.ignore();

		if (Account.accountBalance < 0.00)
		{
			cout << "\nAccount balance cannot be negative" << endl;
		}

		if (Account.accountBalance > 100000.00)
		{
			cout << "\nAccount balance cannot be over $100,000.00" << endl;
		}
	} while (Account.accountBalance < 0.00 || Account.accountBalance > 100000.00);

	do
	{
		cout << "Enter Annual Interest Rate: ";
		cin >> Account.annualInterestRate;
		cin.ignore();

		if (Account.annualInterestRate < 0.01 || Account.annualInterestRate > 15.0)
		{
			cout << "\nInterest rate should be between 0.01% and 15.0%" << endl;
		}
	} while (Account.annualInterestRate < 0.01 || Account.annualInterestRate > 15.0);
	
	return Account;
}


void displayAccount(int acnum)
{
	int acnumber = acnum;
	string fileName = static_cast<ostringstream*>(&(ostringstream() << acnumber))->str();

	string getLine;
	ifstream writeFile(fileName + " Account Details.txt");
	if (writeFile.is_open())
	{
		while (getline(writeFile, getLine))
		{
			cout << getLine << endl;
		}
		writeFile.close();
	}
	else
	{
		cout << "Invalid Account Number" << endl;
	}
}


void computeInterest(int acnum)
{
	int acnumber = acnum;
	string fileName = static_cast<ostringstream*>(&(ostringstream() << acnumber))->str();

	string line, ignore;
	double balance, interest;

	ifstream file(fileName + " Account Details.txt");
	if (file.is_open())
	{
		getline(file, line);
		file >> ignore >> ignore >> ignore >> balance;
		getline(file, line);
		file >> ignore >> ignore >> ignore >> interest;

		double interestAmount, startingBalance, endingBalance;
		int years;

		cout << "Number of years to compute interest for: ";
		cin >> years;

		startingBalance = balance;
		interestAmount = interest / 100;

		cout << "\nStartig Balance: " << startingBalance << "\tAnnual Interest Rate: " << interestAmount << endl;

		cout << "____________________________________________" << endl;

		for (int j = 0; j < years; j++)
		{
			endingBalance = startingBalance + (startingBalance * interestAmount);

			cout << " Ending Balance of Year " << j + 1 << ": $ " << endingBalance << endl;

			startingBalance = endingBalance;
		}
	}
	else
	{
		cout << "Invalid Account Number" << endl;
	}
}
