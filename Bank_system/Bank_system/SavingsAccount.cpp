#include "SavingsAccount.h"
SavingsAccount::SavingsAccount(MyString username, MyString password, MyString iban, MyString id, size_t amount, date dayOfCreation, int interestRate) : Account(username, password, iban, id, amount, dayOfCreation)
{
	this->interestRate = interestRate;
}
void SavingsAccount::setInterestRate(int interestRate)
{
	this->interestRate = interestRate;
}
int SavingsAccount::getInterestRate()const
{
	return interestRate;
}
Account* SavingsAccount::clone() const
{
	return new SavingsAccount(*this);
}
