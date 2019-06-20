/*****************************************************
				Kalé Williams
			Chapter 13 "Payroll"
	This is the implementation file for the 
	Payroll class. It includes a default 
	constructor to set values as well as
	accessor and mutator functions

******************************************************/

#include "Payroll.h"
#include <iostream>
using namespace std;

// Default constructor to
//initialize values
Payroll::Payroll()
{
	empId = 0;
	numHoursWorked = 0.0;
	payRate = 0.0;
	weeklyPay = 0.0;
}

// Mutator functions

// Set the employee id number
void Payroll::setEmpId(int id)
{
	empId = id;
}

// Set the number of hours worked
void Payroll::setNumHours(float hrs)
{
	numHoursWorked = hrs;
}

// Set the hourly pay rate
void Payroll::setPayRate(double pay)
{
	payRate = pay;
}

// Accessor functions


// Return the employee id
int Payroll::getEmpId() const
{
	return empId;
}

// Return the number of hours worked
float Payroll::getNumHours() const
{
	return numHoursWorked;
}

// Return the hourly pay rate
double Payroll::getPayRate() const
{
	return payRate;
}

// Return the total weekly pay
double Payroll::getWeeklyPay() const
{
	return payRate * numHoursWorked;
}
