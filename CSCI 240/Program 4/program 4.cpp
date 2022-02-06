/********************************************************
CSCI 240			Program 4			Fall 2020

Programmer: Isabelle Coletti

Section: 1

Date due: 9/25

Purpose: This program generates three randomly sized
		 sets of random numbers, then displays them.
********************************************************/
#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

//declaring constants
const int MAX_VALUE1 = 25;
const int MAX_VALUE2 = 50;
const int MAX_VALUE3 = 250;
const int LINE_MAX1 = 5;
const int LINE_MAX2 = 6;
const int LINE_MAX3 = 7; 

int main()
{
	int numSet,
		numExecute;	
	
	/*initalize random number generator, generate number of values in first set (1 through 25),
	display number of values in set, then display each value with for loop*/
	srand(17);
	numSet = rand() % MAX_VALUE1 + 1;
	cout << "The number of values in the first set: " << numSet << endl;
	
	for(int x = 0; x < numSet; x++)
	{
		//display numbers in 5 columns with last digit lining up
		if(x % LINE_MAX1 == 0)
		{
			cout << endl;
		}
		cout << right << setw(9) << rand();
	}
	
	/*generate number of values in second set (1 through 50), display number of values in set,
	then display each value using a while loop*/
	numSet = rand() % MAX_VALUE2 + 1;
	cout << endl << endl << "The number of values in the second set: " << numSet << endl;
	
	numExecute = 0;
	while(numExecute < numSet)
	{
		//display numbers in 6 columns with last digit lining up
		if(numExecute % LINE_MAX2 == 0)
		{
			cout << endl;
		}
		cout << right << setw(9) << rand();
		numExecute++;
	}
	
	/*generate number of values in third set (1 through 250), display number of values in set,
	then display each value using a do while loop*/
	numSet = rand() % MAX_VALUE3 + 1;
	cout << endl << endl << "The number of values in the third set: " << numSet << endl;
	
	numExecute = 1; 
	do
	{
		//display numbers in 7 columns with last digit lining up
		if((numExecute - 1) % LINE_MAX3 == 0)
		{
			cout << endl;
		}
		cout << right << setw(9) << rand();
		numExecute++;
	}
	while(numExecute <= numSet); 
	
	return 0;
}
