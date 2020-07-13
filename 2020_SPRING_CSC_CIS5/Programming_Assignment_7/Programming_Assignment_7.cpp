/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Programming_Assignment_7.cpp
 * Author: Ahmad.Okde
 *
 * Created on May 9, 2020, 2:07 PM
 */

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

// Remove punctuation from left end of a word
string& ltrim(string& str, const string& chars = "\t\n\v\f\r.,:;?!-() ")
{
    str.erase(0, str.find_first_not_of(chars));
    return str;
}
 
// Remove punctuation from left end of a word
string& rtrim(string& str, const string& chars = "\t\n\v\f\r.,:;?!-() ")
{
    str.erase(str.find_last_not_of(chars) + 1);
    return str;
}
 
// Remove punctuation from left and right ends of a word
string& trim(string& str, const string& chars = "\t\n\v\f\r.,:;?!-() ")
{
    return ltrim(rtrim(str, chars), chars);
}

//contsant for program
const int MAX = 1000;
const char INPUT_FILENAME[] = "doi.dat";
const char OUTPUT_FILENAME[] = "wordCount.txt";

//function prototypes
int readWords(ifstream &fin, string words[], int word_count[], int &total_words);
int searchWord(string words[], int unique_words, string word);
void sortWords(string words[], int word_count[], int unique_words);
void displayOutput(string words[], int word_count[], int total_words, int unique_words);
void writeOutput(string words[], int word_count[], int total_words, int unique_words);

//main start
int main()
{
	//array to hold words
	string words[MAX];
	int unique_words = 0; //total unique words
	int total_words = 0; //total words in file

	//array to hold word count for each word
	int word_count[MAX]; 

	//open file
	ifstream fin;
	fin.open(INPUT_FILENAME);

	//if file does not exists
	if (!fin)
	{
		cout << "File not found";
		return 1;
	}
	//call function to read words
	unique_words = readWords(fin, words, word_count, total_words);
	//close file
	fin.close();

	//call function to sort words
	sortWords(words, word_count, unique_words);


	//call function to display output
	displayOutput(words, word_count, total_words, unique_words);

	//call function to write output to file wordCount.txt
	writeOutput(words, word_count, total_words, unique_words);
	cout << "End of Programming Assignment 7" << endl;
	return 0;
}

//function to read words from file and count total words in file, total unique words and word count fo each word
int readWords(ifstream &fin, string words[], int word_count[], int &total_words)
{
	string word;
	int unique_words = 0;
	int index;
	//read a word from file
	while (fin >> word)
	{
		//increment total words
		total_words++;
		word = trim(word);
		//check if word has already been read from file in array
		index = searchWord(words, unique_words, word);
		// if no
		if (index == -1) //not found
		{
			//store word in array
			words[unique_words] = word;
			word_count[unique_words] = 1;
			unique_words++;
		}
		//if found
		else
		{
			//increment word counter
			word_count[index] += 1;
		}
	}
	return unique_words;
}

int searchWord(string words[], int unique_words, string word)
{
	for (int i=0; i<unique_words; i++)
	{
		if (words[i] == word)
			return i;
	}
	return -1;
}

//function to sort words in the array and their word count using bubble sort
void sortWords(string words[], int word_count[], int unique_words)
{
    for (int i = 0; i < unique_words-1; i++)      
	{
		for (int j = 0; j < unique_words-i-1; j++)  
		{
			if (words[j] > words[j+1])  
			{
				string temp = words[j];
				words[j] = words[j+1];
				words[j+1] = temp;

				int t = word_count[j];
				word_count[j] = word_count[j+1];
				word_count[j+1] = t;
			}
		}
	}
}

//function to display output to console
void displayOutput(string words[], int word_count[], int total_words, int unique_words)
{
	cout << total_words << " total words and " << unique_words << " unique words read. " <<  endl;
	for (int i=0; i<unique_words; i++)
	{
		cout << setw(15) << left << words[i] << setw(5) << word_count[i] << endl;
	}
}

//function to write output to file
void writeOutput(string words[], int word_count[], int total_words, int unique_words)
{
	ofstream fout;
	fout.open(OUTPUT_FILENAME);
	fout << total_words << " total words and " << unique_words << " unique words read. " <<  endl;
	for (int i=0; i<unique_words; i++)
	{
		fout << setw(15) << left << words[i] << setw(5) << word_count[i] << endl;
	}
	fout.close();
}

