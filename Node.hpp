#include <iostream> 
using namespace std;

template <typename T> class Node{
    public: 
        T valor;
        Node *anterior = NULL;
        Node *siguiente = NULL;

};