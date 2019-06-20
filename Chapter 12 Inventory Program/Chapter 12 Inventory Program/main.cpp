/****************************************************************************

					Kale Williams
				Chapter 12 Inventory Program

	This program uses a structure to store data regarding items
	in inventory. The program allows the user to input as many
	records for items as they wish. It allows the user to display
	any record as well as change any of the records.

*****************************************************************************/
#include <chrono>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

// Constant for the description size
const int DESC_SIZE = 31;

// Structure declaration
struct InventoryItem
{
	char desc[DESC_SIZE];			// For the item description
	int qty;						// For the item quantity
	double wholesaleCost, 
			retailCost;				//For item wholesale and retail cost
	int dateAdded[3];				// Date when the item was added to inventory
};

// Function prototypes
void getItemData(InventoryItem &, fstream &, int &);
void displayRecord(InventoryItem &, fstream &, int);
void changeRecord(InventoryItem &, fstream &, int);
void addRecord(InventoryItem &, fstream &, int);


/************** MAIN FUNCTION ******************/

int main()
{
	// Instantiate structure "record"
	InventoryItem record = {"", 0, 0.0, 0.0, 0 };		
	
	
	bool quit = false;		// to quit program if set to true
	int choice;				// to hold the menu choice from the user
	char flag;				// used to set quit to true
	int numOfRecords = 0;	// keep track of how many records are added


	// Open the file in binary mode for input and output
	// If file exists delete and create new (trunc)
	fstream inventory("Inventory.dat",  ios::in |ios::out |ios::binary | ios:: trunc);
	
	// Error if file creation fails
	if (!inventory)
	{
		cout << "The file did not open";
	}

	// Main loop to give menu options and calls to functions as needed
	while (quit == false)
	{
		// Menu options
		cout << "Please select from the following options: \n";
		cout << "To add a new record to a file press 1\n";
		cout << "To display a record in a file press 2\n";
		cout << "To change a record in a file press 3\n";
		cin >> choice;

		// Call any of three functions based on user choice
		switch (choice)
		{
		case  1:
			addRecord(record, inventory, numOfRecords);
			break;

		case 2:
			displayRecord(record, inventory, numOfRecords);
			break;

		case 3:
			changeRecord(record, inventory, numOfRecords);
			break;

		default:
			cout << "Please select a valid choice\n";
		}

		// Ask the user if they want to continue or quit program
		cout << "\nWould you like to perform another operation?\n";
		cout << "Press Y for yes or any other key to quit the program: ";
		cin >> flag;
		if (flag != 'Y' && flag != 'y')
			quit = true;
	}
	inventory.close();
	return 0;
}

/*****************************************************************************
		The getItemData function will be used by
		other functions to get the user input
		and validate it. 
******************************************************************************/

void getItemData(InventoryItem &record, fstream &inventory, int &numOfRecords)
{
	int year;	// To hold the year the item was added
	int month;	// To hold the month the item was added
	int day;	// To hold the day the item was added

	// Note to user to input data correctly
	cout << "Please note: \n";
	cout << "Invalid entries will prompt you to reenter the data. \n";

	// Input item description
	cout << "\nDescription: ";
	cin.ignore();
	cin.getline(record.desc, DESC_SIZE);

	// Input item quantity
	do
	{
		cout << "Quantity: ";
		cin >> record.qty;
	} while (record.qty < 1);

	// Input item Wholesale cost
	do
	{
		cout << "Wholesale: ";
		cin >> record.wholesaleCost;
	} while (record.wholesaleCost < 1);

	// Input item retail cost
	do
	{
		cout << "Retail: ";
		cin >> record.retailCost;
		// Retail should never be less than wholesale
	} while (record.retailCost < record.wholesaleCost);
	
	// Input the date the item was added to inventory
	cout << "Date added to inventory: \n";
	do
	{
		cout << "Enter the a four digit year (from 2000-20018): ";
		cin >> year;
	} while (year < 2000 || year > 2018);
	do
	{
		cout << "Enter a  month (1-12): ";
		cin >> month;
	} while (month < 1 || month > 12);
	do
	{
		cout << "Enter the day (1-31): ";
		cin >> day;
	} while (day < 1 || day > 31);

	// put the user input into the dateAdded array
	record.dateAdded[2] = year;
	record.dateAdded[1] = month;
	record.dateAdded[0] = day;
	
}


/*****************************************************************************
		The addRecord function will be used to add
		an item record to the end of the file. It
		will place the write position to the end of
		the file to start writing there. It will 
		call the getItemData function to get the
		item data from the user
******************************************************************************/

void addRecord(InventoryItem &record, fstream &inventory, int numOfRecords)
{
	//clear eof flag from prior loop runs 
	inventory.clear();

	// place write position at end of file
	inventory.seekp(0L, ios::end);

	//call to getItemData function to get item data
	getItemData(record, inventory, numOfRecords);

	//write new record 
	inventory.write(reinterpret_cast<char *>(&record), sizeof(record));
	cout << "1 record added\n ";
	numOfRecords++;
}


/*****************************************************************************
		The displayRecord function allows the user
		to select a record to view. It formats the
		data and prints it to the console.
******************************************************************************/

void displayRecord(InventoryItem &record, fstream &inventory, int numOfRecords)
{
	int recNum = 0;		// To hold the record number the user wans to view
	inventory.clear();// clear eof flag
	
	// Ask user for desired record to view
	cout << "Which record do you want to view? ";
	cin >> recNum;

	//Move back to beginning of this record's position
	inventory.seekg(recNum * sizeof(record), ios::beg);
	inventory.read(reinterpret_cast<char *>(&record), sizeof(record));

	// Display the formatted contents of selected item record
	cout << "\nDescription: ";
	cout << record.desc << endl;
	cout << "Quantity: ";
	cout << record.qty << endl;
	cout << "Wholesale cost: " << "$" << setprecision(2) << fixed;
	cout << record.wholesaleCost << endl;
	cout << "Retail: " << "$" << setprecision(2) << fixed;
	cout << record.retailCost << endl;
	cout << "Data added to inventory: ";
	cout << record.dateAdded[1] << "/";
	cout << record.dateAdded[0] << "/";
	cout << record.dateAdded[2] << endl << endl;
	
	
}


/*****************************************************************************
		The changeRecord function allows the user 
		to select a record that they can then alter.
		It will call the getItemData function to 
		get the new data for record and overwrite
		the old data.
******************************************************************************/

void changeRecord(InventoryItem &record, fstream &inventory, int numOfRecords)
{
	int recNum = 0;		// To hold the record number the user wans to view
	inventory.clear();	// clear eof flag
	inventory.seekg(0L, ios::beg);   //go to beginning of file

	cout << "Which record do you want to edit? ";
	cin >> recNum;

	// Call to getItemData function to get data
	getItemData(record, inventory, numOfRecords);


	//Move back to beginning of this record's position
	inventory.seekp(recNum * sizeof(record), ios::beg);

	//write new record over the current
	inventory.write(reinterpret_cast<char *>(&record), sizeof(record));
	cout << "The record has been changed \n";
}

