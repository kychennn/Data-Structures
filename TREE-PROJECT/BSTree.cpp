/************************************************************/
/* Programmer: Jiayi Chen                                   */        
/* Date: May 10, 2021                                       */        
/* Purpose: Binary Search Tree class - implementation file  */ 
/* Input: none                                              */
/* Output: none                                             */
/************************************************************/

#include "BSTree.h"
using namespace std;

template <class T>
BSTree<T> :: BSTree ()
{
   root = NULL;
   totalSentence = 0;
   totalWords = 0;
   totalWordsMoreThanThree = 0;
   totalUniqueWords = 0;
   totalUWMoreThanThree = 0;
   totalChar = 0;
}

template <class T>
BSTree<T> :: ~BSTree ()
{
   destroy (root);
}

template <class T>
void BSTree<T> :: destroy (node<T> *& r)
{   
   if ( r != NULL )
   {
       destroy(r->left);
       destroy(r->right);
       delete r;
       r = NULL;
   }
}

template <class T>
void BSTree<T> :: destroy ()
{   
   destroy (root);
}

template <class T>
BSTree<T> :: BSTree (const BSTree<T> & other)
{
   copy (root, other.root);
}

template <class T>
const BSTree<T> &  BSTree<T> :: operator= (const BSTree<T> & other)
{
   if ( this != &other )
   {
      if ( root != NULL )
          destroy (root);

      // THE TREE IS EMPTY    
      if ( other.root == NULL )
         root = NULL;
      // THE TREE IS NOT EMPTY
      else copy (root, other.root);       
   }
   return *this;
}

template <class T>
void BSTree<T> :: copy (node<T> *& nroot, node<T> *croot  )
{
    if ( croot == NULL )
       nroot = NULL;
    else
    {
       nroot = new node<T>;
       nroot->info = croot->info;    // COPY THE INFO
       copy (nroot->left, croot->left);
       copy (nroot->right, croot->right);
    }    
}

template <class T>
bool BSTree<T> :: isEmpty ()
{
   return root == NULL;
} 

template <class T>
void BSTree<T> :: preOrder ()
{
   preOrder (root);
    
}

template <class T>
void BSTree<T> :: preOrder (node<T> *p )
{
   if (p != NULL)
   {
      cout<<p->info<<" ";
      preOrder(p->left);
      preOrder(p->right);
   }
}

template <class T>
void BSTree<T> :: postOrder ()
{
  postOrder (root);
  
}

template <class T>
void BSTree<T> :: postOrder (node<T> *p )
{
   if ( p != NULL)
   {
      postOrder (p->left);
      postOrder(p->right);
      cout<<p->info<<" ";    
   }
}

template <class T>
void BSTree<T> :: inOrder ()
{
  inOrder(root);
  
}

template <class T>
void BSTree<T> :: inOrder (node<T> *p )
{ 
    if ( p != NULL)
    {
       inOrder (p->left);
       cout<<p->info<<" ";   
       inOrder(p->right);
      
    }  
}

template <class T>
void BSTree<T> :: insertItem (T item)
{
   node<T> *p;         // pointer to walk
   node<T> *trail;     // stay behind p
   node<T> *temp;      // contain item

   temp = new node<T>;
   T str = remPunc(item);
   temp->info = str;
   temp->left = NULL;
   temp->right = NULL;

   if ( root == NULL )    // the tree is empty
   {
     root = temp;
     totalUniqueWords++;
     longWord(item);
   }
      
   else
   {
      p = root;

      while ( p != NULL )
      {
          trail = p;

          //if ( p->info == item )
          if ( p->info == str )
          {
             p->repetition++;
             delete temp;
             return ;
          }
          else if ( p->info > item )
            p = p->left;
                        
          else
            p = p->right;

      }
      
      // insert the item to the left or right of the trail
      if ( trail->info > item )
      {
        trail->left = temp;
        totalUniqueWords++;
        longWord(item);        
      }
          
      else
      {
        trail->right = temp;
        totalUniqueWords++;
        longWord(item);  
      }      
   }   
}

template <class T>
bool BSTree<T> :: searchItem (T item )
{
   node<T> *p;
   bool found;

   p = root;
   found = false;

   while ( p != NULL && !found )
   {
      if ( p->info == item )
         found = true;
      else if ( item < p->info )
         p = p->left;
      else
         p = p->right;      
   }

   return found;
}

