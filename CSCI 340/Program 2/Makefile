#***************************************************************************
#
#  Isabelle Coletti
#  z1900409
#  CSCI 340 Section 2
#
#  I certify that this is my own work and where appropriate an extension 
#  of the starter code provided for the assignment.
#
#***************************************************************************

#include matrix_sub.cc as a dependency
#rule to make matrix executable file
matrix: matrix.cc matrix.h matrix_sub.cc
	g++ -std=c++11 -Wall -Wextra -pedantic -o matrix matrix.cc matrix_sub.cc

#rule to remove executable file
clean:
	rm matrix
