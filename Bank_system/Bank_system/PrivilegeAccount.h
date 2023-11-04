#pragma once
#include "Account.h"
class PrivilegeAccount :public Account
{
	int overdraft;
public:
	PrivilegeAccount(MyString username, MyString password, MyString iban, MyString id, size_t amount, date dayOfCreation, int overdraft);
	void setOverdraft(int overdraft);
	int getOverdraft() const;
	bool withdraw(int amount);
	virtual Account* clone() const override;
	~PrivilegeAccount(){}
};