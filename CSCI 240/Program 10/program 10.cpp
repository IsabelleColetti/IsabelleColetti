/***************************************************************
CSCI 240         Program 10     Fall 2020

Programmer: Isabelle Coletti

Section: 1

Date Due: 12/4

Purpose: To simulate a simplified version of the game Twenty-One.

***************************************************************/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <cstring>


using namespace std;

/**********   Put the Card class definition between these lines   **********/

class Card
{
	public:
		Card();
		void setCard( int, const char * );
		int getFace();
		const char * getSuit();
		void displayCard();
		
	private:
		int faceVal;
		char suit[9];
};

/***************************************************************************/


//Definition for a class that represents a deck of cards

class DeckOfCards
{
public:
  DeckOfCards();

  Card draw();
  void shuffle();
  bool isEmpty();

private:
  static const int MAX_CARDS = 52;       //Maximum number of cards in a deck
  static const int NUM_SUITS = 4;        //Number of card suits
  static const int CARDS_PER_SUIT = 13;  //Number of cards of each suit

  Card deck[MAX_CARDS];     //The deck of cards
  int topCard;              //The subscript of the card on the top of the deck
};


int main()
{
	//Set the seed value for the random number generator
	srand(0);
	//create DeckOfCards object
	DeckOfCards myDeck;
	//create Card object
	Card myCard;
	//create 5 integers
	//number of current player
	int currentPlayer = 1;
	//sum of the current player's points
	int currentSum;
	//number of points to be won during a turn
	int numPoints = 0;
	//set player 1's score to 0
	int score1 = 0;
	//set player 2's score to 0
	int score2 = 0;
	
	//loop to run while the deck is not empty
	while(!myDeck.isEmpty())
	{
		//display whta player is playing
		cout << "Player " << currentPlayer << endl;
		//set current player's sum to 0
		currentSum = 0;
		//loop to run 3 times and while the deck is not empty and the current player's sum is less than 21
		for(int x = 0; x<3 and !myDeck.isEmpty() and currentSum<21; x++)
		{
			//call draw() function to draw a card from the deck and save it in my card object
			myCard = myDeck.draw();
			//display the card that was drawn by calling the displayCard() function
			myCard.displayCard();
			//check if card is an ace
			if(myCard.getFace()==1)
			//add 11 to the current sum if card is an ace
				currentSum += 11;
			//check if the card drawn is a jack, queen, or king
			else if(myCard.getFace()==11 or myCard.getFace()==12 or myCard.getFace()==13)
			//add 10 to the current sum if the card is a jack, queen, or king
				currentSum += 10;
			else 
			//otherwise, just add the face value of the card
				currentSum += myCard.getFace();
			//display the sum of the current player's cards
			cout << "Sum of the cards drawn: " << currentSum << endl;
		}
		cout << endl;
		//check if the current player's sum is greater than 21
		if(currentSum > 21)
		{
			//display losing message
			cout << "Sorry Player " << currentPlayer << "! Busted!" << endl;
			cout << "-------" << endl << endl;
			//set the number of points to be won during a turn to 0
			numPoints = 0;
		}
		//check if the current player's sum is equal to 21
		else if(currentSum==21)
		{
			//display winning message
			cout << "Congrats Player " << currentPlayer << ", you won 15 points!" << endl;
			cout << "-------" << endl << endl;
			//set the number of points to be won during a turn to 15
			numPoints = 15;
		}
		else
		{
			//display a winning message
			cout << "Congrats Player " << currentPlayer << ", you won 10 points!" << endl;
			cout << "-------" << endl << endl;
			//set the number of points to be won during a turn to 10
			numPoints = 10;
		}
		//check if the current player is player 1
		if(currentPlayer == 1)
		//give player 1 the points for the round
			score1 += numPoints;
		else
		//give player 2 the points for the round
			score2 += numPoints;
			
		//check if the current player is player 1
		if(currentPlayer == 1)
		//if so, change to player 2
			currentPlayer = 2;
		else 
		//if not, change to player 1
			currentPlayer = 1;
	}
	//display both players' scores
	cout << "Player 1 score: " << score1 << endl;
	cout << "Player 2 score: " << score2 << endl << endl;
	
	//check if player 1's score is larger than player 2's score
	if(score1 > score2)
	//display winning message
		cout << "Player 1 won!" << endl;
	//check if player 2's score is larger than player 1's score
	else if(score2 > score1)
	//display winning message
		cout << "Player 2 won!" << endl;
	else 
	//if scores are the same, display draw message
		cout << "Draw!" << endl;

return 0;
}


/**********   Code the Card class methods between these lines   **********/

/***************************************************************
Function: Card( ) 

Use: This constructor assigns the face value of the card to a 
	 random number and assigns a random suit to the card.  

Arguments: none

Returns: nothing

Note: None
***************************************************************/

Card::Card()
{
	int random;
	//create a random number between 1 and 13 and save it as the face value
	faceVal = rand()%13+1;
	//create a random number between 1 and 4 and save it as the face value
	random = rand()%4+1;
	switch(random)
	{
		//if the random number equals 1, save the suit as Clubs
		case 1: strcpy(suit, "Clubs");
			break;
		//if the random number equals 2, save the suit as Diamonds
		case 2: strcpy(suit, "Diamonds");
			break;
		//if the random number equals 3, save the suit as Hearts
		case 3: strcpy(suit, "Hearts");
			break;
		//if the random number equals 4, save the suit as Spades
		case 4: strcpy(suit, "Spades");
			break;
		default: break;
	}
}

