/******************************************
CSCI 240 		Program 6		Fall 2020

Programmer: Isabelle Coletti

Section: 1

Due date: 10/16

Purpose: This program simulates a game of
		 Craps. It asks the user for a wager,
		 generates random numbers for dice 
		 rolls, and determines if the user 
		 won or lost the game. It also 
		 calculates how much money the user
		 won or lost.
********************************************/

#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

//declare constants
const int INST_WIN1 = 7;
const int INST_WIN2 = 11;
const int INST_LOSS1 = 2;
const int INST_LOSS2 = 3;
const int INST_LOSS3 = 12;

//prototypes

/***************************************************************
Function: int rollTheDice()

Use: This function creates 2 random numbers between 1 and 6 which
	 represent the user's dice rolls. Then it adds them together

Arguments: None

Returns: The sum of the user's dice rolls

Note: None
***************************************************************/
int rollTheDice();

/***************************************************************
Function: bool winner(int roll)

Use: This function determines if the game is won on the come-out

Arguments: roll - an integer that represents the sum of the user's first roll

Returns: True or false, depending on if the game was won or not

Note: Only determines if the game has been won
***************************************************************/
bool winner(int roll);

/***************************************************************
Function: bool craps(int roll)

Use: This function determines if the game is lost on the come-out

Arguments: roll - an integer that represents the sum of the user's first roll

Returns: True or false, depending on if the game was lost or not

Note: Only determines if the game has been lost
***************************************************************/
bool craps(int roll);

/***************************************************************
Function: void rollMore(int point, double wager)

Use: This function continues the craps game after the come-out roll

Arguments: point - an integer that represents the number that needs to
                   be rolled by the player to win the game

           wager - a double that represents the amount the player
                   wagered on the game

Returns: Nothing

Note: None
***************************************************************/
void rollMore( int point, double wager);

/***************************************************************
Function: double getWager()

Use: This function asks the user for a wager amount, and checks to
	 make sure it is at least 5.00 and is a whole number

Arguments: None

Returns: The wager amount

Note: None
***************************************************************/
double getWager();

int main()
{
	//seed random number generator
	srand(34);
	//format output
	cout << setprecision(2) << fixed;
	//get wager and roll amounts from calling the functions
	double wager = getWager();
	int roll = rollTheDice();
	//check if user won on come-out
	if(winner(roll))
	{
		//if user won, display message and give money
		cout << endl << "Winner! Congratulations!" << endl;
		cout << "You won $" << (wager*2) << endl;
	}
	//check if user lost on come-out
	else if(craps(roll))
	{
		//if user lost, display message and take money
		cout << endl << "Craps! You lose!" << endl;
		cout << "You lost $" << wager << endl;
	}
	else
	//continue playing
		rollMore(roll, wager);
		
	return 0;
}


int rollTheDice()
{
	//get random dice rolls
	int dice1 = rand() % 6 + 1;
	int dice2 = rand() % 6 + 1;
	//calculate sum of dice rolls and display it
	int sum = dice1 + dice2;
	cout << "Roll: " << dice1 << " + " << dice2 << " = " << sum << endl;
	//return the sum
	return sum; 
}


bool winner(int roll)
{
	//determine if the roll sum is 7 or 11
	if(roll==INST_WIN1 || roll==INST_WIN2)
		//tell main() user won
		return true;
	else
		//tell main() user did not win
		return false;
}


bool craps(int roll)
{
	//determine is roll sum is 2, 3, or 12
	if(roll==INST_LOSS1 || roll==INST_LOSS2 || roll==INST_LOSS3)
		//tell main() user lost
		return true;
	else
		//tell main() user did not lose
		return false;
}


void rollMore(int point, double wager)
{
	//display the point
	cout << endl << "The point is " << point << endl << endl;
	//initialize the variable that will control the while loop
	bool cont = true;
	while(cont == true)
	{
		//check if dice roll matches point
		if(rollTheDice()==point)
		{
			//tell user they won
			cout << endl << "The point was made. Winner!" << endl;
			//give them their money
			cout << fixed << setprecision(2) << "You won $" << (wager*2) << endl;
			//stop the loop
			cont = false;
			return;
		}
		//check if dice roll is 7
		else if(rollTheDice()==7)
		{
			//tell user they lost
			cout << endl << "You seven'd out! You lose!" << endl;
			//tell them how much money they lost
			cout << fixed << setprecision(2) << "You lost $" << wager << endl;
			//stop the loop
			cont = false;
			return;
		}
	}
}


double getWager()
{
	double wager;
	//ask for wager amount
	cout << "What's your wager (no cents allowed) (minimum: 5.00)? ";
	cin >> wager; 
	//if the wager is less than 5.00, ask user for a new wager
	while(wager < 5.00)
	{
		cout << setprecision(2) << fixed << "You can't bet $" << wager << ". The minimum bet is 5.00. Please try again: ";
		cin >> wager;
	}
	//determine if the wager is a whole number, and if not, give the user their change back
	double change = (wager - (int)wager);
	if(change > 0)
	{
		//adjust wager so it is a whole number, giving back excess change
		wager -= change; 
		cout << setprecision(2) << fixed << "You can have $" << change << " back. The wager cannot have cents. Your wager is now " << wager << endl;
	}
	cout << endl;
	return wager;
}

