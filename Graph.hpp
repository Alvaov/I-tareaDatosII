#include <stdio.h>
#include "Edge.hpp"
#include "NodeGraph.hpp"
#include "Cola.hpp"


class Graph{
    private :
        linkedList<nodeGraph> nodos;
        linkedList<Edge> edge;


    public :
        
        int anadirArista(int peso, int inicio, int destino);
        int anadirNodo(int valor, int weight);
        void dijkstra(struct Graph* graph, int src);

}