// This program will read in 7 days of work hours, then list
// the days worked and the hours worked followed by the total
// number of hours worked for the week

/* STUDENT:    ahmad okde
 * ASSIGNMENT: Lab Assignment 7a
 * DUE DATE:   4/28/2020, 9:10 PM
 */

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int    DAYS_PER_WEEK = 7;
const string DAY_NAMES[DAYS_PER_WEEK] = 
	{"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

int main()
{
	float hoursWorked[DAYS_PER_WEEK];
  // Total number of hours worked for the week
  float totalHours = 0.0;

  // Read in hours worked each day into the hoursWorked array
  cout << "\nEnter the hours you worked each day:" << endl;
  for (int i = 0; i < DAYS_PER_WEEK; i++)
    {
      cout << DAY_NAMES[i] << ":";
      cin >> hoursWorked[i];

    }

  cout << fixed << setprecision(1) << showpoint;
  cout << "\nHours worked each day:" << endl;

  // List each day and the hours worked
  for (int i = 0; i < DAYS_PER_WEEK; i++)
    {

      cout << setw(12) << left << DAY_NAMES[i] << setw(10) << setprecision(2) << fixed << right << hoursWorked[i] << endl;

      // Fill in a statement to sum the number of hours
      // worked each day in the variable totalHours (15)
      totalHours = totalHours + hoursWorked[i];

    }

  // Output the total hours worked for the week
  cout << "\nTotal hours worked: " << setprecision(2) << fixed << totalHours << endl;

  return 0;
}





