#include <iostream>
#include <string>

using namespace std;


struct BankAccount
{
	int accountNumber;
	double accountBalance;
	string customerName;
	string accountPassword;
};


int main()
{
	string username, password, loginAccNum, loginCustName;

	cout << "\tAdministrator Login" << endl << endl;
	cout << "Username: ";
	cin >> username;
	cout << "Password: ";		
	cin >> password;
	
	BankAccount Customer1;
	
	cout << "\n\n\tEnter Bank Account Details" << endl << endl;
	cout << "Enter Account Number: ";
	cin >> Customer1.accountNumber;
	cin.ignore();
	cout << "Enter Customer Name: ";
	getline(cin, Customer1.customerName);
	cout << "Enter Account Balance: ";
	cin >> Customer1.accountBalance;
	cin.ignore();
	cout << "Enter Account Password: ";
	getline(cin, Customer1.accountPassword);

	cout << "\n\n\tDisplaying Bank Account Details" << endl << endl;
	cout << "Account Number: "<< Customer1.accountNumber << endl;
	cout << "Customer Name: "<< Customer1.customerName << endl;
	cout << "Account Balance: "<< Customer1.accountBalance << endl;
	cout << "Account Password: "<< Customer1.accountPassword << endl << endl;

	cout << "\n\n\tMember Login" << endl << endl;
	cout << "Account Number: ";
	cin >> loginAccNum;
	cin.ignore();
	cout << "Customer Name: ";
	getline(cin, loginCustName);
		
	cout << "\n\n\tYour Account Details" << endl << endl;
	cout << "Account Number: "<< Customer1.accountNumber << endl;
	cout << "Customer Name: "<< Customer1.customerName << endl;
	cout << "Account Balance: "<< Customer1.accountBalance << endl;
		
	system ("pause");
	return 0;
}