#include "BSTree.h"

template <class T>
BSTree<T> :: BSTree ()
{
   root = NULL;
}

template <class T>
BSTree<T> :: ~BSTree ()
{
   destroy (root);
}

// postOrder
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

// preOrder
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
void BSTree<T> :: insertItem (T item )
{
   node<T> *p;         // pointer to walk
   node<T> *trail;     // stay behind p
   node<T> *temp;      // contain item

   temp = new node<T>;
   temp->info = item;
   temp->left = NULL;
   temp->right = NULL;

   if ( root == NULL )    // the tree is empty
      root = temp;
   else
   {
      p = root;

      while ( p != NULL )
      {
          trail = p;

          if ( p->info == item )
          {
             cout<<"ERROR: DUPLICATES NOT ALLOWED";
             delete temp;
             return;
             // p->counter++;   if have counter in struct
          }
          else if ( p->info > item )
            p = p->left;
          else
            p = p->right;
      }
      
      // insert the item to the left or right of the trail
      if ( trail->info > item )
          trail->left = temp;
      else
          trail->right = temp;    
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

// deaing with the tree or linked list with recursion, you can have &
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
    node<T> *q;   // pointer to delete

    q = p;

    //has right child or leaf
    if ( p->left == NULL )
    {
       p = p->right; //p is a real thing(&), modify the tree
       delete q;
    }
    //has left child or leaf
    else if ( p->right == NULL )
    {
       p = p->left;
       delete q;
    }
    // has two children
    else 
    {
       q = p->left;
       node<T> *trail = NULL;   //behind the q

       while ( q->right != NULL)
       {
          trail = q;
          q = q->right;
       }
       p->info = q->info;

       // doesnot go inside the while loop
       if (  trail == NULL )
          p->left = q->left;
       else
          trail->right = q->left;

       delete q;      
    }
}
