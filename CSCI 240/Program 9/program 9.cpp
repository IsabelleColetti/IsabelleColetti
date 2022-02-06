/***************************************************************
CSCI 240         Program 9     Fall 2020

Programmer: Isabelle Coletti

Section: 1

Date Due: 11/24

Purpose: This program contains a class Rational which represents
		 a rational number or fraction. The methods allow the
		 user to alter the rational number by adding,
		 subtracting, multiplying, dividing, and changing the
		 numerator or denominator. 

***************************************************************/

#include <iomanip>
#include <iostream>

using namespace std;

//class definition
class Rational
{
	public:
		Rational();
		Rational( int, int );
		void displayFloat();
		void displayFraction();
		void display();
		void setNumerator( int );
		void setDenominator( int );
		void setRational( int, int );
		Rational add( int, int );
		Rational subtract( int, int );
		Rational multiply( int, int );
		Rational divide( int, int );
	private:
		int numerator, denominator;
		void reduce();
		int GCD( int, int );
		int LCM( int, int );
};

int main()
{
	/*cout << "*** Testing the constructors ***" << endl << endl;
	//creating all of my objects
	Rational obj1 = Rational();
	Rational obj2 = Rational(11,30);
	Rational obj3 = Rational(2,30);
	Rational obj4 = Rational(5,6);
	Rational obj5 = Rational(3,7);
	
	//test default constructor with object 1
	cout << "The default constructor produces ";
	obj1.displayFraction();
	cout << endl << endl;
	
	//test alternate constructor
	//object 2
	cout << "The alternate constructor with 11, 30 produces ";
	obj2.display();
	cout << endl;
	
	//object 3
	cout << setw(46) << "with 2, 30 produces ";
	obj3.display();
	cout << endl;
	
	//object 4
	cout << setw(45) << "with 5, 6 produces ";
	obj4.display();
	cout << endl;
	
	//object 5
	cout << setw(45) << "with 3, 7 produces ";
	obj5.display();
	cout << endl << endl;
	
	cout << "*** Testing the set methods ***" << endl << endl;
	//object 3
	//display what I am going to do and print original fraction
	cout << "setNumerator(8) changes ";
	obj3.displayFraction();
	cout << " to ";
	//call setNumerator()
	obj3.setNumerator(8);
	//print updated fraction
	obj3.displayFraction();
	cout << endl << endl;
	
	//object 4
	//display what I am going to do and print original fraction
	cout << "setDenominator(73) changes ";
	obj4.displayFraction();
	cout << " to ";
	//call setNumerator()
	obj4.setDenominator(73);
	//print updated fraction
	obj4.displayFraction();
	cout << endl << endl;
	
	//object 1
	//display what I am going to do and print original fraction
	cout << "setRational(4,6) changes ";
	obj1.displayFraction();
	cout << " to ";
	//call setNumerator()
	obj1.setRational(4,6);
	//print updated fraction
	obj1.displayFraction();
	cout << endl << endl << endl;
	
	cout << "*** Testing the add method ***" << endl << endl;
	//object 4
	//save result of add() as new object
	Rational obj6 = obj4.add(3,7);
	//display original fraction
	obj4.displayFraction();
	//display what is being done to the original fraction
	cout << " + 3/7 = ";
	//display the result in fraction and decimal format
	obj6.display();
	cout << endl << endl;
	
	//object 6
	//display original fraction before modifying
	obj6.displayFraction();
	//display what is being done to original fraction
	cout << " + 3/7 = ";
	//call add()
	obj6 = obj6.add(3,7);
	//display result in fraction and decimal format
	obj6.display();
	cout << endl << endl;
	
	//object 3
	//call add function and save result into new object
	Rational obj7 = obj3.add(1,2);
	//display original fraction
	obj3.displayFraction();
	cout << " + 1/2 = ";
	//display result after adding
	obj7.display();
	cout << endl << endl;
	
	//object 1
	//call add function and save result into new object
	Rational obj8 = obj1.add(15,16);
	//display original fraction
	obj1.displayFraction();
	cout << " + 15/16 = ";
	//display result after adding
	obj8.display();
	cout << endl << endl << endl;
	
	cout << "*** Testing the subtract method ***" << endl << endl;
	//object 6
	//call subtract function and save result into new object
	Rational obj9 = obj6.subtract(5,7);
	//display original fraction
	obj6.displayFraction();
	cout << " - 5/7 = ";
	//display result after subtracting
	obj9.display();
	cout << endl << endl;
	
	//object 7
	//call subtract function and save result into new object
	Rational obj10 = obj7.subtract(3,6);
	//display orignal fraction
	obj7.displayFraction();
	cout << " - 3/6 = ";
	//display result after subtracting 
	obj10.display();
	cout << endl << endl;
	
	//object 8
	//call subtract function and save result into new object
	Rational obj11 = obj8.subtract(101,117);
	//display original fraction
	obj8.displayFraction();
	cout << " - 101/117 = ";
	//display result after subtracting 
	obj11.display();
	cout << endl << endl << endl;
	
	cout << "*** Testing the multiply method ***" << endl << endl;
	//object 9
	//call multiply function and save result into new object
	Rational obj12 = obj9.multiply(1,1);
	//display original fraction
	obj9.displayFraction();
	cout << " * 1/1 = ";
	//display result after multiplying
	obj12.display();
	cout << endl << endl;
	
	//object 10
	//call multiply function and save result into new object
	Rational obj13 = obj10.multiply(7,30);
	//display original fraction
	obj10.displayFraction();
	cout << " * 7/30 = ";
	//display result after multiplying
	obj13.display();
	cout << endl << endl;
	
	//object 11
	//call multiply function and save result into new object
	Rational obj14 = obj11.multiply(2,4);
	//display original fraction
	obj11.displayFraction();
	cout << " * 2/4 = ";
	//display result after multiplying
	obj14.display();
	cout << endl << endl << endl;
	
	cout << "*** Testing the divide method ***" << endl << endl;
	//object 9
	//call divide function and save result into new object
	Rational obj15 = obj9.divide(5,8);
	//display original fraction
	obj9.displayFraction();
	cout << " / 5/8 = ";
	//display result after dividing
	obj15.display();
	cout << endl << endl;
	
	//object 13
	//call divide function and save result into new object
	Rational obj16 = obj13.divide(5,15);
	//display original fraction
	obj13.displayFraction();
	cout << " / 5/15 = ";
	//display result after dividing
	obj16.display();
	cout << endl << endl;
	
	//object 5
	//call divide function and save result into new object
	Rational obj17 = obj5.divide(2,4);
	//display original fraction
	obj5.displayFraction();
	cout << " / 2/4 = ";
	//display result after dividing
	obj17.display();
	cout << endl;
	*/
	
	Rational myRat(1,3);
	myRat.displayFraction();
return 0;
}

