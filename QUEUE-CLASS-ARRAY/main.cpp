#include <iostream>
using namespace std;
#include "Queue.cpp"

int main() {
  
   Queue<char> Q;

   char f, r;
  

   Q.enqueue('F');
   Q.enqueue('G');
   Q.enqueue('B');
   Q.enqueue('A');
   Q.enqueue('Z');

   Q.getFront(f);
   cout<<"\nFront item : "<<f;

   Q.getRear(r);
   cout<<"\nRear item : "<<r;

   Q.dequeue();
   cout<<"\n\nAFTER DELETING FRONT ITEM\n";

   Q.getFront(f);
   cout<<"\nFront item : "<<f;

   Q.getRear(r);
   cout<<"\nRear item : "<<r;
}