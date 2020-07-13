/*
 *  Demonstrate the use of C++ structures for storing multi-
 *  field data elements. It will read elements from a data file
 *  into a structure and output the element fields from the
 *  structure.
 *
 *
 */

/* 
 * File:   LabExercise11a.cpp
 * Author: Ahmad okde
 * 
 *
 * Created on May 19th, 2020
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

// Declare constant width of each output field
const auto FIELD_WIDTH_1 = 26;
const auto FIELD_WIDTH_2 = 15;
const auto FIELD_WIDTH_3 = 5;
const auto FIELD_WIDTH_4 = 5;
const auto FIELD_WIDTH_5 = 5;


/*
 *  Functions are defined below
 */

// Function: openDataFile
// Given an unopned input stream and a filename, open the file.
// Returns 'true' if the file opened, and 'false' if the open failed.
bool openDataFile( ifstream& stream, string file) {
  stream.open(file);
  return stream.is_open();
}

/*
 *  Main program reads in airline statstics from a file
 *  and performs searches on the data.
 */
int main(int argc, char** argv) {
	int airlineCount;
  
  // Display data Flag
  bool displayData = true;
  
  /// Define a structure for the airline data
  struct AirlineData
  {
	  string airlineName;
	  long long int seatKM;
	  int incidents;
	  int fatalAccidents;
	  int fatalities;
  };
  /// Declare an instance of the airline structure (variable)
   struct AirlineData *airline;

  // Input file related declarations
  string   safetyDataFilename; // User Inputs Filename
  ifstream inStream;           // Input file stream object

  // *** Open the input file

  // Ask user for input, read user response.
  cout << "Enter airline safety data File name: ";
  getline(cin, safetyDataFilename);

  // Try to open file until successful
  while (!openDataFile(inStream, safetyDataFilename)) {
    cout << "File did not open. Re-enter filename: ";
    cin >> safetyDataFilename;
  }

  // Confirm open file
  cout << "File " << safetyDataFilename << " open." << endl;

  // Read number of airlines to process
  inStream >> airlineCount;

  // At this point in the program 'airlineCount' contains the actual number
  // of rows read from the data file
  cout << airlineCount << " Airlines to proccess.\n";

  airline = new AirlineData[airlineCount];

  //
  // Process the airline data
  //

  cout << fixed << setprecision(0) << "\n";
  
  // Loop through airline records
  for (int index = 0; index < airlineCount; index++) {

    /// Read airline data into the airline structure
	  inStream >> airline[index].airlineName;
	  inStream >> airline[index].seatKM;
	  inStream >> airline[index].incidents;
	  inStream >> airline[index].fatalAccidents;
	  inStream >> airline[index].fatalities;
  }
   for (int index = 0; index < airlineCount; index++) {
    /// Output data from the airline structure. Be sure to use 
	/// the fieldwidths provided at the top pf the program.
	  cout << left << setw(FIELD_WIDTH_1) << airline[index].airlineName << right << setw(FIELD_WIDTH_2) << airline[index].seatKM << setw(FIELD_WIDTH_3) << airline[index].incidents << setw(FIELD_WIDTH_4) << airline[index].fatalAccidents << setw(FIELD_WIDTH_5) << airline[index].fatalities << endl;

  }

   delete []airline;
  return 0;
  
}
  
