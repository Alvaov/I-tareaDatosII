#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include "Node.hpp"
using namespace std;

template <typename T> class linkedList{
    public:
        Node<T> *cabeza;
        Node<T> *cola;
        int size;

        linkedList(){
            cabeza = NULL;
            cola = NULL;
            size = 0; 
        }

        void insertarInicio(T dato){
                Node<T> *nuevoNodo = new Node<T>;
                nuevoNodo->valor = dato;
                nuevoNodo->anterior = NULL;
                nuevoNodo->siguiente =cabeza;

                if(cabeza != NULL){
                    cabeza->anterior = nuevoNodo;
                }
                cabeza = nuevoNodo;
            }

        void display() { 
            Node<T> *ptr;
            ptr = cabeza;  
            while(ptr != NULL) { 
                cout<< ptr->valor <<" "; 
                ptr = ptr->siguiente; 
            }
        }
};

