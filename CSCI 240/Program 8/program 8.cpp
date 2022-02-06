/***************************************************************
CSCI 240         Program 8     Fall 2020

Programmer: Isabelle Coletti

Section: 1

Date Due: 11/15

Purpose: This program displays a quadratic equation,  
		 calculates its vertex coordinates, and determines
		 the concavity of the parabola.  

***************************************************************/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>

using namespace std;

/* Place the Quadratic class definition here */

class Quadratic
{
	public: 
		Quadratic( int, int, int );
		void printEquation();
		double calcX();
		double calcY();
		void printVertex();
		void printConcavity();
		void print();
	private: 
		int a;
		int b;
		int c;
};

int main()
{
//Create a Quadratic object with a-coordinate of 1,
//b-coordinate of 4, and c-coordinate of -5
Quadratic equation1(1, 4, -5);


//Display ONLY the equation for Quadratic 1

cout << "-------------------" << endl
     << "-   Quadratic 1   -" << endl
     << "-------------------" << endl;

equation1.printEquation();



//Test the calcX and calcY methods

//Display the coordinates of the vertex with 4 digits
//after the decimal point
cout << fixed << setprecision(4);

cout << endl
     << "The x-coordinate of the vertex is " << equation1.calcX() << endl;

cout << "The y-coordinate of the vertex is " << equation1.calcY()
     << endl << endl;



//Test the printVertex method
equation1.printVertex();


//Test the printConcavity method
equation1.printConcavity();



//Create a Quadratic object with a-coordinate of -1,
//b-coordinate of 2, and c-coordinate of -1
Quadratic equation2(-1, 2, -1);

//Display the information for Quadratic 2
cout << endl << endl
     << "-------------------" << endl
     << "-   Quadratic 2   -" << endl
     << "-------------------" << endl;

equation2.print();


//Create a Quadratic object with a-coordinate of 1,
//b-coordinate of 0, and c-coordinate of 25
Quadratic equation3(1, 0, 25);

//Display the information for Quadratic 3
cout << endl
     << "-------------------" << endl
     << "-   Quadratic 3   -" << endl
     << "-------------------" << endl;

equation3.print();


//Create a Quadratic object with a-coordinate of -12,
//b-coordinate of 2, and c-coordinate of 3
Quadratic equation4(-12, 2, 3);

//Display the information for Quadratic 4
cout << endl << endl
     << "-------------------" << endl
     << "-   Quadratic 4   -" << endl
     << "-------------------" << endl;

equation4.print();


//Create a Quadratic object with a-coordinate of 12,
//b-coordinate of 2, and c-coordinate of 3
Quadratic equation5(12, 2, 3);

//Display the information for Quadratic 5
cout << endl << endl
     << "-------------------" << endl
     << "-   Quadratic 5   -" << endl
     << "-------------------" << endl;

equation5.print();


//Create a Quadratic object with a-coordinate of 0,
//b-coordinate of -3, and c-coordinate of 0
Quadratic equation6(0, -3, 0);

//Display the information for Quadratic 6
cout << endl
     << "-------------------" << endl
     << "-   Quadratic 6   -" << endl
     << "-------------------" << endl;

equation6.print();

return 0;
}

/* Code the constructor and methods for the Quadratic
class below this comment.*/

/***************************************************************
Function: Quadratic( int aTerm, int bTerm, int cTerm ) 

Use: This constructor assigns the 3 arguments to variables
	 a, b, and c.  

Arguments: int aTerm - represents the a coefficient of
		   the quadratic equation.
		   
		   int bTerm - represents the b coefficient of
		   the quadratic equation.
		   
		   int cTerm - represents the c coefficient of
		   the quadratic equation.

Returns: nothing

Note: None
***************************************************************/

Quadratic::Quadratic( int aTerm, int bTerm, int cTerm )
{
	//check if a coefficient is 0 and set to 1 if so
	if(aTerm == 0)
		a = 1;
	//if a is not 0, then assign a to whatever is passed through constructor
	else
		a = aTerm;
	//assign b and c to what was passed through constructor 
	b = bTerm;
	c = cTerm; 
}

/***************************************************************
Function: void printEquation()

Use: This function prints out the equation with its coefficients
	 and x terms. 

Arguments: none

Returns: nothing

Note: None
***************************************************************/

void Quadratic::printEquation()
{
	//print out the coefficients with x terms
	cout << a << "x^2 + " << b << "x + " << c << " = 0" << endl;
}

/***************************************************************
Function: double calcX()

Use: This function calculates the x-coordinate of the vertex
	 of the quadratic equation. 

Arguments: none

Returns: a double representing the x-coordinate of the vertex

Note: None
***************************************************************/

double Quadratic::calcX()
{
	//delcare x-coordinate
	double xCoord;
	//calculate x-coordinate by doing -b/2a
	xCoord = (double)(b*-1)/(2*a);
	//return x-coordinate
	return xCoord; 
}

/***************************************************************
Function: double calcY()

Use: This function caluclates the y-coordinate of the vertex
	 of the quadratic equation. 

Arguments: none

Returns: a double representing the y-coordinate of the vertex

Note: None
***************************************************************/

double Quadratic::calcY()
{
	//declare y-coordinate variable 
	double yCoord;
	//calculate the y-coordinate using ax^2*bx+c, getting the x-coordinate by calling the function
	yCoord = (double)(a*(calcX()*calcX()) + b*calcX() + c);
	//return the y-coordinate 
	return yCoord;
}

/***************************************************************
Function: void printVertex()

Use: This function prints out the coordinates of the vertex. 

Arguments: none

Returns: nothing

Note: None
***************************************************************/

void Quadratic::printVertex()
{
	//print the vertex, getting the coordinates from respective x and y function
	cout << setprecision(4) << fixed << "Vertex Coordinates: (" << calcX() << "," << calcY() << ")" << endl;
}

/***************************************************************
Function: void printConcavity()

Use: This function determines if the parabola opens upwards 
	 or downwards and prints out the result. 

Arguments: none

Returns: nothing

Note: None
***************************************************************/

void Quadratic::printConcavity()
{
	//check if the a value is positive
	if(a > 0)
		//print that the parabola opens up
		cout << "The parabola opens UPWARD" << endl;
	//check if the a value is negative
	else if(a < 0)
		//print that the parabola opens down
		cout << "The parabola opens DOWNWARD" << endl;
}

/***************************************************************
Function: void print()

Use: This function calls previous print methods and displays
	 the equation, vertex, and concavity. 

Arguments: none

Returns: nothing

Note: None
***************************************************************/

void Quadratic::print()
{
	//call each function
	printEquation();
	printVertex();
	printConcavity();
}
