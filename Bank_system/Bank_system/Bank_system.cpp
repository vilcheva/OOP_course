#include <iostream>
#include <cstring>
#include "Bank.h"
 
using namespace std;
void Menu()
{
	cout << "1.Edit" << endl;
	cout << " a.Customer" << endl;
	cout << "  i.Add new customer" << endl;
	cout << "  ii.Delete customer" << endl;
	cout << " b.Account" << endl;
	cout << "  i.Add new account" << endl;
	cout << "  ii.Delete account" << endl;
	cout << "2.List" << endl;
	cout << " a.List all customers" << endl;
	cout << " b.List all account" << endl;
	cout << " c.List customer account" << endl;
	cout << " d.List log" << endl;
	cout << "3.Action" << endl;
	cout << " a.Withdraw from account" << endl;
	cout << " b.Deposit to account" << endl;
	cout << " c.Transfer" << endl;
	cout << "4.Display info for the bank" << endl;
	cout << "5.Quit" << endl;


}

int main()
{
	Bank bank("DSK","Bulgaria street 8");
	int command;
	char command2;
	MyString log;
	MyString errorMessege = "Wrong command";
	char* fileName=new char[30];
	cout << "Insert file name: " << endl << ">";
	cin >> fileName;

	Menu();
	do {
		cout << ">Insert command number: ";
		cin >> command;
		
		if (command==1)
		{
			MyString command3;
			int index;
			cout << ">Insert second command(a/b): ";
				cin >> command2;
				if (command2 == 'a')
				{
					MyString name;
					MyString id;
					MyString address;
					cout << ">Choose option (i/ii): ";
					cin >> command3;
					if (command3 == "i")
					{
						cout << "id: ";
						cin >> id;
						cout << "name: ";
						cin >> name;
						cout << "address: ";
						cin >> address;
						bank.addCustomer(id, name, address);
						log = "Added new customer  name: ";
						log += name;
						log += ", id: ";
						log += id;
						log += " address: ";
						log += address;
						bank.addLog(log);
					}
					else if (command3 == "ii")
					{
						cout << "Insert index: ";
						cin >> index;
						bank.deleteCustomer(index);
						log = "Delete customer on index- ";
						log += MyString(index);
						bank.addLog(log);
					}
					else
						cout << "Wrong command!";
						
				}
				else if (command2 == 'b')
				{
					MyString username;
					MyString password;
					MyString iban;
					MyString id; 
					size_t amount; 
					Account::date dayOfCreation;
					MyString accountType;
					int interestRate;
					int overdraft;
					cout << ">Choose option (i/ii): ";
					cin >> command3;
					if (command3 == "i")
					{
						cout << "Account type (normal/savings/privilege): ";
						cin >> accountType;
						cout << "username: ";
						cin >> username;
						cout << "password: ";
						cin >> password;
						cout << "iban: ";
						cin >> iban;
						cout << "id: ";
						cin >> id;
						cout << "amount: ";
						cin >> amount;
						cout << "date of creation( day month year): ";
						cin >> dayOfCreation.day;
						cin >> dayOfCreation.month;
						cin >> dayOfCreation.year;
						if (accountType == "normal")
						{
							bank.addNormalAccount(username, password, iban,
								id, amount, dayOfCreation);
							/*log = "Created new normal account with username ";
							log += username;
							log += " iban- ";
							log += iban;
							log += " and id- ";
							log += id;
							bank.addLog(log);*/

						}
						else if (accountType == "savings")
						{
							cout << "interest rate: ";
							cin >> interestRate;
							bank.addSavingsAccount(username, password, iban,
								id, amount, dayOfCreation, interestRate);
							log = "Created new savings account with username ";
							log += username;
							log += " iban- ";
							log += iban;
							log += " and id- ";
							log += id;
							bank.addLog(log);
						}
						else if (accountType == "privilege")
						{
							cout << "overdraft: ";
							cin >> overdraft;
							bank.addPrivilegeAccount(username, password, iban,
								id, amount, dayOfCreation, overdraft);
							/*log = "Created new privilege account with username ";
							log += username;
							log += " iban- ";
							log += iban;
							log += " and id- ";
							log += id;
							bank.addLog(log);*/
						}
						else {
							cout << errorMessege;
								continue;
						}
					}
					else if (command3 == "ii")
					{
						cout << "Insert index: ";
						cin >> index;
						bank.deleteAccount(index);
						/*log = "Delete account on index- ";
						log += MyString(index);
						bank.addLog(log);*/
					}
					else
					{
						cout << errorMessege;
					}
				}
				else {
					cout << errorMessege;
				}

			
		}
		else if (command == 2)
		{
			cout << ">Insert second command(a/b/c/d): ";
			cin >> command2;
			if (command2 == 'a')
				bank.listCustomers();
			else if (command2 == 'b')
				bank.listAccounts();
			else if (command == 'c')
			{
				MyString id;
				cout << "insert customer id: ";
				cin >> id;
				bank.listCustomerAccount(id);
			}
			else if (command2 == 'd')
			{
				bank.listLog();
			}
			else
			{
				cout << errorMessege;
			}
		}
		else if (command == 3)
		{   int index;
			size_t amount;
			cout << ">Insert second command(a/b/c): ";
			cin >> command2;
			if (command2 == 'a')
			{
				cout << "Insert amount to withdraw: ";
				cin >> amount;
				cout << "Insert account index: ";
				cin >> index;
				bank.getAccount(index)->withdraw(amount);
				
					/*log = "Withdrawn amount- ";
					log += MyString(amount);
					log += " from account with index- ";
					log += MyString(index);
					bank.addLog(log);*/
				
			}
			else if (command2 == 'b')
			{
				cout << "Insert amount to deposit: ";
				cin >> amount;
				cout << "Insert account index: ";
				cin >> index;
				bank.getAccount(index)->deposit(amount);
				/*log = "Deposited amount- ";
				log += MyString(amount);
				log += " from account with index- ";
				log += MyString(index);
				bank.addLog(log);*/
			}
			else if (command2 == 'c')
			{
				MyString fromIBAN;
				MyString toIBAN;
				cout << "Insert fromIBAN: ";
				cin >> fromIBAN;
				cout << "Insert toIBAN: ";
				cin >> toIBAN;
				cout << "Insert amount to transfer: ";
				cin >> amount;
				bank.transfer(amount, fromIBAN, toIBAN);
				/*log = "Transfered amount- ";
				log += MyString(amount);
				log += " from account with IBAN- ";
				log += fromIBAN;
				log += " to account with IBAN- ";
				log += toIBAN;
				bank.addLog(log);*/

			}
		}
		else if (command == 4)
		{
			bank.display();
		}
		else if(command!=5)
		{
			cout << errorMessege;
			continue;
		}
		log = "";

 }
		 while (command!=5);

		 bank.exportLog(fileName);
}



