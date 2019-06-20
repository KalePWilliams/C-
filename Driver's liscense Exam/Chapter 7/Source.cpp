/* ************Kale Williams Chapter 7 Programming Challenge # 10 P. 451************

			This program will give a pass or fail response for 
			the written portion of a driver's license exam. It
			will check the student's inputted answers against a
			correct answer key. It will only accept valid input
			(A, B, C, or D). It will output the total number of 
			incorrect and correct answers, as well as give the
			question number for any incorrect answers.

***********************************************************************************/

#include <iostream>
#include <vector>		
#include <string>
using namespace std;

int main()
{
	const char NUM_QUESTIONS = 20;			//Constant to ensure both arrays are the same size
	int totalWrong = 0;						//Accumulator for all incorrect answers
	int totalRight = 0;						//Accumulator for all correct answers
	vector<int> wrongAnswers;				//Vector to hold the question numbers that were answered incorrectly
	bool validInput = true;					//Flag will be set to false if given invalid input
	char studentAnswers[NUM_QUESTIONS];		//To hold the student answers
	char correctAnswers[NUM_QUESTIONS] =	//To hold the correct answer key
								{ 'A', 'D', 'B', 'B', 'C',
								  'B', 'A', 'B', 'C', 'D',
								  'A', 'C', 'D', 'B', 'D',
								  'C', 'C', 'A', 'D', 'B' };


			// Promt the user to enter the student's answers
	cout << "Please enter the student's answers for the exam\n";
	cout << "Please only enter A, B, C, or D for each of the 20 questions\n";

			// This loop will iterate for each index
			// of the two arrays, comparing the input
			// of studentAnswers to correctAnswers
	for (int count = 0; count < NUM_QUESTIONS; count++)
	{

		// validation do-while here to make sure ONLY A, B, C, or D is accepted
		// It will continue to loop until given valid input
		do
		{
			char answer;
			cout << "Question " << (count + 1) << ": ";
			cin >> answer;

			if (answer == 'A'|| answer == 'B'||answer == 'C'|| answer == 'D')
			{
				studentAnswers[count] = answer;
				validInput = true;
			}
			else
			{
				validInput = false;
				cout << "Please enter a valid answer for this question\n";
				cout << "Either A, B, C, or D\n";
				cout << "Please try again\n";
			}
		} while (validInput == false);


		// Every correct answer the student gets
		// increments the totalRight accumulator
		if (studentAnswers[count] == correctAnswers[count])
		{
			totalRight++;
		}

		// Every wrong answer the student gets
		// increments the totalWrong accumulator
		else
		{
			totalWrong++;
			wrongAnswers.push_back(count + 1);
			//how do I get the question numbers into this vector?
		}
	}

				// If the student got 15 or more correct
				// the student passed and passing message
				// will be displayed
	if (totalRight >= 15)
		cout << "Congratulations! This student has passed this part of the test!\n";

				// If the student got less than 15 correct
				// a failing message will be displayed
	else
		cout << "Unfourtunatly the student has failed this part of the test.\n";

				
				// The total number of correct and incorrect responses
				// will be displayed
	cout << "The total number of correct responses was " << totalRight << endl;
	cout << "The total number of incorrect responses was " << totalWrong << endl;
	
				// If the vector wrongAnswers is empty
				// message stating 100% correct
	if (wrongAnswers.empty())
		cout << "Congratulations! This test is 100% correct!\n";

				// If any questions are answered incorrectly
				// will display the question numbers that 
				// were answered incorrectly
	else
	{
		cout << "The question which were incorrectly answered were: \n";
		for (char val : wrongAnswers)
			cout << "Question " << to_string(val) << endl;
	}
	return 0;

}