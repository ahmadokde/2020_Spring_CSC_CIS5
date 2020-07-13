
/*
 * The data file AirlineSafetyData.dat contains incident and fatality
 * statistics that occured between 2000 and 2014 for a number of airlines.
 * (https://github.com/fivethirtyeight/data/tree/master/airline-safety)
 *
 *  The data file (AirSafetyData.dat) has 5 columns as follows:
 *    Column 1: Airline name
 *    Column 2: Number of seats flown weekly times number of km flown weekly
 *    Column 3: Number of number of incidents from 2000 to 2014
 *    Column 4: Number of fatal accidents  from 2000 to 2014
 *    Column 5: Number of fatalities  from 2000 to 2014
 */

/* 
 * File:  LabExercise6c.cpp
 * Author: Ahmad okde
 *
 * Created on April 23, 2020
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <ctype.h>
#include <algorithm>

using namespace std;
const int MAX = 1000; //assuming 

// Given an unopened input stream object and a filename, open the file.
// Return 'true' if the file opened, and 'false' if the open failed.
// The stream object must be call-by-reference since opening a file
// makes changes to the stream object that we have to pass pack to
// the calling program.
bool openDataFile( ifstream&, string);
/// WRITE THIS FUNCTION ///
bool openDataFile( ifstream& fin, string filename)
{
	fin.open(filename.c_str());
	if (!fin)
		return false;
	return true;
}
// The first line in the data file contains five column headers.
// Given an input stream object and five parameters, read the headers
// from the file.
// The headers will be returned by reference to the caller.
// Return 'true' if eof was not detected, 'false' if at eof.
bool readHeaders(ifstream&, string&, string&, string&, string&, string&);
/// WRITE THIS FUNCTION ///
bool readHeaders(ifstream& fin, string &airline, string &seat_km_per_week, string &incidents, string &fatal_accidents, string &fatalities)
{
	fin >> airline;
	fin >> seat_km_per_week;
	fin >> incidents;
	fin >> fatal_accidents;
	fin >> fatalities;

	return fin.eof();

}
// Given an input stream and five parameters, read the parameters from the file.
// The values will be returned by reference to the caller.
// Return 'true' if eof was not detected, 'false' if at eof.
bool readData(ifstream& stream, string[], double[], double[], double[], double[], int index);
/// WRITE THIS FUNCTION ///
bool readData(ifstream & stream, string airline[], double seat_km_per_week[], double incidents[], double fatal_accidents[], double fatalities[], int index)
{
	stream >> airline[index];
	stream >> seat_km_per_week[index];
	stream >> incidents[index];
	stream >> fatal_accidents[index];
	stream >> fatalities[index];
	return stream.eof();
}

/*
 * This program opens the data file, then reads and outputs the data.
 */
int main(int argc, char** argv) {

  // Declare constant width of each output field
  const auto FIELD_WIDTH_1 = 26;
  const auto FIELD_WIDTH_2 = 20;
  const auto FIELD_WIDTH_3 = 16;
  const auto FIELD_WIDTH_4 = 16;
  const auto FIELD_WIDTH_5 = 16;
  
  string   safetyDataFilename = "AirlineSafetyData.dat";
  ifstream inStream;           // Input file stream object

  //
  // *** Open the input file
  //

  // Try to open file until successful
  if  (openDataFile(inStream, safetyDataFilename)==false) {
       cout << "File did not open. Exiting the program." << endl;
       exit (1); // return error code 1
}

  // Achknowledge that the file is open.
  cout << "File " << safetyDataFilename << " is open.\n\n";

  
  //
  // *** Read and display the column headers
  //

  // The first row of the data file consists of five column headers
  string   header1, header2, header3, header4, header5;
  
  // Input the headers
  //// ADD A CALL HERE TO READ THE HEADERS ////
    readHeaders(inStream, header1, header2, header3, header4, header5);
  // Output the header row
  // (Used substr to shorten the header if it is wider than the field width)
  cout << left;
  cout << setw(FIELD_WIDTH_1) << left << header1.substr(0,FIELD_WIDTH_1 - 1);
  cout << right;
  cout << setw(FIELD_WIDTH_2) << header2.substr(0,FIELD_WIDTH_2 - 1);
  cout << setw(FIELD_WIDTH_3) << header3.substr(0,FIELD_WIDTH_3 - 1);
  cout << setw(FIELD_WIDTH_4) << header4.substr(0,FIELD_WIDTH_4 - 1);
  cout << setw(FIELD_WIDTH_5) << header5.substr(0,FIELD_WIDTH_5 - 1);
  cout << endl;
	      

  //
  // *** Read and output the data
  //
  
  // Declare field variables
  string field1[MAX];                         // Airline name
  double field2[MAX], field3[MAX], field4[MAX], field5[MAX]; // airline parameters
  int count = 0; //number of records
  
  // Output the data
  cout << setprecision(10);
  while (!(readData(inStream, field1, field2, field3, field4, field5, count)))
    {
		count++;
  }
  for (int i=0; i<count; i++)
  {
      cout << left;
      cout << setw(FIELD_WIDTH_1) << field1[i];
      cout << right;
      cout << setw(FIELD_WIDTH_2) << field2[i];
      cout << setw(FIELD_WIDTH_3) << field3[i];
      cout << setw(FIELD_WIDTH_4) << field4[i];
      cout << setw(FIELD_WIDTH_5) << field5[i];
      cout << endl;

    }
  inStream.close();
  return 0;
}
