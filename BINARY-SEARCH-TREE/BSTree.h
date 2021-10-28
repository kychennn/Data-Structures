#include <iostream>
#include <fstream>
using namespace std;

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

// Define node of tree
template <class T>
struct node
{
   T info;
   node *left;
   node *right; 
   // int counter;   Binary Search Tree has repetition
};

template <class T>
class BSTree
{
   private:
      node<T> *root;
      void preOrder(node<T> *);     //recursion function
      void inOrder(node<T> *);      //recursion function
      void postOrder(node<T> *);    //recursion function
      void destroy (node<T> *&);    //recursion function

   public:
      // default constructor
      BSTree(); 
      //destructor
      ~BSTree();
      // Destroys the tree 
      void destroy();
      //copy constructor
      BSTree (const BSTree<T> &);
      //overload operator =
      const BSTree<T> & operator= (const BSTree<T> &);
      //Copies a tree
      void copy ( node<T> *&, node<T> *);
      //Returns true if tree is empty, false otherwise
      bool isEmpty();
      // Inserts parameter item 
      void insertItem (T item);
      // dummy function for client call
      void deleteItem (T item);
      // Recursion function, look for item inside the tree and call deleteNode
      void deleteItem (node<T> *&, T );
      // receive the node and then delete 
      void deleteNode (node<T> *& );
      // Return true if the item is in the tree
      bool searchItem (T item);
      //Dummy function for preOrder
      void preOrder(); 
      //Dummy function for inOrder
      void inOrder();
      //Dummy function for postOrder
      void postOrder();
};

#endif

/*
~BSTree();
BSTree (const BSTree<T> &);
const BSTree<T> & operator= (const BSTree<T> &);

we need these three because we donot want shallow copy.

how do we know shallow copy will be applied: 
because we are dealing with node<T> *root, 
this is pointer, dynamic memory allocation

*/