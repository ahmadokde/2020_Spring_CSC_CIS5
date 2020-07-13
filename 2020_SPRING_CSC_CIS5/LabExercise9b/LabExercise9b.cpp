/*
 * This program demonstrates the use of pointer variables
 * It finds the area of a rectangle given length and width
 * It prints the length and width in ascending order
 */

 /*
  * File:   LabExercise9b.cpp
  * Author: <Ahmad okde>
  *
  * Created on May 14, 2020
  */

  /* Place Library References Here */
#include <iostream>
using namespace std;

bool getData(int* L, int* W) {

    cout << "\nPlease input the length of the rectangle: ";
    cin >> *L;

        cout << "Please input the width of the rectangle: ";
        cin >> *W;

        // Fill in code to return false if either L or W is 0
        //  Otherwise return true

        if (*L == 0 || *W == 0)
            return false;
        return true;
}


int main()
{

    int length;	// holds length
    int width;	// holds width
    int area;	// holds area

    // Fill in the code to create an int pointer named lengthPtr
    int* lengthPtr;
    //  Initilize lengthPtr to the address of the length variable
    lengthPtr = &length;


    // Fill in the code to create an int pointer named widthPtr
    //  Intialize widthPtr to the address of the variable named width
    int* widthPtr;
    widthPtr = &width;


    while (getData(lengthPtr, widthPtr)==true) { // fill in the code to exit if no data

        area = (*lengthPtr) * (*widthPtr);	// Fill in code to find the area by using only the pointer variables

        cout << "The area is " << area << endl;

        if (*lengthPtr > *widthPtr)// Fill in the condition length > width by using only the pointer variables)
            cout << "The length is greater than the width" << endl;

        else if (*widthPtr > *lengthPtr)  // Fill in the condition of width > length by using only the pointer variables
            cout << "The width is greater than the length" << endl;

        else
            cout << "The width and length are the same" << endl;

    }
    return 0;
}


    



    
