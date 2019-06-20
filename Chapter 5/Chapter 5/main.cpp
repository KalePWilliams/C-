/* Kale Williams
   This program asks the user to input how many floors
   a hotel has and how many rooms per floor. It will not
   allow fewer than 1 floor or fewer than 10 rooms per
   floor. It will also not accept more occupied rooms 
   per floor than are availible on that floor. At the 
   end it will print out the total number of rooms,
   the total number of occupied and unoccupied rooms
   as well as the percentage of occupied rooms. If a 
   hotel is given to have 13 or more floors the 13th 
   floor will be skipped.
*/
#include <iostream>

using namespace std;

int main()
{
	int hotelFloors;				//To hold user given number of floors
	int roomsPerFloor;				//To hold user given number of rooms per floor
	double totalRooms = 0.0;		//To hold total number of rooms in the hotel
	double roomsOccupiedPerFloor;	//To hold user given number of occupied rooms per floor
	double totalRoomsOccupied = 0.0;//To hold the total number of occupied rooms


	/* Do while loop to validate a positive int 
	   is given for the number of floors. It will 
	   prompt the user for correct input and run 
	   again if given less than 1.
	*/
	do
	{
		cout << "How many floors does the hotel have?: " << endl;
		cin >> hotelFloors;
		if (hotelFloors < 1)
		{
			cout << "Please enter a positive number of floors.\n";
			cout << "Please try again. \n";
		}
	} while (hotelFloors < 1);
	
	
	/* For loop to interate through each floor
	   and get user input for number of rooms on
	   each floor and how many are occupied.
	*/

	for (int floor = 1; floor <= hotelFloors; floor++)
	{
		if (floor != 13)	//Floor 13 will run an empty loop and only increment the counter
							//hence floor 13 will seem skipped by the user
		{

			/* Do while loop to validate at least 10 is given for the 
			   number of rooms per floor. The if statement will give 
			   error if roomsPerFloor is less than 10 and the loop 
			   will continue to run. 
			*/
			do
			{
				cout << "How many rooms does floor " << floor << " have?: " << endl;
				cin >> roomsPerFloor;

				
				if (roomsPerFloor < 10)
				{
					cout << "Please enter a number of rooms equal to or greater than 10 \n";
					cout << "Please try again \n";
				}

			} while (roomsPerFloor < 10);


			/* Do while loop to validate that user does not 
			   input a greater number of roomsOccupiedPerFloor
			   than there are rooms available on that floor.The 
			   if statement will give an error if roomsOccupiedPerFloor 
			   is greater than roomsPerFloor and the loop will 
			   continue to run. 
			*/
			do
			{

				cout << "How many rooms on floor " << floor << " are occupied? " << endl;
				cin >> roomsOccupiedPerFloor;

				if (roomsOccupiedPerFloor > roomsPerFloor)
				{
					cout << "Occupied rooms cannot be greater than rooms available on this floor\n";
					cout << "Please try again\n";
				}

			} while (roomsOccupiedPerFloor > roomsPerFloor);

			//Accumulaters 
			totalRooms += roomsPerFloor;				//Accumulate all rooms in totalRooms
			totalRoomsOccupied += roomsOccupiedPerFloor;//Accumulate all occupied in totalRoomsOccupied

		}

	}
			// Ending feedback statments confirming totals
	cout << "The hotel has a total of " << totalRooms << " rooms." << endl;
	cout << "The total number of occupied rooms is " << totalRoomsOccupied << endl;
	cout << "The number of unoccupied rooms is " << (totalRooms - totalRoomsOccupied) << endl;
	cout << "The percentage of occupied rooms is " << (totalRoomsOccupied / totalRooms)*100 << "%"<< endl;
	
	
	return 0;
}