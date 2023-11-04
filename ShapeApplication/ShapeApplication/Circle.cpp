#include "Circle.h"
using namespace std;

Circle::Circle() :Shape()
{
	radius = 0;
}
Circle::Circle(int x, int y, double radius, char* colour):Shape(x,y, colour)
{
	this->radius = radius;
	type = Type::circle;
}
double Circle::getArea() const
{
	return 3.14 * radius * radius;
}
double Circle::getPer() const
{
	return (3.14 * 2 * radius);
}
bool Circle::isPointIn(int x, int y) const
{
	Shape::Point p(x, y);
	return point.getDist(p) <= radius;
}
Shape* Circle::clone() const
{
	return new Circle(*this);
}
bool Circle::within(int x, int y, size_t width, size_t heigth)const
{
	return point.x - radius >= x && point.x + radius <= width - x && point.y + radius<=y
		&& point.y - radius>=y - heigth;
}
bool Circle::within(int x, int y, double radius)const
{
	return point.x + this->radius<=x + radius && point.x - this->radius>=x - radius
		&& point.y + this->radius<=y + radius && point.y - radius>=y - radius;

}
void Circle::print()const
{
	cout <<"circle " << point.x << " " << point.y << " " << radius << " ";
	Shape::print();
}