/***********************************************************
					Kale Williams
		Chapter 8 Problem 2 "Lottery Winners"

	This program will ask the user to input the weekly 
	5 digit lottery number. It will then perform a 
	linear search to check the weekly lottery number
	against the 10 "lucky" 5 digit numbers that the user
	plays each week to see if any are winners. It will 
	then output a message indicating if they won or not.

************************************************************/

#include <iostream>
using namespace std;

// Function prototype
bool searchLuckyNums(const int[], int, int);

int main()
{
	const int SIZE = 10;		// For the size of the array
	int luckyNumbers[SIZE] =	// The "lucky" numbers that the purchaser plays every week
			{ 13579, 26791, 26792, 33445, 55555, 
			62483, 77777, 79422, 85647, 93121 };
	int lottoNum;				// For the weekly lotto number
	bool winner;				// Flag to indicate winning ticket or not


	// Ask the user for input
	cout << "Please enter this week's 5 digit lottery number\n";
	cout << "and I will check if any of your lucky numbers won!\n";
	cin >> lottoNum;

	// Search the array of lucky numbers
	// To see if any match the weekly lotto number
	winner = searchLuckyNums(luckyNumbers, SIZE, lottoNum);


	// Output results to user
	if (winner == false)
	{
		cout << "I am sorry, none of your lucky numbers won\n";
		cout << "Better luck next time!" << endl;
	}
	else
		cout << "You won! Go cash that ticket in!" << endl;
	
	return 0;

}


/*********************************************************************
		The searchLuckyNums function receives an int array from
		the main program and performs a linear search of the array
		to see if the user input matches. If the user input matches
		any elements in the array the flag "won" will be set to 
		true. If no matches are found the function will return
		"won" as false.
*********************************************************************/

bool searchLuckyNums(const int luckyNums[], int numElems, int lottoNum)
{
	int index = 0;			//To search each subscript of the array
	
	bool won = false;		//Flag

	// While loop will iterate through each element
	// Until it reaches the end of the array or 
	// finds a match for the user input in the array
	while (index < numElems && !won)
	{
		if (luckyNums[index] == lottoNum)
		{
			won = true;
			
		}
		index++;
	}
	return won;
}