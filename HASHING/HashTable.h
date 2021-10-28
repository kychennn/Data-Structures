#include <iostream>
using namespace std;

#ifndef HashTable_h
#define HashTable_h

template <class T>
class HashTable
{
     private:
         T *hTable;
         int length;
         int maxhT;
         int *temp; // holds status of hTable[i]: 0 empty, // 1 occupied,  
                    // -1 deleted 

     public:
         HashTable( int m );
         ~HashTable();
         int hashF ( T item );
         void printTable();
         void insertItem ( T item );
         void deleteItem ( T item );
         void searchItem ( T item, bool &found);
};

#endif
