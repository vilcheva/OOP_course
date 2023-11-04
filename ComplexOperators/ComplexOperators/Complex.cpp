#include "Complex.h"
using namespace std;

Complex::Complex()
{
	real = 0;
	im = 0;
}
Complex::Complex(int real, int im)
{
	this->real = real;
	this->im = im;
}
Complex& Complex::operator+=(const Complex& other)
{
	real += other.real;
	im += other.im;
	return *this;
}
Complex& Complex::operator-=(const Complex& other)
{
	real -= other.real;
	im -= other.im;
	return *this;
}
Complex& Complex::operator*=(const Complex& other)
{
	real = real * other.real - im * other.im;
	im = real * other.im + im * other.real;
	return*this;
}

ostream& operator<<(ostream& file, Complex& complex)
{
	file << complex.real << "+" << complex.im << "i";
	return file;
}
istream& operator>>(istream& file, Complex& complex)
{
	file >> complex.real >> complex.im;
	return file;
}

Complex operator+(const Complex& first, const Complex& second)
{
	Complex result = first;
	result += second;
	return result;
}
Complex operator-(const Complex& first, const Complex& second)
{
	Complex result = first;
	result -= second;
	return result;
}
Complex operator*(const Complex& first, const Complex& second)
{
	Complex result = first;
	result *= second;
	return result;
}