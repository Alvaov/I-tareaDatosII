#include <iostream> 
using namespace std;

template <typename T> class nodeGraph{
    public: 
        T valor;

};


class Graph{
    
    
public:

    int numeroDeNodos;
    int numeroDeAristas;
    linkedList<nodeGraph> nodos;
    linkedList<Edge> edges;

    Graph(graphEdge edges[], int n, int N)  {
    
        nodos = new linkedList<nodeGraph>;
        edges = new linkedList<Edge>;
        
    }

    int añadirNodo(int valor, int weight, adjNode* head)   {
        nodeGraph<T> *nuevoNodo = new nodeGraph<int>;
        nuevoNodo->valor = valor;
        nuevoNodo->cost = weight;
        nodos.insertarFinal(nuevoNodo);
         numeroDeNodos++;
        return 0;
    }

    int conectarNodo(int peso, int id, NodeGraph*<T> inicio, NodeGraph*<T> fin){
        
        Edge* edge = new Edge(peso,id,inicio,fin);
        edges.insertarFinal(edge);
        numeroDeAristas++;
        return 0;
    }
    
}