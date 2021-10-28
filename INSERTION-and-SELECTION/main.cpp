#include <iostream>
#include <fstream>
using namespace std;

void selectionSort ( int [], int );
void insertionSort ( int [], int );

void swap (int &x, int &y);

int main() {
  int A[20];
  int length = 0; 
  ifstream infile;
  

  infile.open("Unsorted.txt");
  
  while (!infile.eof())
    infile>> A[length++];
  
  cout<<"\nLIST UNSORTED IS : ";

  for ( int i = 0; i < length; i++ )
     cout<<A[i]<<" ";
  
  //selectionSort (A, length);
  insertionSort (A, length);

  cout<<"\n\nLIST SORTED IS : ";

  for ( int i = 0; i < length; i++ )
     cout<<A[i]<<" ";
  
  infile.close();

  return 0;   
}

void swap ( int &x, int &y)
{
   int temp = x;
   x = y;
   y = temp; 
}


// O (n*n)
void selectionSort ( int A[], int n )
{
   int min;

   for ( int i = 0; i < n-1; i++ )
   {
      min = i;

      for ( int j = i + 1; j < n ; j++ )
      {
          if ( A[j] < A[min] )
             min = j;         
      }
      if ( min != i )
         swap (A[i], A[min]);
   }
}


// O (n*n); better than selection sort
void insertionSort ( int A[], int n )
{   
    bool order;
    int j;

    for ( int i = 1; i < n; i++ )
    {
        order = false;
        j = i;

        while ( !order && j != 0 )
        {
            if ( A[j] < A[j-1])
            {
               swap (A[j], A[j-1]);
               j--;
            }
            else order = true;
        }       
    }
}