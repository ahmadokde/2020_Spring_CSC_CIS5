#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;


/*
 * Prototype for function 'factorial' - given an integer n, returns n!
 */
long int factorial(int);


/*
 * Prototype for function 'largest' - returns largest of two numbers
 */
long int largest(long int, long int);

long int factorial(int n)
{
	if (n<=1)
		return 1;

	return n * factorial(n-1);
}

long int largest(long int a, long int b)
{
	if (a>b)
		return a;
	return b;
}
/*
 *  Main Program
 */

int main(int argc, char** argv) {

  const auto MAX_NUMBER = 20;

  
  // Part 1

  // Calculate the factorials from 0 to MAX_MAXNUMBER
  cout << "The factorials from 0 to " << MAX_NUMBER << endl;
  for (int n = 0; n <= MAX_NUMBER; n++)
    /// Invoke the 'factorial' function to calculate n!
    cout << setw(2) << n << "! = " << setw(20) << factorial(n) << endl;

  
  // Part 2
  
  // Find the largest of MAX_NUMBER random numbers
  cout << setprecision(20) << right;
  cout << "\nLargest possible random number is : " << setw(12) << RAND_MAX << endl;

  srand(time(NULL)); // seed the random number generator
  
  long int large = 0, random = 0;
  for (int n = 1; n <= MAX_NUMBER; n++) {
    random = rand();
    cout << setw(2) << n << ": " << setw(12) << random << endl;
    /// Invoke the 'largest' function to return the larger of two values
    large = largest(large, random);
  }
  
  cout << "The largest of " << MAX_NUMBER << " random numbers generated is " << large << endl;


  return 0;

}



