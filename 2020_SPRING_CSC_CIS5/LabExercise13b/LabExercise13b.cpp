/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LabExercise13b.cpp
 * Author: Ahmad.Okde
 *
 * Created on May 28, 2020, 8:09 PM
 */
#include "Date.h"

int main()
{
	Date d1;
	d1.setDay(28);
	d1.setMonth(5);
	d1.setYear(2020);
	cout << d1.getMDY() << endl;
	cout << d1.getYear() << "-" << d1.getMonth() << "-" << d1.getDay() << endl;
	cout << "Is leap year: " << d1.leapYear() << endl;
	cout << d1.getMnDY() << endl;
	return 0;
}
