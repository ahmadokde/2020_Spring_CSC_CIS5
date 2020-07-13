#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) 
{
    
    
    string Ruler = "1234567890";
    cout << Ruler <<endl;
   
    // creating string to hold name
    string FirstName = "ahmad";
   
    // setwidth will be 10, auto adjusted to right alignment, using string
    // FirstName
    cout << setw(10) << FirstName << endl;
   
    // variable name for integer with -14 assignment
    int var1 = -14;
   
    // aligning left, setting width to 6, then outputting value
    cout << left << setw(6) << var1;
    cout << "X" << endl;

    // creating pi variable
    double Pi = 3.141592654;
   
    //alignment right, set width 10, total digits of 5 for set precision (not fixed)
    cout << right << setw(10) << setprecision(5) << Pi << endl;
   
    //create phi variable
    double Phi = 1.6180339887;
   
    // alignment right, 7 character field, 3 digits on the right
    cout << setw(7) << setprecision(3) << fixed << Phi <<endl;
   
    //create variable PhiPrime
    double PhiPrime = 1+1/Phi;
   
    // alignment right, 7 character field, 3 digits on the right
    cout << setw(7) << setprecision(3) << fixed << PhiPrime <<endl;
   
    //create variable for Midway
    double Midway = 17.5;
   
    // alignment right, 10 character field, 3 digits to the right of the field
    // print trailing zeros
    cout << setw(10) << setprecision(3) << fixed << showpoint << Midway << endl;
   
    return 0;
}
