/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Programming_Assignment_8.cpp
 * Author: Ahmad.Okde
 *
 * Created on May 17, 2020, 2:07 PM
 */
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

//function prototypes
void CalculateMean_SD(float grades[], float &mean, float &sd, int n);
string getLetterGrade(float grade, float mean, float sd);

int main()
{
	//variable to hold number of records
	int n;
	//pointer array to hold students name
	string *names;
	//pointer array to hold students grade
	float *grades;
	int i = 0;
	float mean = 0; //airthmetic mean
	float sd = 0;	//standard deviation

	//open file
	ifstream fin;
	fin.open("studentScores.dat");
	//if file not found
	if (!fin)
	{
		//display error message and return
		cout << "File not found\n";
		return 1;
	}

	fin >> n; //read number of students from file

	//dynamically initialize arrays
	names = new string[n];
	grades = new float[n];

	//read name and grade from file
	for (i=0; i<n; i++)
	{
		fin >> names[i];
		fin >> grades[i];
	}

	fin.close();	//close file

	//call function to calculate mean and standard deviation
	CalculateMean_SD(grades, mean, sd, n);

	cout << endl << endl;

	//display airthmetic mean and standard deviation
	cout << "Airthmetic mean: " << mean << endl;
	cout << "Standard Deviatoin: " << sd << endl;

	//display each student name with grade and letter grade
	cout << "\nStudent Name             Grade     Letter Grade" << endl;
	for (int i=0; i<n; i++)
	{
		cout << setw(25) << left << names[i] << setw(15) << setprecision(2) << fixed << grades[i] << setw(5) << getLetterGrade(grades[i], mean, sd) << endl;
		
	}
	//system("pause");
	return 0;
}

/*Function name: CalculateMean_SD
Purpose: calculate mean and standard deviation of grades
input parameters: grades - float array whose mean and standard deviation to be calculated
				mean - float reference parameter which will hold mean of grades
			   sd - float reference parameter which will hold standard deviation of grades
			   n - integer value which holds number of grades
return value: none
*/
void CalculateMean_SD(float grades[], float &mean, float &sd, int n)
{
	float sum = 0;
	for (int i=0; i<n; i++)
	{
		//calculate sum to values
		sum = sum + grades[i];
	}
	//calculate mean
	mean = sum/n;

	sum = 0;
	//calculate standard deviation
	for (int i=0; i<n; i++)
	{
		sum = sum + (grades[i]-mean)*(grades[i]-mean);
	}
	sd = sum/(n-1);
	sd = sqrt(sd);
}

/*
Function name: getLetterGrade
purpose: calculate and return letter grade based on following conditions:
		A = grade  >=  (mean + 1.5 SD)
	   B = grade  >=  (mean + 0.5 WD)
	   C = grade  >=  (mean - 0.5 SD)
	   D = grade  >= ( mean - 1.5 SD)
	   F = the rest
input parameters: 
		grade - float value for which letter grade to be calculated
		mean - airthmetic mean of grades array
		sd - standard deviation of grades array
return value: string - letter grade
*/
string getLetterGrade(float grade, float mean, float sd)
{
	if (grade >= (mean + 1.5*sd))
	{
		return "A";
	}
	else if (grade >= (mean + 0.5*sd))
	{
		return "B";
	}
	else if (grade >= (mean - 0.5*sd))
	{
		return "C";
	}
	else if (grade >= (mean - 1.5*sd))
	{
		return "D";
	}
	return "F";
}