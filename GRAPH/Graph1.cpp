// adjacency matrix

#include "Graph1.h"

// going to int maxVertices;
// create T *vertices; and int int **edges;;
// initialize int **edges to 0
template <class T>
Graph1<T> :: Graph1 (int max )
{
   // if the client doesnot give the max then will be 100
   maxVertices = max; 
   numVertices = 0;
   // array
   vertices = new T[max];
   visited = new bool[max];
   // create array[max] of pointer to integer (int*)
   // create one dimensional array of pointer
   edges = new int*[max];
   // for each pointer, create one dimensional array of int 
   // already created dynamic 2D array
   for ( int i = 0; i < max; i++ )
      edges[i] = new int [max];

   // initialize dynamic 2D array
   for ( int i = 0; i < max; i++ )
      for ( int j = 0; j < max; j++ )
          edges[i][j] = 0;   

   // edges = new int*[max];  is int so initialize 1/0
   // if bool we initialize T/F
   // if Weighted graph, we initialize max
}