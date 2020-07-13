/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LabExercise8a.cpp
 * Author: Ahmad okde
 *
 * Created on May the 5th be with you, 2020
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
bool openDataFile(ifstream& stream, string file) {
    stream.open(file);
    return stream.is_open();
}

// Function: readData
// Given an ifstream and five parameters, read the parameters from the file.
// The values read will be returned by reference to the caller.
// The function will return 'true' if there all of the elements were read, 'false' if end of file.
bool readData(ifstream& stream, string& f1, long long int& f2, long long int& f3, long long int& f4, long long int& f5) {
    stream >> f1 >> f2 >> f3 >> f4 >> f5;
    return !stream.eof();
}

// Function: outputData
// Given an ifstream and five array parameters, output the selected data
void outputData(ostream& stream, string f1, long long int f2, long long int f3, long long int f4, long long int f5) {
    cout <<
        left <<
        setw(FIELD_WIDTH_1) << f1 <<
        right <<
        setw(FIELD_WIDTH_2) << f2 <<
        setw(FIELD_WIDTH_3) << f3 <<
        setw(FIELD_WIDTH_4) << f4 <<
        setw(FIELD_WIDTH_5) << f5 <<
        endl;
}


// Function: binarySearch (string)
// Given an array to search, the size of the array and a value to search
// return the position of the value in the array, or "-1" if not found.

int binarySearch(string[], int left, int right, string);

int binarySearch(string arr[], int left, int right, string key)
{
   
    if (right >= left) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key)
            return mid;

        if (arr[mid] > key)
            return binarySearch(arr, left, mid - 1, key);

        return binarySearch(arr, mid + 1, right, key);
    }
    return -1;
}



// Function: linearSearch (integer)
// Given an array to search, the size of the array and a value to search
// return the position of the value in the array, or "-1" if not found.
int linearSearch(long long int[], const int, long long int);
int linearSearch(long long int arr[], const int size, long long int key)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

/*
 *  Main program reads in airline statstics from a file
 *  and performs searches on the data.
 */
int main(int argc, char** argv) {

    // Display data Flag
    bool displayData = false;

    // *** Define assumed max data size and defined arrays.
    const auto DATA_SIZE = 100;

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

    string    airlineName[DATA_SIZE];
    long long seatKms[DATA_SIZE];
    long long incidents[DATA_SIZE];
    long long fatalAccidents[DATA_SIZE];
    long long fatalities[DATA_SIZE];

    int rowCount = 0;

    // Read the data into the array and count number of rows
    while (readData(inStream, airlineName[rowCount], seatKms[rowCount],
        incidents[rowCount], fatalAccidents[rowCount], fatalities[rowCount]))
        rowCount++;


    // At this point in the program 'rowCount' contains the actual number
    // of rows read from the data file
    cout << rowCount << " airlines read from data file.\n";


    // Display data if flag is true
    if (displayData) {
        cout << fixed << setprecision(0) << "\n";
        for (int index = 0; index < rowCount; index++)
            outputData(cout, airlineName[index], seatKms[index],
                incidents[index], fatalAccidents[index], fatalities[index]);
    }


    /*
     *  Perform general searches
     */

    int       position = 0;   // Position if item in the list
    string    strSearchValue; // Airline name to search for
    long long intSearchValue; // Integer value to search for



    //search for airlines
    string airlineList[] = { "Aer_Lingus", "Qantas*", "Hawaiian_Airlines", "Fly-By-Night",  "Xiamen_Airlines" };
    int listSize = sizeof(airlineList) / sizeof(*airlineList);

    cout << "\nBINARY SEARCH RESULTS:\n";
    for (int index = 0; index < listSize; index++) {

        cout << "\nSearching for airline '" << airlineList[index] << "'.\n";

        // Call binary earch function
        position = binarySearch(airlineName, 0, rowCount, airlineList[index]);

        if (position >= rowCount || position < 0)
            cout << "Airline " << airlineList[index] << " not found in airline list.\n";
        else
            outputData(cout, airlineName[position], seatKms[position],
                incidents[position], fatalAccidents[position], fatalities[position]);
    }

    int searchList[] = { 23, 0, 158, 537, 23, 293 };
    listSize = sizeof(searchList) / sizeof(*searchList);

    cout << "\nLINEAR SEARCH RESULTS:\n";
    for (int index = 0; index < listSize; index++) {

        cout << "\nSearching for fatality count '" << searchList[index] << "'.\n";

        // Call linear search function
        position = linearSearch(fatalities, rowCount, searchList[index]);

        if (position >= rowCount || position < 0)
            cout << "Fatality search value " << searchList[index] << " not found in airline list.\n";
        else
            outputData(cout, airlineName[position], seatKms[position],
                incidents[position], fatalAccidents[position], fatalities[position]);
    }
    return 0;
}

