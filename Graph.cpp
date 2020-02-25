#include <stdio.h>
#include "Edge.cpp"
#include "linkedList.hpp"


class Graph{
    private :
        linkedList<NodeGraph> NodeGraph;
        linkedList<Edge> Edges;


    public :
        
        añadirArista();
        añadirNodo();
        dijkstra();

}