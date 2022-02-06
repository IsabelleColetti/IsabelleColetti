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

#ifndef H_BTREE
#define H_BTREE

#include "node.h"
#include <stdio.h>
#include <cstdlib>

//class to create a binary tree of nodes
template <typename T> class BinaryTree{

public:
    BinaryTree();                                      // default constructor
    unsigned     getSize() const;                      // returns size of tree
    unsigned     getHeight() const;                    // returns height of tree
    virtual void Insert(const T& x);                     // inserts node in tree
    void         Inorder(void (*)(const T& x));          // inorder traversal of tree

protected:
    Node<T> *root;                                      // root of tree

private:
    unsigned _getSize(Node<T> *n) const;                 // private version of getSize()
    unsigned _getHeight(Node<T> *n) const;               // private version of getHeight()
    void     _Insert(Node<T> *& n, const T& x);             // private version of Insert()
    void     _Inorder(Node<T> *n, void (*)(const T& x));   // private version of Inorder()
    typedef enum {left_side, right_side } SIDE;
    SIDE rnd(){ return rand()%2 ? right_side : left_side; }
};

/**
 * The default constructor for the BinaryTree class.
 * 
 ********************************************************************************/
template <typename T>
BinaryTree<T>::BinaryTree()
{
    root = nullptr;
}

/**
 * The public size function. Calls the private size function.
 *
 ********************************************************************************/
template <typename T>
unsigned BinaryTree<T>::getSize() const
{
    return _getSize(root);          //call the private recursive size function
}

/**
 * Returns the size of the tree. 
 * 
 * @param n A pointer to a node of type T that is the root of the tree
 *          whose size is to be counted.
 *
 ********************************************************************************/
template <typename T>
unsigned BinaryTree<T>::_getSize(Node<T>* n) const
{
    if(n == nullptr)                //if this is the root of the tree, return size of 0
        return 0;
    else
    {
        //otherwise, return the sizes of the lefthand righthand subtrees plus one
        return 1 + _getSize(n->left) + _getSize(n->right);
    }
}

/**
 * The public height function. Returns the size of the tree. 
 *
 ********************************************************************************/
template <typename T>
unsigned BinaryTree<T>::getHeight() const
{
    return _getHeight(root);                //call the private recursive height function
}

/**
 * Returns the height of the tree. 
 * 
 * @param n A pointer to a node of type T that is the root of the tree
 *          whose height is to be counted.
 *
 ********************************************************************************/
template <typename T>
unsigned BinaryTree<T>::_getHeight(Node<T>* n) const
{
    //keep track of the left subtree's height
    size_t left_height = 0;
    //keep track of the right subtree's height
    size_t right_height = 0;

    if(n == nullptr)                //if this is the root of the tree, return 0
        return 0;
    else                    //otherwise, find the height of the left and right subtrees
    {
        left_height = _getHeight(n->left);              //find the height of the left subtree
        right_height = _getHeight(n->right);            //find the height of the right subtree

        if(left_height > right_height)              //if the left subtree's height is larger, return the left height plus one
            return left_height + 1;
        else                            //otherwise, return the right height plus one
            return right_height + 1;
    }
}

/**
 * The public insert function. Calls the private insert function. 
 * 
 * @param x A const reference to a T value that is the data part of the node
 *          to be inserted. 
 *
 ********************************************************************************/
template <typename T>
void BinaryTree<T>::Insert(const T& x)
{
    _Insert(root, x);               //call the private recursive insert function
}

/**
 * Inserts a node into a tree. 
 * 
 * @param n A reference to a pointer node of type T that is the root of the
 *          tree to insert the new node into.
 *
 * @param x A const reference to a T value that is the data part of the node
 *          to be inserted. 
 *
 ********************************************************************************/
template <typename T>
void BinaryTree<T>::_Insert(Node<T>*& n, const T& x)
{
    //if the node to be inserted is null, create a new node to insert
    if(n == nullptr)
        n = new Node<T>(x);
    else
    {
        //randomly determine if the node should be added to the left or right subtree
        if(rnd() == left_side)              //insert the node into the left subtree
            _Insert(n->left, x);
        else
            _Insert(n->right, x);           //insert the node into the right subtree
    }
}

/**
 * The public inorder function. Calls the private inorder function. 
 * 
 * @param p A pointer to a function to be called inside the private inorder
 *          function to print the values of the tree.
 *
 ********************************************************************************/
template <typename T>
void BinaryTree<T>::Inorder(void (*p)(const T& x))
{
    _Inorder(root, p);              //call the private recursive inorder function
}

/**
 * Performs an inorder traversal of the binary tree.
 * 
 * @param n A reference to a pointer node of type T that is the root of the
 *          tree to be traversed.
 *
 * @param p A pointer to a function to be called inside the function to
 *          print the values of the tree.
 *
 ********************************************************************************/
template <typename T>
void BinaryTree<T>::_Inorder(Node<T>* n, void (*p)(const T& x))
{
    //continue while we haven't reached a leaf node
    if(n != nullptr)
    {
        _Inorder(n->left, p);               //visit the left child
        p(n->data);                         //visit the node
        _Inorder(n->right, p);              //visit the right child
    }
}

#endif // End of H_BTREE
