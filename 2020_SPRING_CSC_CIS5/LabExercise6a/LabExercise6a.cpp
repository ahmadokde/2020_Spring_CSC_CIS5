/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   LabExercise6a.cpp
 * Author: ahmad okde
 *
 * Created on March 9, 2020 3:18 PM
 */

/* Place Library References Here */
#include <cstdlib>
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

  const double PI = 3.1415926;

// Define functions below

/*
 * Function Name: displayOutput
 * Description: It display the output containing shape name and area to the console
 */

void displayOutput(string shapeName, double area)
{
    cout << "\nThe area of the " << shapeName << " is " << area << " cubic units.\n";
}

/*
 * Function Name:displayMenu
 * Description: Display menu to user, prompt for choice from user, and returns the choice to the calling function.
 */
int displayMenu()
{
    int shape;
     // Get shape selection input from user
    cout <<"\nEnter the number of the shape whose volume you want to calculate:" << endl
	 << "  0. Quit\n"
	 << "  1. Sphere\n"
	 << "  2. Cone\n"
	 << "  3. Cylinder\n"
	 << "  4. Frustum of a Cone\n"
	 << "  5. Toroid\n"
	 << "Enter your selection: ";

    // read the shape number
    cin >> shape;
    return shape;

}
/*
 * Function Name: circleArea
 * Description: calculate and return circle area using PI * radius * radius formula
 */
double circleArea(double radius)
{
    return PI * radius * radius;
}


/*
 * Main Program
 * Description: Main Program display menu to user, user selects a shape, then program prompt for parameters of shape and
                calculates and display area of selected shape.
 */



int main() {

  double area, r, R, length, height;

  // Define constant values for the switch statement
  const int QUIT      = 0; //
  const int SPHERE    = 1; //
  const int CONE      = 2; //
  const int CYLINDER  = 3; // Constants that define the shape numbers
  const int FRUSTUM   = 4; //
  const int TOROID    = 5; //

  int shape;               // Variable to store user's requested shape
  string shapeName;        // Variable to store the selected shape name


  // Get shape selection input from user
  shape = displayMenu();

  while (shape != QUIT) { // if QUIT (shape = 0) is entered, exit loop

    // Use switch statement to process requested shape
    switch (shape)
      {
      case SPHERE:
	// Request the dimensions of the sphere, calculate and display the area.
	shapeName = "Sphere";
	cout << "What is the radius of the sphere? ";
	cin >> r;
	area = 4.0/3.0 * circleArea(r) *  r;
	displayOutput(shapeName, area);
	break;

      case CONE:
	// Request the dimensions of the cone, calculate and display the area.
	shapeName = "Cone";
	cout << "What is radius of cone base? ";
	cin >> r;
	cout << "What is the height of the cone? ";
	cin >> height;
	area = circleArea(r) * height;
	displayOutput(shapeName, area);
	break;

      case CYLINDER:
        // Request the dimensions of the cylinder, calculate and display the area.
	shapeName = "Cylinder";
	cout << "What is the radius of the cylinder? ";
	cin >> r;
	cout << "What is the length of the cylinder? ";
	cin >> length;
	area = circleArea(r) * length;
	displayOutput(shapeName, area);
	break;

      case FRUSTUM:
	// Request the dimensions of the frustum of a cone, calculate and display the area.
	shapeName = "Frustum of the cone";
	cout << "What is the radius of the base of the frustum? ";
	cin >> R;
	cout << "What is the radius of the top of the frustum? ";
	cin >> r;
	cout << "What is the height of the frustum?";
	cin >> height;
	area = ( height * circleArea(R) + height * PI * R * r + height * circleArea(r) )/3.0;
	cout << "\nThe area of the " << shapeName << " is " << area << " cubic units.\n";
	break;

      case TOROID:
	// Request the dimensions of the toroid, calculate and display the area.
	shapeName = "Toroid";
	cout << "What is the the inner radius of the toroid? ";
	cin >> r;
	cout << "What is the outer radius of the toroid? ";
	cin >> R;
	area = 2 * pow(PI,2) * pow(r,2) * R;
	displayOutput(shapeName, area);
	break;

      default:
	cout << "\n" << shape << " is not a shape I know." << endl;
      }
    shape = displayMenu();

  }

  return 0;

}