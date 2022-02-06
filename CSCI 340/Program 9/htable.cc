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

#include "htable.h"

#define N1 10  // num of decimal digits
#define N2 26  // num of upper-case letters

// Hash function, you may NOT modify this function
int HT::hash(const string &s) {
  int n = (N2 * N1) * (s[0] - 'A') + N1 * (s[1] - 'A') + (s[2] - '0');

  return n % hsize;
}

// You will complete the code below ...

/**
 * The constructor for the HT class. 
 *
 * The constructor dynamically creates the hash table for a fixed size, given
 * by the parameter hs.
 * 
 * @param hs A reference to an unsigned integer representing the size of the 
 *          hash table.
 *
 ********************************************************************************/
HT::HT(const unsigned &hs)
{
  //set the size of the hash table to hs
  hsize = hs;
  //resize the hash table to hsize
  hTable.resize(hsize);
}

/**
 * The destructor for the HT class. 
 *
 * The destructor frees the memory for all vector containers for the hash and 
 * pointer tables.
 *
 ********************************************************************************/
HT::~HT()
{
  //clear the hash table
  hTable.clear();
  //clear the pointer table
  pTable.clear();
}

/**
 * Public insert function for the HT class.
 *
 * Inserts records of items e:(key, desc, num) into the hash table.
 * 
 * @param e A reference to an Entry object that is to be inserted into the 
 *          hash table.
 *
 ********************************************************************************/
void HT::insert(const Entry& e)
{
  //get the hash value for the key to be inserted
  int index = hash(e.key);
  //access the list at the hash value
  list<Entry> &l = hTable[index];

  //try to find e in the hash table
  //if it is not found, then insert it
  if(find_if(l.begin(), l.end(), [e] (Entry en) { return en.key == e.key;}) == l.cend())
  {
    //print the entry
    cout << " entry = " << index << endl;
    //push the entry into the hash table
    hTable[index].push_front(e);
    //push the entry into the pointer table, dynamically increasing the size of the table
    pTable.push_back(&hTable[index].front());
  }
  else          //otherwise, there is a duplicate key so print an error message
  {
    cout << " not inserted - duplicate key!!!" << endl;
  }
}

/**
 * Public search function for the HT class.
 *
 * Searches the hash table for a record with matching key s.
 * 
 * @param s A reference to a string that contains the key that is to be
 *          searched for in hash table.
 *
 ********************************************************************************/
void HT::search(const string& s)
{
  //get the hash value for the key
  int index = hash(s);
  //access the list at the hash value
  list<Entry> &l = hTable[index];

  //try to find the entry with a matching key
  auto it = find_if(l.begin(), l.end(), [s] (Entry en) { return en.key == s;});

  //if the entry was not found, print the message to say so
  if(it == l.cend())
  {
    cout << " not in table!!" << endl;
  }
  else          //otherwise, print the entry
  {
    cout << " ==> number: " << it->num << " - item:" << it->desc << endl;
  }
}

/**
 * Public hash table print function for the HT class.
 *
 * Prints the subscript and contents of all active records in the hash table.
 *
 ********************************************************************************/
void HT::hTable_print()
{
  cout << endl;
  //loop through the entire hash table
  for(size_t x = 0; x < hsize; ++x)
  {
    //access the list at the current hash table value
    list<Entry> &l = hTable[x];

    //if the list is not empty,
    if(!l.empty())
    {
      //loop through the entire list
      for(auto it = l.begin(); it != l.end(); ++it)
      {
        //print the entry
        cout << setw(4) << x << ": ";
        cout << it->key << " - ";
        cout << setw(5) << it->num << " - ";
        cout << it->desc << endl;
      }
    }
  }
}

/**
 * Public sorted hash table print function for the HT class.
 *
 * Prints the contents of all active records in the hash table in alphabetical
 * order by key value. Sorts the elements of the pointer table.
 *
 ********************************************************************************/
void HT::pTable_print()
{
  //sort the entries in the pointer table in alphabetical order by key value
  sort(pTable.begin(), pTable.end(), [] (Entry *p, Entry *q) {return p->key < q->key;});
  //loop through the pointer table
  for(auto it = pTable.begin(); it != pTable.end(); ++it)
   {
     //print the entry
     cout << setw(6) << (*it)->key << "  -  ";
     cout << setw(4) << (*it)->num << "  -  ";
     cout << (*it)->desc << endl;
   }
}