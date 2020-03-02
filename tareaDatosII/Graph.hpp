#ifndef GRAPH_HPP
#define GRAPH_HPP
/*
 *Codigo basado en https://github.com/GGLSoftware/Grafos/blob/master/Grafo.c#L254
*/
#include <stdio.h>
#include <string>
#include <string.h>

using namespace std;

#define Nodo struct nodo
#define Arista struct arista
#define Lista struct pila

Nodo{
    char dato;
    Nodo* siguiente;
    Arista* adyacencia;
    int visitado,terminado;
    int monto;
    char anterior;
};

Arista{
    Nodo*vrt;
    Arista*siguiente;
    int peso;
};

Lista{
    Nodo* dato;
    Lista*siguiente;
    int size;
};

class Graph{
public:

    Nodo*inicio=NULL;
    Lista*ini=NULL;
    Lista*final=NULL;

    void insertarNodo(char dato){
        Nodo* aux;
        Nodo* nuevo= new Nodo;
        nuevo->dato = dato;
        nuevo->siguiente=NULL;
        nuevo->adyacencia=NULL;
        nuevo->visitado=nuevo->terminado=0;
        nuevo->monto=-1;
        nuevo->anterior=0;
        if(inicio==NULL){
            inicio=nuevo;
        }else{
            aux=inicio;
            while(aux->siguiente!=NULL){
                aux=aux->siguiente;
            }
            aux->siguiente=nuevo;
          }

     }

    void insertarArista(int peso, char ini, char fin){
        Arista* nuevo=new Arista;
        nuevo->siguiente=NULL;
        Nodo* aux;
        Nodo* aux2;
        if(inicio==NULL){
             printf("Error: El grafo está vacio\n");
             return;
        }
        nuevo->peso = peso;
        aux=inicio;
        aux2=inicio;
        while(aux2!=NULL){
            if(aux2->dato==fin){
                break;
            }
            aux2=aux2->siguiente;
        }
        if(aux2==NULL){
            printf("Error:Vertice no encontrado\n");
            return;
        }
        while(aux!=NULL){
            if(aux->dato==ini){
                agregarArista(aux,aux2,nuevo);
                return;
            }
            aux = aux->siguiente;
        }
        if(aux==NULL)
            printf("Error:Vertice no encontrado\n");
    }

    void agregarArista(Nodo* aux,Nodo* aux2,Arista* nuevo){
        Arista* a;
        if(aux->adyacencia==NULL){
            aux->adyacencia=nuevo;
            nuevo->vrt=aux2;
        }else{
            a=aux->adyacencia;
            while(a->siguiente!=NULL)
                a=a->siguiente;
            nuevo->vrt=aux2;
            a->siguiente=nuevo;
        }
    }

    void visualizarGrafo(){
        Nodo*aux=inicio;
        Arista* ar;
        printf("Nodos\n");
        while(aux!=NULL){
            printf("%c:    ",aux->dato);
            if(aux->adyacencia!=NULL){
                ar=aux->adyacencia;
                while(ar!=NULL){
                    printf(" %c",ar->vrt->dato);
                    ar=ar->siguiente;
                }
            }
            printf("\n");
            aux=aux->siguiente;
        }
        printf("\n");
    }

    void insertarPila(Nodo* aux){
        Lista*nuevo= new Lista;
        nuevo->dato=aux;
        nuevo->siguiente=NULL;
        if(ini==NULL){
            ini=nuevo;
            final=nuevo;
            ini->size++;
        }else{
           nuevo->siguiente=ini;
           ini=nuevo;
           ini->size;
        }
    }

    Nodo*desencolar(){
        Lista*aux;
        if(ini==NULL){
            return NULL;
        }else{
            aux=ini;
            ini=ini->siguiente;
            aux->siguiente=NULL;
            if(ini==NULL)
            final=NULL;
        }
        Nodo*resultado=aux->dato;
        delete aux;
        return resultado;
    }

    void reiniciar(){
        if(inicio!=NULL){
            Nodo*aux=inicio;
            while(aux!=NULL){
                aux->visitado=aux->terminado=0;
                aux=aux->siguiente;
            }
        }
    }

    string dijkstra(char a, char b){
        Nodo*aux=inicio;
        fflush(stdin);
        while(aux!=NULL){
            if(aux->dato==a){
                aux->terminado=1;
                aux->monto=0;
                break;
            }
            aux=aux->siguiente;
        }
        if(aux==NULL){
            printf("Vertice no encontrado\n");
            return "";
        }
        while(aux!=NULL){
            Arista*a=aux->adyacencia;
            while(a!=NULL){
                if(a->vrt->monto==-1 || (aux->monto+a->peso)<a->vrt->monto){
                    a->vrt->monto=aux->monto+a->peso;
                    a->vrt->anterior=aux->dato;
                }
                a=a->siguiente;
            }
            aux=inicio;
            Nodo*min=inicio;
            while(min->anterior==0 || min->terminado ==1)
            min=min->siguiente;
            while(aux!=NULL){
                if(aux->monto<min->monto && aux->terminado==0 && aux->anterior!=0)
                min=aux;
                aux=aux->siguiente;
            }
            aux=min;
            aux->terminado=1;
            if(aux->dato==b)
            break;
        }
        while(aux->anterior!=0){
            insertarPila(aux);
            char temp=aux->anterior;
            aux=inicio;
            while(aux->dato!=temp){
               aux=aux->siguiente;
            }
        }
        insertarPila(aux);
        string ruta = "";
        while(ini!=NULL){
            char paso = desencolar()->dato;
            printf("%c ",paso);
            ruta+" "+paso;

        }
            printf("\n");
        reiniciar();
        return ruta;
    }
};
#endif
