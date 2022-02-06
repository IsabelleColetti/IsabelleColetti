/********************************************************
CSCI 240			Program 5			Fall 2020

Programmer: Isabelle Coletti

Section: 1

Date due: 10/9

Purpose: This program generates three random salaries for 3 jobs,
		then calculates the amount of money earned after a
		randomly generated number of days worked. 
********************************************************/
#include <iomanip>
#include <iostream>
#include <cstdlib>

using namespace std;

//declare constants
const int MAX_SAL = 10;
const int MAX_NUMDAYS = 30;

int main()
{
	int job1,
		numDays1,
		job2,
		numDays2,
		job3,
		numDays3;
	double sal1,
			sal2,
			sal3;
			
	//seed random number generator
	srand(15);
	//generate first job base salary
	job1 = rand() % MAX_SAL + 1;
	sal1 = (double) job1 / 100;
	cout << setprecision(2) << fixed;
	double incomeTotal1 = 0;
	double incomeTotal2 = 0;
	double incomeTotal3 = 0;
	//generate random number of days to be worked
	numDays1 = rand() % MAX_NUMDAYS + 1;
	
	//display the starting salary and number of days to be worked
	cout << "********" << setw(9) << "Job 1" << setw(12) << "********" << endl << endl << "Starting Salary: $" << sal1 << endl << "Number of days to work: " << numDays1 << endl << endl;
	
	//display salary each day in a for loop, then display the total amount earned from job 1
	for(int x = 0; x < numDays1; x++)
	{
		if(x==0)
		{
			cout << "Day " << (x+1) << ":" << setw(16) << sal1 << endl;
		}
		else
		{
			if(sal1 >= 10)
				cout << "Day " << (x+1) << ":" << setw(15) << (sal1*=2) << endl;
			else
				cout << "Day " << (x+1) << ":" << setw(16) << (sal1*=2) << endl;
		}
		incomeTotal1 += sal1;
	}
	
	cout << endl << "For Job 1, you earned $" << incomeTotal1 << " in " << numDays1 << " day(s)." << endl << endl << endl;
	
	//generate base salary for job 2 and number of days to be worked
	job2 = rand() % MAX_SAL + 1;
	sal2 = (double) job2 / 100;
	numDays2 = rand() % MAX_NUMDAYS	 + 1;
	
	//display starting salary and number of days to be worked
	cout << "********" << setw(9) << "Job 2" << setw(12) << "********" << endl << endl << "Starting Salary: $" << sal2 << endl << "Number of days to work: " << numDays2 << endl << endl;
	
	//display salary each day in a while loop, then display the total amount of money earned from job 2
	int x = 0;
	while(x < numDays2)
	{
		if(x==0)
			cout << "Day " << (x+1) << ":" << setw(16) << sal2 << endl;
		else
			if(sal2 >= 10)
				cout << "Day " << (x+1) << ":" << setw(15) << (sal2*=2) << endl;
			else
				cout << "Day " << (x+1) << ":" << setw(16) << (sal2*=2) << endl;
		incomeTotal2 += sal2;
		x++;
	}
	
	cout << endl << "For Job 2, you earned $" << incomeTotal2 << " in " << numDays2 << " day(s)." << endl << endl << endl;
	
	//generate base salary for job 3 and number of days to be worked
	job3 = rand() % MAX_SAL + 1;
	sal3 = (double) job3 / 100;
	numDays3 = rand() % MAX_NUMDAYS + 1;
	 //display base salary and days to be worked
	cout << "********" << setw(9) << "Job 3" << setw(12) << "********" << endl << endl << "Starting Salary: $" << sal3 << endl << "Number of days to work: " << numDays3 << endl << endl;
	
	//display salary each day in a do while loop, then display the total amount earned in job 3
	x = 0;
	do
	{
		if(x==0)
			cout << "Day " << (x+1) << ":" << setw(16) << sal3 << endl;
		else
			if(sal3 >= 10)
				cout << "Day " << (x+1) << ":" << setw(15) << (sal3*=2) << endl;
			else
				cout << "Day " << (x+1) << ":" << setw(16) << (sal3*=2) << endl;
		incomeTotal3 += sal3;
		x++;
	}while(x<numDays3);
	
	cout << endl << "For Job 3, you earned $" << incomeTotal3 << " in " << numDays3 << " day(s)." << endl << endl << endl;
	
	//determine which job made the most money and display it
	if(incomeTotal1 > incomeTotal2 && incomeTotal1 > incomeTotal3)
	{
		cout << "The highest paying job was job 1, paying $" << incomeTotal1 << endl << endl;
	}
	else if(incomeTotal2 > incomeTotal1 && incomeTotal2 > incomeTotal3)
	{
		cout << "The highest paying job was job 2, paying $" << incomeTotal2 << endl << endl;
	}
	else
		cout << "The highest paying job was job 3, paying $" << incomeTotal3 << endl << endl;
		
	//determine which job was the least paying job and display it
	if(incomeTotal1 < incomeTotal2 && incomeTotal1 < incomeTotal3)
	{
		cout << "The lowest paying job was job 1, paying $" << incomeTotal1;
	}
	else if(incomeTotal2 < incomeTotal1 && incomeTotal2 < incomeTotal3)
	{
		cout << "The lowest paying job was job 2, paying $" << incomeTotal2;
	}
	else
		cout << "The lowest paying job was job 3, paying $" << incomeTotal3;
	
	return 0;
}
