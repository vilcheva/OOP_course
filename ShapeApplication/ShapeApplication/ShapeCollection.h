#pragma once
#include <iostream>
#include "Shape.h"

class ShapeCollection
{
	Shape** collection;
	size_t collectionSize;
	size_t capacity;

	void copyFrom(const ShapeCollection& other);
	void free();
	void resize();
	void Create(Shape* shape);
public:
	ShapeCollection();
	ShapeCollection(const ShapeCollection& other);
	ShapeCollection& operator=(const ShapeCollection& other);
	~ShapeCollection();
	size_t getSize()const;
	void Print();
	void createRectangle(int x, int y, size_t width, size_t height, char* colour);
	void createCircle(int x, int y, double radius , char* colour);
	void createLine(int x, int y, int x2, int y2, char* colour);
	void Erase(size_t index);
	void Translate(size_t index, int horizontal, int vertical);
	void Translate(int horizontal, int vertical);
	void WithIn(int, int, size_t, size_t);
	void WithIn(int, int, double);
	void PointIn(int x, int y);
	void Areas();
	void Pers();
};