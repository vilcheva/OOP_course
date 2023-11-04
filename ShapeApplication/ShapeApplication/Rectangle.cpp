#include "Rectangle.h"
using namespace std;

Rectangle::Rectangle() :Shape()
{
	width = 0;
	height = 0;
}
Rectangle::Rectangle(int x, int y, size_t width, size_t height, char* colour) : Shape(x, y, colour)
{
	this->width = width;
	this->height = height;
	type = Type::rectangle;
}
double Rectangle::getArea() const
{
	return width * height;
}
double Rectangle::getPer() const
{
	return 2 * (width + height);
}
bool Rectangle::isPointIn(int x, int y) const
{
	return (x >= point.x && x <= point.x + width && y <= point.y && y >= point.y - height);
}
Shape* Rectangle::clone() const
{
	return new Rectangle(*this);
}
bool Rectangle::within(int x, int y, size_t width, size_t heigth)const
{
	return point.x >= x && point.y <= y&& point.x - x + this->width <= width 
		&& y - point.y + this->height <= height;
}
bool Rectangle::within(int x, int y, double radius)const
{
	return point.x > x - radius && point.y < y + radius 
		&& point.x + width<x + radius && point.y - height>y - radius;
}
void Rectangle::print()const
{
	cout <<"rectangle " << point.x << " " << point.y << " " << width << " " << height << " ";
	Shape::print();
}