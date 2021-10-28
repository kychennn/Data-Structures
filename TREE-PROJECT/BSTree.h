/*****************************************************/
/* Programmer: Jiayi Chen                            */        
/* Date: May 10, 2021                                */        
/* Purpose: Binary Search Tree - header file         */ 
/*****************************************************/

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
   int repetition = 0;   // Increase when the item is repetition
};

template <class T>
class BSTree
{
   private:
      // TOTAL NUMBER OF SENTENCE 
      int totalSentence;
      // TOTAL NUMBER OF WORDS
      int totalWords;
      // TOTAL NUMBER OF WORDS OF MORE THAN 3 LETTERS
      int totalWordsMoreThanThree;
      // TOTAL NUMBER OF “UNIQUE” WORDS
	    int totalUniqueWords;
      // TOTAL NUMBER OF “UNIQUE” WORDS OF MORE THAN THREE LETTERS
	    int totalUWMoreThanThree;
      // THE TOTAL NUMBER OF WORDS OF MORE THAN 3 LETTERS 
      int totalChar;
      // Pointer to the root node
      node<T> *root;
      // Recursion Function for preOrder
      void preOrder(node<T> *);
      // Recursion Function for inOrder
      void inOrder(node<T> *); 
      // Recursion Function for postOrder
      void postOrder(node<T> *);
      // Recursion Function for destroy
      void destroy (node<T> *&);  
      // WORDS OF MORE THAN 3 LETTERS THAT ARE USED MORE THAN 5% 
      // OF THE TOTAL NUMBER OF WORDS OF MORE THAN 3 LETTERS
      void printOftenWords(node<T> *, ofstream&);
      // PRINT INDEX OF UNIQUE WORDS
      void printIndex(node<T> *, char &, ofstream&);

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
      // RETURN TOTAL NUMBER OF WORDS
      int getTotalWords();
      // RETURN TOTAL NUMBER OF WORDS OF MORE THAN THREE LETTERS
      int getTotalWordsMoreThanThree();
      // RETURN TOTAL NUMBER OF “UNIQUE” WORDS
      int getTotalUniqueWords();
      // RETURN TOTAL NUMBER OF “UNIQUE” WORDS OF MORE THAN THREE LETTERS
      int getTotalUWMoreThanThree();  
      // RETURN AVERAGE WORD LENGTH  
      int getAvgWordLength();
      // RETURN AVERAGE SENTENCE LENGTH
      int getAvgSentenceLength();
      // RETURN TRUE WHEN THERE IS A SENTENCE
      bool isSentence(T item);
      // Increase TOTAL NUMBER OF “UNIQUE” WORDS OF MORE THAN THREE LETTERS WHEN IT IS
      void longWord(T item);
      // Increase total number of word when there is word
      void wordCounter(T item);
      // Increase total number of character when there is character
      void charCounter(T item);
      // Increase total number of sentence when there is sentence
      void sentenceCounter(T item);
      // Print WORDS USED TOO OFTEN
      void printOftenWords(ofstream&);
      // Print INDEX OF UNIQUE WORDS
      void printIndex(ofstream&); 
      // Remove all the punctuations
      T remPunc(const T& );
};
#endif