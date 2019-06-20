/*  Kale Williams Chapter 6 Programming Challenge # 12

	This program takes scores from 5 judges for a performer.
	The final score is determined by dropping the highest and
	lowest score and then averaging the remaining 3. The 
	program will not accept values less than 1 or greater than
	10 as a score.
******************************************************************/

#include <iostream>
using namespace std;


		// Function prototypes
void getJudgeData(double&);					//to get each of the 5 scores from the judges
void calcScore								//to calculate the final average score
	(double, double, double, double, double);
double findLowest							//to find the lowest score in order to drop it
	(double, double, double, double, double);
double findHighest							//to find the highest score in order to drop it
	(double, double, double, double, double);



int main()
{

	double score1, score2, score3,
				score4, score5;		//to hold the 5 judge's scores

	//calls to getJudgeData function
	//to get the 5 scores
	getJudgeData(score1);
	getJudgeData(score2);
	getJudgeData(score3);
	getJudgeData(score4);
	getJudgeData(score5);

	//call to calcScore will send each score to that
	//function to get the final score
	calcScore(score1, score2, score3, score4, score5);

	return 0;
}



/*****************************************************
	getJudgeData uses the reference variable &score
	in order to change the value from the main
	each time it is called. It will validate the iput
	from the user is between 0 and 10 inclusive. The
	do-while loop will continue to run and ask for
	correct input if given numbers outside the range asked
	for
*********************************************************/

void getJudgeData(double &score)
{
	
	do
	{
		cout << "Please enter a score for this performer: ";
		cin >> score;

		if (score < 0 || score > 10)
		{
			cout << "Please enter a value between 1 and 10\n";
			cout << "Please try again\n";
		}
	} while (score < 0 || score > 10);

}



/***********************************************************	
	calcScore recieves the 5 scores. It will then make a call
	to the findLowest and findHighest functions to determine
	which two scores to drop. It will then average the remaining
	scores and display the results.
**********************************************************/

void calcScore(double score1, double score2, double score3, double score4, double score5)
{
	double lowest =
		findLowest(score1, score2, score3, score4, score5);

	double highest =
		findHighest(score1, score2, score3, score4, score5);

	double droppedValues = (lowest + highest);

	double averageScore = (score1 + score2 + score3 + score4 + score5 - droppedValues) / 3;
	cout << "The final score for this performer is " << averageScore << endl;

}



/**********************************************************
	findLowest function will determine which of the 5 scores 
	is the lowest and then return that to calcScore.
***********************************************************/

double findLowest(double score1, double score2, double score3, double score4, double score5)
{
	if (score1 <= score2 && score1 <= score3 && score1 <= score4 && score1 <= score5)
		return score1;
	else if
		(score2 <= score1 && score2 <= score3 && score2 <= score4 && score2 <= score5)
		return score2;
	else if
		(score3 <= score1 && score3 <= score2 && score3 <= score4 && score3 <= score5)
		return score3;
	else if
		(score4 <= score1 && score4 <= score2 && score4 <= score3 && score4 <= score5)
		return score4;
	else
		return score5;

}


/****************************************************************	
	findHighest function will determine which of the 5 scores
	is the highest and then return that to calcScore.
*****************************************************************/

double findHighest(double score1, double score2, double score3, double score4, double score5)
{
	if (score1 >= score2 && score1 >= score3 && score1 >= score4 && score1 >= score5)
		return score1;
	else if
		(score2 >= score1 && score2 >= score3 && score2 >= score4 && score2 >= score5)
		return score2;
	else if
		(score3 >= score1 && score3 >= score2 && score3 >= score4 && score3 >= score5)
		return score3;
	else if
		(score4 >= score1 && score4 >= score2 && score4 >= score3 && score4 >= score5)
		return score4;
	else
		return score5;

}