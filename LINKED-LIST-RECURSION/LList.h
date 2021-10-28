#include <iostream>
using namespace std;

/***************************************************************/
/* Programmer: Anna Salvati                                    */        
/* Date: Fenruary 10 , 2021                                    */        
/* Purpose:  generic sorted linked list class - header file    */ /***************************************************************/

#ifndef LLIST_H
#define LLIST_H

template <class T>
struct node
{
    T info;
    node *next;
};

template <class T>
class LList 
{
   private:
      node<T> *first; 
       
   public:
      //Constructor 
      LList();
      // Destructor
      ~LList();
      //Copy constructor
      LList ( const LList<T> & other);
      //Overloaded =  
      const LList<T> & operator= (const LList<T> & other);
      //Returns the current length of list
      int getLength();
      //Returns true if list is empty, false otherwise
      bool isEmpty();
      // Inserts parameter item in its proper position
      void insertItem(T item);
      //If list is not empty and parameter item is in the list. If list is //empty or item is not in the list, prints error message
      void deleteItem(T item);
      //Returns true if parameter item is in the list, false otherwise
      bool searchItem(T item);
      //Prints all items in the list in ascending order. Prints error message if 
      //list is empty.
      void printList(node<T> *);
      //dummy non recursive print called by client
      void printList();
      //Copies a list
      void copy (const LList<T> & other);
      //Destroys the list 
      void destroy();
};
#endif


