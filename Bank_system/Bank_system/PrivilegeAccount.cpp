#include "PrivilegeAccount.h"
PrivilegeAccount::PrivilegeAccount(MyString username, MyString password, MyString iban, MyString id, size_t amount, date dayOfCreation, int overdraft) :Account(username, password, iban, id, amount, dayOfCreation)
{
	this->overdraft = overdraft;
}
int PrivilegeAccount::getOverdraft() const
{
	return overdraft;
}
void PrivilegeAccount::setOverdraft(int overdraft)
{
	this->overdraft = overdraft;
}
bool PrivilegeAccount::withdraw(int amount)
{
	if (getAmount() + overdraft > amount)
	{
		setAmount((getAmount() + overdraft) - amount);
		return true;
	}
	return false;
}
Account* PrivilegeAccount::clone() const
{
	return new PrivilegeAccount(*this);
}