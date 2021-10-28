#include <iostream>
#include <fstream>
using namespace std;

// log n
// quickSort is better than mergeSort in average cases
// quickSort is bad, IS NOT log n level, IS n level: 
// 15 14 12 10 8 7 5 3 2
void quickSort ( int[], int, int );
int split ( int [], int, int);

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
  
  quickSort (A, 0, length-1);

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

void quickSort ( int a[], int first, int last )
{
  if ( first < last )
  {
     int pivotindex;
     pivotindex = split (a, first, last);
     quickSort (a, first, pivotindex -1);
     quickSort  (a, pivotindex+1, last);    
  }
}

// function can call partition or split
// i: walk through the array
// If element is greater than pivot then leave it alone
// If element is smaller than pivot then increase pv, also swap a[pv] and a[i]
int split ( int a[], int f, int l)
{
   int pivot = a[f];
   int pv = f;

   for ( int i = f+1; i <= l; i++ )
   {
       if ( a[i] < pivot )
       {
          pv++;
          swap (a[pv], a[i]);
       }
   }

   swap (a[pv], a[f]);

   return pv;
}

// two loop
// one loop from the beginning: if smaller than pivot, keep going 
// the other from the end: if greater than pivot, keep going 
int split2 ( int a[], int f, int l )
{
    int pivot = a[f];
    int save = f++;
    
    do
    {
        while ( f <= l && a[f] <= pivot )
           f++;

        while ( f <= l && a[l] > pivot)
           l--;

        if ( f < l )
           swap (a[f++], a[l--]);       

    }while ( f <= l);
 
    swap (a[save], a[l]);

    return l;
}