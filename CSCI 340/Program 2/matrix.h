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

#ifndef H_MATRIX_MULTIPLY
#define H_MATRIX_MULTIPLY

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

//data files to be opened
constexpr char FILE1[] = "./matrix01.dat";
constexpr char FILE2[] = "./matrix02.dat";

#define ITEM_W 8			//number of spaces for each printed number

/**
 * Opens two data files for reading.
 *
 * Opens two data files for reading and creates two input
 * streams, is1 and is2. Prints error message to stderr and aborts
 * if either file fails to open.
 *
 * @param is1 A reference to the first input stream that is to be created.
 * @param is2 A reference to the second input stream that is to be created.
 *
 ********************************************************************************/
void open_files(ifstream& is1, ifstream& is2);

/**
 * Reads input values from input stream and stores them in a matrix.
 *
 * Reads input values from the input stream is and stores the values
 * in a matrix m, a two dimensional vector of integers.
 *
 * @param is A reference to the input stream that is used to read input data.
 * @param m A reference to the two dimensional vector of integers to be filled
 *	with input values.
 *
 ********************************************************************************/
void read_data(ifstream& is, vector <vector <int>>& m);

/**
 * Prints a matrix to stdout.
 *
 * Prints the matrix m to stdout, allocating ITEM_W spaces between each item.
 * The number of values on a single line is the number of columns of m and the
 * nnumber of lines on stdout is the number of rows of m.
 *
 * @param m A reference to the two dimensional vector of integers to be printed.
 *
 ********************************************************************************/
void print_data(const vector <vector<int>>& m);

/**
 * Fills matrix C with the product of matrices A and B.
 *
 * Multiplies the values in matrices A and B and stores the result in C. The
 * resulting matrix C has the same number of rows as A and the same number
 * of columns as B.
 *
 * @param A A reference to the two dimensional vector of integers to be multiplied
 *	by B.
 * @param B A reference to the two dimensional vector of integers to multiply
 *	matrix A by.
 * @param C A reference to the two dimensional vector of integers which is the
 *	product matrix of A and B.
 *
 ********************************************************************************/
void gen_data(const vector <vector<int>>& A, const vector <vector<int>>& B, vector <vector<int>>& C);

#endif
