#include "DList.cpp"

/***************************************************************/
/* Programmer: Jiayi Chen.                                     */
/* Date: March 2, 2021                                         */
/* Purpose: Test the doubly linked list class using a menu     */
/*          driven program                                     */
/* Input: user’s choice to perform an operation                */  
/* Output: menu of choices and results of user’s operations.   */  
/***************************************************************/

// printMenu displays a menu of choices and returns the user's choice
 
int printMenu();

// InsertList inserts an item at front

void insertItemAtFront ( DList<int> & );

// InsertList inserts an item at back

void insertItemAtBack ( DList<int> & );

// deleteList deletes an item from the list parameter

void deleteListItem ( DList<int> & );

// searchItem searches for an item in the list parameter

void searchListItem ( DList<int> & ); 

//************************** main program ************************/

int main()
{
   DList<int> l;
   int choice;
   
   cout<<"\nOperations allowed on the unsorted list of integers are below."
      <<"\nPlease enter the number of your choice and press return.\n\n"; 

   choice = printMenu();

   while ( choice != 7 )
   {

       switch ( choice )
      {
   
         case 1 : insertItemAtFront( l );
                  break;

         case 2 : insertItemAtBack( l );
                  break;
    
         case 3 : deleteListItem ( l );
                  break;

         case 4 : l.printList();
                  break;
                   
         case 5 : searchListItem ( l );
                  break;
                     
         case 6 : cout<<"\nThe list contains "<<l.getLength()
                      << " items\n\n";
                  break; 
                 
         default :cout<<"\nNumber is not correct. Please look at "
                      <<"choices and reenter\n\n";
                 break;
      }

      choice = printMenu();
   }

   DList<int> l2; 

   l2 = l;   

   cout<<"\nPrinting a new list with the same values as the old list \n";
   
   l2.printList();
   
   cout<<"\n\n\nTesting the iterator\n";

   // Access items from front to back
   auto iter = l.beginAtFront();
   cout<<"\nThe first item in the list is "<<*iter;
   
   iter++;
   cout<<"\nThe second item in the list is "<<*iter;

   // Access items from back to front
   iter = l.beginAtBack();
   cout<<"\nThe last item in the list is "<<*iter<<endl;
   

   cout<<"\nProgram terminated\n\n";


   return 0;
}

//********************functions implementation ********************//

int printMenu ()
{
   int c;

   cout<<"\n1: Add an item to the list at front.";
   cout<<"\n2: Add an item to the list at back.";
   cout<<"\n3: Delete an item from the list.";
   cout<<"\n4: Print the list.";
   cout<<"\n5: Search the list for a given item";
   cout<<"\n6: Return the number of items in the list";
   cout<<"\n7: Quit.\n\n";
   cin>>c;

   return c;
}

void insertItemAtFront ( DList<int> &l )
{
   int num;  
  
   
      cout<<"\nEnter the number to insert at front: ";
      cin>>num;
      l.insertItemAtFront(num);
      cout<<"\nThe number has been inserted\n\n";
   
   
}

void insertItemAtBack ( DList<int> &l )
{
   int num;  
  
   
      cout<<"\nEnter the number to insert at back: ";
      cin>>num;
      l.insertItemAtBack(num);
      cout<<"\nThe number has been inserted\n\n";
   
   
}

void deleteListItem ( DList<int> &l )
{

   int num;

   cout<<"\nEnter the number to delete : ";
   cin>>num;
   
   if ( l.searchItem (num))
   { 
      l.deleteItem (num);
      cout<<"\nThe number has been deleted\n\n";
   }
   else  cout<<"\nThe number is NOT in the list\n\n";
 
       
}

void searchListItem ( DList<int> &l )
{

   int num;

   cout<<"\nEnter the number to search for : ";
   cin>>num;
       
   if ( l.searchItem (num))
   
       cout<<"\nThe number is in the list\n\n";
   
   else  cout<<"\nThe number is NOT in the list\n\n";
          
}