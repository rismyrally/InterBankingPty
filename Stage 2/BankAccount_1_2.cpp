#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;


struct BankAccount
{
	int accountNumber[2];
	double accountBalance[2];
	string customerName;
	string accountPassword;
}Accounts;


int main()
{
	cout << "Welcome to InterBanking Pty\n" << endl;

	int choice;
	
	while (true)
	{
		do
		{
			cout << "\nMain Menu:" << endl;
			cout << "1 - Create a Bank Account" << endl;
			cout << "2 - View a Bank Account Details" << endl;
			cout << "3 - Perform Fund Transfer" << endl;
			cout << "0 - Exit" << endl;
			cout << "\nEnter your Choice: ";
			cin >> choice;

			if (choice != 0 && choice != 1 && choice != 2 && choice != 3)
			{
				cout << "\nInvalid Entry!!\nPlease Try Again\n" << endl;
			}
		}
		while (choice != 0 && choice != 1 && choice != 2 && choice != 3);

	
		if (choice == 1)
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
			}
			while (!login);

			cout << "\n\n_____________________" << endl;
			cout << "Bank Account Creation" << endl;
			cout << "---------------------\n" << endl;
			cout << "Enter details of Bank Account\n" << endl;
			cout << "Enter Customer Name: ";
			getline(cin, Accounts.customerName);
			cout << "Enter Account Password: ";
			getline(cin, Accounts.accountPassword);
			cout << "Enter Account Number: ";
			cin >> Accounts.accountNumber[0];
			cin.ignore();
			if (Accounts.accountNumber[0] < 1000 || Accounts.accountNumber[0] > 9999)
			{
				cout << "\nAccount Number should be between 1000 and 9999" << endl;
				break;
			}

			cout << "Enter Account Balance: ";
			cin >> Accounts.accountBalance[0];
			cin.ignore();

			if (Accounts.accountBalance[0] < 0)
			{
				cout << "\nAccount balance cannot be negative" << endl;
				break;
			}

			char input;
			bool inputRepeat = false;
			
			do
			{
				cout << "\nDo you wish to create a second account ('Y' or 'N'): ";
				cin >> input;
				if (input == 'Y' || input == 'y' || input == 'N' || input == 'n')
				{
					inputRepeat = true;
				}
				else
				{
					cout << "\nInvalid Entry!!\nPlease Try Again\n" << endl;
				}
			}
			while (!inputRepeat);
		
			if (input == 'Y' || input == 'y')
			{
				cout << "\nEnter Account Number for 2nd Account: ";
				cin >> Accounts.accountNumber[1];
				cin.ignore();
				if (Accounts.accountNumber[1] < 1000 || Accounts.accountNumber[1] > 9999)
				{
					cout << "\nAccount Number should be between 1000 and 9999" << endl;
					break;
				}
				if (Accounts.accountNumber[1] == Accounts.accountNumber[0])
				{
					cout << "\nCannot have two accounts with the same number" << endl;
					break;
				}
				
				cout << "Enter Account Balance for 2nd Account: ";
				cin >> Accounts.accountBalance[1];
				cin.ignore();

				if (Accounts.accountBalance[1] < 0)
				{
					cout << "\nAccount balance cannot be negative" << endl;
					break;
				}

				cout << "\nYour entered details\n" << endl;
				cout << "Customer Name: " << Accounts.customerName << endl;
				cout << "Account Password: " << Accounts.accountPassword << endl;
				cout << "1st Account Number: " << Accounts.accountNumber[0] << endl;
				cout << "1st Account Balance: " << Accounts.accountBalance[0] << endl;
				cout << "2nd Account Number: " << Accounts.accountNumber[1] << endl;
				cout << "2nd Account Balance: " << Accounts.accountBalance[1] << endl << endl;

			}
			else
			{
				cout << "\nYour entered details\n" << endl;
				cout << "Customer Name: " << Accounts.customerName << endl;
				cout << "Account Password: " << Accounts.accountPassword << endl;
				cout << "Account Number: " << Accounts.accountNumber[0] << endl;
				cout << "Account Balance: " << Accounts.accountBalance[0] << endl << endl;
			}
		}

		if (choice == 2)
		{
			int acNum;
			string cName;
			bool memberLogin = false;

			do
			{
				cout << "\n\nMember Login\n" << endl;
				cout << "Account Number: ";
				cin >> acNum;
				cin.ignore();
				cout << "Customer Name: ";
				getline(cin, cName);

				for (int i = 0; i < 2; i++)
				{
					if (acNum == Accounts.accountNumber[i] && cName == Accounts.customerName)
					{
						cout << "\nLogin Successfull" << endl;
						memberLogin = true;
						break;
					}
				}

				if (!memberLogin)
				{
					cout << "\nLogin Unsuccessfull\nPlease try again\n" << endl;
				}
			}
			while (!memberLogin);

			if (Accounts.accountNumber[1] != NULL)
			{
				cout << "\n\n____________________" << endl;
				cout << "Your Account Details" << endl;
				cout << "--------------------" << endl << endl;
				cout << "Customer Name: "<< Accounts.customerName << endl;
				cout << "1st Account Number: "<< Accounts.accountNumber[0] << endl;
				cout << "1st Account Balance: "<< Accounts.accountBalance[0] << endl;
				cout << "2nd Account Number: "<< Accounts.accountNumber[1] << endl;
				cout << "2nd Account Balance: "<< Accounts.accountBalance[1] << endl;
				cout << endl;
			}
			else
			{
				cout << "\n\n____________________" << endl;
				cout << "Your Account Details" << endl;
				cout << "--------------------" << endl << endl;
				cout << "Customer Name: "<< Accounts.customerName << endl;
				cout << "Account Number: "<< Accounts.accountNumber[0] << endl;
				cout << "Account Balance: "<< Accounts.accountBalance[0] << endl;
				cout << endl;
			}
		}

		if (choice == 3)
		{
			int acNum;
			string cName;
			bool memberLogin = false;

			do
			{
				cout << "\n\nMember Login\n" << endl;
				cout << "Account Number: ";
				cin >> acNum;
				cin.ignore();
				cout << "Customer Name: ";
				getline(cin, cName);

				for (int i = 0; i < 2; i++)
				{
					if (acNum == Accounts.accountNumber[i] && cName == Accounts.customerName)
					{
						cout << "\nLogin Successfull" << endl;
						memberLogin = true;
						break;
					}
				}

				if (!memberLogin)
				{
					cout << "\nLogin Unsuccessfull\nPlease try again\n" << endl;
				}
			}
			while (!memberLogin);

			cout << "\n\n_____________" << endl;
			cout << "Fund Transfer" << endl;
			cout << "-------------\n" << endl;

			int fromAccount, toAccount;
			double transferAmount;

			if (Accounts.accountNumber[1] == NULL)
			{
				cout << "\nNeed to have two accounts to perform fund transfer" << endl;
				break;
			}
			else
			{
				cout << "1st Account Number: "<< Accounts.accountNumber[0] << endl;
				cout << "1st Account Balance: "<< Accounts.accountBalance[0] << endl;
				cout << "2nd Account Number: "<< Accounts.accountNumber[1] << endl;
				cout << "2nd Account Balance: "<< Accounts.accountBalance[1] << endl << endl;

				cout << "Enter Account Number to Transfer Fund From: ";
				cin >> fromAccount;
				if (fromAccount < 1000 || fromAccount > 9999)
				{
					cout << "\nInvalid Account Number!!\n" << endl;
					break;
				}
				if (fromAccount != Accounts.accountNumber[0] && fromAccount != Accounts.accountNumber[1])
				{
					cout << "\nAccount Number not in the system\n" << endl;
					break;
				}

				cout << "Enter Account Number to Transfer Fund To: ";
				cin >> toAccount;
				if (toAccount <=1000 || toAccount >= 9999)
				{
					cout << "\nInvalid Account Number!!\n" << endl;
					break;
				}
				if (toAccount != Accounts.accountNumber[0] && toAccount != Accounts.accountNumber[1])
				{
					cout << "\nAccount Number not in the system\n" << endl;
					break;
				}
				
				if (fromAccount == toAccount)
				{
					cout << "\nFrom Account Number and To Account Number cannot be same\n" << endl;
					break;
				}

				cout << "Enter Transfer Amount: ";
				cin >>transferAmount;

				if ((fromAccount == Accounts.accountNumber[0]) && (toAccount == Accounts.accountNumber[1]))
				{
					if ((Accounts.accountBalance[0] - transferAmount) < 0.00)
					{
						cout << "\nInsufficient Balance to perfom transfer\n" << endl;
						break;
					}

					if ((Accounts.accountBalance[0] - transferAmount) <= 10.00)
					{
						cout << "\nTransfer will cause the balance in the first account to drop below $10.00\n" << endl;
					}

					if ((Accounts.accountBalance[1] + transferAmount) > 100000.00)
					{
						cout << "\nTransfer will cause the balance in the second account to be greater than\n"
							"$100,000.00, which is the highest amount that is federally insured.\n"<< endl;
					}

					Accounts.accountBalance[0] = Accounts.accountBalance[0] - transferAmount;
					Accounts.accountBalance[1] = Accounts.accountBalance[1] + transferAmount;
					
					cout << "\nTransfer Completed\n" << endl;
					cout << "1st Account Number: "<< Accounts.accountNumber[0] << endl;
					cout << "1st Account Balance: "<< Accounts.accountBalance[0] << endl;
					cout << "2nd Account Number: "<< Accounts.accountNumber[1] << endl;
					cout << "2nd Account Balance: "<< Accounts.accountBalance[1] << endl << endl;
				}

				if ((fromAccount == Accounts.accountNumber[1]) && (toAccount == Accounts.accountNumber[0]))
				{
					if ((Accounts.accountBalance[1] - transferAmount) < 0.00)
					{
						cout << "\nInsufficient Balance to perfom transfer\n" << endl;
						break;
					}

					if ((Accounts.accountBalance[1] - transferAmount) <= 10.00)
					{
						cout << "\nTransfer will cause the balance in the first account to drop below $10.00\n" << endl;
					}

					if ((Accounts.accountBalance[0] + transferAmount) > 100000.00)
					{
						cout << "\nTransfer will cause the balance in the second account to be greater than\n"
							"$100,000.00, which is the highest amount that is federally insured.\n"<< endl;
					}

					Accounts.accountBalance[1] -= transferAmount;
					Accounts.accountBalance[0] += transferAmount;

					cout << "\nTransfer Completed\n" << endl;
					cout << "1st Account Number: "<< Accounts.accountNumber[0] << endl;
					cout << "1st Account Balance: "<< Accounts.accountBalance[0] << endl;
					cout << "2nd Account Number: "<< Accounts.accountNumber[1] << endl;
					cout << "2nd Account Balance: "<< Accounts.accountBalance[1] << endl << endl;
				}
			}
		}

		if (choice == 0)
		{
			cout << "\nThank you for using InterBanking Pty.\n" << endl;
			exit(0);
		}
	}
	
	
	system ("pause");
	return 0;
}
