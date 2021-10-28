// class to implememt graphs with adjacency list
// create your own struct node
template <class T>
struct node
{
   T info;
   node *next;
};

template <class T>
class Graph2
{
   private:
     int numVertices;
     int maxVertices;
     T *vertices;
     // pointer *edges to node*
     node **edges;

   public:
     Graph2(int max)
     {
        numVertices = 0;
        maxVertices = max;
        vertices = new T[max];
        edges = new node<T>*[max];
        for ( int i = 0; i < maxVertices; i++)
          edges[i] = NULL;
     }  
}