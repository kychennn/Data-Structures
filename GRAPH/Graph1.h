// class that implements a graph using adjacency matrix

template <class T>
class Graph1
{
    private:
       // how many vertices we have right now 
       int numVertices;
       // the maximum vertices
       int maxVertices;
       // pointer to create vertices dynamic array
       T *vertices;
       // double pointer to create dynamic 2D array
       // *edges is a pointer to pointer int*
       int **edges;
       // array of type boolean
       bool *visited; 
    public:
       Graph1 (int = 100);
       void insertVertex (T);   // very easy
       void deleteVertex(T);  // hard
       // T from to T
       void addEdge (T,T);    // easy
       void deleteEdge (T,T);  // easy
       bool hasEdge (T,T);    // easy
       bool isFull();
       int getNumVertices();

       void resetVisited();
       void setVisted (T);       
       bool isVisited (T); 
       
       // for each vertex y adjacent to x
       void getVertices (T, Queue<T> &);

};