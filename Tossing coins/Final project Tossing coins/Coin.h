/***********************************************************
				Kalé Williams
			Final Exam Program
		Chapter 13 #13 "Tossing coins for a Dollar"
	
	The Coin class defines a Coin object. It contains private
	member variables: sidUp, a string to denote if the coin
	is currently heads-up or tails-up, an int variable randomNum
	to hold the randomly generated number. If randomNum is even,
	sideUp will be set to "heads", otherwise it will be set to
	"tails". The class contains a default constructor that 
	initializes the sideUp variable, a void toss function which 
	can also be used to randomly set the sideUp variable after
	the Coin object has been created, and a getSideUp function
	which returns a string indicating "heads" or "tails".

************************************************************/

#pragma once
#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
using namespace std;

class Coin
{
private:
	string sideUp;	//To hold either heads or tails
	int randomNum;	//To hold the randomly generated number
	int seed;		//To hold the system time to seed the random number genterator
	

public:
	//default constructor randomly initializes
	//the side of the coin that is facing up
	Coin()
	{
		//get system time
		seed = time(0);

		//seed the random number generator
		srand(seed);

		//set randomNum to a random number
		randomNum = rand();
		
		//If random number is even set
		//sideUp to "heads". If not set
		//sideUp to "tails".
		if (randomNum % 2 == 0)
			sideUp = "heads";
		else
			sideUp = "tails";

	}

	// void toss simulates a coin toss by
	// randomly determining the side of
	// the coin facing up
	void toss()
	{
		//get system time
		seed = time(0);

		//seed the random number generator
		srand(seed);

		//set randomNum to a random number
		randomNum = rand();

		//If random number is even set
		//sideUp to "heads". If not set
		//sideUp to "tails".
		if (randomNum % 2 == 0)
			sideUp = "heads";
		else
			sideUp = "tails";

	}
	// return the sideUp value
	string getSideUp()
	{
		return sideUp;
	}
};

