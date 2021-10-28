#include <iostream>
using namespace std; 

//int sumEven (int);

void sumEven (int, int&);

void sumPositives (int, int&);

void printPositiveBack (int[], int);

void printPositiveFront (int[], int, int);

int main() 
{
   int limit = 20;
   int sumE = 0;
   int sumP = 0;
   int A[10] = {3,-2,0,5,8,11,6,-4,-7,12};
   int size = 10;

   //sumE = sumEven (limit);
   sumEven(limit, sumE);
   sumPositives(limit, sumP);
   printPositiveBack (A, size);
   printPositiveFront (A, size, 0);
   
   cout<<"\nThe sum of all even between 0 and " <<limit <<" is "<< sumE; 

   cout<<"\nThe sum of all positive integers between 0 and " 
       <<limit <<" is "<< sumP; 
}
/*
int sumEven (int limit)
{
  if (limit == 0)
    return 0;
  else 
    return limit + sumEven (limit-2);
}
*/
void sumEven ( int limit, int &sumE )
{
   if ( limit > 0 )
   {
      sumE += limit;
      sumEven (limit-2, sumE);
   }
}

void sumPositives ( int limit, int &sumP )
{
   if ( limit > 0 )
   {
      sumP = sumP + limit;
      sumPositives (limit-1, sumP);
   }
}

void printPositiveBack(int A[], int size)
{
  if(size > 0)
  {
      if (A[size-1] > 0)
        cout<<A[size-1]<<" ";
      printPositiveBack (A,size-1);
  }
}

void printPositiveFront(int A[], int size, int index)
{
  if(index < size)
  {
      if (A[index] > 0)
        cout<<A[index]<<" ";
      printPositiveFront (A,size,index+1);
  }
}