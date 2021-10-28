#include <iostream>
using namespace std;

/***************************************************************/
/* Programmer: Anna Salvati                                    */     
/* Date:  February 3, 2021                                     */        
/* Purpose:  List class, array implementation, header file     */ 
/* Input: none                                                 */
/* Output: none                                                */
/***************************************************************/

#ifndef LIST_H
#define LIST_H
template <class T>
class List
{
    private:
       T *data;
       int max;
       int length;

    public:
       // Constructor with default parameter for max capacity
       // Sets length to 0 and creates array of parameter capacity
       List ( int = 100 );
       //Destructor
       ~List();
       // Copy constructor
       List ( const List<T> & );   
       // Overloaded = 
       const List<T> &  operator= ( const List<T> & );
       // Function that returns the current length of the list
       int getLength();
       //Function returns true if list is full, false otherwise
       bool isFull();
       //Function returns true if list is empty, false otherwise
       bool isEmpty();
       // Function inserts parameter in the list - if list is not full - 
       // and increases length. If list is full it prints an error message
       void insertItem (T);
       // Function deletes parameter from the list - if parameter is in the // list - and decreases length. If list is empty ot parameter is not // in the list it prints an error message
       void deleteItem (T);
       // Function returns true if parameter is in the list, false otherwise
       bool searchItem (T);
       // Function prints items in the list
       void printList();
};

#endif