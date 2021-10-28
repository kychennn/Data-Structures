#include "Stack.h"

/***************************************************************/
/* Programmer: Anna Salvati                                    */        
/* Date: February 3, 2021                                      */        
/* Purpose: Array  Stack class  -   implementation file        */ 
/* Input: none                                                 */
/* Output: none                                                */
/***************************************************************/

template <class T>
Stack<T> :: Stack ( int size )
{
   max = size;
   top_ = -1;
   data = new T[size]; //data = new T[max];
}

template <class T>
Stack<T> :: ~Stack()
{
  delete [] data; 
}

template <class T>
Stack<T> :: Stack ( const Stack<T> & other )
{
  copy (other);
}

template <class T>
const Stack<T> & Stack<T> :: operator= ( const Stack<T> & other )
{
   if ( this != &other )
   {
      destroy();
      copy (other);
   }
}

template <class T>
bool Stack<T> :: isEmpty ()
{
   return top_ == -1;
}

template <class T>
bool Stack<T> :: isFull ()
{
   return top_ == max - 1;
}

template <class T>
void Stack<T> :: push ( T item )
{
  if ( isFull() )
      cout<<"\nSTACK IS FULL";
  else
    data[++top_] = item;
}

template <class T>
void Stack<T> :: pop ()
{
   if ( isEmpty())
      cout<<"ERROR - STACK IS EMPTY";
   else
      top_--; 
}

template <class T>
int Stack<T> :: getLength()
{
   return top_ + 1;
}

template <class T>
void Stack<T> :: top (T &item)
{
   if ( isEmpty())
      cout<<"ERROR - STACK IS EMPTY";
   else
      item = data[top_];   
}

template <class T>
void Stack<T> :: copy (const Stack<T> & other)
{
   max = other.max;
   top_ = other.top_;
   data = new T[max];
   for( int i = 0; i <= other.top_; i++)
     data[i] = other.data[i];
}

template <class T>
void Stack<T> :: destroy()
{
  delete [] data;
}