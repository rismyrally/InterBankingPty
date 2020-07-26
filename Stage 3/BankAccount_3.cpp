#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

void adminLogin();
void memberLogin();


struct BankAccount
{
	string customerName;
	string accountPassword;
	int accountNumber[2];
	double accountBalance[2];
	double annualInterestRate[2];
	double automaticWithdrawal[2];
	double automaticDeposit[2];
}Accounts;


int main()
{
	const int NUM_OF_ACCOUNTS = 2;

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
			cout << "4 - Compute Interest" << endl;
			cout << "0 - Exit" << endl;
			cout << "\nEnter your Choice: ";
			cin >> choice;

			if (choice != 0 && choice != 1 && choice != 2 && choice != 3 && choice != 4)
			{
				cout << "\nInvalid Entry!!\nPlease Try Again\n" << endl;
			}
		}
		while (choice != 0 && choice != 1 && choice != 2 && choice != 3 && choice != 4);

		switch (choice)
		{
			case 1:
				{					
					adminLogin();

					cout << "\n\n_____________________" << endl;
					cout << "Bank Account Creation" << endl;
					cout << "---------------------\n" << endl;
					cout << "Enter details of Bank Account\n" << endl;
					cout << "Enter Customer Name: ";
					getline(cin, Accounts.customerName);
					cout << "Enter Account Password: ";
					getline(cin, Accounts.accountPassword);
					
					for (int i = 0; i < NUM_OF_ACCOUNTS; i++)
					{
						do
						{
							cout << "Enter Account Number for Account No." << i+1 << ": ";
							cin >> Accounts.accountNumber[i];
							cin.ignore();

							if (Accounts.accountNumber[i] < 1000 || Accounts.accountNumber[i] > 9999)
							{
								cout << "\nAccount Number should be between 1000 and 9999" << endl;
							}
						} while (Accounts.accountNumber[i] < 1000 || Accounts.accountNumber[i] > 9999);

						do
						{
							cout << "Enter Account Balance for Account No." << i + 1 << ": ";
							cin >> Accounts.accountBalance[i];
							cin.ignore();

							if (Accounts.accountBalance[i] < 0.00)
							{
								cout << "\nAccount balance cannot be negative" << endl;
							}

							if (Accounts.accountBalance[i] > 100000.00)
							{
								cout << "\nAccount balance cannot be over $100,000.00" << endl;
							}
						} while (Accounts.accountBalance[i] < 0.00 || Accounts.accountBalance[i] > 100000.00);

						do
						{
							cout << "Enter Interest Rate for Account No." << i + 1 << ": ";
							cin >> Accounts.annualInterestRate[i];
							cin.ignore();

							if (Accounts.annualInterestRate[i] < 0.01 || Accounts.annualInterestRate[i] > 15.0)
							{
								cout << "\nInterest rate should be between 0.01% and 15.0%" << endl;
							}
						} while (Accounts.annualInterestRate[i] < 0.01 || Accounts.annualInterestRate[i] > 15.0);

						cout << "Enter Automatic Withdrawal Amount per Month for Account No." << i + 1 << ": ";
						cin >> Accounts.automaticWithdrawal[i];
						cin.ignore();
						cout << "Enter Automatic Deposit Amount per Month for Account No." << i + 1 << ": ";
						cin >> Accounts.automaticDeposit[i];
						cin.ignore();
						cout << endl;
					}
					
					cout << "\nYour entered details\n" << endl;
					cout << "Customer Name: " << Accounts.customerName << endl;
					cout << "Account Password: " << Accounts.accountPassword << endl << endl;

					for (int i = 0; i < NUM_OF_ACCOUNTS; i++)
					{
						cout << "Account Number for Account No." << i + 1 << ": " << Accounts.accountNumber[i] << endl;
						cout << "Account Balance for Account No." << i + 1 << ": " << Accounts.accountBalance[i] << endl;
						cout << "Account Annual Interest Rate for Account No." << i + 1 << ": " << Accounts.annualInterestRate[i] << endl;
						cout << "Automatic Withdrawal Amount per Month for Account No." << i + 1 << ": " << Accounts.automaticWithdrawal[i] << endl;
						cout << "Automatic Deposit Amount per Month for Account No." << i + 1 << ": " << Accounts.automaticDeposit[i] << endl << endl;
					}
					break;
				}

			case 2:
				{
					memberLogin();

					cout << "\n\n____________________" << endl;
					cout << "Your Account Details" << endl;
					cout << "--------------------" << endl << endl;
					cout << "Customer Name: " << Accounts.customerName << endl;

					for (int i = 0; i < NUM_OF_ACCOUNTS; i++)
					{
						cout << "Account Number for Account No." << i + 1 << ": " << Accounts.accountNumber[i] << endl;
						cout << "Account Balance for Account No." << i + 1 << ": " << Accounts.accountBalance[i] << endl;
						cout << "Account Annual Interest Rate for Account No." << i + 1 << ": " << Accounts.annualInterestRate[i] << endl;
						cout << endl;
					}
					
					break;
				}

			case 3:
				{
					memberLogin();

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
						cout << "1st Account Number: " << Accounts.accountNumber[0] << endl;
						cout << "1st Account Balance: " << Accounts.accountBalance[0] << endl;
						cout << "2nd Account Number: " << Accounts.accountNumber[1] << endl;
						cout << "2nd Account Balance: " << Accounts.accountBalance[1] << endl << endl;

						do
						{
							cout << "Enter Account Number to Transfer Fund From: ";
							cin >> fromAccount;
							if (fromAccount < 1000 || fromAccount > 9999)
							{
								cout << "\nInvalid Account Number!!\n" << endl;
							}

							if (fromAccount != Accounts.accountNumber[0] && fromAccount != Accounts.accountNumber[1])
							{
								cout << "\nAccount Number not in the system\n" << endl;
							}
						}
						while ((fromAccount < 1000 || fromAccount > 9999) || (fromAccount != Accounts.accountNumber[0] && fromAccount != Accounts.accountNumber[1]));

						do
						{
							cout << "Enter Account Number to Transfer Fund To: ";
							cin >> toAccount;
							if (toAccount <= 1000 || toAccount >= 9999)
							{
								cout << "\nInvalid Account Number!!\n" << endl;
							}
							if (toAccount != Accounts.accountNumber[0] && toAccount != Accounts.accountNumber[1])
							{
								cout << "\nAccount Number not in the system\n" << endl;
							}

							if (fromAccount == toAccount)
							{
								cout << "\nFrom Account Number and To Account Number cannot be same\n" << endl;
							}
						}
						while ((toAccount <= 1000 || toAccount >= 9999) || (toAccount != Accounts.accountNumber[0] && toAccount != Accounts.accountNumber[1]) || (fromAccount == toAccount));

						cout << "Enter Transfer Amount: ";
						cin >> transferAmount;

						if ((fromAccount == Accounts.accountNumber[0]) && (toAccount == Accounts.accountNumber[1]))
						{
							if ((Accounts.accountBalance[0] - transferAmount) < 0.00)
							{
								do
								{
									cout << "\nInsufficient Balance to perfom transfer\n" << endl;
									cout << "Account Number: " << Accounts.accountNumber[0] << endl;
									cout << "Account Balance: " << Accounts.accountBalance[0] << endl;
									cout << "\nEnter Transfer Amount: ";
									cin >> transferAmount;
								}
								while ((Accounts.accountBalance[0] - transferAmount) < 0.00);
							}

							if ((Accounts.accountBalance[0] - transferAmount) <= 10.00)
							{
								cout << "\nTransfer will cause the balance in the first account to drop below $10.00\n" << endl;
							}

							if ((Accounts.accountBalance[1] + transferAmount) > 100000.00)
							{
								cout << "\nTransfer will cause the balance in the second account to be greater than\n"
									"$100,000.00, which is the highest amount that is federally insured.\n" << endl;
							}

							Accounts.accountBalance[0] = Accounts.accountBalance[0] - transferAmount;
							Accounts.accountBalance[1] = Accounts.accountBalance[1] + transferAmount;
							
							cout << "\nTransfer Completed\n" << endl;
							cout << "1st Account Number: " << Accounts.accountNumber[0] << endl;
							cout << "1st Account Balance: " << Accounts.accountBalance[0] << endl;
							cout << "2nd Account Number: " << Accounts.accountNumber[1] << endl;
							cout << "2nd Account Balance: " << Accounts.accountBalance[1] << endl << endl;
						}

						if ((fromAccount == Accounts.accountNumber[1]) && (toAccount == Accounts.accountNumber[0]))
						{
							if ((Accounts.accountBalance[1] - transferAmount) < 0.00)
							{
								do
								{
									cout << "\nInsufficient Balance to perfom transfer\n" << endl;
									cout << "Account Number: " << Accounts.accountNumber[1] << endl;
									cout << "Account Balance: " << Accounts.accountBalance[1] << endl;
									cout << "\nEnter Transfer Amount: ";
									cin >> transferAmount;
								} while ((Accounts.accountBalance[1] - transferAmount) < 0.00);
							}

							if ((Accounts.accountBalance[1] - transferAmount) <= 10.00)
							{
								cout << "\nTransfer will cause the balance in the first account to drop below $10.00\n" << endl;
							}

							if ((Accounts.accountBalance[0] + transferAmount) > 100000.00)
							{
								cout << "\nTransfer will cause the balance in the second account to be greater than\n"
									"$100,000.00, which is the highest amount that is federally insured.\n" << endl;
							}

							Accounts.accountBalance[1] -= transferAmount;
							Accounts.accountBalance[0] += transferAmount;

							cout << "\nTransfer Completed\n" << endl;
							cout << "1st Account Number: " << Accounts.accountNumber[0] << endl;
							cout << "1st Account Balance: " << Accounts.accountBalance[0] << endl;
							cout << "2nd Account Number: " << Accounts.accountNumber[1] << endl;
							cout << "2nd Account Balance: " << Accounts.accountBalance[1] << endl << endl;
						}
					}
					break;
				}

			case 4:
			{
				memberLogin();

				double interestAmount, startingBalance, endingBalance;

				cout << "\n\n________________" << endl;
				cout << "Compute Interest" << endl;
				cout << "----------------" << endl << endl;
				cout << "Customer Name: " << Accounts.customerName << endl;

				cout << "\nBalance forecast for the next 12 Months\n" << endl;

				for (int i = 0; i < NUM_OF_ACCOUNTS; i++)
				{
					interestAmount = ((Accounts.annualInterestRate[i]) / 12) / 100;
					startingBalance = Accounts.accountBalance[i];
										
					cout << "Balance Forecast for Account Number: " << Accounts.accountNumber[i] << endl;
					cout << "____________________________________________________________________" << endl;
					cout << "Year\tMonth Number\tMonth Starting Balance\tMonth Ending Balance" << endl;
					cout << "--------------------------------------------------------------------" << endl;

					for (int j = 0; j < 1; j++)
					{
						for (int k = 0; k < 12; k++)
						{
							endingBalance = startingBalance + (startingBalance * interestAmount);
							endingBalance += Accounts.automaticDeposit[i];
							endingBalance -= Accounts.automaticWithdrawal[i];

							cout << j + 1 << "\t" << k + 1 << "\t\t" << startingBalance << "\t\t\t" << endingBalance << endl;

							startingBalance = endingBalance;
						}
					}
					cout << endl;
				}

				break;
			}

			case 0:
				{
					cout << "\nThank you for using InterBanking Pty.\n" << endl;
					exit(0);
					break;
				}
		}
	}
	
	
	system ("pause");
	return 0;
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
	}
	while (!login);
}


void memberLogin()
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
}
