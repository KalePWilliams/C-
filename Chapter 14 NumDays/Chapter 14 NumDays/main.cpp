/*******************************************************************************************
										Kalé Williams
									NumDays Chapter 14

		This program tests the constructor and functions of the NumDays class
***********************************************************************************************/

#include "NumDays.h"
#include <iostream>
using namespace std;

int main()
{
	NumDays workWeek1(18.0);	// NumDays object to hold week1 hours
	NumDays workWeek2(6.0);		// NumDays object to hold week 2 hours
	double bothWorkWeeks;		// To hold sum or difference of both NumDays objects 

	// Test getHours and getDays functions
	cout << "Work week 1 information: \n";
	cout << "Hours: " << workWeek1.getHours() << endl;
	cout << "Days worked: " << workWeek1.getDays() << endl << endl;


	// Test prefix increment operator
	cout << "Adding 1 hour to work week 1 in prefix mode\n";
	++workWeek1;
	cout << "Now the updated work week 1 information: \n";

	// Show the updated days and hours functions
	cout << "Hours: " << workWeek1.getHours() << endl;
	cout << "Days worked: " << workWeek1.getDays() << endl << endl;

	// Test postfix increment operator
	cout << "Adding 1 hour to work week 1 in postfix mode\n";
	cout << "The hours currently are " << workWeek1++ << endl;

	// Show the updated days and hours functions
	cout << "Now the updated work week 1 information: \n";

	// Show the updated days and hours functions
	cout << "Hours: " << workWeek1.getHours() << endl;
	cout << "Days worked: " << workWeek1.getDays() << endl << endl;
	
	// Verify work week 2 information
	cout << "Work week 2 information: \n";
	cout << "Hours: " << workWeek2.getHours() << endl;
	cout << "Days worked: " << workWeek2.getDays() << endl << endl;

	// Test prefix decrement operator
	cout << "Subtracting 1 hour from work week 2 in prefix mode\n";
	--workWeek2;
	cout << "Now the updated work week 2 information: \n";

	// Show the updated days and hours functions
	cout << "Hours: " << workWeek2.getHours() << endl;
	cout << "Days worked: " << workWeek2.getDays() << endl << endl;

	// Test postfix decrement operator
	cout << "Subtracting 1 hour from work week 2 in postfix mode\n";
	cout << "The hours currently are " << workWeek2-- << endl;

	// Show the updated days and hours functions
	cout << "Now the updated work week 2 information: \n";
	cout << "Hours: " << workWeek2.getHours() << endl;
	cout << "Days worked: " << workWeek2.getDays() << endl << endl;

	// Test overloaded addition operator
	cout << "Now adding the two work weeks \n";
	bothWorkWeeks = workWeek1 + workWeek2;
	cout << "Total hours for both weeks is: ";
	cout << bothWorkWeeks << endl << endl;

	// Test overloaded subtraction operator
	cout << "Now subtracting week 2 from week 1: \n";
	bothWorkWeeks = workWeek1 - workWeek2;
	cout << "Total hours for both weeks now is: ";
	cout << bothWorkWeeks << endl;


	return 0;
}