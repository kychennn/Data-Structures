#include <iostream>
using namespace std;

/***************************************************************/
/* Programmer: Anna Salvati                                    */        
/* Date: Fenruary 10 , 2021                                    */        
/* Purpose:  generic stack class                              */ /***************************************************************/

#ifndef STACK_H
#define STACK_H

template <class T>
struct node
{  
    T info;
    node *next;
};

template <class T>
class Stack
{
   private:
      node<T> *top_;
      int length;
     
   public:
      //Constructor 
      Stack();
      // Destructor
      ~Stack();
      //Copy constructor
      Stack ( const Stack<T> & other);
      //Overloaded =  
      const Stack<T> & operator= (const Stack<T> & other);
      //Returns true if stack is empty, false otherwise
      bool isEmpty();
      // Insert item
      void push(T item);
      //Deletes top item from stack. 
      void pop(); 
      // returns # items in stack
      int getLength();
      // Return top item through parameter
      void top(T&); 
      // Copy function
      void copy (const Stack<T> & other);
      //Destroys the stack
      void destroy(); 

};
#endif

//  stack :  LIFO