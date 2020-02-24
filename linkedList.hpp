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
                }else{
                    cola = nuevoNodo;
                }
                cabeza = nuevoNodo;
                size++;
            }

        void insertarFinal(T dato){
                Node<T> *nuevoNodo = new Node<T>;
                nuevoNodo->valor = dato;
                nuevoNodo->anterior = cola;
                nuevoNodo->siguiente =NULL;

                if(cola != NULL){
                    cola->siguiente = nuevoNodo;
                }else{
                    cabeza = nuevoNodo;
                }
                cola = nuevoNodo;
                size++;
            }
        void eliminarInicio(){
            cabeza = cabeza->siguiente;
            delete cabeza->anterior;
        }

        void eliminarFinal(){
            cola = cola->anterior;
            delete cola->siguiente;
        }

        void display() { 
            Node<T> *ptr;
            ptr = cabeza;  
            while(ptr != NULL) { 
                cout<< ptr->valor <<" "; 
                ptr = ptr->siguiente; 
            }
        }

        void displayR() { 
            Node<T> *ptr;
            ptr = cola;  
            while(ptr != NULL) { 
                cout<< ptr->valor <<" "; 
                ptr = ptr->anterior; 
            }
        }
};

