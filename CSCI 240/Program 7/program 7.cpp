/******************************************
CSCI 240 		Program 7		Fall 2020

Programmer: Isabelle Coletti

Section: 1

Due date: 10/30

Purpose: This program calculates the quiz 
		 average for a student in the CSCI
		 240 course. 
********************************************/

#include <iomanip>
#include <iostream> 
#include <fstream>
#include <cstdlib>

using namespace std;

//declare constant
const int MAX_ARRAYSIZE = 12;

//prototypes

/***************************************************************
Function: int buildQuizArray( int quizArray[] )

Use: This function fills the array with values from 
	 the input file and counts how many quizzes there are. 

Arguments: quizArray[] - an integer array that holds all of
		   the student's quiz scores

Returns: the number of quizzes

Note: None
***************************************************************/
int buildQuizArray( int quizArray[] );

/***************************************************************
Function: void printQuizArray( string title, int quizArray[], int numberOfQuizzes )

Use: This function prints out a title and then each quiz number
	 and its respective grade. 

Arguments: title - a string that represents a meaningful title 
		   to be displayed about the quizzes and scores
		   
		   quizArray[] - an integer array that holds all of
		   the student's quiz scores
		   
		   numberOfQuizzes - an integer that represents the 
		   number of quizzes the student has taken

Returns: nothing

Note: None
***************************************************************/
void printQuizArray( string title, int quizArray[], int numberOfQuizzes );

/***************************************************************
Function: double calcQuizAverage( int quizArray[], int numberOfQuizzes )

Use: This function caluclates the average of the student's quiz
	 scores, depending on the number of quizzes the student
	 has taken.

Arguments: quizArray[] - an integer array that holds all of
		   the student's quiz scores
		   
		   numberOfQuizzes - an integer that represents the
		   number of quizzes the student has taken

Returns: the average of all the student's quiz scores

Note: None
***************************************************************/
double calcQuizAverage( int quizArray[], int numberOfQuizzes );

/***************************************************************
Function: void sortArray( int quizArray[], int numberOfQuizzes )

Use: This function sorts the values of the arrays into
	 ascending order. 

Arguments: quizArray[] - an integer array that holds all of
		   the student's quiz scores
		   
		   numberOfQuizzes - an integer that represents the
		   number of quizzes the student has taken

Returns: nothing 

Note: None
***************************************************************/
void sortArray( int array[], int numberOfQuizzes );

/***************************************************************
Function: void copyArray( int destination[], int source[], int numberOfQuizzes )

Use: This function copies the values from one array to another.

Arguments: destination[] - an integer array that you want to
		   copy values into
		   
		   source[] - an integer array that you want to copy
		   values from
		   
		   numberOfQuizzes - an integer that represents the
		   number of quizzes the student has taken

Returns: nothing 

Note: None
***************************************************************/
void copyArray( int destination[], int source[], int numberOfValues );

int main()
{
	string title = "Quiz Scores";
	//create quiz array
	int quizArray[MAX_ARRAYSIZE];
	int numberOfQuizzes;
	double average;
	//get the number of quizzes and fill in the array by calling buildQuizArray()
	numberOfQuizzes = buildQuizArray(quizArray);
	//get the average of quiz scores by calling calcQuizAverage()
	average = calcQuizAverage(quizArray, numberOfQuizzes);
	//display the quiz score average
	cout << "Quiz average: " << setprecision(2) << fixed << average << "%" << endl << endl;
	//print each quiz and its respective score
	printQuizArray(title, quizArray, numberOfQuizzes);
	
	return 0;
}

int buildQuizArray(int quizArray[])
{
	int count = 0;
	int num;
	//declare input file stream
	ifstream infile; 
	//open the input file
	infile.open("quizscores.txt");
	//if the file fails to open, display a message and exit program 
	if(infile.fail())
	{
		cout << "The quizscores.txt input file did not open.";
		exit(-1);
	}
	//read in first value from input file
	infile >> num;
	//while there is still data to be read in, fill in each index of the array
	while(!infile.eof())
	{
		quizArray[count] = num;
		infile >> num;
		//add to count to keep track of number of indexes
		count++;
	}
	//close the file
	infile.close();
	//return the number of values
	return count; 
}

void printQuizArray(string title, int quizArray[], int numberOfQuizzes)
{
	cout << title << endl << "----------------" << endl;
	//display each value in the array
	for(int x=0; x<numberOfQuizzes; x++)
	{
		//if the index in the array is the 10th index or later, adjust width for correct formatting
		if(x>=9)
			cout << "Quiz " << (x+1) << ": " << setw(4) << quizArray[x] << "/10" << endl;
		else
			cout << "Quiz " << (x+1) << ": " << setw(5) << quizArray[x] << "/10" << endl;
	}
}

double calcQuizAverage(int quizArray[], int numberOfQuizzes)
{
	//create copy of original array to store values
	int calcArray[12];
	//call copyArray() to actually copy the values from quizArray to calcArray
	copyArray(calcArray, quizArray, numberOfQuizzes);
	double average; 
	int sum = 0;
	int firstTwo;
	//get the sum of all quiz scores
	for(int x=0; x<numberOfQuizzes; x++)
		{
			sum += quizArray[x];
		}
	//checks if the student has completed more than 2  quizzes
	if(numberOfQuizzes > 2)
	{
		//sorts calcArray in ascending order in order to not disturb the order of quizArray
		sortArray(calcArray, numberOfQuizzes);
		//determine and sum up the 2 lowest quiz scores
		firstTwo = calcArray[0] + calcArray[1];
		//calculate the average using formula
		average = (double)(sum - firstTwo) / (10*(numberOfQuizzes-2))*100;
	}
	//if the student has completed 2 or less quizzes
	else
	{
		average = (double)(sum/(10*numberOfQuizzes))*100;
	}
	return average; 
}

void sortArray(int array[], int numberOfQuizzes)
{
	//create temporary variable to store a value while indexes are switched around
	int temp;
	for(int x=0; x<numberOfQuizzes; x++)
	{
		for(int y=x+1; y<numberOfQuizzes; y++)
		{
			//check if the value at x is larger than the one at y
			if(array[x] > array[y])
			{
				//swap the values at x and y
				temp = array[y];
				array[y] = array[x];
				array[x] = temp;
			}
		}
	}
}

void copyArray(int destination[], int source[], int numberOfQuizzes)
{
	//go through each index of the destination array and copy the value from the same index of the source array
	for(int x=0; x<numberOfQuizzes; x++)
	{
		destination[x] = source[x];
	}
}

