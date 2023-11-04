#include "ShapeCollection.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Line.h"
#include <iostream>
using namespace std;

ShapeCollection::ShapeCollection()
{
	collectionSize = 0;
	capacity = 4;
	collection = new Shape * [capacity];
}

void ShapeCollection::free()
{
	for (size_t i = 0; i < collectionSize; i++)
		delete collection[i];
	delete[] collection;
}
void ShapeCollection::copyFrom(const ShapeCollection& other)
{
	collection = new Shape * [other.collectionSize];
	collectionSize = other.collectionSize;
	capacity = other.capacity;

	for (size_t i = 0; i < collectionSize; i++)
	{
		collection[i] = other.collection[i]->clone();
	}
}

void ShapeCollection::resize()
{
	Shape** newCollection = new Shape * [capacity *= 2];
	for (size_t i = 0; i < collectionSize; i++)
		newCollection[i] = collection[i];
	delete[] collection;
	collection = newCollection;
}

ShapeCollection::ShapeCollection(const ShapeCollection& other)
{
	copyFrom(other);
}
ShapeCollection& ShapeCollection:: operator=(const ShapeCollection& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}
ShapeCollection::~ShapeCollection()
{
	free();
}
size_t ShapeCollection::getSize()const
{
	return collectionSize;
}
void ShapeCollection::Print()
{
	for (int i = 0; i < collectionSize; i++)
	{
		cout << i+1 << '.';
		collection[i]->print();
	}
}
void ShapeCollection::Create(Shape* shape)
{
	if (collectionSize >= capacity)
		resize();
	collection[collectionSize++] = shape;
}
void ShapeCollection::createRectangle(int x, int y, size_t width, size_t height, char* colour)
{
	Rectangle* rect = new Rectangle(x, y, width, height, colour);
	Create(rect);
	
}
void ShapeCollection::createCircle(int x, int y, double radius, char* colour)
{
	Circle* circle = new Circle(x, y, radius, colour);
	Create(circle);
	
}
void ShapeCollection::createLine(int x, int y, int x2, int y2, char* colour)
{
	Line* line = new Line(x, y, x2, y2, colour);
	Create(line);
	
}
void ShapeCollection::Erase(size_t index)
{
	if (index >= collectionSize)
	{
		cout << "There is no figure number " << index;
		return;
	}

	delete collection[index];
	cout << "Erased " << index+1;
	collection[index] = nullptr;
	collectionSize--;
	for (int i = index; i < collectionSize; i++)
	{
		collection[i] = collection[i + 1];
	}
}
void ShapeCollection::PointIn(int x, int y)
{
	for (int i = 0; i < collectionSize; i++)
	{
		if (collection[i]->isPointIn(x, y))
		{
			cout << i+1 << '.';
			collection[i]->print();
		}
			
	}
}
void ShapeCollection::Areas()
{
	for (int i = 0; i < collectionSize; i++)
	{
		cout << i+1 << '.';
		cout << collection[i]->getArea();
	}
}

void ShapeCollection::Pers()
{
	for (int i = 0; i < collectionSize; i++)
	{
		cout << i+1 << '.';
		cout << collection[i]->getPer();
	}
}
void ShapeCollection::Translate(size_t index, int horizontal, int vertical)
{
	if (index >= collectionSize)
	{
		cout << "There is no figure number " << index;
		return;
	}

	collection[index]->trnaslate(horizontal, vertical);
}
void ShapeCollection::Translate(int horizontal, int vertical)
{
	for (int i = 0; i < collectionSize; i++)
	{
		collection[i]->trnaslate(horizontal, vertical);
	}
}
void ShapeCollection::WithIn(int x, int y, size_t width, size_t height)
{
	bool isEmpty = true;
	for (int i = 0; i < collectionSize; i++)
	{
		if (collection[i]->within(x, y, width, height))
		{
			cout << i+1 << '.';
			collection[i]->print();
			isEmpty = false;
		}
		
	}
	if (isEmpty)
	{
		cout << "No figures are located within rectangle " << x << ' '
			<< y << ' ' << width << ' ' << height << endl;
	}
}
void ShapeCollection::WithIn(int x, int y, double radius)
{
	bool isEmpty = true;
	for (int i = 0; i < collectionSize; i++)
	{
		if (collection[i]->within(x, y, radius))
		{
			cout << i+1 << '.';
			collection[i]->print();
			isEmpty = false;
		}
	}
	if (isEmpty)
	{
		cout << "No figures are located within circle " << x << ' '
			<< y << ' ' << radius<< endl;
	}
}