#include <cstring>
#include "Person.h"
using namespace std;
Person::Person()
{
	name = nullptr;
	age = 0;
	grade = 2;
}
Person::Person(char* name, int age, double grade)
{
	setAge(age);
	setGrade(grade);
	setName(name);
}
void Person::copyFrom(const Person& other)
{
	age = other.age;
	grade = other.grade;
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);
}
void Person::free()
{
	delete[]name;
}
Person& Person::operator= (const Person& other) 
{
	if (this != &other)
	{
		free();
		copyFrom(other);	
	}
	return *this;
}
Person::Person(const Person& other) 
{
	copyFrom(other);
}
int Person::getAge()const
{
	return age;
}
double Person::getGrade()const
{
	return grade;
}
const char* Person::getName() const
{
	return name;
}
void Person::setAge(int age) 
{
	this->age = age;
}
void Person::setGrade(double grade)
{
	this->grade = grade;
}
void Person::setName(const char* name)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}
Person::~Person()
{
	free();
}
void Person::print() const
{
	cout << "Name is: " << name<<endl;
	cout << "Age is: " << age<<endl;
	cout << "Grade is: " << grade<<endl;
}