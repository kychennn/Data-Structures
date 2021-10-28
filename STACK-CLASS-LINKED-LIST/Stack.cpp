#include "Stack.h"

/***************************************************************/
/* Programmer: Anna Salvati                                    */        
/* Date: February 3, 2021                                      */        
/* Purpose: Array  Stack class  -   implementation file        */ 
/* Input: none                                                 */
/* Output: none                                                */
/***************************************************************/

template <class T>
Stack<T> :: Stack ( )
{
   length = 0;
   top_ = NULL;
}

template <class T>
Stack<T> :: ~Stack()
{
  destroy(); 
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
   return *this;
}

template <class T>
bool Stack<T> :: isEmpty ()
{
   return top_ == NULL;
}

template <class T>
void Stack<T> :: push ( T item )
{
      	node<T> *temp = top_;		
	      top_ = new node<T>;		
	      top_->info = item;		
	      top_->next = temp;	
        length++;	
  /*
    node<T> *temp = new node<T>;				
    temp->info = item;				
    temp->next = top;				
    top = temp;		
    length++;
  */
}

template <class T>
void Stack<T> :: pop ()
{
   if ( isEmpty())
      cout<<"ERROR - STACK IS EMPTY";
   else
      {
         node<T> *temp = top_;
         top_ = top_->next;
         delete temp;
         temp = NULL;
         length--;
      }
}

template <class T>
int Stack<T> :: getLength()
{
   return length;
}

template <class T>
void Stack<T> :: top (T &item)
{
   if ( isEmpty())
      cout<<"ERROR - STACK IS EMPTY";
   else
      item = top_->info;   
}

template <class T>
void Stack<T> :: copy (const Stack<T> & other)
{
   if ( other.top_ == NULL )
      top_ = NULL;
   else
   {
      top_ = new node<T>;
      top_->info = other.top_->info;

      node<T> *p = other.top_->next;
      node<T> *r = top_;

      while ( p != NULL )
      {
         r->next = new node<T>;
         r->next->info = p->info;
         p = p->next;
         r = r->next;
      }
    
      r->next = NULL;  
   }   
}

template <class T>
void Stack<T> :: destroy()
{
  node <T> *p;

  while ( top_ != NULL )
    {
       p = top_;
       top_ = top_->next;
       delete p;      
    }
}
