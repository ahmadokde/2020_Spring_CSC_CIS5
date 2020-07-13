/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Date.cpp
 * Author: Ahmad.Okde
 * 
 * Created on May 28, 2020, 8:10 PM
 */

#include "Date.h"

Date::Date()
{
	//Set the initial date to January 1, 1900.
	day = 1;
	month = 1;
	year = 1900;
}
//setMonth  sets the integer month, but ignores values <1 or > 12.
void Date::setMonth(int m)
{
	if (month >=1 && month<=12)
		month = m;
}
//setDay sets the integer day, but ignores values <0 or >31.
void Date::setDay(int d)
{
	//ignores values <0 or >31.
	if (day>0 && day<=31)
		day = d;
}
//setYear sets the integer year.
void Date::setYear(int y)
{
	year = y;
}
//getMonth returns the integer month.
int Date::getMonth() const
{
	return month;
}
//getDay returns the integer day .
int Date::getDay()const
{ 
	return day;
}
//getYear returns the integer year.
int Date::getYear() const
{
	return year;
}
//leapYear returns 'true' if the year is a leap year.
bool Date::leapYear() const
{
	return (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
}
//getMDY returns the date as a string formatted like this:  "5/28/2020" (See Hints)
string Date::getMDY()
{
	return to_string(month) + "/" + to_string(day) + "/" + to_string(year);
}

//challenge
//Add function getMnDY that returns name of month with day and year as a string, e.g., "May 28, 2020".
string Date::getMnDY()
{
	string months[] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
	return months[month - 1] + " " + to_string(day) +  ", " + to_string(year);
}

