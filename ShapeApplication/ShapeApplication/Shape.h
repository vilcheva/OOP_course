#pragma once
#include <iostream>

class Shape
{
protected:
	struct Point
	{
		Point() :x(0), y(0) {}
		Point(int x, int y) :x(x), y(y) {}
		int x;
		int y;
		double getDist(const Point& other) const
		{
			int dx = x - other.x;
			int dy = y - other.y;

			return sqrt(dx * dx + dy * dy);
		}
	}point;
	enum Type
	{
		rectangle,
		circle,
		line,
		unknown
	}type;
private:
	char* colour;
	void copyFrom(const Shape& other);
	void free();


public:
	Shape();
	Shape(int x, int y, char* colour);
	Shape(const Shape& other);
	Shape& operator=(const Shape& other);
	virtual ~Shape();

	void setPoint(int x, int y);

	virtual double getArea() const = 0;
	virtual double getPer()  const = 0;
	virtual bool isPointIn(int x, int y) const = 0;
	virtual Shape* clone() const = 0;
	virtual void trnaslate(int horizontal, int vertical);
	virtual bool within(int x, int y, double radius)const = 0;;
	virtual bool within(int x, int y, size_t width, size_t height)const = 0;
	virtual void print() const;
	
}; 
