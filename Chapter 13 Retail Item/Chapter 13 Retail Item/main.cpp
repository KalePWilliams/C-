/**********************************************************
				Kalé Williams
		Chapter 13 P 803 #5 "Retail Item Class"

	This program uses a class called RetailItem. It
	creates three instances of the class and then
	prints out the results

***********************************************************/

#include <iostream>
#include "RetailItem.h"
using namespace std;

int main()
{
	string descrip;			//to hold the item description
	int unitsOnHand;		//to hold the number of units
	double price;			//to hold the item price

	//data for the first RetailItem
	descrip = "Jacket";
	unitsOnHand = 12;
	price = 59.95;
	
	//Create the first RetailItem object
	RetailItem item1(descrip, unitsOnHand, price);

	//data for the second RetailItem
	descrip = "Designer Jeans";
	unitsOnHand = 40;
	price = 34.95;

	//Create the second RetailItem object
	RetailItem item2(descrip, unitsOnHand, price);

	//data for the third RetailItem
	descrip = "Shirt";
	unitsOnHand = 20;
	price = 24.95;

	//Create the third RetailItem object
	RetailItem item3(descrip, unitsOnHand, price);

	//Print the data for the first RetailItem object
	cout << "Here is the information for the retail items\n";
	cout << "Description: " << item1.getDescription() << endl;
	cout << "Units on hand: "<< item1.getUnits() << endl;
	cout << "Price: $"<< item1.getPrice() << endl << endl;

	//Print the data for the second RetailItem object
	cout << "Description: " << item2.getDescription() << endl;
	cout << "Units on hand: " << item2.getUnits() << endl;
	cout << "Price: $" << item2.getPrice() << endl << endl;

	//Print the data for the third RetailItem object
	cout << "Description: " << item3.getDescription() << endl;
	cout << "Units on hand: " << item3.getUnits() << endl;
	cout << "Price: $" << item3.getPrice() << endl << endl;

	return 0;
}