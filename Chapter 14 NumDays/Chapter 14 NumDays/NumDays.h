/*******************************************************************************************
										Kalé Williams
									NumDays Chapter 14

	This class stores a value that represents a number of work hours and 
	converts it to a number of days. It has a constructor that accepts a 
	number of hours, as well as member functions for storing and retrieving 
	the hours and days. It also hasthe following overloaded operators.

	
+	Addition operator. When two NumDays objects are added together, the 
	overloaded + operator should return the sum of th two objects' hours members.

-	Subtraction operator. When one NumDays object is subtracted from 
	another, the overloaded - operator should return the difference of 
	the two objects's hours members.

++	Prefix and postfix increment operators. These operator should increment 
	the number of hours stored in the object. When incremented, the number of 
	days should be automatically recalculated.

--	Prefix and postfix decrement operators. these operators should decrement 
	the number of hours stored in the object. When decremented, the number of 
	days shold be automatically recalculated.
***********************************************************************************************/

#pragma once
#include <iostream>
using namespace std;

const int WORK_DAY_HRS = 8;

class NumDays
{
private:
	double hours;

public:						// Using inline definitions 

	// constructor
	NumDays(double hrs)
	{
		hours = hrs;
	}
							//mutator function

	// Set the hours
	void setHours(double hrs)
	{
		hours = hrs;
	}
							//accessor functions

	// Get the hours
	double getHours() const
	{
		return hours;
	}

	// Get the amount of 8 hr work days
	double getDays() const
	{
		return hours / WORK_DAY_HRS;
	}

						// Operator functions                                                

	// Overloaded operater to add two NumDays objects
	double operator+(const NumDays & right)
	{
		return hours + right.hours;
	}

	// Overloaded operater to subtract two NumDays objects
	double operator-(const NumDays &right)
	{
		return hours - right.hours;
	}
	// Increment a NumDays object in prefix mode
	double operator++()
	{
		return ++hours;
	}
	
	// Increment a NumDays object in postfix mode
	double operator++(int)
	{
		return hours++;
	}
	// Decrement a NumDays object in prefix mode
	double operator--()
	{
		return --hours;
	}
	// Decrement a NumDays object in postfix mode
	double operator--(int)
	{
		return hours--;
	}
};