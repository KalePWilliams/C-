/********************************************************************
				Kalé Williams
			Chapter 13 "Payroll"
	This program uses the Payroll class to
	create a array of seven Payroll objects.
	It prompts the user to input the amount
	of hours worked by each employee and will
	then display the weekly gross pay for each.

********************************************************************/


#include "Payroll.h"
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int employeeId;				//to hold the employee id
	float hoursWorked;			//for each employee's weekly hours worked
	double payRate;				//to hold the hourly rate of pay
	const int SIZE = 7;			//constant for size of array
	Payroll employee[SIZE];		//create the array of Payroll objects

	// Loop to get user input for hours and
	// set values for each Payroll object
	for (int i = 0; i < SIZE; i++)
	{
		employeeId = i + 1;
		//set the employee id
		employee[i].setEmpId(employeeId);

		//Loop will not allow more than 60 hrs
		//for hoursWorked
		do
		{
			cout << "Please enter the number of hours worked by employee ";
			cout << employee[i].getEmpId();
			cout << "\n(No more than 60 hours)";
			cin >> hoursWorked;
			cout << endl;
		} while (hoursWorked > 60);

		//set the hours worked
		employee[i].setNumHours(hoursWorked);
		payRate = 45.00;
		//set the hourly pay rate
		employee[i].setPayRate(payRate);
	}

	// Print out the employee information
	cout << "\n***Here is the information for the employees:*** \n";
	cout << endl;
	cout << setw(5) << "ID"
		<< setw(15) << "Hours worked"
		<< setw(11) << "Pay Rate"
		<< setw(14) << "Weekly Pay" << endl;
	cout << "_______________________________________________________\n";

	// Loop to print each employee Payroll object
	for (int i = 0; i < SIZE; i++)
	{
		cout << setw(5) << employee[i].getEmpId();
		cout << fixed << showpoint << setprecision(2);
		cout << setw(15) << employee[i].getNumHours();
		cout << setw(11) << employee[i].getPayRate();
		cout << setw(14) << employee[i].getWeeklyPay() <<endl;
	}

	return 0;
}