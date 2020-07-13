

/*
 * The object of this program is to demonstrate opening a file for
 * input, reading data from file, looping until the end of the file is
 * detected, and searching for a keyword in the input line.  
*/

/* 
 * File:   Labexercise5c.cpp
 * Author: ahmad okde
 * Created on April 6 2020
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*
 * 
 */

string getTime(string line);

int main(int argc, char** argv) {

// The following variables will be used in the program.
  
   string filename     = "";       // File name entered by the user
   string keyword      = "";      // Keyword or phrase entered by the user
   string line         = "";     // A line read from the file
   int    keywordCount =  0;    // Count of input lines containing the keyword
   int    totalCount   =  0;   // Total count of lines read
   // constants used in the Challenge
	const string earlyTime = "16:00"; // early time for crime (CHALLENGE ONLY)
	const string lateTime = "22:00"; // late time for crime (CHALLENGE ONLY)

   // Declare an input stream object [100, 122]]
   ifstream fin;
   // Ask the user for the input data file name [107]
   cout << "Enter file name: ";
   cin >> filename;

   // Open the file for input [101, 109, 122]]
   fin.open(filename);

   // While the file is not open (open failed) [102, 110, 111]
   while (!fin)
   {
      // Display a message to the user
	   cout << "File can not be opened. Try again.\n";
      // Ask the user to re-enter the filname
	    cout << "ReEnter file name: ";
		cin >> filename;
		fin.open(filename);
   }

   // Ask the user to enter a keyword to search for (case sensitive and may contain spaces)
   cout << "Enter a Keyword: ";
   cin.ignore();
   getline(cin, keyword);

   while (getline(fin, line)) { // Loop until the end-of-file (EOF) is reached. [104, 111]

     // Get a line from the input file 
     // Update the total count of lines read
	   totalCount = totalCount + 1;
     // If the line contains the keyword
     if(line.find(keyword) != string::npos) {
		 //Only list the crimes matching the keyword that occurred between 4:00 PM and 10:00 PM.
		string time = getTime(line);
		if (time>=earlyTime && time<=lateTime)
		{
			// Output the line that contains the keyword
			cout << line << endl;
			// Count the total count of input lines containing the keyword
		 keywordCount = keywordCount + 1;
		}
		 
     }

	 
   }

   // Close the input file [105, 122]
   fin.close();
   // Output "The total number of lines read is xxxx."
   cout << "\n\nThe total number of lines read is " << totalCount <<  "." << endl << endl;
   // Output "xxxx lines contain 'keyword'."
   cout << keywordCount << " lines contain '" << keyword << "'." << endl;

   return 0;
}

string getTime(string line) {

	int commaPos = line.find(',',0); // Find the first comma
	string time = line.substr(commaPos-5,5); // Get time from the input line

	if (time[0] == ' ') // If the first digit is blank
	time[0] = '0'; // Replace it with 0

	return time; // Return the proper time
}


