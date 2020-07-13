/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Programming_Assignment_3.cpp
 * Author: Ahmad.Okde
 *
 * Created on March 15, 2020, 9:13 PM
 */

#include <iostream>
#include<string.h>
#include<iomanip>
using namespace std;
int main( )

{
	
	//Base rate is $12.00 and includes up to 1 gigabyte of data.
    const double BASE_RATE = 12.00;
    //Anything over 1 gigabyte is an additional $10.00.
    const double ADD_DATA_RATE = 10.00;
    //Normal customers get no discount.
	//Students get a 20% discount on data over 1 gigabyte.
    const double STUDENT_DISC = 20.00;
    //Retirees get a 10% discount on data over 1 gigabyte.
    const double RETIREE_DISC = 10.00;
    
    string cust_num;
    char status;
    double num_gigs;
    double amount;
    double disc = 0;
 
	//a simple "while (true)" loop around the code , 
	while (true) {
		cout<<"Enter six character customer number (Enter \"000000\" to exit): ";
		cin >>cust_num;
		if("000000" == cust_num) {
			//break out of the loop if the customer number is "000000"
			break;
		}
		cout<<"Enter a single character customer status of 'N'/'n' (normal), 'S'/'s' (student), 'R'/'r' (retired): ";
		cin>>status;
		cout<<"Enter number of gigabytes used up to 2 decimal places: ";
		cin>>num_gigs;
		
		cout<<setw(20)<<"Customer number"<<":"<<setw(11)<<cust_num<<endl;
		cout<<setw(20)<<"Customer status"<<":"<<setw(6)<<status<<endl;
		
		if(status == 'S' || status == 's' ) {
			disc = STUDENT_DISC;
		}else if(status == 'R' || status == 'r' ) {
			disc = RETIREE_DISC;
		}else if(status == 'N' || status == 'n' ) {
			disc = 0;
		}
		if(disc>0)
		cout<<setw(20)<<"Discount (percent)"<<":"<<setw(10)<<setprecision(2)<<fixed<<disc<<endl;
		else
		cout<<setw(20)<<"Discount (percent)"<<":"<<setw(9)<<setprecision(2)<<fixed<<disc<<endl;
		cout<<setw(20)<<"Gigabytes used"<<":"<<setw(9)<<setprecision(2)<<fixed<<num_gigs<<endl;
		 
		if (num_gigs>1) {
			amount = (num_gigs - 1) * ADD_DATA_RATE; //over 1 gb amount
			amount = amount - (disc/100.0); //apply discount over 1gb
			amount = amount + (BASE_RATE) ; //total amount
		}else {
			amount =   (num_gigs * BASE_RATE);
		}
		cout<<setw(20)<<"Amount"<<":"<<setw(6)<<"$"<<setprecision(2)<<fixed<<amount<<endl;
		 
	}
     return 0;
    
}