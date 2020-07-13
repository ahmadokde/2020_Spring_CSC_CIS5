
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
#include <cmath>
using namespace std;
const int MAX = 1000; //assuming 
int readData(ifstream& fin, string airline[], double stat[MAX][4]);
int getFatalAccidentIndex(double seat_km_per_week, double fatal_accidents);


/*
 * This program opens the data file, then reads and outputs the data.
 */
int main(int argc, char** argv) {
    string   safetyDataFilename = "AirlineSafetyData.dat";
    ifstream inStream;           // Input file stream object

    inStream.open(safetyDataFilename.c_str());

    if (!inStream) {
        cout << "File did not open. Exiting the program." << endl;
        return 1; // return error code 1
    }

    // Achknowledge that the file is open.
    cout << "File " << safetyDataFilename << " is open.\n\n";


    // Declare field variables
    string airline[MAX];                         // Airline name
    //double seat_km_per_week[MAX], incidents[MAX], fatal_accidents[MAX], fatalities[MAX]; // airline parameters
    double stat[MAX][4];

    int count = 0; //number of records

    //call function to read records
    count = readData(inStream, airline, stat);

    inStream.close();//close file


    //SECOND LOOP
    int busiest = stat[0][0];
    string busiest_airline = airline[0];

    string safest_airline = airline[0];
    int safest_index = getFatalAccidentIndex(stat[0][0], stat[0][2]);

    string least_safest_airline = airline[0];
    int least_safest_index = getFatalAccidentIndex(stat[0][0], stat[0][2]);

    float total_fatalities = 0;
    float average_fatalities = 0;

    for (int i = 0; i < count; i++)
    {
        //find busiest airline
        if (busiest < stat[i][0])
        {
            busiest_airline = airline[i];
            busiest = stat[i][0];
        }

        if (safest_index < getFatalAccidentIndex(stat[i][0], stat[i][2]))
        {
            safest_index = getFatalAccidentIndex(stat[i][0], stat[i][2]);
            safest_airline = airline[i];
        }
        if (least_safest_index > getFatalAccidentIndex(stat[i][0], stat[i][2]))
        {
            least_safest_index = getFatalAccidentIndex(stat[i][0], stat[i][2]);
            least_safest_airline = airline[i];
        }


        total_fatalities = total_fatalities + stat[i][3];
    }
    average_fatalities = total_fatalities / count;

    //display output
    cout << "\nThe busiest airline is " << busiest_airline << " having " << busiest << " km seats. " << endl;
    cout << "The safest airline is " << safest_airline << " having an fatal accident index of " << safest_index << "." << endl;
    cout << "The least safe airline is " << least_safest_airline << " having an fatal accident index of  " << least_safest_index << "." << endl;
    cout << "The average number of fatalities for all airlines is " << average_fatalities << "." << endl;
    return 0;
}


int readData(ifstream& fin, string airline[], double stat[MAX][4])
{
    string   header1, header2, header3, header4, header5;
    //read header
    fin >> header1 >> header2 >> header3 >> header4 >> header5;

    //read records from file
    int count = 0;

    //FIRST LOOP
    while (fin >> airline[count])
    {
        fin >> stat[count][0];
        fin >> stat[count][1];
        fin >> stat[count][2];
        fin >> stat[count][3];
        count++;
    }
    return count;
}

int getFatalAccidentIndex(double seat_km_per_week, double fatal_accidents)
{
    if (fatal_accidents == 0)
        fatal_accidents = 1;
    return ceil(seat_km_per_week / fatal_accidents);
}