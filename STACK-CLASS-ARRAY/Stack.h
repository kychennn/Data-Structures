#include <iostream>
using namespace std;

/***************************************************************/
/* Programmer: Anna Salvati                                    */        
/* Date: Fenruary 10 , 2021                                    */        
/* Purpose:  generic stack class                              */ /***************************************************************/

#ifndef STACK_H
#define STACK_H

template <class T>
class Stack
{
   private:
      int max;
      int top_;
      T *data;
     
   public:
      //Constructor 
      Stack(int = 100);
      // Destructor
      ~Stack();
      //Copy constructor
      Stack ( const Stack<T> & other);
      //Overloaded =  
      const Stack<T> & operator= (const Stack<T> & other);
      //Returns true if stack is empty, false otherwise
      bool isEmpty();
      //Returns true if stack is full, false otherwise
      bool isFull();
      //Inserts a new item at the top of the stack
      void push(T item);
      //Remove top item from stack. 
      void pop(); 
      // returns # items in stack
      int getLength();
      // Return top item through parameter
      // T top(); -->BAD: always return somthing even if the stack is empty
      void top(T &); 
      // Copy function
      void copy (const Stack<T> & other);
      //Destroys the stack
      void destroy();    
};
#endif