/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ProgrammingAssignment9.cpp
 * Author: Ahmad.Okde
 *
 * Created on May 26, 2020, 1:02 AM
 */

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

const int N = 9;

//function prototypes
void ReadFile(ifstream &fin, int arr[][N]);
bool duplicatePresent(int num[], int index, string where);
bool blockCheck(int row, int col, int arr[][N]);

int main()
{
	int arr[N][N];
	bool isValid;
	string filename;
	
	//prompt for file name
	cout << "Enter file name: ";
	cin >> filename;
	//open file
	ifstream fin;
	fin.open(filename.c_str());
	//if file not exists
	if (!fin)
	{
		cout << filename << " not found";
		return 1;
	}
	cout << "Opening " << filename << endl << endl;
	
	//call function to read file in 2D array
	ReadFile(fin, arr);

	//close file
	fin.close();

	//display sudoku
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << arr[i][j] << "  ";
		}
		cout << endl;
	}
	cout << endl; cout << endl;

	/*PART - 1*/
	bool done = true;
	//call containsDuplicate function for each row of the arr
	for (int i = 0; i < N; i++)
	{
		isValid = duplicatePresent(arr [i], i+1, "Row");
		if (!isValid)
			done = false;
	}

	//call function to check duplicate values in columns
	int temp[N];
	for (int i = 0; i < N; i++)
	{
		//copy column in temp
		for (int j = 0; j < N; j++)
		{
			temp[j] = arr[j][i];
		}
		//call function to check if duplicate exists in 
		isValid = duplicatePresent(temp, i+1, "Column");
		if (isValid == false)
		{
			done = false;
		}
	}

	/*PART 2*/
	//check each grid
	for (int i = 0; i < N; i = i + 3) {
		for (int j = 0; j < N; j = j + 3)
		{
			isValid = blockCheck(i, j, arr);
			if (isValid == false)
			{
				cout << "Grid (" << (i + 1) << ", " << (j + 1) << ") contains duplicate elements." << endl;
				done = false;
			}
		}
	}


	if (done == true)
	{
		cout << "Sudoku solution is a valid solution" << endl;
	}
	else
	{
		cout << "Sudoku solution is not a valid solution" << endl;
	}
	return 0;
}

/*
Function Name: ReadFile
Description: Read file open through fin in 2d array arr
return value: none
input parameters: fin - file pointer, arr - 2d array of integers
*/
void ReadFile(ifstream& fin, int arr[][N])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			fin >> arr[i][j];
		}
	}
}


/*
Function name: dupicatePresent
Description: Check if the array contains duplicate elements
return value: bool (true if contains duplicate, false otherwise)
input parameters: num - array in which duplicate element is to be searched
				index: index of row or column to display
				where - whether row or column to display
*/
bool duplicatePresent(int num[], int index, string where)
{

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < i - 1; j++)
		{
			if (num[i] == 0)
			{
				cout << "Empty location in " << where << " #" << index << endl;
				return false;
			}
			else if (num[i] == num[j])
			{
				cout << num[i] << " is duplicate in " << where << " #" << index << endl;
				return false;
			}
		}
	}
	return true;
}

/*
Function name: blockCheck
Description: checkes if the block contains duplicate elements or not
Return value: bool - true if contains duplicate, false otherwise
Input parameters - row - row number for grid, col - column number for block, arr - complete 2D array containing sudoku solution
*/
bool blockCheck(int row, int col, int arr[][N])
{
	for (int num = 1; num <= N; num++)
	{
		int count = 0;
		for (int i = row; i < row + 3; i++)
		{
			for (int j = col; j < col + 3; j++)
			{
				if (arr[i][j] == num)
					count++;
			}
			if (count > 1)
				return false;
		}
	}
	return true;
}

