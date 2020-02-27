#include <stdio.h>
#include "NodeGraph.hpp"

template <typename T> class Edge{
    public :

        int peso, id;
        nodeGraph<T>* inicio, destino;

        Edge(int peso, int id, nodeGraph<T>* destino){
            this->peso = peso;
            this->inicio = inicio;
            this->destino = destino;
            this->id = id;
        }

};