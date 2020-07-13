/*
 * Describe assignment here.
 */

/*
 * File:   ProgrammingAssignment5.cpp
 * Author: ahmad okde
 *
 * Created on March 24, 2020
 */
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

 double calculateDiscount(char = 'N');
  double calculateAmount(double = 0.0, double = 0.0);

int main() {
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

	/*
	1. Ask the user for the input file name (customerData.dat) and the output file name  (BACBilling.txt). 
    a. Declare input and output stream objects and then open both files.
    b. If either file fails to open, display a message and ask the operator to re-enter the file name.
	*/
	string inputfilename;
	string outputfilename;

	ifstream fin;
	ofstream fout;

	cout << "Enter input file name: ";
	cin >> inputfilename;

	fin.open(inputfilename.c_str());
	while (!fin)
	{
		cout << "ERROR: File not open. Try again.\n\n";
		cout << "Enter input file name: ";
		cin >> inputfilename;
		fin.open(inputfilename.c_str());
	}


	cout << "Enter output file name: ";
	cin >> outputfilename;

	fout.open(outputfilename.c_str());
	while (!fin)
	{
		cout << "ERROR: File not open. Try again.\n\n";
		cout << "Enter output file name: ";
		cin >> outputfilename;
		fout.open(outputfilename.c_str());
	}

	 fout << fixed << setprecision(2) << showpoint;

	 // Get intial customer inumber
	while (fin >> customerNumber)
	{
		fin >> customerStatus;
		fin >> customerUsage;
		discount = calculateDiscount(customerStatus);
		 // Set discount based on customer status
        if (customerStatus == NORMAL_CODE) // Normal customer
        {
            total_normal_customer++;
        }
        else if (customerStatus == RETIREE_CODE) // Retiree  customer
        {
            total_retiree_customer++;
        }
        else if (customerStatus == STUDENT_CODE) // Student customer
        {
            total_student_customer++;
        }

		amountBilled = calculateAmount(customerUsage, discount);

		total_amount = total_amount + amountBilled;

		 // Output Billing Report
        fout << "\n";
        fout << setw(20) << left << "Customer number:" << " " << setw(6) << right << customerNumber << endl;
        fout << setw(20) << left << "Customer status:" << " " << setw(6) << right << customerStatus << endl;
        fout << setw(20) << left << "Discount (percent):" << " " << setw(6) << right << discount * 100.0 << endl;
        fout << setw(20) << left << "Gigabytes used:" << " " << setw(6) << right << customerUsage << endl;
        fout << setw(20) << left << "Amount:" << "$" << setw(6) << right << amountBilled << endl;
	}

  


	fout << endl;
    fout << setw(25) << left << "Total Student Customers:" << setw(11) << right << total_student_customer << endl;
    fout << setw(25) << left << "Total Retiree Customers:" << setw(11) << right << total_retiree_customer << endl;
    fout << setw(25) << left << "Total Normal Customers:" << setw(11) << right << total_normal_customer << endl;
    fout << setw(25) << left << "Total Amount: " <<  "$" << setw(10) << setprecision(2) << fixed << right << total_amount << endl;

	//close files
	fin.close();
	fout.close();
    fout << "\nExiting program.\n";

    return 0;

}

/*3. Write a function that, when given the customer status, returns the appropriate discount. The prototype is:
   double calculateDiscount(char = 'N');*/

 double calculateDiscount(char status)
 {
	 if (status == 'S')
		 return 0.20;
	 if (status == 'R')
		 return .10;
	 return 0.0;
 }

 /*4. Write a function that , when given the GB usage and the discount, returns the amount of the bill. The prototype is:
   double calculateAmount(double = 0.0, double = 0.0);*/
  double calculateAmount(double customerUsage, double discount)
  {
	   // Usage parameters
    const double BASE_GIGABYTES = 1.0; // Base GB
    const double BASE_RATE = 12.00; // Cost for <= Base GB
    const double OVER_RATE = 10.00; // Cost for >  Base GB
	  double amountBilled;
	  
	  if (customerUsage>BASE_GIGABYTES) {
			amountBilled = (customerUsage - 1) * OVER_RATE; //over 1 gb amount
			amountBilled = amountBilled - (discount/100.0); //apply discount over 1gb
			amountBilled = amountBilled + (BASE_RATE) ; //total amount
		}else {
			amountBilled =   (customerUsage * BASE_RATE);
		}
	  return amountBilled;
  }