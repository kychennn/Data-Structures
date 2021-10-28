#include "HashTable.h"

template <class T>
HashTable<T>::HashTable( int m )
{
  length = 0;
  maxhT = m;
  hTable = new T [m];
  temp = new int [m];
  for ( int i = 0; i < m; i++ )
         temp[i] = 0; 
}

template <class T>
HashTable<T>:: ~HashTable() 
{
  delete [] hTable;
  delete [] temp;
}

template <class T>
int HashTable<T> :: hashF( T item )
{
   return ( item % maxhT);
}

template <class T>
void HashTable<T> :: printTable()
{
   for ( int j = 0; j < maxhT; j++ )
     if ( temp[j] == 1 )
        cout<<"\nPosition "<<j << " is" <<hTable[j] <<"\n";
     else cout<<"\nPosition "<<j <<" is empty\n";   
}

template <class T>
void HashTable<T> :: insertItem ( T item )
{
  
   int hashIndex;

   hashIndex = hashF( item );  
      
   while ( temp[hashIndex] == 1 && hTable[hashIndex] != item )
  {
      hashIndex= (hashIndex + 1) % maxhT;
  }

  if ( temp[hashIndex] != 1 )
  {
    hTable[hashIndex] = item;
    temp[hashIndex] = 1;
    length++;
  }
  else if ( hTable[hashIndex] == item )
    cout<<"Item is already in the table";
  else cout<<"Table is full";

}

template <class T>
void HashTable<T> :: deleteItem ( T item )
{













}

template <class T>
void HashTable<T> :: searchItem ( T item, bool & found )
{

















}

