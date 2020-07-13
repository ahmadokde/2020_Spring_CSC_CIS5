/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Lab_exercise_home.cpp
 * Author: Ahmad.Okde
 *
 * Created on February 27, 2020, 10:21 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
int people;
float bill, tip, percentage, owe;
cout << "how much is the bill? ";
cin >> bill;
cout << "how many people will be splitting the bill? ";
cin >> people;
cout << "what is the percentage of the tip? ";
cin >> tip;

percentage= bill * (tip/100.) ;
owe = (percentage + bill)/people;

cout << endl;
cout << "the percentage at " << tip << "% is $" << percentage << '.' << endl;
cout << "each person will pay $" << owe << '.' << endl;
    return 0;
}

