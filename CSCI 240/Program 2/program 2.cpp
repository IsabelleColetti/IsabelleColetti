/***************************************************************
CSCI 240         Program 2     Fall 2020

Programmer: Isabelle Coletti

Section: 1

Date Due: 9/11

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
	float shootingPercentage;

	cout << endl << "Enter the number of goals that were scored: " << endl;							//receives goals
	cin >> numGoals;
	
	//checks if number user enetered is less than 0 and prompts user to re-enter value if so
	if(numGoals<0)
	{
		cout << "Error: the number of goals must be greater than 0. Try again: " << endl;
		cin >> numGoals;
	}

	cout << endl << "Enter the number of scores that were attempted: " << endl;			  			//receives scores
	cin >> numShots;
	
	//checks if number user enetered is less than 0 and prompts user to re-enter value if so
	if(numShots<=0)
	{
		cout << "Error: the number of shot attempts must be greater than 0. Try again: " << endl;
		cin >> numShots;
	}

	//calculates shooting percentage as a float and formats number when displayed so there is only one digit after the decimal point, then displays result
	shootingPercentage = (float)numGoals / (float)numShots * 100;
	cout << setprecision(1) << fixed;
	cout << endl << "The Shooting Percentage is " << shootingPercentage << endl; 					
	
	return 0;
}
