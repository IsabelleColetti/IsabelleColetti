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

#ifndef H_JOSEPHUS
#define H_JOSEPHUS

#include <iostream>
#include <sstream>
#include <string>
#include <list>
#include <algorithm>

using namespace std;

#define NO_LETS  26    // no of letters in English alphabet
#define NO_ITEMS 12    // no of items printed on single line

// struct for input arguments

struct args {
    unsigned N,       // no of initial people   
             M,       // count to eliminate person
             K;       // frequency of printouts
};

// class to generate name tags for people

class SEQ {
private:
    string id;         // name tag for person
    unsigned size, nd; // no of people, no of digits in name tags

    // returns no of digits in name tags
    unsigned find_nd ( const double& sz ) {
        if ( ( sz / NO_LETS ) <= 1 ) return 2;
        else return ( find_nd ( sz / NO_LETS ) + 1 );
    }

public:
    // constructor for name-tag generator
    SEQ ( const unsigned& s = 1 ) : size ( s ) {
        double sz = ( double ) size / 9; nd = find_nd ( sz );
        id = string ( nd, 'A' ); id [ nd - 1 ] = '1'; 
    }

    // returns next name tag in sequence
    string operator ( ) ( ) {
        string tmp = id; int i = nd - 1;
        if ( id [ i ] < '9' ) id [ i ]++;
        else {
            id [ i ] = '1'; bool flag = true;
            for ( i--; i >= 0 && flag; i-- )
                if ( id [ i ] < 'Z' ) { id [ i ]++; flag = false; }
                else id [ i ] = 'A';
        } 
        return tmp;
    }
};

// reads and initializes all input arguments
/**
 * Reads the input values and fills the list with names.
 *
 * Reads the input values N, M, and K from the struct
 * and uses those values to fill the names of people in
 * the list. 
 *
 * @param L A reference to a list to be filled with names of people.
 * @param in A reference to a struct containing the N, M, and K values.
 *
 ********************************************************************************/
void init_vals(list<string> &L, args &in);

// prints all name tags for remaining people after elimination
/**
 * Prints out the contents of the list.
 *
 * Prints out the contents of the list at the beginning
 * and after removing K names from the list each time, until
 * only one name remains. Also prints the name of the last person.
 * Only prints NO_ITEMS names on a single line of output.
 *
 * @param L A reference to a list filled with names of people that is to be printed.
 * @param cnt A reference to a constant unsigned value that indicates the total
 *      number of removals so far. 
 *
 ********************************************************************************/
void print_list (const list < string > &L, const unsigned &cnt);

#endif
