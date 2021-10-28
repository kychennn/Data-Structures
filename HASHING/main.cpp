#include "HashTable.cpp"

int main()
{
  int size,i, item;
  bool found;

  cout<<"Enter the size of the hash table ";
  cin>> size;

  HashTable<int> HT(size);

  for ( i = 1; i <= 12; i++ )
  {
     cout<<"\nEnter the item to insert ";
     cin>> item;

     HT.insertItem (item);
  }

     /*for ( i = 1; i <= 3; i++ )
       {
         cout<<"Enter the item to delete ";
         cin>> item;

         HT.deleteItem (item);
       }
  
     for ( i = 1; i <= 3; i++ )
     {
        cout<<"Enter the item to search for ";
        cin>> item;
       
        HT.searchItem ( item, found );

        if ( found )
          cout<<"Item found";
        else  cout<<"Item not there";
     }*/

     HT.printTable();

return 0;
}


