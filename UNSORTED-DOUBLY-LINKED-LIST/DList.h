#include <iostream>
using namespace std;

/*********************************************************************/
/* Programmer: Jiayi Chen                                            */        
/* Date: March 2, 2021                                               */        
/* Purpose: generic unsorted  doubly linked list class - header file */ 
/*********************************************************************/

#ifndef DLIST_H
#define DLIST_H

template <class T>
struct node
{
    T info;
    node *next;
    node *back;
};

template <class T>
class DList 
{
   private:
      node<T> *first; 
      node<T> *last;
       
   public:
      //Constructor 
      DList();
      // Destructor
      ~DList();
      //Copy constructor
      DList ( const DList<T> & other);
      //Overloaded =  
      const DList<T> & operator= (const DList<T> & other);
      //Returns the current length of list
      int getLength();
      //Returns true if list is empty, false otherwise
      bool isEmpty();
      // Inserts parameter item at front
      void insertItemAtFront(T item);
      // Inserts parameter item at back
      void insertItemAtBack(T item);
      //If list is not empty and parameter item is in the list. If list is 
      //empty or item is not in the list, prints error message
      void deleteItem(T item);
      //Returns true if parameter item is in the list, false otherwise
      bool searchItem(T item);
      //Prints all items in the list. Prints error message if list is empty.
      void printList();
      //Copies a list
      void copy (const DList<T> & other);
      //Destroys the list 
      void destroy();

      // Inner class Iterator
      class Iterator
      {
        private:
            node<T> *current;

        public:
            // Default constructor
            Iterator();
            // Constructor initializes the iterator with the node
            Iterator(node<T> *&);
            // Overloaded prefix increment operator
            Iterator& operator++();
            // Overloaded postfix increment operator
            Iterator& operator++(int);
            // Overloaded prefix decrement operator
            Iterator& operator--();
            // Overloaded postfix decrement operator
            Iterator& operator--(int);
            // Overloaded dereference operator
            T& operator*();
      };

      // Provide an iterator to access items from front to back
      Iterator beginAtFront();
      // Provide an iterator to access items from back to front
      Iterator beginAtBack();
};
#endif
