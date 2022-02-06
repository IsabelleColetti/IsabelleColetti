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
#ifndef WORDSCANNER_H
#define WORDSCANNER_H

#include <string>
#include <map>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <iomanip>

using std::string;
using std::map;
using std::cin;
using std::cout;
using std::setw;
using std::endl;
using std::left;

constexpr int NO_ITEMS = 4;
constexpr int ITEM_WORD_WIDTH = 14;
constexpr int ITEM_COUNT_WIDTH = 3;

/**
 * Gets a word from input stream and adds it to the map.
 *
 * Gets a word from the input stream, cleans it, and adds it to the map
 * if it's length is not 0.
 * 
 * @param m A reference to a map with each word represented by
 *          a pair<string, int> that is to be filled with clean words.
 *
 ********************************************************************************/
void get_words(map<string, int>& m);

/**
 * Prints the final list of words and their frequencies.
 *
 * Prints the final list of words, their frequencies, the number of 
 * non-empty words, and the number of distinct words in the input stream.
 * 
 * @param m A reference to a map with each word represented by
 *          a pair<string, int> that is to be printed.
 *
 ********************************************************************************/
void print_words(const map<string, int>& m);

/**
 * Cleans a word from its punctuation marks.
 *
 * Cleans a word from its punctuation marks and fills str with the clean
 * word.
 * 
 * @param s A reference to a constant string that contains the full word
 *			including punctuation.
 *
 * @param str A reference to a string that is to be filled with the cleaned
 *			word.
 *
 ********************************************************************************/
void clean_entry(const string& s, string& str);

#endif