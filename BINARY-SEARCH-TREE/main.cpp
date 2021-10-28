#include "BSTree.cpp"

int main() 
{
  BSTree<int> T1;
  int item;

  ifstream infile;

  infile.open("Numbers.txt");
  
  while (!infile.eof())
  {
     infile>> item;
     T1.insertItem (item);
  }

  T1.inOrder();

  T1.deleteItem (35);
  
  cout<<"\n";
  
  T1.preOrder();


  return 0;
}