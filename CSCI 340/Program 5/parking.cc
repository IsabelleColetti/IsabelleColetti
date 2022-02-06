//***************************************************************************
//
//  Isabelle Coletti
//  z1900409
//  CSCI 340 Section 2
//
//  I certify that this is my own work and where appropriate an extension 
//  of the starter code provided for the assignment.
//
//***************************************************************************

#include "parking.h"

void get_input_vals(const std::string &line, char &xact_type, std::string &license)
{
	//assign the type of action as the first character of the line
	xact_type = line[0];
	//assign the license as the part of the line after the first colon
	//until the last colon
	license = line.substr(2, line.size() - 3);
}

/**
 * The main function for parking.cc
 *
 * @return 0 upon success, and a nonzero integer upon failure.
 *
 ********************************************************************************/
int main()
{
	//declare a garage g to create the "parking lot" deque
	garage g;
	//create a string to hold the line read from stdin
	std::string l;
	//create a char to hold the action
	char act;
	//create a string to hold the license
	std::string li;

	//continue reading lines from stdin until there's nothing left to read
	while(getline(cin, l))
	{
		//call get_input_vals to parse the line
		get_input_vals(l, act, li);
		
		//if the action is an A
		if(act == 'A')
		{
			//call the garage's arrival function
			g.arrival(li);
		}
		//if the action is a D
		else if(act == 'D')
		{
			//call the garage's departure function
			g.departure(li);
		}
		else			//if the action is anything but an A or a D
		{
			//print error message for invalid action
			cout << "\'" << act << "\': invalid action!" << endl << endl;
		}
	}

	return 0;
}