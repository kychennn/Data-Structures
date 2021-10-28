// Programmer:
// Date: 
// Purpose : Queue class implementation file
// Input: none
// Output: none

#include <iostream>
using namespace std;
#include "Queue.h"

template <class T>
Queue<T> :: Queue()
{
   rear = NULL;
   front = NULL;
}

template <class T>
Queue<T> :: ~Queue()
{
   destroy();
}

//Copy constructor
template <class T>
Queue<T> :: Queue ( const Queue<T> & other)
{
   copy(other);
}

template <class T>
const Queue<T> & Queue<T> :: operator= (const Queue<T> & other)
{  
  if ( this != &other)
  {
     destroy();
     copy(other);
  }

  return *this; 
}

template <class T>
bool Queue<T> :: isEmpty()
{
   return front == NULL;
}

template <class T>
void Queue<T> :: enqueue(T item)
{
   node<T> *p = new node<T>;
   p->info = item;
   p->next = NULL;

   if ( rear != NULL )
      rear->next = p;
   else
       front = p;  
   
   rear = p;
}

template <class T>
void Queue<T> :: dequeue()
{
   if ( front == NULL )
       cout<<"ERROR - Queue is empty";
   else
   {
      node<T> *p = front;
      front = front->next; 
      delete p;
      if ( front == NULL )
         rear = NULL;
   }       
}

template <class T>
void Queue<T> :: getFront ( T &item)
{
   if ( !isEmpty())
      item = front->info;
}

template <class T>
void Queue<T> :: getRear ( T &item)
{
  if ( !isEmpty())
      item = rear->info;
}

template <class T>
void Queue<T> :: destroy()
{
   node<T> *p;

    while ( front != NULL )
    {
       p = front;
       front = front->next;
       delete p;
    }  

    rear = NULL;
}

template <class T>
void Queue<T> :: copy (const Queue<T> & other)
{
   if ( other.front == NULL )
      front = NULL;
   else
   {
      front = new node<T>;
      front->info = other.front->info;

      node<T> *p = other.front->next;
      node<T> *r = front;

      while ( p != NULL )
      {
          r->next = new node<T>;
          r->next->info = p->info;
          p = p->next;
          r = r->next;
      }
      
      rear = r;
      r->next = NULL;
   }   
}
