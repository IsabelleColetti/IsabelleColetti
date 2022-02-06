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
#ifndef STACK_H
#define STACK_H
#include <queue>

class Stack
{
private:
    std::queue<int> q1, q2;

public:

/**
 * Checks if q1 and q2 are empty.
 *
 * @return A bool, true if both queues are empty and false if not.
 *
 ********************************************************************************/
    bool empty() const;

/**
 * Returns the size of q1 and q2 added together.
 *
 * @return An int representing the sizes of q1 and q2 added together.
 *
 ********************************************************************************/
    int size() const;

/**
 * Returns the newest element.
 *
 * @return An int containing the newest element.
 *
 ********************************************************************************/
    int top();

/**
 * Adds val to a non-empty queue.
 *
 * @param val A reference to an int containing the value to be added to the queue.
 *
 ********************************************************************************/
    void push(const int &val);

/**
 * Removes the newest element.
 *
 ********************************************************************************/
    void pop();
};

#endif // STACK_H
