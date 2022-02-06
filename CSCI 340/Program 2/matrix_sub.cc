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

#include "matrix.h"
#include <iostream>
#include <fstream>
#include <vector>

void open_files(ifstream &is1, ifstream &is2)
{
	//open the first file in read mode
	is1.open(FILE1, ios::in);

	//if there is an error opening the file, print message to stderr
	//and exit with nonzero value
	if(!is1)
	{
		cerr << "Error opening File 1.";
		exit(1);
	}

	//open the second file in read mode
	is2.open(FILE2, ios::in);
	//if there is an error opening the file, print message to stderr
	//and exit with nonzero value
	if(!is2)
	{
		cerr << "Error opening File 2.";
		exit(1);
	}
}

void read_data(ifstream &is, vector<vector<int>> &m)
{
	//loop through the entire two dimensional vector
	for(size_t i = 0; i < m.size(); ++i)
	{
		for(size_t j = 0; j < m[i].size(); ++j)
		{
			int num;
			
			//while the end of file has not been reached, read the next input
			//value into num
			if(!is.eof())
			{
				is >> num;
				
				//store value that was read in m
				m[i][j] = num;
			}
		}
	}

	//close the file
	is.close();
}

void print_data(const vector<vector<int>> &m)
{
	int line = 0;

	//display the size of the matrix
	cout << m.size() << " x " << m[0].size();
	cout << endl << "----------------------------------------------------------------------" << endl;

	//loop through the entire two dimensional vector
	for(size_t i = 0; i < m.size(); ++i)
	{
		for(size_t j = 0; j < m[i].size(); ++j)
		{
			//only print the number of columns items on each line
			if(line != 0 and line % m[i].size() == 0)
			{
				//if the limit on number of items has been reached, print a new line and reset line to 0
				cout << endl;
				line = 0;
			}

			//print each element of m with ITEM_W spaces
			cout << setw(ITEM_W) << m[i][j];
			//increment the number of items on the line
			line++;
		}
	}
	
	//print an empty line
	cout << endl;
}

void gen_data(const vector<vector<int>> &A, const vector<vector<int>> &B, vector<vector<int>> &C)
{
	//loop through C (two dimensional vector)
	for(size_t i = 0; i < C.size(); ++i)
	{
		for(size_t j = 0; j < C[i].size(); ++j)
		{
			//for the number of columns in A, calculate the value of C at that element and add it
			for(size_t k = 0; k < A[i].size(); ++k)
				C[i][j] += A[i][k] * B[k][j];
		}
	}
}
