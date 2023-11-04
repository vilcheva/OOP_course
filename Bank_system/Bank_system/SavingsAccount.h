#pragma once
#include "Account.h"
class SavingsAccount: public Account
{
	int interestRate;
public:
	SavingsAccount(MyString username, MyString password, MyString iban, MyString id, size_t amount, date dayOfCreation, int interestRate);
	void setInterestRate(int interestRate);
	int getInterestRate()const;
	virtual Account* clone() const override;
	~SavingsAccount(){}
 };