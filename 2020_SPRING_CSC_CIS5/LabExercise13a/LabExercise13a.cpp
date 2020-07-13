/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LabExercise13a.cpp
 * Author: Ahmad.Okde
 *
 * Created on May 26, 2020, 7:13 PM
 */

#include <iostream>
using namespace std;


//Define a specification for a class called Circle.
class Circle
{
	//Private float variables x , y, and r initialized to 0, 0 and 1, respectively.
private:
	float x, y, r;
public:
	Circle()
	{
		//initialized to 0, 0 and 1, respectively.
		x = 0;
		y = 0;
		r = 1;
	}
	//1. setCenter that has two float parameters.
	void setCenter(float a, float b)
	{
		x = a;
		y = b;
	}

	//2. getX that returns one float type.
	float getX()
	{
		return x;
	}
	//3. getY that returns one float type.
	float getY()
	{
		return y;
	}
	//4. setRadius that has one float parameter;
	void setRadius(float radius)
	{
		r = radius;
	}

	//5. getRadius that returns a float type.
	float getRadius()
	{
		return r;
	}

	//6. getArea that returns the area of the circle.
	float getArea()
	{
		return 3.14 * r * r;
	}
};
int main()
{
	// Create an instance of Circle
	Circle circle;

	// Set circle parameters using mutator functions
	circle.setCenter(1.2, 3.4);
	circle.setRadius(5.0);

	// Demonstrate accessor functions
	cout << "Radius = " << circle.getRadius() << endl;
	cout << "X      = " << circle.getX() << endl;
	cout << "Y      = " << circle.getY() << endl;
	cout << "Area   = " << circle.getArea() << endl;
	return 0;
}

