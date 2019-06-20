/***************************************************************
			Kalé Williams
			Chapter 15 part 1

	The ProductionWorker class is derived from the Employee
	class. It extends the Employee class by adding the 
	shift and hourlyPay variables. It includes mutator and
	accessor functions for the new variables.

***************************************************************/

#pragma once
#include "Employee.h"
using namespace std;

// ProductionWorker is derived from Employee
class ProductionWorker : public Employee
{
private:
	int shift;			// To hold the shift
	double hourlyPay;	// To hold the hourly pay rate

public:
	// Default constructor
	ProductionWorker() : Employee()
	{
		shift = 0;
		hourlyPay = 0.0;
	}

	// Constructor which sends the name, num, and date to the base class
	ProductionWorker(string name, int num, string date, int shf, double pay)
		: Employee(name, num, date)
	{
		shift = shf;
		hourlyPay = pay;
	}
	// Mutator functions
	void setShift(int shf)
	{
		shift = shf;
	}
	
	void setHourlyPay(double pay)
	{
		hourlyPay = pay;
	}
	
	//Accessor functions
	int getShift() const
	{
		return shift;
	}

	double getHourlyPay() const
	{
		return hourlyPay;
	}
};
