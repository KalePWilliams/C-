/***************************************************************
			Kalé Williams
			Chapter 15 part 1

	This program tests the ProductionWorker class which
	is a derived class from the base class of Employee.
	It creates one ProductionWorker object and then prints
	the data for that object.

***************************************************************/

#include <iomanip>
#include <iostream>
#include "ProductionWorker.h"
using namespace std;

int main()
{
	// Create a ProductionWorker object (default constructors are called)
	ProductionWorker firstWorker;


	// Give values to each variable to test the set functions

	string name = "Harvey Phillips";	// firstWorker object name
	int num = 239;						// firstWorker object employee number
	string date = "12/12/2017";			// firstWorker object hire date
	int shf = 2;						// firstWorker object shift
	double pay = 39.86;					// firstWorker object pay rate
	
	// Test mutator functions
	firstWorker.setName(name);
	firstWorker.setEmpNum(num);
	firstWorker.setHireDate(date);
	firstWorker.setShift(shf);
	firstWorker.setHourlyPay(pay);
	

	// Test all of the accessor functions with cout statements
	cout << "The information for the first worker is: \n";
	cout << "_____________________________________________\n";
	cout << left << setw(12) << "Name" << ": ";
	cout << firstWorker.getName() << endl;
	cout << left << setw(12) << "Employee ID" << ": ";
	cout << firstWorker.getEmpNum() << endl;
	cout << left << setw(12) << "Date hired" << ": ";
	cout << firstWorker.getHireDate() << endl;
	cout << left << setw(12) << "Shift " << ": ";
	cout << firstWorker.getShift() << endl;
	cout << left << setw(12) << "Hourly pay" << ": " << "$";
	cout << setprecision(2) << fixed << firstWorker.getHourlyPay() << endl;


	return 0;
}