#include "Bank.h"
#include "NormalAccount.h"
#include "PrivilegeAccount.h"
#include "SavingsAccount.h"
#include <iostream>
#include <fstream>
using namespace std;
Bank::Bank()
{
	customers = new Customer*[CAPACITY];
	customersCount = 0;
	customersCapacity = CAPACITY;
	accounts = new Account*[CAPACITY];
	accountsCount = 0;
	accountsCapacity = CAPACITY;
	log = new MyString[CAPACITY];
	logsCount = 0;
	logsCapacity = CAPACITY;

}
void Bank::copyFrom(const Bank& other)
{
	name = other.name;
	address = other.address;
	customers = new Customer*[other.customersCapacity];
	for (int i = 0; i < customersCount; i++)
	{
		customers[i] = other.customers[i]->clone();
	}
	customersCount = other.customersCount;
	customersCapacity = other.customersCapacity;
	accounts = new Account * [other.accountsCapacity];
	for (int i = 0; i < accountsCount; i++)
	{
		accounts[i] = other.accounts[i]->clone();
	}
	accountsCount = other.accountsCount;
	accountsCapacity = other.accountsCapacity;
	log = new MyString[other.logsCapacity];
	for (int i = 0; i < other.logsCount; i++)
	{
		log[i] = other.log[i];
	}
	logsCapacity = other.logsCapacity;
	logsCount = other.logsCount;
}
void Bank::free()
{
	for (int i = 0; i < customersCount; i++)
	{
		delete customers[i];
	}
	delete[] customers;

	for (int i = 0; i < accountsCount; i++)
	{
		delete accounts[i];
	}
	delete[] accounts;
	delete[] log;
}
void Bank::resizeCustomers()
{
	Customer** tempCustomers = new Customer * [customersCapacity *= 2];
	for (int i = 0; i < customersCount; i++)
	{
		tempCustomers[i] = customers[i];
		delete customers[i];
	}
	delete[] customers;
	customers = tempCustomers;
	for (int i = 0; i < customersCount; i++)
	{
		delete[]tempCustomers[i];
	}
	delete[] tempCustomers;
}
void Bank::resizeAccounts()
{
	Account** tempAccounts = new Account * [accountsCapacity *= 2];
	for (int i = 0; i < accountsCount; i++)
	{
		tempAccounts[i] = accounts[i];
		delete accounts[i];
	}
	delete[] accounts;
	accounts = tempAccounts;
	for (int i = 0; i < accountsCount; i++)
	{
		delete[]tempAccounts[i];
	}
	delete[] tempAccounts;
}
void Bank::resizeLog()
{
	MyString* tempLogs = new MyString[logsCapacity *= 2];
	for (int i = 0; i < logsCount; i++)
	{
		tempLogs[i] = log[i];
	}
	delete[] log;
	log = tempLogs;
}
Bank::Bank(MyString name, MyString address)
{
	this->name = name;
	this->address = address;
	customersCount = 0;
	accountsCount = 0;

}
Bank::Bank(const Bank& other)
{
	copyFrom(other);
}
Bank& Bank::operator=(const Bank& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}
void Bank::addCustomer(MyString id, MyString name, MyString address)
{
	if (customersCount >= customersCapacity)
		resizeCustomers();
	Customer* cust=new Customer(id, name, address);
	customers[customersCount++] = cust;
}
void Bank::deleteCustomer(size_t index)
{
	if (index >= customersCount)
	{
		cout << "there is not a customer with index " << index<<endl;
		return;
	}
	delete customers[index];
	customersCount--;
	for (int i = index; i < customersCount; i++)
	{
		customers[i] = customers[i + 1];
	}
}
void Bank::addAccount(Account* account)
{
	bool isValidId = false;
	for (int i = 0; i < customersCount; i++)
	{
		if (customers[i]->getId() == account->getId())
		{
			isValidId = true;
			break;
		}
	}
	if (isValidId)
	{
		if (accountsCount >= accountsCapacity)
			resizeAccounts();
		accounts[accountsCount++] = account->clone();
	}
	else
		cout << "There is not a customer with id " << account->getId() << endl;
}
void Bank::addNormalAccount(MyString username, MyString password, MyString iban,
	MyString id, size_t amount, Account::date dayOfCreation)
{
	NormalAccount* acc = new NormalAccount(username, password, iban,
		id, amount, dayOfCreation);
	addAccount(acc);

}
void Bank::addSavingsAccount(MyString username, MyString password,
	MyString iban, MyString id, size_t amount, Account::date dayOfCreation, int interestRate)
{
	SavingsAccount* acc = new SavingsAccount(username, password, iban,
		id, amount, dayOfCreation, interestRate);
	addAccount(acc);
}
void Bank::addPrivilegeAccount(MyString username, MyString password, MyString iban, MyString id,
	size_t amount, Account::date dayOfCreation, int overdraft)
{
	PrivilegeAccount* acc = new PrivilegeAccount(username, password, iban,
		id, amount, dayOfCreation, overdraft);
	addAccount(acc);
}
void Bank::addLog(MyString& l)
{
	if (logsCount >= logsCapacity)
		resizeLog();
	log[logsCount++] = l;
}
void Bank::deleteAccount(size_t index)
{
	if (index >= accountsCount)
	{
		cout << "there is not an account with index " << index;
		return;
	}
	delete accounts[index];
	accountsCount--;
	for (int i = index; i < accountsCount; i++)
	{
		accounts[i] = accounts[i + 1];
	}
}
void Bank::listCustomers()
{
	for (int i = 0; i < customersCount; i++)
		customers[i]->print();
}
void Bank::listAccounts()
{
	for (int i = 0; i < accountsCount; i++)
		accounts[i]->display();
}
void Bank::listCustomerAccount(MyString id)
{
	for (int i = 0; i < accountsCount; i++)
	{
		if (accounts[i]->getId() == id)
			accounts[i]->display();
	}
}
void Bank::listLog()
{
	for (int i = 0; i < logsCount; i++)
	{
		cout << log[i];
	}
}
void Bank::exportLog(char* fileName)
{
	ofstream file(fileName);
	if (!file.is_open())
	{
		cout << "error";
		return;
	}
		for (int i = 0; i < logsCount; i++)
		{
			file << log[i].c_str() << endl;
		}

	
}
void Bank::transfer(int amount, MyString& fromIBAN, MyString& toIBAN)
{
	bool isPossible=false;
	int indexTo = -1;
	for (int i = 0; i < accountsCount; i++)
	{
		if (accounts[i]->getIban() == fromIBAN && accounts[i]->withdraw(amount))
		{
			isPossible = true;
		}
		if (accounts[i]->getIban() == toIBAN)
			indexTo = i;
	}
	if (isPossible && indexTo > -1)
	{
		accounts[indexTo]->deposit(amount);
		cout << "Transfer is successful!";
	}
	else
		cout << "Transfer is impossible!";
}
void Bank::display()
{
	cout << "Bank: " << name<<endl;
	cout << "Address is: " << address << endl;
	cout << "Customers count is " << customersCount<<endl;
	cout << "Accounts count is " << accountsCount << endl;
	cout << "Customers are: " << endl;
	listCustomers();
	cout << "Accounts are: " << endl;
	listAccounts();

}
Account* Bank::getAccount(int index)const
{
	return accounts[index];
}
