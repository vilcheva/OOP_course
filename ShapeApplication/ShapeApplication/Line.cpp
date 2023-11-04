#include "Line.h"
using namespace std;

Line::Line():Shape()
{
	point2.x = 0;
	point2.y = 0;
}
Line::Line(int x, int y, int x2, int y2, char* colour) : Shape(x, y, colour)
{
	point2.x = x2;
	point2.y = y2;
	type = Type::line;
}
double Line::getArea() const
{
	return 0;
}
double Line::getPer() const
{
	return 2 * point.getDist(point2);
}
bool Line::isPointIn(int x, int y) const
{
		int A = (point2.y - point.y);
		int B = (point2.x - point.x) * (-1);
		int C = (B * point.y) + (A * point.x);
		return A * x + B * y + C == 0;
}
Shape* Line::clone() const
{
	return new Line(*this);
}
void Line::trnaslate(int horizontal, int vertical)
{
	Shape::trnaslate(horizontal, vertical);
	point2.x += horizontal;
	point2.y += vertical;
}
bool Line::within(int x, int y, size_t width, size_t heigth)const
{
	return point.x > x && point.x<x + width && point.y<y&& point.y>y - heigth &&
		point2.x>x && point2.x < x + width && point2.y<y&& point2.y>y - heigth;
}
bool Line::within(int x, int y, double radius)const
{
	return point.x > x - radius && point.x<x + radius && point.y>y - radius && point.y<y + radius
		&& point2.x>x - radius && point2.x<x + radius && point2.y>y - radius && point2.y < y + radius;
}
void Line::print()const
{
	cout <<"line " << point.x << " " << point.y << " " << point2.x << " " << point2.y << " ";
	Shape::print();
}