template <class T>
void BSTree<T> :: deleteItem (T item )
{
   deleteItem (root, item);
}

template <class T>
void BSTree<T> :: deleteItem (node<T> *&p, T item )
{
    if ( p == NULL )
       cout<<"ITEM NOT THERE";
    else if ( item > p->info )
       deleteItem (p->right, item);
    else if ( item < p->info )
       deleteItem (p->left, item);
    else 
       deleteNode (p);              
}

template <class T>
void BSTree<T> :: deleteNode (node<T> *& p )
{
    node<T> *q;

    q = p;

    if ( p->left == NULL )
    {
       p = p->right;
       delete q;

    }
    else if ( p->right == NULL )
    {
       p = p->left;
       delete q;
    }
    else 
    {
       q = p->left;
       node<T> *trail = NULL;

       while ( q->right != NULL)
       {
          trail = q;
          q = q->right;
       }

       p->info = q->info;

       if (  trail == NULL )
          p->left = q->left;
       else
          trail->right = q->left;

       delete q;      
    }
}

template <class T>
int BSTree<T> :: getTotalWords()
{
  return totalWords;
}

template <class T>
int BSTree<T> :: getTotalWordsMoreThanThree()
{
  return totalWordsMoreThanThree;
}

template <class T>
int BSTree<T> :: getTotalUniqueWords()
{
  return totalUniqueWords;
}
      
template <class T>      
int BSTree<T> :: getTotalUWMoreThanThree()
{
  return totalUWMoreThanThree;
} 

template <class T>
int BSTree<T> :: getAvgWordLength()
{
  return (totalChar/totalWords);
}

template <class T>
int BSTree<T> :: getAvgSentenceLength()
{
  return (totalWords/totalSentence);
}

template <class T>     
bool BSTree<T> :: isSentence(T item)
{
  int size = item.length();
  bool isPunc = false;
  if ( item[size-1] == '.' || item[size-1] == '!' || item[size-1] == '?' || item[size-1] == '\0')
      isPunc = true;
  return isPunc;
}

template <class T>     
void BSTree<T> :: wordCounter(T item)
{
  if ( item.length() > 3 )
    totalWordsMoreThanThree++;

  totalWords++;
}

template <class T>     
void BSTree<T> :: charCounter( T item )
{
  for ( int i = 0; i < item.length() && !isSentence(item) ; i++ )
      totalChar++;
}

template <class T>
void BSTree<T> :: sentenceCounter(T item)
{
  if ( isSentence(item) )
  {
    totalSentence++;
  }
}

template <class T>
void BSTree<T> :: longWord(T item)
{
  if ( item.length() > 3 )
     totalUWMoreThanThree++;
}

template <class T>
void BSTree<T> :: printOftenWords (ofstream& outfile)
{
  printOftenWords (root, outfile);
}

template <class T>
void BSTree<T> :: printOftenWords (node<T> *p, ofstream& outfile)
{
  double percentage = 0;
  static int i = 1;
  if ( p != NULL)
  {
     printOftenWords (p->left, outfile);

     percentage = static_cast<double> (p->repetition) / static_cast<double> (getTotalWordsMoreThanThree());
     if (p->info.length() > 3)
     {
       if ( percentage > 0.05 )
       {
         outfile << i <<") " << p->info << endl;
         i++;
       }
     }
      printOftenWords(p->right, outfile);
  }
}

template <class T>
void BSTree<T> :: printIndex(ofstream& outfile)
{
  char a = '0';
  printIndex( root, a, outfile );
}

template <class T>
void BSTree<T> :: printIndex(node<T> *p , char &index, ofstream& outfile )
{
  if ( p != NULL )
  {
    printIndex (p->left, index, outfile);

    if(p->info[0] > index)
    {
       outfile << "\n---" << char(p->info[0]-32) << "---\n";
       index = p->info[0];
    }
    outfile << p->info << endl;

    printIndex (p->right, index, outfile);
  }
}     

template <class T>
T BSTree<T> :: remPunc(const T& w)
{
    string result;
    for (auto ch: w)
        if (!ispunct(ch))
            result += ch;
    return result;
}