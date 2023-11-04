#pragma once
#include<iostream>
using namespace std;

class Complex
{
	int real;
	int im;

public:
	Complex();
	Complex(int real, int im);
	Complex& operator+=(const Complex& other);
	Complex& operator-=(const Complex& other);
	Complex& operator*=(const Complex& other);

	friend ostream& operator<<(ostream& file, Complex& other);
	friend istream& operator>>(istream& file, Complex& other);
	
};

Complex operator+(const Complex& first, const Complex& second);
Complex operator-(const Complex& first, const Complex& second);
Complex operator*(const Complex& first, const Complex& second);

