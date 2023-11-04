#include "Shape.h"
#include <cstring>
#pragma warning (disable: 4996)

using namespace std;

Shape::Shape() 
{
	point = Point(0, 0);
	colour = new char[1];
	colour[0] = '\0';
}
Shape::Shape(int x, int y, char* colour)
{
	point.x = x;
	point.y = y;
	//colour = nullptr;
	size_t size=strlen(colour);
	this->colour = new char[size + 1];
	strcpy(this->colour, colour);

}
void Shape::copyFrom(const Shape& other)
{
	int strLen = strlen(other.colour);
	colour = new char[strLen + 1];
	strcpy(colour, other.colour);
}
void Shape::free()
{
	delete[] colour;
}

Shape::Shape(const Shape& other)
{
	copyFrom(other);
}
Shape& Shape::operator= (const Shape& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}
Shape::~Shape()
{
	free();
}

void Shape::setPoint(int x, int y)
{
	point= Point(x, y);
}
void Shape::trnaslate(int horizontal, int vertical)
{
	point.x += horizontal;
	point.y += vertical;
}
void Shape::print() const
{
	cout << colour << endl;
}