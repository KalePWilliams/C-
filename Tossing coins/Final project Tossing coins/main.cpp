/***********************************************************
				Kalé Williams
			Final Exam Program
		Chapter 13 #13 "Tossing coins for a Dollar"
	
	This program utilizes the Coin class and creates three
	instances of the class; a quarter, a dime, and a nickle.
	The program uses these three Coin objects to play a game
	where each coin is tossed once per round, and each coin
	which results in a "heads" state will add its respective 
	value to the player's balance which starts at $0. The 
	game continues through successive rounds until either 
	the player's balance meets or exceeds $1.00. Ending on
	exactly $1.00 wins the game.

************************************************************/


#include "Coin.h"
#include <iostream>
#include <iomanip>
using namespace std;


int main()
{
	double balance = 0.0;	//To hold the player balance
	int round = 1;			//To keep track of the round number
	string flip;			//To recieve user input to initiate a coin toss

	cout << "Let's play Tossing Coins For a Dollar! \n";
	cout << "See if you can get exactly $1.00! \n";

	Coin quarter;	//creates a coin object named quarter
	Coin dime;		//creates a coin object named dime
	Coin nickle;	//creates a coin object named nickle


	//do-while loop to continue the game while the player's 
	//balance is less than $1.00
	do
	{
		cout << endl;
		cout << "________________________________\n\n";
		cout << "   ********* Round " << round;
		cout << " *********" << endl;
		cout << "________________________________\n" << endl;
		cout << "Get ready to flip the coins!!!...\n";
		cout << endl;

		//user initiate each flip for the three coins
		cout << "Press any letter then the enter key to flip the quarter ";
		cin >> flip;
		quarter.toss();
		cout << "Press any letter then the enter key to flip the dime ";
		cin >> flip;
		dime.toss();
		cout << "Press any letter then the enter key to flip the nickle ";
		cin >> flip;
		nickle.toss();
		cout << endl;

		//print the sideUp results for each coin object
		cout << "Quarter: " << quarter.getSideUp() << endl;
		cout << "Dime   : " << dime.getSideUp() << endl;
		cout << "Nickle : " << nickle.getSideUp() << endl;
		cout << endl;

		//The value of each coin that lands "heads" will be
		//added to the player's balance
		if (quarter.getSideUp() == "heads")
			balance += 0.25;
		if (dime.getSideUp() == "heads")
			balance += 0.10;
		if (nickle.getSideUp() == "heads")
			balance += 0.05;

		//Print the updated balance from this round
		cout << "Your balance after round " << round << " is $";
		cout << fixed << showpoint << setprecision(2);
		cout << balance << endl;
		round++;

	} while (balance < 1.0);

	//If the balance equals $1.00 exactly the player wins
	//else the player loses
	if (balance == 1.0)
		cout << "Thank you for playing, YOU HAVE WON!";
	else
		cout << "Thank you for playing, better luck next time.\n";

	return 0;
}
