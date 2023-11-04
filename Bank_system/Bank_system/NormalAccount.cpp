#include "NormalAccount.h"
using namespace std;
NormalAccount::NormalAccount(MyString username, MyString password, MyString iban, MyString id, size_t amount, date dayOfCreation)
	:Account(username, password, iban, id,  amount, dayOfCreation)
{}
bool NormalAccount::withdraw(int amount)
{
	if (amount <= getAmount())
	{
		setAmount(getAmount()-amount);
		return true;
	}
	return false;
}
void NormalAccount::display()
{
	cout << "Normal Account" << endl;
	cout << "iban is: " << getIban() << endl;
	cout << "id is: " << getId() << endl;
	cout << "balance is:" << getBalance()<<endl;
 }
Account* NormalAccount::clone() const
{
	return new NormalAccount(*this);
}