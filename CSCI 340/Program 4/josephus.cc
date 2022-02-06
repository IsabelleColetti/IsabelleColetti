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
#include "josephus.h"

void init_vals(list<string> &L, args &in)
{
	//read in the N value
	cout << "Number of people? ";
	cin >> in.N;
	//read in the M value
	cout << "Index for elimination? ";
	cin >> in.M;
	//read in the K value
	cout << "Index for printing? ";
	cin >> in.K;

	//resize the list to the N value entered
	L.resize(in.N);
	//generate the names in the list
	generate(L.begin(), L.end(), SEQ(in.N));
}

void print_list(const list<string> &L, const unsigned &cnt)
{
	//if there have been zero removals so far
	if(cnt == 0)
	{
		//print the original list
		cout << endl << "Initial group of people" << endl << "-----------------------" << endl;
	}
	else
	{
		//otherwise, if there are less than 10 eliminations, format the output correctly
		if(cnt < 10)
			cout << endl << "After eliminating " << cnt << "th person" << endl << "----------------------------" << endl;
		//if there are more than 10 eliminations, format the output correctly with an extra -
		else
			cout << endl << "After eliminating " << cnt << "th person" << endl << "-----------------------------" << endl;
	}

	int line = 0;
	//loop through the list to print each element
	for(auto it = L.begin(); it != L.end(); ++it)
	{
		//only print NO_ITEMS names per line
		if(line != 0 and line % NO_ITEMS == 0)
			cout << endl;
		//print a space after every element
		cout << *it << " ";
		line++;
	}
	cout << endl;
}

int main()
{
	//create the list of names
	list<string> L;
	//create the struct for N, M, and K
	args a;

	//call init_vals to fill the list with names
	init_vals(L, a);
	//print the list before any removals
	print_list(L, 0);

	//create i to keep track of the position in the list
	int i = 0;
	//initialize the number of removals to 0
	unsigned removals = 0;

	//continue removing people until there is only one person left
	while(L.size() > 1)
	{
		//get the position of the Mth person
		i = (i + (a.M - 1)) % L.size();

		//create an iterator pointing to the beginning of the list
		auto it = L.begin();
		//move the iterator to the position of the Mth person
		advance(it, i);
		//erase the Mth person
		L.erase(it);

		//increment the number of removals
		removals++;

		//if there have been K removals, print the list with print_list
		if(removals % a.K == 0)
			print_list(L, removals);
	}
	//print the list once there is only one person remaining
	print_list(L, removals);

	return 0;
}