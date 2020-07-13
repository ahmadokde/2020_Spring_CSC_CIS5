/*
 * CLASS ID: 18FAL-CIS/CSC-5-48840/48841 
 *
 * STUDENT:    <ahmad okde>
 * ASSIGNMENT: LabExercises7b_challenge
 * DUE DATE:   04/30/2020
 *
 */

/* Place Library References Here */
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

/*
 * Place Global Constants Below
*/
const string INPUT_FILENAME = "testScoreData.dat";
const int    STUDENT_COUNT = 9;
const int    TEST_COUNT = 6;
const int    FIELD_WIDTH = 9;
const int    NAME_FIELD = 15; // challenge only
const string COLUMN_FILENAME = "columnHeaders.dat";
const string STUDENT_FILENAME = "studentNames.dat";

/*
 * Place Functions or Function Protypes Below
*/
void openInputFile(ifstream& inputFile, string inputFilename = INPUT_FILENAME)
{

    inputFile.open(inputFilename);
    if (!inputFile.is_open())
    {
        cout << "Failed to " << inputFilename << "input file. Exiting program. " << endl;
        exit(1);
    }

}

/*
 * Main Program
 * Description: <describe what main program does>
 */
int main() {

    // The algoritm for writing this program is show below.
    // *After each comment* below enter the statement or statements to
    // implement the requested functionality. You will find examples
    // in the lecture slides.

    // Declare a double-subscript array into which the scores will be read (127-128)
    double scores[STUDENT_COUNT][TEST_COUNT];
    // Using the provided function, open the input file and read the scores from the file into the array.
    ifstream fin;
    openInputFile(fin, INPUT_FILENAME);

    for (int i = 0; i < STUDENT_COUNT; i++)
    {
        for (int j = 0; j < TEST_COUNT; j++)
        {
            fin >> scores[i][j];
        }
    }
    // Close the input file
    fin.close();

    ifstream header;
    openInputFile(header, COLUMN_FILENAME);
    ifstream student;
    openInputFile(student, STUDENT_FILENAME);


    // Output the array to the screen as a table using FIELD_WIDTH for each entry. (134,135)
    // At the end of each row output the average score for that row. (139-141)
    double student_total = 0;
    double student_average = 0;
    double class_total = 0;
    double class_average = 0;
    string str;

    //print header
    while (header >> str)
    {
        cout << setw(FIELD_WIDTH) << str;
    }
    header.close();

    cout << endl;
    cout << setprecision(1) << fixed;

    for (int i = 0; i < STUDENT_COUNT; i++)
    {
        student_total = 0;
        student >> str;
        cout << setw(NAME_FIELD) << str;
        for (int j = 0; j < TEST_COUNT; j++)
        {
            cout << setw(FIELD_WIDTH) << scores[i][j];
            student_total = student_total + scores[i][j];
        }
        student_average = student_total / TEST_COUNT;
        cout << setw(FIELD_WIDTH) << student_average << endl;
        class_total = class_total + student_average;
    }
    student.close();
    // After outputting the student scores and the student averages output the class average (136,138)
    class_average = class_total / STUDENT_COUNT;

    cout << "Class Average: " << class_average << endl;

    return 0;

}



