/***************************************************************
			Kalé Williams
			Chapter 15 part 1

	The Employee class defines an object which includes
	an employee name, an employee ID number and the 
	employee's hire date. The class includes mutator and
	accessor functions for setting and getting each of 
	the object attributes.

***************************************************************/

#pragma once
#include <string>
using namespace std;


class Employee
{
private:
	string empName;		// Employee name
	int empNumber;		// Employee id number
	string hireDate;	// Employee hire date

public:
	// Default constructor
	Employee()
	{
		empName = " ";
		empNumber = 0;
		hireDate = " ";
	}

	// Constructor
	Employee(string name, int num, string date)
	{
		empName = name;
		empNumber = num;
		hireDate = date;
	}

	// Mutator functions
	void setName(string name)
	{
		empName = name;
	}

	void setEmpNum(int num)
	{
		empNumber = num;
	}

	void setHireDate(string date)
	{
		hireDate = date;
	}

	// Accessor functions
	string getName() const
	{
		return empName;
	}

	int getEmpNum() const
	{
		return empNumber;
	}

	string getHireDate()
	{
		return hireDate;
	}
};


