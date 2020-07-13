/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   lab_assignment_4.cpp
 * Author: Ahmad.Okde
 *
 * Created on March 14, 2020, 6:36 AM
 */


#include <iostream>

using namespace std;

int main()
{
    int cus_number,dis_per;
    char cus_status;
    float dis_amount,giga,amount;
    while(true){
        cout<<"Please enter customer number:";
        cin>>cus_number;
        if(cus_number == 000000){
            break;
        }
        cout<<"\nPlease enter customer status:";
        cin>>cus_status;
        cout<<"\nPlease enter gigabytes used:";
        cin>>giga;
        if(giga > 1){
            if((cus_status == 'n')||(cus_status == 'N')){
                dis_amount = 0.00;
                amount = 12.00 + 10.00;
            }else if((cus_status == 's')||(cus_status == 'S')){
                dis_amount = 10.00 * (20.00/100.00);
                amount = 12.00 + (10.00 - dis_amount);
            }else if((cus_status == 'r')||(cus_status == 'R')){
                dis_amount = 10.00 * (10.00/100.00);
                amount = 12.00 + (10.00 - dis_amount);
            }

        }else{
            dis_amount = 0.00;
            amount = 12.00;
        }

        cout<<"Customer number:     \t"<<cus_number;
        cout<<"\nCustomer status:   \t"<<cus_status;
        cout<<"\nDiscount (percent):\t"<<dis_amount;
        cout<<"\nGigabytes used:    \t"<<giga;
        cout<<"\nAmount:            \t$"<<amount<<"\n";
    }
    return 0;
}


