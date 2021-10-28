#include <iostream>
#include <fstream>
using namespace std;

// n*logn
// very stable
// recursive is log n and comparison/merge is n
void mergeSort ( int [], int, int );
void merge ( int [], int, int, int, int);

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
  
  mergeSort (A, 0, length-1);

  cout<<"\n\nLIST SORTED IS : ";

  for ( int i = 0; i < length; i++ )
     cout<<A[i]<<" ";
  
  infile.close();

  return 0;   
}

void mergeSort ( int a[], int first, int last )
{
   if ( first < last )
   {
      // get the index of the element which is in the middle
      int middle = (first + last )/ 2;
      // sort the left side of the array
      mergeSort (a, first, middle);
      // sort the righ side of thr array
      mergeSort (a, middle+1, last);
      // combine them both
      merge (a, first,middle,middle+1,last);   
   }
}

void merge ( int a[], int lfirst, int llast, int rfirst, int rlast )
{
   int temp[20];
   int save = lfirst;
   int j = lfirst;  //temp array index

   while ( lfirst <= llast && rfirst <= rlast )
   {
       if ( a[lfirst] < a[rfirst] )
          temp[j++] = a[lfirst++];
       else
          temp[j++] = a[rfirst++];   
   }

   while ( lfirst <= llast )
       temp[j++] = a[lfirst++];

   while ( rfirst <= rlast )
       temp[j++] = a[rfirst++];
 
   // put the sorted temp array back to original array
   for ( int i = save ; i <= rlast; i++ )
       a[i] = temp[i];    
}