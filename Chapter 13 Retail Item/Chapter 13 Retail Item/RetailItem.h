//#pragma once
/**********************************************************
				Kalé Williams
		Chapter 13 P 803 #5 "Retail Item Class"
	
	This is the specification file for the RetailItem 
	class. This file declares the member variables
	and functions of the RetailItem class

***********************************************************/
#ifndef	RETAILITEM_H
#define RETAILITEM_H
#include <string>
using namespace std;

//Begin class declaration
class RetailItem
{
	//private member variables
private:
	string description;		//For the item description
	int unitsOnHand;		//For the units on hand
	double price;			//For the price of each item

	//public functions
public:
	//Declare a constructor that accepts arguments
	//for each of the member variables
	RetailItem(string, int, double); 

	//Mutator functions
	void setDescription(string);
	void setUnitsOnHand(int);
	void setPrice(double);

	//Accessor functions
	string getDescription() const;
	int getUnits() const;
	double getPrice() const;
	
};
#endif