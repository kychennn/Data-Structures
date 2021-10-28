#include "LList.h"

/***************************************************************/
/* Programmer: Anna Salvati                                    */        
/* Date: Fenruary 10 , 2021                                    */        
/* Purpose:  generic sorted linked list class                  */
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

/*    
template <class T>        
void LList<T> :: insertItem(T item)
{
   node<T> *temp;
   temp = new node<T>;

   temp->info = item;

   if ( first == NULL || item < first->info )
   {
      temp->next = first;
      first = temp;
   }
   else
   {
     node<T> *r = first;
     node<T> *p = first->next;

     while ( p != NULL && p->info < item )
     {
        r = p;
        p = p->next;
     }

     temp->next = p;
     r->next = temp;
   }
}
*/

template <class T>        
void LList<T> :: insertItem(T item, node<T> *&p )
{
   if ( p == NULL || item < p->info )
   {
     node<T> *temp = p;		
     p = new node<T>;		
     p->info = item;		
     p->next = temp;		
   }
   else insertItem (item, p->next); 
}

template <class T>        
void LList<T> :: insertItem(T item)
{
    insertItem (item, first);
} 

/*      
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
*/

template <class T>        
void LList<T> :: deleteItem(T item)
{
    if ( first == NULL || item < first->info )
       cout<<"LIST EMPTY OR ITEM NOT THERE";
    else
       deleteItem (item, first);          
} 

template <class T>
void LList<T> :: deleteItem (T item, node<T> *&p)
{
   if ( p == NULL || item < p->info )
      cout<<"ITEM NOT THERE";
   else
   {
      if ( item == p->info )
      {
        node<T> *temp = p;		
        p = p->next;		
        delete temp;		
      }
      else deleteItem (item, p->next);
   }
}

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
   
   while ( p != NULL )
      {
         count++;
         p = p->next;
      
      }
 
   return count;
}

template <class T>        
bool LList<T> :: searchItem (T item)
{
  node<T> *p = first;

 
  while ( p != NULL )
  {
     if ( p->info == item )
        return true;
     else
        p = p->next;   
  }
  
  return false;

} 


template <class T>
void LList<T> :: printList (node<T> *p)
{
   if ( p != NULL )
   {     
       printList (p->next);
       cout<<p->info<<" ";
   }
}

template <class T>
void LList<T> :: printList ()
{
   printList(first);
}

/*
cout<<p->info<<" ";
printList (p->next);

tail recursive -- waste memory
function comes back nothing else need to do       
*/


/* Print backwards non recursive
template <class T>        
void LList<T> :: printList()
{
   node<T> *p;
   int length = getLength();
   T *A = new T[length];
   int index = 0;
   p = first;
     
   while ( p != NULL )
   {
      A[index++] = p->info;
      p = p->next;
   }
   
   for ( int i = length-1; i >= 0; i-- )
     cout<<A[i]<<"  ";

   delete [] A;  
} 
*/
