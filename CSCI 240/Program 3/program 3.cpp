/***************************************************************
CSCI 240         Program 3     Fall 2020

Programmer: Isabelle Coletti

Section: 1

Date Due: 9/18

Purpose: This program calculates and displays the shooting
         percentage for multiple games for an NHL team
***************************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int numShots,
	  	numGoals;
	int totalGoals = 0;
	int totalShots = 0;
	int games = 0;
	float shootingPercentage,
		  firstGamePercentage;
	string answer;

	do{
		games++;
		cout << endl << "Enter the number of goals that were scored: " << endl;							//receives goals
		cin >> numGoals;
	
	//checks if number user enetered is less than 0 and prompts user to re-enter value if so
		while(numGoals<0)
		{
			cout << "Error: the number of goals must be greater than 0. Enter a new value: " << endl;
			cin >> numGoals;
		}
		
		totalGoals += numGoals;

		cout << endl << "Enter the number of scores that were attempted: " << endl;			  			//receives scores
		cin >> numShots;
	
	//checks if number user enetered is less than 0 and prompts user to re-enter value if so
		while(numShots<=0)
		{
			cout << "Error: the number of shot attempts must be greater than 0. Enter a new value: " << endl;
			cin >> numShots;
		}
		
		totalShots += numShots;
		
		if(games==1)
		{
			firstGamePercentage = (float)totalGoals / (float)totalShots * 100;
		}

	//calculates shooting percentage as a float and formats number when displayed so there is only one digit after the decimal point, then displays result
		shootingPercentage = (float)totalGoals / (float)totalShots * 100;
		cout << setprecision(1) << fixed;
		cout << endl << "The Team Shooting Percentage after " << games << " game(s) is " << shootingPercentage << "%." << endl << endl; 	
		
		cout << "Is there more data to be entered? (y or n)" << endl;
		cin >> answer;				
	}
	while(answer == "y");
	
	cout << endl << "The change in Team Shooting Percentage after " << games << " game(s) is " << shootingPercentage - firstGamePercentage << "%." << endl;
	
	return 0;
}
