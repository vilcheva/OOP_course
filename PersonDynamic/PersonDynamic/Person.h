#include<iostream>
class Person
{
	char* name;
	int age;
	double grade;

	void copyFrom(const Person& other);
	void free();

public:
	Person();
	Person(char* name, int age, double grade);
	Person& operator= (const Person& other);
	Person(const Person& other);
	int getAge()const;
	double getGrade()const;
	const char* getName() const;
	void setAge(int age);
	void setGrade(double grade);
	void setName(const char* name);
	~Person();
	void print() const;

};