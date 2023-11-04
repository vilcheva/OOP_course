#pragma once
#include <ctime>
#include <iostream>
#include "MyString.h"
class Account
{
public:
	struct date {
		size_t year;
		size_t month;
		size_t day;
		date()
		{
			year = 1;
			month = 1;
			day = 1;
		}
		date(size_t year, size_t month, size_t day)
		{
			this->year = year;
			this->month = month;
			this->day = day;
		}
	}dateOfCreation;
private:
	MyString username;
	MyString password;
	MyString iban;
	MyString id;
	int amount;
public:
	void setAmount(int amount);
	MyString getUsername()const;
	MyString getPassword()const;
	MyString getIban()const;
	MyString getId()const;
	int getAmount()const;
	date getDateOfCreation()const;

	Account() = default;
	Account(MyString username, MyString password, MyString iban, MyString id, size_t amount,date dayOfCreation);
	virtual void deposit(int amount);
	virtual bool withdraw(int amount);
	virtual void display();
	int getBalance();
	virtual ~Account(){}
	virtual Account* clone() const = 0;
};


