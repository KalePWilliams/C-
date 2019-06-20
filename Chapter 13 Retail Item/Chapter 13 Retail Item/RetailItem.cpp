/**********************************************************
				Kalé Williams
		Chapter 13 P 803 #5 "Retail Item Class"

	This is the implementation file for the RetailItem
	class. This file defines the constructor, Mutator 
	and accessor functions for the RetailItem class.

***********************************************************/

//Implementation file for RetailItem class
#include "RetailItem.h"
#include <iostream>
#include <string>
using namespace std;

//constructor
RetailItem::RetailItem(string desc, int units, double cost)
{
	description = desc;			//Short description of the item
	unitsOnHand = units;		//Number of units on hand for any given item
	price = cost;				//Cost of an item
}
				//Mutator functions

//set the description
void RetailItem::setDescription(string desc)
{
	description = desc;
}

//set the number of units on hand
void RetailItem::setUnitsOnHand(int units)
{
	unitsOnHand = units;
}

//set the retail price
void RetailItem::setPrice(double cost)
{
	price = cost;
}
				//Accessor functions
//get the description
string RetailItem::getDescription() const
{
	return description;
}

//get the number of units on hand
int RetailItem::getUnits() const
{
	return unitsOnHand;
}

//get the price of the item
double RetailItem::getPrice() const
{
	return price;
}