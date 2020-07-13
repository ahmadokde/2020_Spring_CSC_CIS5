/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   lab_exercise_5a.cpp
 * Author: Ahmad.Okde
 *
 * Created on March 26, 2020, 8:00 PM
 */

#include <iostream>
using namespace std;

int main()
{
	//const int n = 2000000;
	int n = 0;
	//2. Use a loop counter, k, that starts at 0 and loops as long as the counter is less than n.
	int k = 0;

	double sum = 0;
	//1. Write a program that contains a while loop that will loop n times. (n is a constant in the program).
	//You must use the while loop’s condition to terminate the loop.

	while (abs(sum)<= 0.000001)
	{
		//3. Inside the loop calculate the following sum:
		int num = (4*k+1)*(4*k+3);
		sum = sum + (1/(num*1.0));
		k++;
		n++;
	}
	sum = sum * 8;

	cout << "Sum = " << sum << endl;
	cout << "Iterations: " << n << endl;
	//system("pause");
	return 0;
}


/*Challenge: Calculate this number without knowing n. (i.e., with k unbound).
Set the loop condition to stop the loop when 5 digits of precision have been obtained.
Display how many iterations it ran and the number obtained.*/
