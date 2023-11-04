#include "Account.h"
using namespace std;
Account::Account(MyString username, MyString password, MyString iban, MyString id, size_t amount, date dateOfCreation)
{
	this->username = username;
	this->password = password;
	this->iban = iban;
	this->id = id;
	this->amount = amount;
	this->dateOfCreation = dateOfCreation;
}
void Account::setAmount(int amount)
{
	this->amount = amount;
}
MyString Account::getUsername()const
{
	return username;
}
MyString Account::getPassword()const
{
	return password;
}
MyString Account::getIban()const
{
	return iban;
}
MyString Account::getId()const
{
	return id;
}
int Account::getAmount()const
{
	return amount;
}
Account::date Account::getDateOfCreation()const
{
	return dateOfCreation;
}

void Account::deposit(int amount)
{
	this->amount += amount;
}
void Account::display()
{
	cout << "username is: " << username << endl;
	cout << "password is: " << password << endl;
	cout << "iban is: " << iban << endl;
	cout << "id is: " << id << endl;
	cout << "amount is" << amount << endl;
	cout << "date of creation is: " << dateOfCreation.day<<'.'<<dateOfCreation.month<<'.'<<dateOfCreation.year;
}
bool Account::withdraw(int amount)
{
	cout << "Operation withdraw is impossible!";
	return false;
}
int Account::getBalance()
{
	return amount;
}

