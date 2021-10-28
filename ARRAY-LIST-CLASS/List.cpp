#include "List.h"

/***************************************************************/
/* Programmer: Anna Salvati                                    */        
/* Date: February 3, 2021                                      */        
/* Purpose: Array  List class  -   implementation file         */ 
/* Input: none                                                 */
/* Output: none                                                */
/***************************************************************/

template <class T>
List<T> :: List ( int size )
{
   max = size;
   length = 0;
   data = new T[max];
}

template <class T>
List<T> :: ~List()
{
   delete [] data;
}

template <class T>
List<T> :: List ( const List<T> & other )
{
   max = other.max;
   length = other.length;
   data = new T[max];
   for ( int i = 0; i < length; i++ )
       data[i] = other.data[i];
}

template <class T>
const List<T> & List<T> :: operator= ( const List<T> & other )
{
   if ( this != &other )
   {
      delete [] data;
      max = other.max;
      length = other.length;
      data = new T[max];
      for ( int i = 0; i < length; i++ )
        data[i] = other.data[i];
   } 

   return *this;    
}

template <class T>
int List<T> :: getLength()
{
   return length;
}

template <class T>
bool List<T> :: isFull ()
{
   return max == length;
}

template <class T>
bool List<T> :: isEmpty ()
{
    return length == 0;

}

template <class T>
void List<T> :: printList()
{
   if ( isEmpty())
      cout<<"\nLIST IS EMPTY";
   else
   {
      for ( int i = 0; i < length; i++ )
         cout<<data[i]<<"  ";
   }   
}

template <class T>
void List<T> :: insertItem ( T item )
{
    if ( isFull())
        cout<<"\nLIST IS FULL INSERTION FAILED";
    else
        data[length++] = item;      
    
}

template <class T>
bool List<T> :: searchItem (T item )
{
    bool found;
    int i;

    found = false;
    i = 0;

    while ( i < length && !found )
    {
        if ( data[i] == item )
            found = true;
        else
            i++;    
    }

    return found;
}

template <class T>
void List<T> :: deleteItem (T item)
{
    if ( isEmpty())
       cout<<"\nDELETION FAILED - LIST EMPTY";
    {
        bool found;
        int i;

        found = false;
        i = 0;

        while ( i < length && !found )
        {
           if ( data[i] == item )
               found = true;
           else
              i++;    
        }

        if ( found )
           data[i] = data[--length];
        else
           cout<<"\nDELETION FAILED - ITEM NOT IN THE LIST";   
    }   
}
