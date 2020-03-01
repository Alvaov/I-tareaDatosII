#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <stdio.h>
#include "NodeGraph.hpp"

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

    void recorridos(){
        char vertice;
        Nodo*aux=inicio,*aux2=inicio;
      if(inicio!=NULL){
         fflush(stdin);
         printf("Escoger vertice inicial:");
         scanf("%c",&vertice);
         while(aux!=NULL){
            if(aux->dato==vertice)
            break;
            aux=aux->siguiente;
         }
         if(aux==NULL){
            printf("Error: Vertice no encontrado\n");
         }else{
            printf("Recorrido por anchura: ");
            aux->visitado=1;
            insertarCola(aux);
            recorridoAnchura();
            reiniciar();
            printf("\nRecorrido por profundidad: ");
            recorridoProfundidad(aux);
            while(aux2!=NULL){
                if(aux2->terminado==0)
                recorridoProfundidad(aux2);
                aux2=aux2->siguiente;
            }
            while(ini!=NULL)
                printf("%c ",desencolar()->dato);
            reiniciar();
            printf("\n");
         }
       }
    }
    // 0407 Contraseña de MemoLey
    // 1-0 Contraseña de internet
    void recorridoAnchura(){
        Nodo*aux=desencolar();
        if(aux==NULL)
        return;
        printf("%c ",aux->dato);
        if(aux->adyacencia!=NULL){
            Arista*a=aux->adyacencia;
            while(a!=NULL){
                if(a->vrt->visitado==0){
                    insertarCola(a->vrt);
                    a->vrt->visitado=1;
                }
                a=a->siguiente;
            }
        }
        recorridoAnchura();

    }

    void recorridoProfundidad(Nodo* aux){
        Arista*a;
        aux->visitado=1;
        if(aux->adyacencia!=NULL){
            a=aux->adyacencia;
            while(a!=NULL){
                if(a->vrt->visitado==0){
                    recorridoProfundidad(a->vrt);
                }
                a=a->siguiente;
            }
        }
        aux->terminado=1;
        insertarPila(aux);
    }

    void insertarPila(Nodo* aux){
        Lista*nuevo=(Lista*)malloc(sizeof(Lista));
        nuevo->dato=aux;
        nuevo->siguiente=NULL;
        if(ini==NULL){
            ini=nuevo;
            final=nuevo;
        }else{
           nuevo->siguiente=ini;
           ini=nuevo;
        }
    }

    void insertarCola(Nodo*aux){
        Lista*nuevo=(Lista*)malloc(sizeof(Lista));
        nuevo->dato=aux;
        nuevo->siguiente=NULL;
        if(ini==NULL){
            ini=nuevo;
            final=nuevo;
        }else{
            final->siguiente=nuevo;
            final=nuevo;
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
        free(aux);
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
    //Lorem Ipsum
    void dijkstra(char a, char b){
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
            return;
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
        while(ini!=NULL){
            printf("%c ",desencolar()->dato);
        }
            printf("\n");
        reiniciar();
    }
};
#endif
 /*
class Graph{

    public :
        int numeroNodos;
        linkedList<nodeGraph<int>*>* nodos;
        linkedList<Edge<int,nodeGraph>*>* edges;
        linkedList<nodeGraph<int>*>* ini = new linkedList<nodeGraph<int>*>;

        Graph();
        nodeGraph<int>* insertarNodo(int valor,char dato);
        int insertarArista(int peso, char inicio, char destino);
        void dijkstra(char inicio, char b);
        void insertarPila(nodeGraph<int>* fuente);
        nodeGraph<int>* desencolar();
        void reiniciar();

};


    Graph::Graph(){
        nodos = new linkedList<nodeGraph<int>*>;
        edges = new linkedList<Edge<int,nodeGraph>*>;
        numeroNodos = 0;

        }

    nodeGraph<int>* Graph::insertarNodo(int valor, char dato){
            nodeGraph<int>* nuevoNodo = new nodeGraph<int>;
            nuevoNodo->valor = valor;
            nuevoNodo->dato = dato;
            nuevoNodo->adyacencia = new linkedList<Edge<int,nodeGraph>*>;
            nuevoNodo->visitado = 0;
            nuevoNodo->terminado = 0;
            nuevoNodo->monto = 0;
            nuevoNodo->anterior = 0;
            nodos->insertarFinal(nuevoNodo);
            numeroNodos++;
            return nuevoNodo;
        }

    int Graph::insertarArista(int peso,char inicio, char destino){

        Node<nodeGraph<int>*>* nodoInicio = nodos->obtenerValor(0);
        Node<nodeGraph<int>*>* nodoFinal = nodos->obtenerValor(0);
        Edge<int,nodeGraph>*edge = new Edge<int,nodeGraph>;
        edge->peso = peso;

        for(int i = 0; i < nodos->size; i++){
            if(nodoInicio->valor->dato == inicio){
                nodoInicio->valor->adyacencia->insertarFinal(edge);
                break;
            }
            nodoInicio = nodoInicio->siguiente;
        }

        for(int i = 0; i < nodos->size; i++){
            if(nodoFinal->valor->dato == destino){
                edge->destino = nodoFinal->valor;
                break;
            }
            nodoFinal = nodoFinal->siguiente;
        }

        return 0;
    }

    nodeGraph<int >* Graph::desencolar(){
            Node<nodeGraph<int>*>* aux;
            if(ini->size == 0){
                    return NULL;
            }else{
                    aux=ini->obtenerValor(0);
                    Node<nodeGraph<int>*>* iniNode = ini->obtenerValor(0);
                    iniNode = iniNode->siguiente;
                    aux->siguiente=NULL;
                    if(ini==NULL){
                        ini->cola=NULL;
                    }
                    ini->cabeza = iniNode;
            }
            nodeGraph<int>* resultado = aux->valor;
            //free(aux);
            ini->eliminarInicio();
            return resultado;
    }

    void Graph::insertarPila(nodeGraph<int>* aux){
        ini->insertarInicio(aux);
    }


    void Graph::reiniciar(){
        Node<nodeGraph<int>*>* inicioNode = nodos->obtenerValor(0);
        nodeGraph<int>* inicio = inicioNode->valor;
            if(inicio!=NULL){
                    nodeGraph<int>* auxiliar =inicio;
                    while(auxiliar!=NULL){
                            auxiliar->visitado = auxiliar->terminado = 0;
                        inicioNode = inicioNode->siguiente;
                        if(inicioNode != NULL){
                            auxiliar = inicioNode->valor;
                        }else{
                            auxiliar = NULL;
                        }
                    }
            }
    }

    void Graph::dijkstra(char inicio, char b){
        Node<nodeGraph<int>*>* fuenteNode = nodos->obtenerValor(0);
        nodeGraph<int>* fuente = fuenteNode->valor;
        for(int i = 0; i < nodos->size; i++){
            fuenteNode = nodos->obtenerValor(i);
            if(fuenteNode->valor->dato == inicio){
                fuente = fuenteNode->valor;
                break;
            }
        }
        fuente->monto = 0;
        fuente->terminado = 1;

        while(fuenteNode != NULL){
            Node<Edge<int,nodeGraph>*>* edgeNodo = fuente->adyacencia->obtenerValor(0);
            Edge<int,nodeGraph>* edge = edgeNodo->valor;

            while(edgeNodo != NULL){
                if((edge->destino->monto = -1) || (fuente->monto + edge->peso)< edge->destino->monto){
                    edge->destino->monto = fuente->monto + edge->peso;
                    edge->destino->anterior = fuente->dato;
                }
                edgeNodo = edgeNodo->siguiente;
                if(edgeNodo != NULL){
                    edge = edgeNodo->valor;
                }
            }
            Node<nodeGraph<int>*>* minimoNode = fuenteNode;
            nodeGraph<int>* minimo = minimoNode->valor;
            while(minimo->anterior==0 || minimo->terminado == 1){
                minimoNode = minimoNode->siguiente;
                minimo = minimoNode->valor;
            }while(fuenteNode != NULL){
                if(fuente->monto < minimo->monto && fuente->terminado == 0 && fuente->dato != 0){
                    minimo = fuente;
                }
                fuenteNode = fuenteNode->siguiente;
                if(fuenteNode != NULL){
                    fuente = fuenteNode->valor;
                }
            }
            fuente = minimo;
            fuente->terminado = 1;

            if(fuente->dato = b){
                break;
            }

        }
        while(fuente->anterior!=0){
            insertarPila(fuente);
            char temp=fuente->anterior;
            fuente= (nodos->obtenerValor(0))->valor;
            while(fuente->dato!=temp){
                fuenteNode = fuenteNode->siguiente;
                fuente = fuenteNode->valor;
            }
        }

        insertarPila(fuente);
        while(ini->size != 0){
            printf("%c ",desencolar()->dato);
        }
        printf("\n");
        reiniciar();
    }*/
