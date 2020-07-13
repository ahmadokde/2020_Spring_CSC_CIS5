/*
 * Purpose: Demonstrate the use of the 'for' loop, nesting loops and
 * output formatting.
 *
 * Instructions:Write a program that will use nested "for" loops to 
 * output a 12 x 12 multiplication table. Each output field is 4 
 * characters wide.
 */
 
/* 
 * File:   LabExercise5b.cpp
 * Author: Ahmad okde
 * Created on April 2, 2020
 */
#include <iostream>
#include <iomanip>
using namespace std;

int main() 
{

  // Define constants
  const auto columns    = 12;     // Number of columns
  const auto rows       = 12;    // Number of rows
  const auto fieldWidth =  4;   // Size of field

  //blank field
  cout << setw(5)<< "|";
  //.  First, use a single 'for'loop to output the column headers 0 - 12.
   // Output header row
    for (int i=0; i<=columns; i++)
    {
        cout << setw(4) << i;
    }
    cout << endl << "---------------------------------------------------------" << endl;
    // Output multiplication table, inluding row headers.
    for (int i=0; i<=rows; i++)
    {
        cout << setw(4) << i << "|";
        for (int j=0; j<=columns; j++)
        {
            cout << setw(4) << i*j;
        }
        cout << endl;
    }
    return 0;
}