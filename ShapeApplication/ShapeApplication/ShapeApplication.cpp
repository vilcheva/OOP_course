#include <iostream>
#include <cstring>
#include "Rectangle.h"
#include "Circle.h"
#include "Line.h"
#include "ShapeCollection.h"
using namespace std;
bool strCompare(char* first, const char* second)
{
	if (strlen(first) != strlen(second))
		return false;
	for (int i = 0; i < strlen(first); i++)
	{
		if (first[i] != second[i])
			return false;
	}
	return true;
}
void Menu(ShapeCollection shapeCollection,char* fileName)
{
	char* command = new char[10];
	char* type = new char[10];
	int x, y;
	size_t width, height;
	double radius;
	size_t index;
	do {
		cout << "Choose command " << endl;
		cout << "> ";
		cin >> command;
		if (strCompare(command, "open"))
		{
			cout << "Insert file name: ";
			cin >> fileName;
			//TO DO..
			cout << "Successfully opened " << fileName << endl;
		}
		else if (strCompare(command, "print"))
		{
			shapeCollection.Print();
		}
		else if (strCompare(command, "create"))
		{
			char* colour = new char[10];
			cout << "Choose figure type: ";
			cin >> type;
			if (strCompare(type, "rectangle"))
			{
				cin >> x >> y >> width >> height >> colour;
				shapeCollection.createRectangle(x, y, width, height, colour);
				cout << "Successfully created rectangle(" << shapeCollection.getSize() << ')' << endl;
			}
			else if (strCompare(type, "circle"))
			{
				cin >> x >> y >> radius >> colour;
				shapeCollection.createCircle(x, y, radius, colour);
				cout << "Successfully created circle(" << shapeCollection.getSize() << ')' << endl;
			}
			else if (strCompare(type, "line"))
			{
				int x2, y2;
				cin >> x >> y >> x2 >> y2 >> colour;
				shapeCollection.createLine(x, y, x2, y2, colour);
				cout << "Successfully created line(" << shapeCollection.getSize() << ')' << endl;
			}

			delete[] colour;
		}
		else if (strCompare(command, "erase"))
		{
			cin >> index;
			shapeCollection.Erase(index - 1);
		}
		else if (strCompare(command, "translate"))
		{
			char* temp = new char[20];
			int horizontal, vertical;
			cin >> temp;
			if (strCompare(temp, "vertical="))
			{
				cin >> vertical;
				cin >> temp;
				if (strCompare(temp, "horizontal="))
					cin >> horizontal;
				shapeCollection.Translate(horizontal, vertical);
			}
			else if (strCompare(temp, "index="))
			{
				cin >> index;
				cin >> temp;
				if (strCompare(temp, "vertical="))
				{
					cin >> vertical;
					cin >> temp;
					if (strCompare(temp, "horizontal="))
						cin >> horizontal;
				}
				shapeCollection.Translate(index - 1, horizontal, vertical);
			}
			delete[]temp;
		}
		else if (strCompare(command, "within"))
		{
			cin >> type;
			if (strCompare(type, "rectangle"))
			{
				cin >> x >> y >> width >> height;
				shapeCollection.WithIn(x, y, width, height);
			}
			else if (strCompare(type, "circle"))
			{
				cin >> x >> y >> radius;
				shapeCollection.WithIn(x, y, radius);
			}
		}
		else if (strCompare(command, "save"))
		{
			//TO DO..
			cout << "Successfully saved the changes to" << fileName << endl;
		}
		else if (strCompare(command, "pointIn"))
		{
			cout << "Insert point(x, y)";
			cin >> x >> y;
			shapeCollection.PointIn(x, y);
		}
		else if (strCompare(command, "pers"))
		{
			shapeCollection.Pers();
		}
		else if (strCompare(command, "areas"))
		{
			shapeCollection.Areas();
		}
		else
			continue;
	} while (!strCompare(command, "exit"));

	cout << "Exit" << endl;
	delete[] command;
	delete[] type;
}
int main()
{
	ShapeCollection shapeCollection;
	char* fileName = new char[20];
	Menu(shapeCollection, fileName);
	delete[] fileName;
}

