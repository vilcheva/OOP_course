#pragma once
#include "MyString.h"
class Customer
{
	MyString id;
	MyString name;
	MyString address;

public:
	Customer() = default;
	Customer(MyString id, MyString name, MyString address);
	MyString getId();
	void print()const;
	Customer* clone()const;
};