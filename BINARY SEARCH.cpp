#include <iostream>

int main() {
  std::cout << "Hello World!\n";
}
/*

binary search, also known as half-interval search, 
logarithmic search, or binary chop, 
is a search algorithm that finds the position of a target value within a sorted array. 
Binary search compares the target value to the middle element of the array.
*/



template <class T>
bool List<T> :: searchItem (T item )
{
    //      3    12    23   45    67   77    87    90  
    //    As long as the beginning index is less than or equal to the ending index (i.e. there IS an array)
    //      1.find the middle element by adding the beginning index and the ending index and divide by two
    //         if item is the middle element than you found it
    //         else if item is less than the middle element set the end to the index before the middle 
    //         else if item is larger than the middle element set the beginning to the index after the middle 
    //      2. go back to step 1 as long 

    int middle, beginning, ending;
    int count = 0;
    beginning = 0;
    ending = length -1;

    while ( beginning <= ending )
    {
       middle = (beginning + ending)/2;
       if ( item == data[middle] )
          return true;
       else if ( item < data[middle] )
          ending = middle -1;
       else  
          beginning = middle + 1;   

       count++;     
    }

    cout<<"\n****"<<count<<"*****\n"; 
    return false;

}
