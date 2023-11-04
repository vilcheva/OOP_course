#pragma once
#include "Account.h"
class NormalAccount:public Account
{
public:
	NormalAccount(MyString username, MyString password, MyString iban, MyString id, size_t amount, date dayOfCreation);
	bool withdraw(int amount);
	void display() override;
	~NormalAccount() {}
	virtual Account* clone() const override;
};