/***************************************************************
Function: Rational( ) 

Use: This constructor assigns the numerator and denominator
	 of the fraction to 1 and 1, respectively.  

Arguments: none

Returns: nothing

Note: None
***************************************************************/

Rational::Rational()
{
	//set both the numerator and denominator to 1
	numerator = 1;
	denominator = 1;
}

/***************************************************************
Function: Rational( int num, int den ) 

Use: This constructor assigns the numerator and denominator
	 of the fraction to whatever is passed through the 
	 arguments. 

Arguments: int num - represents the number to be saved as
			the numerator.
		   int den - represents the number to be saved as
		    the denominator.

Returns: nothing

Note: None
***************************************************************/


Rational::Rational( int num, int den )
{
	/*call the setRational function to set the numerator and denominator
	to whatever is passed through the arguments*/
	
	setRational(num,den);
}

/***************************************************************
Function: void setNumerator( int newNum ) 

Use: This function changes the numerator to whatever is passed
	 through the argument.

Arguments: int newNum - represents the number the numerator
		   should be changed to.

Returns: nothing

Note: None
***************************************************************/

void Rational::setNumerator( int newNum )
{
	//replace the old numerator with the new value
	numerator = newNum;
	//reduce the fraction
	reduce();
}

/***************************************************************
Function: void setDenominator( int newDen ) 

Use: This function changes the denominator to whatever is 
	 passed through the argument. 

Arguments: int newDen - represents the number the denominator
		   should be changed to. 

Returns: nothing

Note: None
***************************************************************/

