#pragma once
#include "Shape.h"
#include <iostream>

class Line:public Shape
{
	Point point2;
public:
	Line();
	Line(int x, int y, int x2, int y2, char* colour);
	double getArea() const override;
	double getPer() const override;
	bool isPointIn(int x, int y) const override;
	Shape* clone() const override;
	void trnaslate(int horizontal, int vertical) override;
	bool within(int x, int y, size_t width, size_t heigth)const override;
	bool within(int x, int y, double radius)const override;
	void print() const override;
};