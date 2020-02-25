#include <iostream> 
using namespace std;

template <typename T> class NodeGraph{
    public: 
        T valor;
        NodeGraph *anterior = nullptr;
        NodeGraph *siguiente = nullptr;

};