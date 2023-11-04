#pragma once
#include <iostream>
#include "Shape.h"

class Rectangle:public Shape
{
	size_t width;
	size_t height;

	
public:
	Rectangle();
	Rectangle(int x, int y, size_t width, size_t height,char* colour);
	double getArea() const override;
	double getPer() const override;
	bool isPointIn(int x, int y) const override;
	Shape* clone() const override;
	bool within(int x, int y, size_t width, size_t heigth)const override;
	bool within(int x, int y, double radius)const override;
	void print()const override;
};
