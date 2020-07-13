/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   labexercise9a.cpp
 * Author: Ahmad.Okde
 *
 * Created on May 12, 2020, 8:06 PM
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


// Function: sortArrays
// Given 5 parallel arrays, (one 'string', four 'long long int', and the 'int' array size), sort the arrays
// based on the seatKM data in the first 'long loing int' array.
void sortArrays(string*, long long int*, long long int*, long long int*, long long int*, int);
//// Write the sort function here
//// You may write the bubble or the selection sort unless you have accepted the challenge
void sortArrays(string *airlineName, long long int *seatKM, long long int *incidents, long long int *fatalAccidents, long long int *fatalities, int rowCount)
{
    int i, j;
    bool flag;
    for (i = 0; i < rowCount - 1; i++)
    {
        flag = false;
        for (j = 0; j < rowCount - i - 1; j++)
        {
            if (*(seatKM+j) > *(seatKM+j + 1))
            {
                //swap airline name
                string temp = *(airlineName+j);
                *(airlineName+j) = *(airlineName+j + 1);
                *(airlineName+j + 1) = temp;

                //swap other array values
                long long int t = *(seatKM+j);
                *(seatKM+j) = *(seatKM+j + 1);
                *(seatKM+j + 1) = t;

                t = *(incidents+j);
                *(incidents+j) = *(incidents+j + 1);
                *(incidents+j + 1) = t;

                t = *(fatalAccidents+j);
                *(fatalAccidents+j) =*(fatalAccidents+j + 1);
                *(fatalAccidents+j + 1) = t;

                t = *(fatalities+j);
                *(fatalities+j) = *(fatalities+j + 1);
                *(fatalities+j + 1) = t;
                flag = true;
            }
        }

        if (!flag)
            break;
    }
}



// Function: binarySearchR (string)
// Given an array to search, the size of the array and a value to search
// return the position of the value in the array, or "-1" if not found.
// Recursive versio of binary search
int binarySearchR(long long int*, int, int, long long int);


// Function: linearSearch (integer)
// Given an array to search, the size of the array and a value to search
// return the position of the value in the array, or "-1" if not found.
int linearSearch(long long int*, const int, long long int);


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

    string    *airlineName;
    airlineName = new string[DATA_SIZE];

    long long int *seatKms;
    seatKms = new long long int[DATA_SIZE];


    long long int *incidents;
    incidents = new long long int[DATA_SIZE];

    long long int *fatalAccidents;
    fatalAccidents = new long long int[DATA_SIZE];

    long long int *fatalities;
    fatalities = new long long int[DATA_SIZE];


    int rowCount = 0;
    int *rowCountPtr;
    rowCountPtr = &rowCount;

    // Read the data into the array and count number of rows
    while (readData(inStream, *(airlineName+(*rowCountPtr)), *(seatKms+(*rowCountPtr)),
        *(incidents+(*rowCountPtr)), *(fatalAccidents+(*rowCountPtr)), *(fatalities+(*rowCountPtr))))
        (*rowCountPtr)++;


    // At this point in the program 'rowCount' contains the actual number
    // of rows read from the data file
    cout << *rowCountPtr << " airlines read from data file.\n";


    // Display data if flag is true
    if (displayData) {
        cout << fixed << setprecision(0) << "\n";
        for (int index = 0; index < *rowCountPtr; index++)
            outputData(cout, *(airlineName+index), *(seatKms+index),
               *(incidents+index), *(fatalAccidents+index), *(fatalities+index));
    }


    /*
     * There ae two steps in verifying that the sort worked
     * 1) Verify that no seatKM is smaller than the one in the previsous arrays element/
     * 2) Verify that all 5 arrays were swapped a set of entries usig their fatality count
     *    and then using a binary search to locate the same records using their seatKMs.
     */


    int           position = 0;   // Position if item in the list
    string        strSearchValue; // Airline name to search for
    long long int intSearchValue; // Integer value to search for

    cout << "\nArray synchronization test.\nIf the sort worked each item in all columns of the\nfollowing lists will be identical\n";
    cout << "--------------------------------------------------------\n";

    //
    // Create a baseline for verifying the sort algorithm.
    //
