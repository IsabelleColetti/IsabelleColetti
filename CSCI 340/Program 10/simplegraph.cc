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

#include <fstream>
#include <iostream>
#include <list>
#include <vector>

#include "graph.h"

using namespace std;

/**
 * The main function for simplegraph.cc
 *
 * @return 0 upon success, and a nonzero integer upon failure.
 *
 ********************************************************************************/
int main(int argc, char** argv) {
  if (argc < 2) {
    cerr << "args: input-file-name\n";
    return 1;
  }

  Graph g(argv[1]);

  g.Print();

  g.Traverse();

  return 0;
}