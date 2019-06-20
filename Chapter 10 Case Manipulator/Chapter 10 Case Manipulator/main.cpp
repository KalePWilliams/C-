/***********************************************				
				Kale Williams
			  "Case Manipulator"
	This program will change the case of several
	letters that the user will input. It will 
	first switch all lowercase letters given to
	uppercase and uppercase letters given to 
	lowercase. Next, it will convert the entire
	string to lowercase, and finally it will 
	convert the entire string to uppercase.
	After each of the three functions changes
	the case the program will print the results

************************************************/

#include <iostream>
using namespace std;
void upper(char *);			//to convert all characters to uppercase
void lower(char *);			//to convert all characters to lowercase
void reverse(char *);		//to convert all characters to their opposite case
void printString(char *);	//to print the resulting strings

int main()
{
	const int SIZE = 30;
	char userInput[SIZE];

	// Get the string to manipulate from the user
	cout << "Please enter several uppercase and/or lowercase letters and \n";
	cout << "I will change their case in a few different ways \n";
	cin.getline(userInput, SIZE);

	// Convert all characters to their opposite case and print results
	cout << "Here are the letters you entered with the case switched\n";
	reverse(userInput);
	printString(userInput);

	// Convert all characters to lowercase and print results
	cout << "\nHere are the letters you entered all in lowercase\n";
	lower(userInput);
	printString(userInput);

	// Convert all characters to uppercase and print results
	cout << "\nHere are the letters you entered all in uppercase\n";
	upper(userInput);
	printString(userInput);
	
	return 0;
}

/*************************************************
	The upper function recieves a C-string pointer
	and while it has not encountered the null
	terminator will change each character to
	uppercase as it iterates through the string.

*************************************************/

void upper(char *strPtr)
{
	while (*strPtr != '\0')
	{
		*strPtr = toupper(*strPtr);
		strPtr++;
	}

}

/*************************************************
	The lower function recieves a C-string pointer
	and while it has not encountered the null
	terminator will change each character to
	lowercase as it iterates through the string.

*************************************************/

void lower(char *strPtr)
{
	while (*strPtr != '\0')
	{
		*strPtr = tolower(*strPtr);
		strPtr++;
	}

}

/*************************************************
	The reverse function recieves a C-string pointer
	and while it has not encountered the null
	terminator will change each character to
	the opposite case that it was given as it 
	iterates through the string.

*************************************************/

void reverse(char *strPtr)
{
	while (*strPtr != '\0')
	{
		if (isupper(*strPtr))
			*strPtr = tolower(*strPtr);
		else *strPtr = toupper(*strPtr);
		strPtr++;
	}
}

/*************************************************
	The printString function recieves a C-string 
	pointer and while it has not encountered the 
	null terminator will print each character
	as it iterates through the string.

*************************************************/

void printString(char *strPtr)
{
	while (*strPtr != '\0')
	{
		cout << *strPtr << ", ";
		strPtr++;
	}
}