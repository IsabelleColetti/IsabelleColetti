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
#include <iostream>
#include <iomanip>
#include <string>

int main()
{
    Stack s;
    std::string op;
    int val = 0;

    //display labels
    std::cout << "operation -- size front end" << std::endl;
    //read in the operation until the end of file is reached
    std::cin >> op;
    while (!std::cin.eof())
    {
        //if the operation is push, read the value and call push() with it
        if (op == "push")
        {
            std::cin >> val;
            s.push(val);
            std::cout << op << " " << val << "    -- ";
        }
        //if the operation is pop, call pop()
        else if (op == "pop")
        {
            s.pop();
            std::cout << op << "       -- ";
        }
        //otherwise, exit with nonzero code and write to standard error
        else
        {
            std::cerr << "Error input: " << op << std::endl;
            return 1;
        }
        //print the size and top value of the stack after each operation
        std::cout << std::setw(3) << s.size() << std::setw(5) << s.top() << std::endl;
        std::cin >> op;
    }

    //remove all elements of the stack once all operations are finished
    while (!s.empty())
        s.pop();
    //print the size of the stack once all elements are removed
    std::cout << "End -- size of Stack is: " << s.size() << std::endl;

    return 0;
}
