/****************************************************
				Kalé Williams
			Chapter 13 "Payroll"
	This is the specification file for
	the Payroll class. 

*****************************************************/
//#pragma once
#ifndef PAYROLL_H
#define PAYROLL_H

using namespace std;

class Payroll
{
private:

	int empId;				//for employee id number
	float numHoursWorked;	//for weekly hours worked
	double payRate;			//to hold employee hourly pay rate
	double weeklyPay;		//for employee total weekly pay

public:
	Payroll();		//constructor

					//Mutator functions

	// Set the employee id number
	void setEmpId(int id);
	// Set the number of hours worked
	void setNumHours(float hrs);
	// Set the hourly pay rate
	void setPayRate(double pay);

					//Accessor functions

	// Return the employee id
	int getEmpId() const;
	// Return the number of hours worked
	float getNumHours() const;
	// Return the hourly pay rate
	double getPayRate() const;
	// Return the total weekly pay
	double getWeeklyPay() const;

};
#endif
