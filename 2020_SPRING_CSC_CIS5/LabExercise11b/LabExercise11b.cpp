/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LabExercise11b.cpp
 * Author: Ahmad.Okde
 *
 * Created on May 21, 2020, 7:33 PM
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

/*Function template to dynamically allocate arrays of any type
*
* Function Name : createArray
* Description : Dynamically allocates an array of the template type with 'size'
elements.
*
*Call : createArray(size, initValue);
*Returns: a pointer to the new array .
*
*/
template <class targetType>
targetType *createArray(int size, targetType initVal) {
    // allocate array and initialize to default value for the type
    targetType* newArray = new targetType[size]();
    // Set every element to initVal
    for (int i = 0; i < size; i++)
        newArray[i] = initVal;
    return newArray;
}
/// Define a structure for the airline data
struct AirlineData
{
    string airlineName;
    long long int seatKM;
    int incidents;
    int fatalAccidents;
    int fatalities;
};

// Function: sortArrays
// Given 5 parallel arrays, (one 'string', four 'long long int', and the 'int' array size), sort the arrays
// based on the seatKM data in the first 'long loing int' array.
void sortArrays(struct AirlineData * ptr_airline, int rowCount);
//// Write the sort function here
//// You may write the bubble or the selection sort unless you have accepted the challenge
void sortArrays(struct AirlineData * ptr_airline, int rowCount)
{
    int i, j;
    bool flag;
    for (i = 0; i < rowCount - 1; i++)
    {
        flag = false;
        for (j = 0; j < rowCount - i - 1; j++)
        {
            if (ptr_airline[j].fatalities < ptr_airline[j+1].fatalities)
            {
                struct AirlineData temp = ptr_airline[j];
                ptr_airline[j] = ptr_airline[j + 1];
                ptr_airline[j + 1] = temp;
                
                flag = true;
            }
        }

        if (!flag)
            break;
    }
}


/*
 *  Functions are defined below
 */

 // Function: openDataFile
 // Given an unopned input stream and a filename, open the file.
 // Returns 'true' if the file opened, and 'false' if the open failed.
bool openDataFile(ifstream& stream, string file) {
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

    /// Declare an instance of the airline structure (variable)
    struct  AirlineData init;
    init.airlineName = "novalue";
    init.seatKM = 0;
    init.incidents = 0;
    init.fatalAccidents = 0;
    init.fatalities = 0;

    struct AirlineData* airline = createArray(airlineCount, init);

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

    //Challenge: Create a parallel array of pointers to elements of the airline array, then sort the pointers based on the structures they point to.
    struct AirlineData* ptr_airline;
    ptr_airline = airline;

    //call sort function to sort the values
    sortArrays(ptr_airline, airlineCount);

    for (int index = 0; index < airlineCount; index++) {
        /// Output data from the airline structure. Be sure to use 
        /// the fieldwidths provided at the top pf the program.
        cout << left << setw(FIELD_WIDTH_1) << airline[index].airlineName << right << setw(FIELD_WIDTH_2) << airline[index].seatKM << setw(FIELD_WIDTH_3) << airline[index].incidents << setw(FIELD_WIDTH_4) << airline[index].fatalAccidents << setw(FIELD_WIDTH_5) << airline[index].fatalities << endl;

    }

    delete[]airline;
    return 0;

}
