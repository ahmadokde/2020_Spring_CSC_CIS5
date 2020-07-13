/*
 * This goal of this exercise is for you to become familiar with creating 
 * valid variable names and integer types, declaring integer variables, 
 * initializing and assigning integer variables, and understanding integer
 * variable limits. 
 *
 */

/* 
 * File:   Lab_Assignment_2a.cpp
 * Author: <your name here>
 *
 * Created on February 25, 2020
 *
 */

#include <iostream>
#include <limits.h>
using namespace std;

/*
 * Predefined integer constants you can use as needed.
 * They are from the "limits.h" file included above.
 * You will not use them all in this assignment.
 *
 * Type: short int or short
 * SHRT_MIN	Minimum value for an object of type short int
 * SHRT_MAX	Maximum value for an object of type short int
 * USHRT_MAX	Maximum value for an object of type unsigned short int
 *
 * Type: int
 * INT_MIN       Minimum value for an object of type int
 * INT_MAX       Maximum value for an object of type int
 *
 * Type: unsigned int
 * UINT_MAX	Maximum value for an object of type unsigned int
 *
 * Type: long int or long
 * LONG_MIN	Minimum value for an object of type long int
 * LONG_MAX	Maximum value for an object of type long int
 *
 * Type: unsigned long int or unsignd long
 * ULONG_MAX	Maximum value for an object of type unsigned long int
 *
 * Type: long long int or long long
 * LLONG_MIN	Minimum value for an object of type long long int
 * LLONG_MAX	Maximum value for an object of type long long int
 *
 * Type: unsigned long long int or unsigned long
 * ULLONG_MAX	Maximum value for an object of type unsigned long long int
 */

int main() {
   const int fWide = 21;

   // <<<< Example >>>>
   cout << "Part 0 - Example using 'unsigned short int' type" << endl;

   // Declare an 'unsigned short int' variable
   unsigned short int number1;
   // Initialize the variable to USHRT_MAX
   number1 = USHRT_MAX;
   //Display the variable's value
   cout << "unsigned int maximum = " << number1 << endl;
   // Add 12 to the value
   number1 = number1 + 12;
   // Display the variable's value
   cout << "unsigned int maximum = " << number1 << endl;



   // There are three parts. Do not change the existing cout staements since they
   // will tell me which section you are processing.
   // You will notice that half of each section is "display the variable's value"
   // so you can just cut and paste it as needed. Just be sure that if you cut
   // and paste from one part to he another part you change the variable name
   // and comment.

   // You choose your own variable names. Try to make them more meaningful than
   // the one in the example :-)
   // For each section be sure your outpur stement includes a string descibing
   // the value you are outputting.


   cout << "Part 1 - 'short int' type" << endl;
   
   // Declare a 'short int' variable

   // Intialize it to SHRT_MIN

   // Display the variable's value

   // Change the variable to SHRT_MAX

   // Display the variable's value

   // Add 1 to the variable

   // Display the variable's value

   // Set the variable to the value 23654

   // Display the variable's value

   // Add 15875 toi the variable

   // Display the variable's value
   

   cout << "Part 2 - 'int' type" << endl;
   
   // Declare an 'int' variable

   // Intialize it to INT_MAX

   // Display the variable's value

   // Add one to the variable

   // Change the variable to INT_MIN

   // Display the variable's value

   // Subtract 1 from the variable

   // Display the variable's value

   // Change the variable to 24.99

   // Display the variable's value

   // Set the variable to -24.99

   // Display the variable's value

   
   cout << "Part 3 - 'unsigned int' type" << endl;
   
   // Declare an 'unsigned int' variable

   // Intialize it to UINT_MAX

   // Display the variable's value

   // Add 1 to the variable

   // Display the variable's value

   // Change the variable to 0

   // Display the variable's value

   // Subtract 1 from the variable

   // Display the variable's value

   // Set the variable to 24.99

   // Display the variable's value

   return 0;
 
}

