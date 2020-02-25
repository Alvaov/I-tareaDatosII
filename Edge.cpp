#include <stdio.h>
#include "NodeGraph.hpp"

class Edge{
    public :

        int peso, id;
        NodeGraph<T>* inicio, fin;

        Edge(int peso, NodeGraph*<T> inicio, NodeGraph*<T> fin, int id){
            this->peso = peso;
            this->inicio = inicio;
            this->fin = fin;
            this->id = id;
        }

}