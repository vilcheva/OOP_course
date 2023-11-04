#pragma once
#include <iostream>
#include "Shape.h"

class Circle :public Shape
{
	double radius;
public:
	Circle();
	Circle(int x, int y, double radius,char* colour);
	double getArea() const override;
	double getPer() const override;
	bool isPointIn(int x, int y) const override;
	Shape* clone() const override;
	bool within(int x, int y, size_t width, size_t heigth)const override;
	bool within(int x, int y, double radius)const override;
	void print()const override;
};
