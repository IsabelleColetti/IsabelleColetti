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

#include "btree.h"
#include "node.h"
#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_

//class to create a binary search tree of nodes
template <typename T>
class BinarySearchTree : public BinaryTree<T>
{
public:
    void Insert(const T &x);       // inserts node with value x
    bool Search(const T &x) const; // searches leaf with value x
    bool Remove(const T &x);       // removes leaf with value x
private:
    void _Insert(Node<T> *& n, const T &x);      // private version of insert
    bool _Search(Node<T> * n, const T &x) const; // private version of search
    void _Remove(Node<T> *& n, const T &x);      // private version of remove
    bool _Leaf(Node<T> *node) const;          // checks if node is leaf
};

/**
 * Public Insert function that inserts a node with the data value 'x' into the tree.
 * 
 * @param x A reference to a const T value that is the data part of the node
 *          to be inserted.
 *
 ********************************************************************************/
template <typename T>
void BinarySearchTree<T>::Insert(const T& x)
{
	_Insert(this->root, x);			//call the private Insert function to insert the node
}

/**
 * Private Insert function that recursively inserts a node with the data value
 * 'x' into the tree.
 * 
 * @param n A reference to a node pointer of type T that is the parent of the node
 *			to be inserted.
 * @param x A reference to a const T value that is the data part of the node
 *          to be inserted.
 *
 ********************************************************************************/
template <typename T>
void BinarySearchTree<T>::_Insert(Node<T> *& n, const T& x)
{
	//if the root is null, create a new node to insert
	if(n == nullptr)
	{
		//create a new node to insert
		n = new Node<T>(x);
		return;
	}

	//if the data and x match, return since the node already exists in the tree
	if(n->data == x)
		return;

	//if x is larger than the node's data 
	if(x > n->data)
		_Insert(n->right, x);		//move onto the node's right child
	else
		_Insert(n->left, x);		//otherwise, move onto the node's left child
}

/**
 * Public Search function that looks for a node with the data value 'x' in the tree.
 * 
 * @param x A reference to a const T value that is the data part of the node
 *          to be searched for.
 *
 ********************************************************************************/
template <typename T>
bool BinarySearchTree<T>::Search(const T &x) const
{
	return _Search(this->root, x);			//call the private Search function
}

/**
 * Private Search function that recursively searches for a node with the data value
 * 'x' in the tree.
 * 
 * @param n A reference to a node pointer of type T that is root of the tree
 *			to be searched.
 * @param x A reference to a const T value that is the data part of the node
 *          to be searched for.
 *
 ********************************************************************************/
template <typename T>
bool BinarySearchTree<T>::_Search(Node<T> * n, const T &x) const
{
	//if the node is null, return because the tree is empty
	if(n == nullptr)
		return false;
	else if(n->data < x)				//if x is greater than the node's data value
		return _Search(n->right, x);	//move onto the node's right child
	else if(n->data > x)				//if x is less tthan the node's data value
		return _Search(n->left, x);		//move onto the node's left child
	else		//if n->data == x, see if the node is a leaf
		return _Leaf(n);			//call Leaf to check if the node is a leaf
}

/**
 * Checks if a node is a leaf node.
 * 
 * @param node A reference to a node of type T that is to be checked to see if
 *          it is a leaf node.
 *
 * @return true if the node was a leaf node, otherwise false
 *
 ********************************************************************************/
template <typename T>
bool BinarySearchTree<T>::_Leaf(Node<T> *node) const
{
	//return true if the left and right children are both nullptr
	return(node->right == nullptr and node->left == nullptr);
}

/**
 * Public Remove function that removes a node from the tree.
 * 
 * @param x A reference to a const T value that is the data part of the node
 *          to be removed.
 *
 * @return true if the node was found in the tree, otherwise false
 *
 ********************************************************************************/
template <typename T>
bool BinarySearchTree<T>::Remove(const T &x)
{
	//if the search is unsuccessful, return false since the node is not in the tree
	if(!Search(x))
		return false;
	else
	{
		//otherwise, call the private Remove function
		_Remove(this->root, x);
		//return true since the remove was successful
		return true;
	}
}

/**
 * Private Remove function that removes a node from the tree.
 * 
 * @param n A reference to a node pointer of type T that is the node to be removed.
 * @param x A reference to a const T value that is the data part of the node
 *          to be removed.
 *
 ********************************************************************************/
template <typename T>
void BinarySearchTree<T>::_Remove(Node<T> *& n, const T &x)
{
	//if the node is empty, return and do not remove anything
	if(n == nullptr)
		return;
	else if(x > n->data)			//if x is larger than the node's data,
		_Remove(n->right, x);		//move to the node's right child
	else if(x < n->data)			//if x is smaller than the node's data,
		_Remove(n->left, x);		//move to the node's left child
	else	//if x == n->data, remove the node
	{
		//delete the node
		delete n;
		//set the node to nullptr
		n = nullptr;
		return;
	}
}

#endif //BINARYSEARCHTREE_H_