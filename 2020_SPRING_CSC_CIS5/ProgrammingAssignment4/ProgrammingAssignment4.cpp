/*
 * Describe assignment here.
 */

/*
 * File:   ProgrammingAssignment4.cpp
 * Author: <your name here>
 *
 * Created on March 24, 2020
 */
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    const double STUDENT_DISCOUNT = 0.20;
    const double RETIREE_DISCOUNT = 0.10;
    const double NORMAL_DISCOUNT = 0.00;
    const double DEFAULT_DISCOUNT = 0.00;

    // Usage parameters
    const double BASE_GIGABYTES = 1.0; // Base GB
    const double BASE_RATE = 12.00; // Cost for <= Base GB
    const double OVER_RATE = 10.00; // Cost for >  Base GB

    // Discount codes
    const char STUDENT_CODE = 'S'; // Code for Student
    const char RETIREE_CODE = 'R'; // Code for Retiree
    const char NORMAL_CODE = 'N'; // Code for Normal Customer

    const string SENTINEL_VAL = "000000"; // Ends program


    // Data entered by customer
    string customerNumber = ""; // 6-Digit customer number
    char customerStatus = ' '; // Single character customer status
    double customerUsage = 0.00; // Number of GB used

    // Amounts inferred or calculated
    double discount = 0.00; // Will be set to appropriate discount
    double amountBilled = 0.00; // Holds amount billed

    int total_normal_customer = 0;
    int total_retiree_customer = 0;
    int total_student_customer = 0;

    double total_amount = 0;

    // set up output precision
    cout << fixed << setprecision(2) << showpoint;

    // INPUT SECTION - Get data from user
    // Get intial customer inumber
    cout << "\nEnter 6-digit customer number: ";
    cin >> customerNumber;

    // Loop until customer number sentinel is encountered
    while (customerNumber!=SENTINEL_VAL)
    {
        // Echo Customer Number
        //cout << "Customer number:" << customerNumber << endl;

        // Select discount based on customer status
        cout << "Enter customer status normal (N), student (S) or retiree (R): ";
        cin >> customerStatus;

        // Echo Customer Status
        //cout << "Customer status: " << customerStatus << endl;


        // Get usage statistics (gigabytes)
        cout << "Enter customer usage in gigabytes: ";
        cin >> customerUsage;

        // Echo amount of data used
        //cout << "Gigabytes used:" << customerUsage << endl;


        // PROCESSING SECTION - Calculate amount billed
        // Convert customer status to upper case.
        customerStatus = toupper(customerStatus);

        // Set discount based on customer status
        if (customerStatus == NORMAL_CODE) // Normal customer
        {
            discount = NORMAL_DISCOUNT;
            total_normal_customer++;
        }
        else if (customerStatus == RETIREE_CODE) // Retiree  customer
        {
            discount = RETIREE_DISCOUNT;
            total_retiree_customer++;
        }
        else if (customerStatus == STUDENT_CODE) // Student customer
        {
            discount = STUDENT_DISCOUNT;
            total_student_customer++;
        }

        else {
            cout << "Invalid customer status: " << customerStatus << endl;
            discount = DEFAULT_DISCOUNT;
        }

        // Perform billing calculation
        //amountBilled = BASE_RATE;
        //if (customerUsage > BASE_GIGABYTES)
           // amountBilled = amountBilled + OVER_RATE * (1.0 - discount);

        if (customerUsage>BASE_GIGABYTES) {
			amountBilled = (customerUsage - 1) * OVER_RATE; //over 1 gb amount
			amountBilled = amountBilled - (discount/100.0); //apply discount over 1gb
			amountBilled = amountBilled + (BASE_RATE) ; //total amount
		}else {
			amountBilled =   (customerUsage * BASE_RATE);
		}

        total_amount = total_amount + amountBilled;
        // OUTPUT SECTION - output customer report

        // Output Billing Report
        cout << "\n";
        cout << setw(20) << left << "Customer number:" << " " << setw(6) << right << customerNumber << endl;
        cout << setw(20) << left << "Customer status:" << " " << setw(6) << right << customerStatus << endl;
        cout << setw(20) << left << "Discount (percent):" << " " << setw(6) << right << discount * 100.0 << endl;
        cout << setw(20) << left << "Gigabytes used:" << " " << setw(6) << right << customerUsage << endl;
        cout << setw(20) << left << "Amount:" << "$" << setw(6) << right << amountBilled << endl;

        // INPUT SECTION - Get data from user
        // Get intial customer inumber
        cout << "\nEnter 6-digit customer number: ";
        cin >> customerNumber;

    }

    cout << setw(25) << left << "Total Student Customers:" << setw(11) << right << total_student_customer << endl;
    cout << setw(25) << left << "Total Retiree Customers:" << setw(11) << right << total_retiree_customer << endl;
    cout << setw(25) << left << "Total Normal Customers:" << setw(11) << right << total_normal_customer << endl;
    cout << setw(25) << left << "Total Amount: " <<  "$" << setw(10) << setprecision(2) << fixed << right << total_amount << endl;


    cout << "\nExiting program.\n";

    return 0;

}
