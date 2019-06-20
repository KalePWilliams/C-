/****************************************************************
					Kale Williams
				Drink Machine Simulator

	This program simulates a soda vending machine. It
	starts by giving the user the choice between 5
	different kinds of soda or quitting the program.
	If a drink is chosen the user will be promted to
	input a payment amount and if payment exceeds the 
	amount due, the amount of change will be displayed.
	Each time a soda is chosen it will be removed from 
	inventory. If the user selects a soda with no more
	inventory left the program will output an error.
	The program will continue to loop to choose more
	drinks unless the user selects to quit. At the end
	the program will output the total amount of money
	it has earned.
*****************************************************************/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Structure declaration
struct Drink
{
	string name;		//To store each drink's name
	double drinkCost;	//To store each drink's cost
	int InventoryNum;	//How many of each drink the machine has
};


int main()
{
	const int SODA_TYPES = 5;//Constant for size of array
	Drink soda[SODA_TYPES] = //Drink structure array 
							 {{"Cola", .75, 20},
						 {"Root Beer", .75, 20},
						{"Lemon-Lime", .75, 20},
						{"Grape Soda", .80, 20},
						{"Cream Soda", .80, 20}};

	bool quit = false;		//flag to continue loop
	int selection;			//For the user selection of soda
	double payment;			//Money amount user inputs
	double totalEarned = 0;	//Accumulator for money earned on all sales
	double change = 0;		//Amount due back to user


	// Program will continue to loop until the user selects "quit"
	while (quit == false)
	{
		do
		{	// Menu to choose drink or quit
			cout << "Please select a drink or press 5 to quit \n";
			for (int i = 0; i < SODA_TYPES; i++)
			{
				cout << "Press " << i << " for ";
				cout << soda[i].name << endl;
			}
			cin >> selection;

			// If that selection is sold out repeat loop
			// and give an error
			if (soda[selection].InventoryNum == 0)
			{
				cout << "I'm sorry, that selection is sold \n";
				cout << "out. Please make another selection\n";
			}
		} while (soda[selection].InventoryNum == 0);

		
		// If a soda was chosen continue
		if (selection != 5)
		{
			// Confirm the soda chosen and display the price
			cout << "You chose " << soda[selection].name << endl;
			cout << fixed << showpoint << setprecision(2);
			cout << "It costs $" << soda[selection].drinkCost << endl;

			// Request payment and validate the amount of money put in
			do
			{
				cout << "Please type the amount of money you will enter (no more than a dollar): $";
				cin >> payment;
				cout << endl;
				if (payment < 0 || payment > 1 || payment < soda[selection].drinkCost)
					cout << "Please enter a valid payment amount \n";
			} while (payment < 0 || payment > 1 || payment < soda[selection].drinkCost);

			// Indicate if change is due and how much
			if (payment > soda[selection].drinkCost)
			{
				change = (payment - soda[selection].drinkCost);
				cout << fixed << showpoint << setprecision(2);
				cout << "Your change is $" << (payment - soda[selection].drinkCost) << endl;
			}
			// accumulate total money earned
			totalEarned += (payment - change);
			change = 0;

			// Subtract selected soda from inventory
			soda[selection].InventoryNum--;

		}
		else
			quit = true;

	}
	// Output the total money earned
	cout << fixed << showpoint << setprecision(2);
	cout << "This machine has earned a total amount of $" << totalEarned;
	return 0;
}