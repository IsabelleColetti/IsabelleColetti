/***************************************************************
CSCI 240         Program 1     Fall 2020

Programmer: Isabelle Coletti

Section: 1

Date Due: 9/4

Purpose: This program calculates and displays the shooting
         percentage for an NHL team
***************************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int numShots,
	  	numGoals;

	cout << "Enter the number of goals that were scored: " << endl;							//receives goals
	cin >> numGoals;
	
	if(numGoals<0)
	{
		cout << "Error: the number of goals must be greater than 0. Try again: " << endl;
		cin >> numGoals;
	}

	cout << "Enter the number of scores that were attempted: " << endl;				//receives scores
	cin >> numShots;
	
	if(numShots<0)
	{
		cout << "Error: the number of shot attempts must be greater than 0. Try again: " << endl;
		cin >> numShots;
	}

	cout << endl << "The Shooting Percentage is " << setprecision(1) << fixed << (float)numGoals / (float)numShots * 100 << endl; 					//computes Shooting Percentage and prints result
	
	return 0;
}
