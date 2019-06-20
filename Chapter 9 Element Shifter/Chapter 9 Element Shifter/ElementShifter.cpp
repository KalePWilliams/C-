/****************************************************************
						Kale Williams							*
				Problem 12 "Element Shifter"					*
																*
	This program creates an original array which is then sent	*
	to a getNewArray function which will create a new array		*
	based on the original array, but with the elements shifted	*
	over by one element. The resulting new array will be one	*
	element longer than the original array. The program will	*
	then print out the original array and the new array.		*
****************************************************************/

#include <iostream>
using namespace std;

// Function prototypes
int *getNewArray(const int *, int);
void displayArray(const int[], int);

int main()
{
	// constant for original element size
	const int ELEMENTS = 10;
	// original array of 10 elements
	int origArray[ELEMENTS] = { 1,2,3,4,5,6,7,8,9,10 };

	// Define a pointer for the new array
	int *newArray = nullptr;

	// Create the new array that is 1 element
	// longer and contains the original array
	// elements shifted over by one element
	newArray = getNewArray(origArray, ELEMENTS);

	// call to function to display the
	// original array
	cout << "Here is the original array \n";
	displayArray(origArray, ELEMENTS);

	// call to funciton to display
	// the new array
	cout << "Here is the new array \n";
	displayArray(newArray, (ELEMENTS + 1));

	// Free the dynamically allocated memory
	delete[] newArray;

	// Set newArray back to a nullptr
	newArray = nullptr;
	return 0;
}


/********************************************************************
	The getNewArray function accepts an int array and its size.		*
	It then creates a newArray that is one element larger than		*
	the original array. The first element in the newArray is set	*
	to 0 and it then copies the elements from the original array.	*
********************************************************************/

int *getNewArray(const int *oldArray, int size)
{
	int *newArray = nullptr;

	// return a nullptr if an invalid
	// array size is given
	if (size <= 0)
		return nullptr;

	// Dynamically allocate memory for newArray
	newArray = new int[size + 1];
	// Initialize the first element as 0
	newArray[0] = 0;


	// Loop to copy the original array elements
	// to the new array starting at the new 
	// array's second element
	for (int i = 0; i < size; i++)
		newArray[i + 1] = oldArray[i];

	// Return the pointer to the new array
	return newArray;

}


/****************************************************
	The displayArray function recieves an array		*
	and its size as arguments. It will then			*
	print the elements of the array.				*
****************************************************/
void displayArray(const int arr[], int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << ", ";
	cout << endl;
}