/***************************************************************
Function: setCard( int newFace, const char * newSuit ) 

Use: This function changes the suit and face value of the 
	 card to a new suit and face value. 

Arguments: int newFace - represents the new face value of the card
		   
		   const char * newSuit - represents the new suit of 
		   						 the card

Returns: nothing

Note: The default face value and suit for invalid input is Ace
	 of Hearts.
***************************************************************/

void Card::setCard( int newFace, const char * newSuit )
{
	//check if the passed face value is between 1 and 13, change the face value to the passed value
	if(newFace<=13 and newFace>=1)
		faceVal = newFace;
	else
	//otherwise, change the face value to 1
		faceVal = 1;
	//check if the new suit value is equal to Clubs
	if(strcmp(newSuit, "Clubs")==0)
	//change the suit to the new value
		strcpy(suit, newSuit);
	//check if the new suit value is equal to Diamonds
	else if(strcmp(newSuit, "Diamonds")==0)
	//change the suit to the new value
		strcpy(suit, newSuit);
	//check if the new suit value is equal to Hearts
	else if(strcmp(newSuit, "Hearts")==0)
	//change the suit to the new value
		strcpy(suit, newSuit);
	//check if the new suit value is equal to Spades
	else if(strcmp(newSuit, "Spades")==0)
	//change the suit to the new value
		strcpy(suit, newSuit);
	else
	//otherwise, change the suit to Hearts
		strcpy(suit, "Hearts");
}

/***************************************************************
Function: getFace( ) 

Use: This function returns the face value of the card.  

Arguments: none

Returns: an integer representing the face value of the card

Note: None
***************************************************************/

int Card::getFace()
{
	return faceVal;
}

/***************************************************************
Function: getSuit( ) 

Use: This function returns the suit of the card.

Arguments: none

Returns: a char array representing the suit of the card

Note: None
***************************************************************/

const char * Card::getSuit()
{
	return suit;
}

/***************************************************************
Function: displayCard( ) 

Use: This function displays the face value and suit of the card.

Arguments: none

Returns: nothing

Note: None
***************************************************************/

void Card::displayCard()
{
	//check if the face value is 1
	if(faceVal==1)
	//display Ace
		cout << "Ace";
	//check if the face value is 11
	else if(faceVal==11)
	//display Jack
		cout << "Jack";
	//check if the face value is 12
	else if(faceVal==12)
	//display Queen
		cout << "Queen";
	//check if the face value is 13
	else if(faceVal==13)
	//display King
		cout << "King";
	else
	//otherwise, just display the face value of the card
		cout << faceVal;
		
	//display the suit
	cout << " of " << suit << endl;
}

/*************************************************************************/



/***************************************************************
Constructor

Use: This creates a DeckOfCards object and then shuffles the
     cards

Arguments: none

Note: -1 is used to signal that no cards have been removed from
      the deck
***************************************************************/

DeckOfCards::DeckOfCards()
{
//An array of the 4 possible values for the card suits
const char suitVals[NUM_SUITS][9] = { "Clubs", "Diamonds", "Hearts", "Spades" };

int cardSub = 0;    //subscript to process the deck of cards

//Go through all 52 spots in the array of Cards and put a card
//at the location

for( int suitSub = 0; suitSub < NUM_SUITS; suitSub++ )
  {
  //For each of the suits, put in all of the cards for the suit
  for( int faceVal = 1; faceVal <= CARDS_PER_SUIT; faceVal++ )
    {
    //Put the card into the deck
    deck[ cardSub ].setCard( faceVal, suitVals[suitSub] );

    //Move to the next card in the deck
    cardSub++;
    }
  }

//shuffle the playing cards
shuffle();

//Set the top card location to -1 to indicate the deck is brand new
topCard = -1;
}



/***************************************************************
Method:  Card draw()

Use: This method draws a card from the top of the deck

Arguments: none

Returns: a Card object (the card on the top of the deck)
***************************************************************/

Card DeckOfCards::draw()
{
//Increment to get the subscript of the current top card
topCard++;

//return the card that is currently on the top of the deck
return deck[topCard];
}



/***************************************************************
Method:  void shuffle()

Use: This method shuffles the deck of cards

Arguments: none

Returns: nothing

Note: this method uses the random_shuffle function that is part
      of the algorithm library to shuffle the 52 cards
***************************************************************/

void DeckOfCards::shuffle()
{
//Shuffle all 52 cards that are in the deck

random_shuffle(deck, deck+MAX_CARDS);
}


/***************************************************************
Method:  bool isEmpty()

Use: This method determines if the deck of cards is empty( have
     all of the cards been drawn)

Arguments: none

Returns: boolean value: true if all of the cards have been drawn
                        false if there are still cards in the deck
***************************************************************/

bool DeckOfCards::isEmpty()
{
//if topCard subscript plus 1 is greater than 52, the deck is
//empty. Otherwise, there are cards that can be drawn.

return topCard + 1 >= MAX_CARDS;
}
