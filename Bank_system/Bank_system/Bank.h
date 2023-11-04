#pragma once
#include  <fstream>
#include "Customer.h"
#include "Account.h"
#include "MyString.h"
const int CAPACITY = 8;

class Bank
{
	MyString name;
	MyString address;
	Customer** customers;
	int customersCount;
	int customersCapacity;
	Account** accounts;
	int accountsCount;
	int accountsCapacity;
	MyString* log;
	int logsCount;
	int logsCapacity;

	void copyFrom(const Bank& other);
	void free();
	void resizeCustomers();
	void resizeAccounts();
	void resizeLog();
public: 
	
	Bank();
	Bank(MyString name, MyString address);
	Bank(const Bank& other);
	Bank& operator=(const Bank& other);
	void addCustomer(MyString id,MyString name, MyString address);
	void deleteCustomer(size_t index);
	void addAccount(Account* account);
	void addNormalAccount(MyString username, MyString password, MyString iban, 
		MyString id, size_t amount, Account::date dayOfCreation);
	void addSavingsAccount(MyString username, MyString password, 
		MyString iban, MyString id, size_t amount, Account::date dayOfCreation,int interestRate);
	void addPrivilegeAccount(MyString username, MyString password, MyString iban, MyString id,
		size_t amount, Account::date dayOfCreation,int overdraft);
	void addLog(MyString& log);
	void deleteAccount(size_t index);
	void listCustomers();
	void listAccounts();
	void listCustomerAccount(MyString id);
	void listLog();
	
	void exportLog(char* fileName);
	void transfer(int amount, MyString& from, MyString& to);
	void display();
	Account* getAccount(int index)const;


};