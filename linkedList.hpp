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
            Node<T>* tmp = cabeza;
            cabeza = cabeza->siguiente;
            cabeza->anterior = NULL;
            delete tmp;
            size--;
        }

        void eliminarFinal(){
            cola = cola->anterior;
            delete cola->siguiente;
            size--;
        }

        void insertarPosicion(T dato, int posicion){
            
            if(posicion > size){
                insertarFinal(dato);
            }else  if(posicion == 0){
                insertarInicio(dato);
            }else{
                Node<T> *nuevoNodo = new Node<T>;
                nuevoNodo->valor = dato;
                Node<T>* puntero = cabeza;
                for(int i = 1; i < posicion;i++){
                    puntero = puntero->siguiente;
                }
                puntero->anterior->siguiente = nuevoNodo;
                nuevoNodo->anterior = puntero->anterior;
                puntero->anterior = nuevoNodo;
                nuevoNodo->siguiente = puntero;
            }
        }

        void eliminarPosicion(int posicion){
            if(posicion > size){
                eliminarFinal();
            }else  if(posicion == 0){
                eliminarInicio();
            }else{
                Node<T>* puntero = cabeza;
                for(int i = 1; i < posicion;i++){
                    puntero = puntero->siguiente;
                }
                puntero->anterior->siguiente = puntero->siguiente;
                puntero->siguiente->anterior = puntero->anterior;
                delete(puntero);
                size--;
            }
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

