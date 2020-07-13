/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Date.h
 * Author: Ahmad.Okde
 *
 * Created on May 28, 2020, 8:10 PM
 */
#include <iostream>
#include <string>
using namespace std;

#ifndef DATE_H
#define DATE_H

class Date
{
	//private members
private:
	int month, day, year;
//public members
public:
	Date(); //constructor
	//setters
	void setMonth(int m);
	void setDay(int d);
	void setYear(int y);
	//getters
	int getMonth() const;
	int getDay() const;
	int getYear() const;
	//member functions
	bool leapYear() const;
	string getMDY();
	string getMnDY();	//challenge
};

#endif /* DATE_H */

