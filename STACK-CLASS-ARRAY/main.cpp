#include "Stack.cpp"


/***************************************************************/
/* Programmer: Anna Salvati                                    */         /* Date: February 3, 2021                                      */          
/* Purpose: Test the stack class using a menu driven      */
/*          program                                            */
/* Input: user’s choice to perform an operation                */          /* Output: menu of choices and results of user’s operations.   */           /***************************************************************/

// printMenu displays a menu of choices and returns the user's choice
 
int printMenu();

//************************** main program ************************/

int main()
{

   Stack<int> S;

   int choice;
   int item;
   
   cout<<"\nOperations allowed on the stack of integers are below."
      <<"\nPlease enter the number of your choice and press return.\n\n"; 

   choice = printMenu();

   while ( choice != 4 )
   {

       switch ( choice )
      {
   
         case 1 : cout<<"\nEnter number to push on the stack : ";
                  cin>>item;
                  S.push(item);
                  break;
    
         case 2 : S.pop();
                  break;

         case 3 : S.top(item);
                  cout<<"\nTop item is : "<<item;
                  break;
                 
         default :cout<<"\nNumber is not correct. Please look at "
                      <<"choices and reenter\n\n";
      }

      choice = printMenu();
   }
   
   return 0;

   
}

int printMenu ()
{
   int c;

   cout<<"\n1: Push an item to the stack.";
   cout<<"\n2: Pop an item from the stack.";
   cout<<"\n3: Return the top item";
   cout<<"\n4: Quit.\n\n";
   cin>>c;

   return c;
}

