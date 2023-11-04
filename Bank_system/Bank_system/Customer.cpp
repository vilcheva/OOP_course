#include <iostream>
#include "Customer.h"

using namespace std;
Customer::Customer(MyString id, MyString name, MyString address)
{
	this->id = id;
	this->name = name;
	this->address = address;
}
MyString Customer::getId()
{
	return id;
}
void Customer::print()const
{
	cout << name << " id is: " << id << " address is: " << address << endl;
}
Customer* Customer::clone()const
{
	return new Customer(*this);
}