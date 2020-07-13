/*This program is to read different shapes and their parameters from file and display their area and perimeter by creating their objects*/


#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"

using namespace std;


const string FILENAME = "ProgrammingAssignment10.dat";
string touppercase(string str);
int main()
{
	//open file
	ifstream fin;
	fin.open(FILENAME);

	//if file not found
	if (!fin)
	{
		cout << FILENAME << " file not found." << endl;
		return 1;
	}

	string shape;

	//read shape name from file
	while (fin >> shape)
	{
		//check shape
		if (touppercase(shape) == "CIRCLE")
		{
			double radius;
			//read radius from file
			fin >> radius;
			//construct circle object
			Circle circle(radius);

			//display summary of circle
			cout << "Circle" << endl;
			cout << setprecision(2) << fixed;

			cout << "Radius   : " << circle.getRadius() << endl;
			cout << "Area     : " << circle.getArea() << endl;
			cout << "Perimeter: " << circle.getPerimeter() << endl << endl << endl;
		}
		else if (touppercase(shape) == "RECTANGLE")
		{
			double length, width;
			//read length and width from file
			fin >> length >> width;
			//construct rectangle object
			Rectangle rect(length, width);
			//display summary of Rectangle
			cout << "Rectangle" << endl;
			cout << setprecision(2) << fixed;

			cout << "Length   : " << rect.getLength() << endl;
			cout << "Width    : " << rect.getWidth() << endl;
			cout << "Area     : " << rect.getArea() << endl;
			cout << "Perimeter: " << rect.getPerimeter() << endl << endl << endl;

		}
		else if (touppercase(shape) == "SQUARE")
		{
			double side;
			//read side from file
			fin >> side;
			//construct square object
			Square sq(side);
			//display summary of Square
			cout << "Square" << endl;
			cout << setprecision(2) << fixed;

			cout << "Side     : " << sq.getSide() << endl;
			cout << "Area     : " << sq.getArea() << endl;
			cout << "Perimeter: " << sq.getPerimeter() << endl << endl << endl;
		}
		else
		{
			cout << "*** No matching shape found" << endl;
		}
	}
	fin.close();
	return 0;
}

//function to convert string to upper case
string touppercase(string str)
{
	for (int i = 0; i < str.length(); i++)
	{
		str[i] = toupper(str[i]);
	}
	return str;
}

