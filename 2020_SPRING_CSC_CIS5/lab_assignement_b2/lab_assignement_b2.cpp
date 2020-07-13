/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   lab_assignement_b2.cpp
 * Author: Ahmad.Okde
 *
 * Created on March 2, 2020, 4:49 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) 
{
    float PI, radius, area, circumference, diameter, sphere,volsp;
    PI = 3.14159;
    // Printing Value Of radius of the circle
    cout << "enter the radius of the circle"<< endl;
    cin >> radius;
    // printing value of the diameter
    cout << "please input the value of the diameter? ";
    cin >> diameter;
    // printing value of the circumference
    cout << "please input the value of the circumference ? ";
    cin >> circumference;
    // printing value of the area
    cout << "please input the value of the area? ";
    cin >> area;
    // Printing Value Of Volume of the sphere
    cout <<  "please input the radius of the sphere ? ";
    cin >> sphere;
    
    diameter = 2 * radius;
    area = PI * (radius*radius);
    circumference = 2 * PI* radius;
    volsp = (4*PI*radius*radius*radius)/3;
    cout << "the volume of the sphere is ? " << volsp << endl;
    return 0;
}

