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
#include "stack.h"

bool Stack::empty() const
{
	//return true if both queues are empty, false if not
	return (q1.empty() and q2.empty());
}

int Stack::size() const
{
	//return the number of elements in q1 and q2
	return (q1.size() + q2.size());
}

int Stack::top()
{
	//if q1 is not empty, return the newest element of q1
	if(!q1.empty())
		return q1.front();
	//otherwise, return the newest element of q2
	return q2.front();
}

void Stack::push(const int &val)
{
	//if both q1 and q2 are empty, add the new element to q1
	if(q1.empty() and q2.empty())
	{
		//add element to arbitrary queue
		q1.push(val);
	}
	else
	{
		//move all elements from q1 into q2
		while(!q1.empty())
		{
			q2.push(q1.front());
			//remove each element after it is shifted into q2
			q1.pop();
		}

		//add the new "front" value into q1
		q1.push(val);

		//add all the elements from q2 back into q1
		while(!q2.empty())
		{
			q1.push(q2.front());
			//remove each element after it is shifted into q1
			q2.pop();
		}
	}
}

void Stack::pop()
{
	//if q1 is not empty
	if(!q1.empty())
	{
		//delete the "newest" element
		q1.pop();
	}
}