void Rational::setDenominator( int newDen )
{
	//replace the old denominator with the new value
	denominator = newDen;
	//reduce the fraction
	reduce();
}

/***************************************************************
Function: void setRational( int newNum, int newDen )

Use: This function changes the numerator and denominator to 
	 whatever is passed through the arguments. 

Arguments: int newDen - represents the number the denominator
		   should be changed to. 
		   int newNum - represents the number the numerator
		   should be changed to.

Returns: nothing

Note: None
***************************************************************/

void Rational::setRational( int newNum, int newDem )
{
	//replace the numerator and denominator with their new values
	numerator = newNum;
	denominator = newDem;
	//reduce the fraction
	reduce();
}

/***************************************************************
Function: void displayFloat() 

Use: This function displays the fraction as a decimal with 5
	 digits after the decimal. 

Arguments: none

Returns: nothing

Note: None
***************************************************************/

void Rational::displayFloat()
{
	//print the fraction as a decimal with 5 digits after the decimal point
	cout << setprecision(5) << fixed << (double)numerator/denominator;
}

/***************************************************************
Function: void displayFraction() 

Use: This function displays the fraction as a fraction, with
	 the numerator and denominator separated by a /.

Arguments: none

Returns: nothing

Note: None
***************************************************************/

void Rational::displayFraction()
{
	//print the fraction as a fraction with a / between the numerator and denominator
	cout << numerator << "/" << denominator;	
}

/***************************************************************
Function: void display() 

Use: This function displays the fraction as a decimal and as 
	 a fraction by calling the other display functions. 

Arguments: none

Returns: nothing

Note: None
***************************************************************/

void Rational::display()
{
	//call the displayFraction function to display the fraction as a fraction
	displayFraction();
	cout << " or ";
	//call the displayFloat function to display the fraction as a decimal
	displayFloat();
}

/***************************************************************
Function: Rational add( int addNum, int addDen ) 

Use: This function adds 2 fractions together.

Arguments: int addNum - represents the numerator of the second
		   fraction to be added.
		   int addDen - represents the denominator of the 
		   second fraction to be added. 

Returns: a Rational object representing the sum of the 2 fractions

Note: None
***************************************************************/

Rational Rational::add( int addNum, int addDen )
{
	//find the LCM by calling the LCM function and save it
	int myLCM = LCM(addDen, denominator);
	/*calculate the amount by which the current instance's numerator must be divided by
	to be equal to a fraction with the LCM as a denominator*/
	int localFactor = myLCM/denominator;
	/*calculate the amount by which the numerator of the passed arguments must be divided by
	to be equal to a fraction with the LCM as a denominator*/
	int passedFactor = myLCM/addDen;
	//calculate the new numerator of the current instance by multiplying the numerator by the factor found earlier
	int updatedLocalNum = localFactor*numerator;
	//calculate the new numerator of the passed arguments by multiplying the other numerator by the factor found earlier
	int updatedPassedNum = passedFactor*addNum;
	/*create a Rational object with the sum of the current instance and passed numerators
	as its numerator and the LCM as its denominator*/
	Rational addedFrac = Rational(updatedLocalNum+updatedPassedNum, myLCM);
	//return the Rational object
	return addedFrac;
}

/***************************************************************
Function: Rational subtract( int subNum, int subDen )

Use: This function subtracts 1 fraction from another.

Arguments: int subNum - represents the numerator of the fraction
		   to be subtracted.
		   int subDen - represents the denominator of the fraction
		   to be subtracted. 

Returns: a Rational object representing the difference of the 
		 2 fractions

Note: None
***************************************************************/

Rational Rational::subtract( int subNum, int subDen )
{
	//find the LCM by calling the LCM function and save it
	int myLCM = LCM(subDen, denominator);
	/*calculate the amount by which the current instance's numerator must be divided by
	to be equal to a fraction with the LCM as a denominator*/
	int localFactor = myLCM/denominator;
	/*calculate the amount by which the numerator of the passed arguments must be divided by
	to be equal to a fraction with the LCM as a denominator*/
	int passedFactor = myLCM/subDen;
	//calculate the new numerator of the current instance by multiplying the numerator by the factor found earlier
	int updatedLocalNum = localFactor*numerator;
	//calculate the new numerator of the passed arguments by multiplying the other numerator by the factor found earlier
	int updatedPassedNum = passedFactor*subNum;
	/*create a Rational object with the difference of the current instance and passed numerators
	as its numerator and the LCM as its denominator*/
	Rational subFrac = Rational(updatedLocalNum-updatedPassedNum, myLCM);
	//return the Rational object
	return subFrac;
}

