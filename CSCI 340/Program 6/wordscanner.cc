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
#include "wordscanner.h"

void get_words(map<string, int>& m)
{
	string s;
	string str;

	//continue reading from stdin until all words are read
	while(cin >> s)
	{
		//clean word with clean_entry
		clean_entry(s, str);

		//if the length of the cleaned string is 0, don't add it to the map
		if(str.length() != 0)
			m[str]++;			//otherwise, add the cleaned string to the map and increment its frequency
	}
}

void print_words(const map<string, int>& m)
{
	//keep track of the total number of frequencies
	int total = 0;
	//keep track of the number of words
	int count = 0;

	//loop through the entire map
	for(auto it = m.begin(); it != m.end(); ++it)
	{
		//if the number of items on each line has been reached, print a new line
		if(count != 0 and count % NO_ITEMS == 0)
			cout << endl;
		
		//print the word with formatting and then the frequency with formatting
		cout << setw(ITEM_WORD_WIDTH) << left << it->first << ":" << setw(ITEM_COUNT_WIDTH) << it->second;

		//increment the number of words in the map
		count++;
		//add the frequency of the word to the total
		total += it->second;
	}
	cout << endl << endl;

	//print the number of words
	cout << setw(30) << left << "no of words in input stream" << ":" << total << endl;
	
	//print the total number of frequencies
	cout << setw(30) << left << "no of words in output stream" << ":" << m.size() << endl;
}

void clean_entry(const string& s, string& str)
{
	size_t indexf = 0;
	size_t indexl = 0;

	//find the first alphanumeric character and save the index in indexf
	for(indexf = 0; indexf < s.length(); ++indexf)
	{
		if(isalnum(s[indexf]))				//if the character is alphanumeric, exit
			break;
	}

	//loop through the string starting from the start index and save the first non-alphanumeric character in indexl
	for(indexl = indexf; indexl < s.length(); ++indexl)
	{
		if(!isalnum(s[indexl]))				//if the character is not alphanumeric, break
			break;
	}

	//save the clean part of the word in str
	str = s.substr(indexf, indexl - indexf);

	for(size_t i = 0; i < str.length(); ++i)
	{
		//change every character to lowercase
		str[i] = tolower(str[i]);
	}
}

/**
 * The main function for wordscanner.cc
 *
 * @return 0 upon success, and a nonzero integer upon failure.
 *
 ********************************************************************************/
int main()
{
	//create an empty map
	map <string, int> m;

	//fill the map with words
	get_words(m);
	//print the map
	print_words(m);

	return 0;
}