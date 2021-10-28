#include "LList.h"

/***************************************************************/
/* Programmer: Anna Salvati                                    */        
/* Date: Fenruary 10 , 2021                                    */        
/* Purpose:  generic sorted circular linked list class         */
/*           implementation file                               */
/***************************************************************/

template <class T>
LList<T> :: LList()
{
   first = NULL;
}

template <class T>     
LList<T> :: ~LList()
{ 
   destroy();
}

template <class T>        
LList<T> :: LList ( const LList<T> & other)
{
   copy (other);
}

template <class T>        
const LList<T> & LList<T> :: operator= (const LList<T> & other)
{
   if ( this != &other )
   {
      destroy();
      copy(other);
   }

   return *this;
}

template <class T>        
bool LList<T> :: isEmpty()
{
   return first == NULL;
}
      
template <class T>        
void LList<T> :: insertItem(T item)
{
   node<T> *temp;
   temp = new node<T>;

   temp->info = item;

   // The list is empty
   if ( first == NULL )
   {
      temp->next = temp;
      first = temp;
   }

   // The item is less than the fisrt
   else if ( item < first->next->info )
   {
     temp->next = first->next;
     first->next = temp;
   }

   else
   {
     node<T> *r = first;
     node<T> *p = first->next;

     do
     {
       r = p;
       p = p->next;
     } while ( p != first && p->info < item );

     if ( p == first ) //insert after the fisrt, greater tha the fisrt
     {
       temp->next = p->next;
       first->next = temp;
       first = temp;
     }
     else // Item insert in between
     {
       temp->next = p;
       r->next = temp;
     } 
   }
}

// need to modify to circular     
template <class T>      
void LList<T> :: deleteItem(T item)
{
   if ( first == NULL || item < first->info )
      cout<<"ERROR - LIST IS EMPTY OR ITEM IS NOT IN THE LIST";
   else
   {
      node<T> *p = first;

      if ( item == first->info )
      {
         first = first->next;
         delete p;
      }
      else
      {
        node<T> *r = p;
        p = p->next;

        while ( p != NULL && item > p->info )
        {
           r = p;
           p = p->next;
        }

        if ( p == NULL || p->info > item )
           cout<<"ERROR - ITEM NOT IN THE LIST";
        else
        {
           r->next = p->next;
           delete p; 
        }
      }   
   }   
}

// need to modify to circular
template <class T>
void LList<T> :: destroy()
{
    node <T> *p;

    while ( first != NULL )
    {
       p = first;
       first = first->next;
       delete p;      
    }
}

// need to modify to circular   
template <class T>
void LList<T> :: copy ( const LList<T> & other )
{
   if ( other.first == NULL )
      first = NULL;
   else
   {
      first = new node<T>;
      first->info = other.first->info;

      node<T> *p = other.first->next;
      node<T> *r = first;

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
int LList<T> :: getLength()
{
   node<T> *p = first;
   int count = 0;
   if ( p != NULL )
   {
     do 
     {
       count++;
       p = p->next;
     } while ( p != first);
   }
   return count;
}

template <class T>        
bool LList<T> :: searchItem (T item)
{
  node<T> *p = first;

  if ( p != NULL )
  {
    do
    {
      if ( p->info == item )
        return true;
     else
        p = p->next; 
    } while ( p != first && p->info <= item );
  }
  return false;
} 

template <class T>        
void LList<T> :: printList()
{
   node<T> *p;

   p = first;

   if ( p != NULL)
   {
     do
     {
       cout<<p->info<<" ";
       p = p->next;
     } while ( p != first );
   }
} 