#include "DList.h"

/*******************************************************/
/* Programmer: Jiayi Chen                              */        
/* Date: March 2, 2021                                 */        
/* Purpose:  generic unsorted doubly list class        */
/*           implementation file                       */
/*******************************************************/

template <class T>
DList<T> :: DList()
{
   first = NULL;
   last = NULL;
}

template <class T>     
DList<T> :: ~DList()
{ 
   destroy();
}

template <class T>        
DList<T> :: DList ( const DList<T> & other)
{
   copy (other);
}

template <class T>        
const DList<T> & DList<T> :: operator= (const DList<T> & other)
{
   if ( this != &other )
   {
      destroy();
      copy(other);
   }

   return *this;
}

template <class T>        
bool DList<T> :: isEmpty()
{
   return first == NULL;
}
      
template <class T>        
void DList<T> :: insertItemAtFront(T item)
{
   node<T> *temp;
   temp = new node<T>;

   temp->info = item;

   // The list is empty
   if ( first == NULL )
   {
      temp->next = temp->back = NULL;
      first = temp;
      last = first;
   }

   // The list is not empty
   else
   {
     node<T> *p = first; 
     if( p->next == NULL) // define last node
        last = p;
     temp->next = p;
     temp->back = p->back;
     first = temp;
     p->back = temp;
   }
}

template <class T>        
void DList<T> :: insertItemAtBack(T item)
{
  node<T> *temp;
  temp = new node<T>;

  temp->info = item;

  // The list is empty
  if ( first == NULL )
   {
      temp->next = temp->back = NULL;
      first = temp;
      last = first;
   }

   // The list is not empty
   else
   {
     node<T> *p = last;
     temp->next = NULL;
     temp->back = p;
     p->next = temp;
     last = temp;
   }
}

template <class T>      
void DList<T> :: deleteItem(T item)
{
  //The list is empty
   if ( first == NULL )  
      cout<<"ERROR - LIST IS EMPTY";
   else
   {
      node<T> *p = first; 
      bool found;
      //Delete the item if at the first
      if ( item == first->info )
      {
         first = first->next;
         first->back = NULL;
         delete p;
      }
      else
      {
        found = false;
        while ( p != NULL && !found )  //search the list
        {
          if ( item == p->info )
             found = true;
          else
             p = p->next;
        }
        
        if ( found == true )  //The item has been found at the middle or the end
        {
          p->back->next = p->next;
          if ( p == last )
             last = last->back;
          else
             p->next->back = p->back;
          delete p;
        }

        else    //The item is not in the list
          cout<<"ERROR - ITEM NOT IN THE LIST";
      }
    }        
}

template <class T>
void DList<T> :: destroy()
{
    node <T> *p;

    while ( first != NULL )
    {
       p = first;
       first = first->next;
       delete p;      
    }
    last = NULL;
}

template <class T>
void DList<T> :: copy ( const DList<T> & other )
{
   if ( other.first == NULL )
   {
     first = NULL;
     last = NULL;
   }
      
   else
   {
      first = new node<T>;
      first->info = other.first->info;
      first->back = NULL;
      
      node<T> *p = other.first->next;
      node<T> *r = first;

      while ( p != NULL )
      {
         r->next = new node<T>;
         r->next->info = p->info;
         r->next->back = r;
         p = p->next;
         r = r->next;
      }
      r->next = NULL;  
      last = r;
   }   
       
}

template <class T>        
int DList<T> :: getLength()
{
   node<T> *p = first;
   int count = 0;

   while ( p != NULL )
   {
      count++;
      p = p->next;
   }

   return count;
}

template <class T>        
bool DList<T> :: searchItem (T item)
{
  node<T> *p = first;
  
  while ( p != NULL )
  {
     if ( item == p->info )
        return true;
     else
        p = p->next;   
  }
  
  return false;
} 

template <class T>        
void DList<T> :: printList()
{
   node<T> *p;

   p = first;

   while ( p != NULL )
   {
      cout<<p->info<<" ";
      p = p->next;
   }
} 

// Class Iterator
template <class T>
DList<T>::Iterator::Iterator()
{
  current = NULL;
}

template <class T>
DList<T>::Iterator::Iterator(node<T> *&p)
{
  current = p;
}

template <class T>
typename DList<T>::Iterator& DList<T>::Iterator::operator++()
{
  if (current != NULL)
  {
    current = current->next;
  }
  return *this;
}

template <class T>
typename DList<T>::Iterator& DList<T>::Iterator::operator++(int)
{
  Iterator *temp = this;
  if (current != NULL)
  {
    current = current->next;
  }
  return *temp;
}

template <class T>
typename DList<T>::Iterator& DList<T>::Iterator::operator--()
{
  if (current != NULL)
  {
    current = current->back;
  }
  return *this;
}

template <class T>
typename DList<T>::Iterator& DList<T>::Iterator::operator--(int)
{
  Iterator *temp = this;
  if (current != NULL)
  {
    current = current->back;
  }
  return *temp;
}

template <class T>
T& DList<T>::Iterator::operator*()
{
  return current->info;
}

template <class T>
typename DList<T>::Iterator DList<T>::beginAtFront()
{
  Iterator iter(first);
  return iter;
}

template <class T>
typename DList<T>::Iterator DList<T>::beginAtBack()
{
  Iterator iter(last);
  return iter;
}