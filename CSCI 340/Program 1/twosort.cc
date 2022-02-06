/*
	Isabelle Coletti
	z1900409
	CSCI 340 Section 2
	
	I certify that this is my own work and where appropriate an extension 
	of the starter code provided for the assignment.
*/

#include "twosort.h"
#include <iostream>
#include <vector>
#include <iomanip>
#include <bits/stdc++.h>

using namespace std;

/**
 * The main function of twosort.
 *
 * @return 0, an integer, upon success.
 *
 ********************************************************************************/

int main()
{
	int linearCount = 0;				//number of successful linear searches
	int binaryCount = 0;				//number of successful binary searches

	//define empty vector of size ARRAY_SIZE
	std::vector<int> v1(ARRAY_SIZE);
	//define empty vector of size TEST_ARRAY_SIZE
	std::vector<int> v2(TEST_ARRAY_SIZE);

	//call generateVectors to fill the vectors with random numbers
	generateVectors(v1, v2, SEED1, SEED2);
	
	cout << endl;

	//print the elements of vector 1
	printVector(v1);
	cout << endl;

	//sort vector 1
	sortVector(v1);

	//print the elements of vector 2
	printVector(v1);
	cout << endl;

	//print the elements of vector 2
	printVector(v2);

	//search vector 1 for elements of vector 2 and save the number of 
	//successful searches in linearCount
	linearCount = searchVector(v1, v2, linearSearch);

	cout << "Linear Search: Percent of Successful Searches = ";
	//print the percent of successful linear searches
	printStat(linearCount, TEST_ARRAY_SIZE);
	cout << "%" << endl;
	
	//search vector 1 for elements of vector 2 and save the number of
	//successful searches in binaryCount
	binaryCount = searchVector(v1, v2, binarySearch);

	cout << "Binary Search: Percent of Successful Searches = ";
	//print the percent of successful binary searches
	printStat(binaryCount, TEST_ARRAY_SIZE);
	cout << "%" << endl;

	return 0;
}

void generateVectors(vector<int> &v1, vector<int> &v2, int s1, int s2)
{
	//seed the random generator with s1
	srand(s1);
	//fill vector 1 with random numbers
	for(int i = 0; i < ARRAY_SIZE; i++)
	{
		//generate a random integer in the range
		v1[i] = rand() % (HIGH - LOW + 1) + LOW;
	}

	//seed the random generator with s2
	srand(s2);
	//fill vector 2 with random numbers
	for(int i = 0; i < TEST_ARRAY_SIZE; i++)
	{
		//generate a random integer in the range
		v2[i] = rand() % (HIGH - LOW + 1) + LOW;
	}
}

bool linearSearch(const vector<int> &v, int x)
{
	//used STL find to search for x in v
	if(find(v.begin(), v.end(), x) != v.end())
		return true;			//if x is found, return true
	return false;				//otherwise return false
}

bool binarySearch(const vector<int> &v, int x)
{
	//use STL binary_search to find x in v
	return binary_search(v.begin(), v.end(), x);			//return true if x is found, false otherwise
}

int searchVector(const vector<int> &v1, const vector<int>& v2, bool(*p)(const vector<int> &, int))
{
	int num = 0;
	int key;

	//loop through entire vector v2
	for(size_t i = 0; i < TEST_ARRAY_SIZE; i++)
	{
		//make key the current value in v2
		key = v2.at(i);
		if(p(v1, key))				//call p() for each element of vector v2 in vector v1
			num++;						//if p() is successful, add to the number of successful searches
	}

	return num;						//return the number of successful searches
}

void sortVector(vector<int> &v)
{
	//use STL sort to sort v in ascending order
	std::sort(v.begin(), v.end());
}

void printVector(const vector<int > &v)
{
	int line = 0;

	//loop through the entire vector
	for(size_t i = 0; i < v.size(); ++i)
	{
		//make sure there are only NUM_ITEMS items on each line
		if(i % NUM_ITEMS == 0 and i != 0)
		{
			cout << endl;
			line = 0;					//reset the number of items on the line to 0
		}

		//check if the item is the last one in the row or last
		//one in the vector
		if(line == 15 or i == v.size() - 1)
			cout << setw(ITEM_W) << v.at(i);					//if so, print without a space
		else
			cout << setw(ITEM_W) << v.at(i) << " ";		//otherwise, print space after element

		line++;							//increment line
	}

	cout << endl;					//print an extra line
}

void printStat(int totalSucCnt, int vectorSz)
{
	//calculate the percent of successful searches
	double percent = ((double)totalSucCnt / vectorSz) * 100;
	//display the percent with correct formatting
	cout << setprecision(2) << fixed << percent;
}

