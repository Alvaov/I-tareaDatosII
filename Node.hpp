#include <iostream> 
using namespace std;

template <typename T> class Node{
    public: 
        T valor;
        Node *anterior;
        Node *siguiente;

};