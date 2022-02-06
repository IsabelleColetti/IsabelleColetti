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

//test comment for ssh

#include "graph.h"

using std::ifstream;
using std::cerr;
using std::cout;
using std::endl;
using std::vector;
using std::string;

bool *visited;
vector<string> path;

/**
 * Private function that does a depth-first traversal.
 *
 * Performs a depth-first traversal starting at the vertex v.
 * 
 * @param v An integer representing the index value of the vertex to start
 *          the traversal with.
 *
 ********************************************************************************/
void Graph::Depthfirst(int v) 
{
	//print out the label of the vertex we are currently on
	cout << labels[v] << " ";
	//set the visit status of the vertex to true because we have visited it
	visited[v] = true;
	
	//loop through the integer list at index v of the adjacency list
	for(auto it = adj_list[v].begin(); it != adj_list[v].end(); ++it)
	{
		//save the index of the iterator
		int w = *it;
		if(!visited[w])				//if the index has not already been visited,
		{
			//"visit" the index by adding the transition to the path vector
			string s = "(";
			s += labels[v];
			s += ", ";
			s += labels[w];
			s += ")";
			path.push_back(s);
			//call Depthfirst on the visited vertex to continue the traversal
			Depthfirst(w);
		}
	}
}

/**
 * Constructor for the Graph class.
 *
 * Opens and reads data from the file. Builds the graph with an adjacency
 * list representation.
 * 
 * @param filename A const pointer to a character that represents the name
 *          of the file to be opened and read from.
 *
 ********************************************************************************/
Graph::Graph(const char* filename)
{
	ifstream is;

	//open the file
	is.open(filename);

	if(!is)				//if there is an error opening the file,
	{
		//print appropriate error message to stderr and exit
		cerr << "Error opening file " << filename;
		exit(1);
	}
	
	//read in the size
	is >> this->size;

	char c;

	//loop through the entire size of the graph
	for(int i = 0; i < size; ++i)
	{
		//read the labels into the labels vector
		is >> c;
		labels.push_back(c);
	}

	//resize the adjacency list to the size of the graph
	adj_list.resize(size);
	
	//loop through the outer part of the adjacency list
	for(int i = 0; i < size; ++i)
	{
		//loop through the inner integer list of the adjacency list
		for(int j = 0; j < size; ++j)
		{
			//skip over the first read because it is the label, not an edge
			if(j == 0)
				is >> c;
			//read in the integer
			is >> c;
			//if it's a 1, add the edge to the adjacency list at that label
			if(c == '1')
				adj_list[i].push_back(j);
		}
	}

	//close the file
	is.close();
}

/**
 * Destructor for the Graph class.
 *
 ********************************************************************************/
Graph::~Graph()
{
	//clear the adjacency list while it is not empty
	while(!adj_list.empty())
		adj_list.pop_back();
}

/**
 * Public function that returns the size of the graph.
 * 
 * @return An integer representing the size of the graph.
 *
 ********************************************************************************/
int Graph::Getsize() const 
{ 
	return this->size;
}

/**
 * Public function that traverses a graph. Calls the Depthfirst function.
 *
 ********************************************************************************/
void Graph::Traverse() 
{
	//print top label of traverse
	cout << endl << "------- traverse of graph ------" << endl;

	//create an array to keep track of the vertices that were visited
	visited = new bool[size];
	//set all vertices of the graph's visited state to false
	for(int i = 0; i < size; ++i)
		visited[i] = false;

	//loop through the entire graph
	for(int i = 0; i < size; ++i)
	{
		//if the vertex was not already visited,
		if(!visited[i])
			Depthfirst(i);			//call Depthfirst to perform the traversal
	}

	cout << endl;
	//print out the path of transitions that were taken
	for(auto it = path.begin(); it != path.end(); ++it)
		cout << *it << " ";

	//print the end label for traverse
	cout << endl << "--------- end of traverse -------" << endl << endl;
	//delete the visited array
	delete[] visited;
}

/**
 * Public function that prints the adjacency list for the graph.
 *
 ********************************************************************************/
void Graph::Print() const 
{
	//print the number of vertices in the graph
	cout << endl << "Number of vertices in the graph: " << Getsize() << endl << endl;
	cout<< "-------- graph -------" << endl;
	
	//loop through the entire graph
	for(int i = 0; i < size; ++i)
	{
		//print the label at the index
		cout << labels[i] << ": ";
		//print the adjacency list for the index
		for(auto it = adj_list[i].begin(); it != adj_list[i].end(); ++it)
			cout << labels.at(*it) << ", ";
		cout << endl;
	}
	cout << "------- end of graph ------" << endl;
}