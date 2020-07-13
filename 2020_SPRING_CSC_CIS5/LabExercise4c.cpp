/*
 * A menu drive program demonstration that will ask the user to select
 * one of several shapes, ask the user for the parameters of that
 * shape, then will calulate and output certain characteristics of
 * that shape.
 *
 */

/* 
 * File:   shapeAreaLab4b.cpp
 * Author: Ahmad okde
 * Created on March 24, 2020, 8:14 PM
 */

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <stdlib.h>
using namespace std ;


// define PI as a named constant
const double PI = 3.1415926;

int main() {
	int choice;
	float area, perimeter;
	while (true)
	{
		// Put your menu display and user prompt code here
		cout << endl;
		cout << "0. Quit" << endl;
		cout << "1. Triangle" << endl;
		cout << "2. Square" << endl;
		cout << "3. Rectangle" << endl;
		cout << "4. Circle" << endl;
        cout << "5. Ellipse" << endl;
        cout << "6. Polygon" << endl;

		cout << "Enter choice: ";
		cin >> choice;

		switch(choice)
		{
        case 0:
            {
                cout << "Thank you for using the program\n\n";
                exit(0);
            }
        case 1:
            {
                float a, b, c;

                cout << "Enter a: ";
                cin >> a;
                cout << "Enter b: ";
                cin >> b;
                cout << "Enter c: ";
                cin >> c;
                float s = (a+b+c)/2;

                area = sqrt(s*(s-a) * (s-b)*(s-c));
                perimeter = a+b+c;
                cout  << "Area of triangle: " << setprecision(2) << fixed << area << endl;
                cout << "Perimeter of triangle: " << setprecision(2) << fixed << perimeter << endl;
            }
            break;
        case 2:
            {
                float side;
                cout << "Enter side of square: ";
                cin >> side;
                area = side * side;
                perimeter = 4 * side;
                cout << "Area of Square: " << setprecision(2) << fixed << area << endl;
                cout << "Perimeter of Square: " << setprecision(2) << fixed << perimeter << endl;
            }
            break;
        case 3:
            {
                float width, height;
                cout << "Enter width: ";
                cin >> width;
                cout << "Enter height: ";
                cin >> height;
                area = width * height;
                perimeter = 2*(width + height);
                cout  << "Area of rectangle: " << setprecision(2) << fixed << area << endl;
                cout << "Perimeter of rectangle: " << setprecision(2) << fixed << perimeter << endl;
            }
            break;
        case 4:
            {
                float radius;
                cout << "Enter radius of circle: ";
                cin >> radius;
                area = PI * radius * radius;
                perimeter = 2 * PI * radius;
                cout  << "Area of Circle: " << setprecision(2) << fixed << area << endl;
                cout << "Perimeter of Circle: " << setprecision(2) << fixed << perimeter << endl;
            }
            break;
        case 5:
            {
                float a, b;
                cout << "Enter major axis: ";
                cin >> a;
                cout << "Enter minor axis: ";
                cin >> b;
                perimeter = 2 * PI * sqrt((a*a + b*b)/2);
                area = PI * a * b;
                cout  << "Area of Ellipse: " << setprecision(2) << fixed << area << endl;
                cout << "Perimeter of Ellipse: " << setprecision(2) << fixed << perimeter << endl;
            }
            break;
        case 6:
            {
                int sideCount;
                float sideLength;
                cout << "Enter number of sides: ";
                cin >> sideCount;
                if (sideCount<3)
                {
                    cout << "Error: Invalid sides in polygon\n";
                }
                else{
                    cout << "Enter side length: ";
                    cin >> sideLength;
                    perimeter = sideCount * sideLength;
                    area = (sideLength*sideLength * sideCount) / (4 * tan(PI/sideCount));
                    cout  << "Area of Polygon: " << setprecision(2) << fixed << area << endl;
                    cout << "Perimeter of Polygon: " << setprecision(2) << fixed << perimeter << endl;
                }
            }
            break;
        default:
            {
                cout << "Invalid option entered\n";
                cin.ignore (256,'\n');
            }
		}

	} // end of while loop
	return 0;
}