searchBlock1:
    {
        // List items having these fatality counts for comparison to seatKMS below
        int searchList[] = { 88, 337, 158,   7,
                 88, 416, 225,  51,
                 14,  92,  22, 143,
                 283, 537,  46,   1,
                 110,  83,   3, 188,
                 1,  84, 109,  23 };

        int listSize = sizeof(searchList) / sizeof(*searchList);

        for (int index = 0; index < listSize; index++) {

            //cout << "\nSearching for fatality count '" << searchList[index]<< "'.\n";

            // Call linear search function
            position = linearSearch(fatalities, *rowCountPtr, *(searchList+index));

            if (position >= *rowCountPtr || position < 0)
                cout << "Fatality search value " << *(searchList+index) << " not found in airline list.\n";
            else
                outputData(cout, *(airlineName+position), *(seatKms+position),
                    *(incidents+position), *(fatalAccidents+position), *(fatalities+position));
        }
    }


    cout << "--------------------------------------------------------\n";
    // Sort the arrays
    sortArrays(airlineName, seatKms, incidents, fatalAccidents, fatalities, *rowCountPtr);

    // Display sorted data, if requested
    if (displayData) {
        cout << fixed << setprecision(0) << "\n";
        for (int index = 0; index < *rowCountPtr; index++)
            outputData(cout, *(airlineName+index), *(seatKms+index),
                *(incidents+index), *(fatalAccidents+index), *(fatalities+index));
    }


searchBlock2:
    // Binary search based on seatKMs
    {
        // List the items having these seatKMS. they are synchronized with th efatality list above
        long long int searchList[] = { 1197672318, 3004002661,  869253552,  710174817,
                      965346773, 5228357340,  813216487, 6525658894,
                      557699891,  488560643,  613356665,  301379762,
                      277414794, 1039171244,  348563137,  413007158,
                      682971852, 2376857805,  259373346, 1509195646,
                      1702802250, 1946098294, 7139291291, 2455687887 };
        int listSize = sizeof(searchList) / sizeof(*searchList);

        //cout << "\nRECURSIVE BINARY SEARCH RESULTS:\n";
        for (int index = 0; index < listSize; index++) {

            //cout << "\nSearching for seatKMs '" << seatKms[index]<< "'.\n";

            // Call binary search function
            position = binarySearchR(seatKms, 0, *rowCountPtr - 1, *(searchList+index));

            if (position >= *rowCountPtr || position < 0)
                cout << "Seat_KM value " << *(searchList+index) << " not found in airline list.\n";
            else
                outputData(cout, *(airlineName + position), *(seatKms + position),
                    *(incidents + position), *(fatalAccidents + position), *(fatalities + position));

        }
        cout << "--------------------------------------------------------\n";
    }

    // Verify that the SeatKM array is sorted in ascendbg order.
sortVerification:
    {
        int sortFailureCount = 0;
        bool showSortFailures = false;
        cout << "\nSeatKM array sort verification test:\n";
        // Verify seatKMs are sorted
        for (int index = 1; index < *rowCountPtr; index++) {
            if (*(seatKms+index) < *(seatKms+index - 1)) {   // verify seatKMs are monotonic increasing
                sortFailureCount++;
                if (showSortFailures) {
                    cout << "\nSort failure at line " << index << ":\n";
                    outputData(cout, *(airlineName+index - 1), *(seatKms+index - 1),
                        *(incidents+index - 1), *(fatalAccidents+index - 1), *(fatalities+index - 1));
                    cout << "VS\n";
                    outputData(cout, *(airlineName+index), *(seatKms+index),
                        *(incidents+index), *(fatalAccidents+index), *(fatalities+index));
                }
            }
        }
        if (sortFailureCount)
            cout << "Sort FAILED: " << sortFailureCount << " non-sorted items.\n";
        else
            cout << "Sort PASSED.\n";
    }

    delete[] airlineName;
    delete[] seatKms;
    delete[] incidents;
    delete[] fatalAccidents;
    delete[] fatalities;

    return 0;
}



// Function: binarySearchR (string)
// Given an array to search, the size of the array and a value to search
// return the position of the value in the array, or "-1" if not found.
// Recursive versio of binary search
int binarySearchR(long long int *array, int start, int end, long long int target) {
    int middle = (start + end) / 2;
    if (end < start) {
        return -1;
    }
    if (target == *(array+middle)) {
        return middle;
    }
    else if (target < *(array + middle)) {
        return binarySearchR(array, start, middle - 1, target);
    }
    else {
        return binarySearchR(array, middle + 1, end, target);
    }
}


// Function: linearSearch (integer)
// Given an array to search, the size of the array and a value to search
// return the position of the value in the array, or "-1" if not found.
int linearSearch(long long int *values, const int size, long long int searchValue) {
    //// If you have chosen linear search, add code here and be sure to change the return statement.
    for (int i = 0; i < size; i++)
        if (*(values+i) == searchValue)
            return i;
    return -1;
}