/***************************************************************
Function: Rational multiply( int multNum, int multDen )

Use: This function multiplies 2 fractions.

Arguments: int multNum - represents the numerator of the second
		   fraction to be multiplied. 
		   int multDen - represents the denominator of the second
		   fraction to be multiplied. 

Returns: a Rational object representing the product of the 2
		 fractions

Note: None
***************************************************************/

Rational Rational::multiply( int multNum, int multDen )
{
	/*create Rational object with the product of the current instance and passed numerators
	as its numerator and the product of the current instance and passed denominators as its denominator*/
	Rational multFrac = Rational(multNum*numerator, multDen*denominator);
	//return the Rational object
	return multFrac;
}

/***************************************************************
Function: Rational divide( int divNum, int divDen )

Use: This function divides 1 fraction by another.

Arguments: int divNum - represents the numerator of the fraction
		   to be divided by.
		   int divDen - represents the denominator of the fraction
		   to be divided by. 

Returns: a Rational object representing the quotient of the 2
		 fractions

Note: None
***************************************************************/

Rational Rational::divide( int divNum, int divDen )
{
	/*create Rational object with the product of the current instance's numerator and passed denominator
	as its numerator and the product of the current instance's denominator and passed numerator as its denominator,
	in order to multiply by the reciprocal*/
	Rational divFrac = Rational(numerator*divDen, denominator*divNum);
	//return the Rational object 
	return divFrac;
}

/***************************************************************
Function: void reduce()

Use: This function reduces a fraction by dividng the numerator
	 and denominator by the GCD.

Arguments: none

Returns: nothing

Note: None
***************************************************************/

void Rational::reduce()
{
	//find the GCD by calling the GCD function
	int myGCD = GCD(numerator, denominator);
	//divide the nuemrator by the GCD to reduce it
	numerator /= myGCD;
	//divide the denominator by the GCD to reduce it
	denominator /= myGCD;
}

/***************************************************************
Function: int GDC( int val1, int val2 )

Use: This function finds the greatest common divisor of a numerator
	 and denominator passed through the arguments. 

Arguments: int val1 - represents either a numerator or denominator
		   to be compared.
		   int val2 - represents either a numerator or denominator
		   to be compared. 

Returns: an integer representing the GCD

Note: None
***************************************************************/

int Rational::GCD( int val1, int val2 )
{
int remainder, num1, num2;

//set variables num1 and num2 to the two passed in values
num1 = val1;
num2 = val2;

//continue dividing num1 by num2 until a remainder of 0 is found
while (true)
  {
  //find the remainder when num1 is divided by num2
  remainder = num1 % num2;

  //if the remainder is 0, get out of the loop
  if( remainder == 0 )
    break;

  //set num1 to the current num2 value
  num1 = num2;
  
  //set num2 to the remainder
  num2 = remainder;
  }//end while

//After the loop is done executing, the variable num2 will contain the
//greatest common divisor.
return num2;
}

/***************************************************************
Function: int LCM( int val1, int val2 )

Use: This function finds the least common multiple of 2 denominators.

Arguments: int val1 - represents one denominator to be compared.
		   int val2 - represents one denominator to be compared. 

Returns: an integer representing the LCM of the 2 denominators

Note: None
***************************************************************/

int Rational::LCM( int val1, int val2 )
{
int num1, num2, lcm;

//set variables num1 and num2 to the two passed in values
num1 = val1;
num2 = val2;

//set lcm to the first passed in value
lcm = num1;

//while lcm is less than or equal to the product of num1 and num2
while( lcm <= num1 * num2 )
  {
  //if the remainder of lcm divided by num1 is 0 and
  //   the remainder of lcm divided by num2 is 0, get out of the loop
  if( lcm % num1 == 0 and lcm % num2 == 0 )
    break;

  //increment lcm by 1
  lcm++;
  }//end while

//return the least common multiple
return lcm;
}
