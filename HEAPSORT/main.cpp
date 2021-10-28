#include <iostream>
#include <fstream>
using namespace std;

// Heap is implemented as an array
// Definition:
// A heap is a list in which each element contains a key,
// such that the key in the element at position k 
// in the list is at least as large as the key in the element 
// at position 2k + 1 (if it exists) and 2k + 2 (if it exists).

void heapSort ( int [], int );
void heapDown ( int [], int, int );

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
  
  heapSort (A, length);

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


void heapSort ( int a[], int n )
{
   int j;

   // loop to create the heap
   for ( j = n/2-1; j >= 0; j-- )
      heapDown (a,j, n-1);

   // After create a heap, loop to sort the heap
   for ( j = n-1; j >= 1; j-- )
   {
      swap ( a[0], a[j] );    // keep swap the root and the last unsorted element
      heapDown (a, 0, j-1);
   }

}

void heapDown ( int a[], int root, int last )
{
   // assume the larger number is left child
   // if there only one child that must be left (complete binary tree)
   int large = 2 * root + 1;   // cannot be applied to linked list, reply on 2*root+1
   int temp = a[root];

   while ( large <= last )
   {
      // There is right child and if larger than left child
      // and change large=right child
      if ( large < last )
         if (a[large] < a[large + 1] )
             large = large + 1;


      // if root greater than child, get out the loop
      if ( temp > a[large])
         break;
      // if root less than child
      else   
      {
         a[root] = a[large];
         root = large;
         large = 2 * root + 1;   //left child
      }          
   }
   a[root] = temp;    
   // do this once at the end out of the loop and donot use swap in the loop because efficiency
}