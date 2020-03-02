#ifndef GRAPH_HPP
#define GRAPH_HPP
/**
 *Codigo basado en https://github.com/GGLSoftware/Grafos/blob/master/Grafo.c#L254
 * Modificado por Alejandro Vásquez Oviedo
*/

#include <stdio.h>
#include <string>
#include <string.h>

using namespace std;

#define Nodo struct nodo
#define Arista struct arista
#define Lista struct pila

/**
 * Estructura que almacena los nodos utilizados para representar los vertices
 * del grafo y a su vez funciona como lista de nodos
 */
Nodo{
    char dato;
    Nodo* siguiente;
    Arista* adyacencia;
    int visitado,terminado;
    int monto;
    char anterior;
};

/**
 * Estructura que almacena las aristas utilizados para representar los vertices
 * del grafo y a su vez funciona como lista de nodos
 */
Arista{
    Nodo*vrt;
    Arista*siguiente;
    int peso;
};

/**
 * Estructura que almacena un puntero a un nodo y una referencia de tipo lista al
 * siguiente, con el objetivo de utilizarlo como los nodos de la cola para
 * Dijkstra
*/
Lista{
    Nodo* dato;
    Lista*siguiente;
    int size;
};
/**
 * Clase grafo que permite la creación del grafo, sus nodos y aristas. Así como
 * la implementación de Dijkstra con
*/
class Graph{
public:
    /**
     * @brief inicio
     * Primer nodo del grafo
     */
    Nodo*inicio=NULL;
    /**
     * @brief ini
     * Lista donde se almacenará la cola requerida para Dijkstra
     */
    Lista*ini=NULL;
    /**
     * @brief final
     * Referencia utilizada en la cola como el final de esta
     */
    Lista*final=NULL;
    /**
     * Función que permite crear un nuevo nodo sin conexiones al grafo.
     * Obtiene un char como el valor que contendrá el nodo
    */
    char insertarNodo(char dato){
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
        return nuevo->dato;

     }
    /**
     * Método que toma el peso, origen y destino como parámetros para formar una arista
     * Se apoya en agregarArista() para completar la conexión entre dos nodos de un
     * grafo dirigido
    */
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
    /**
     * Método auxiliar en la creación de aristas encargado de asignar la arista a la
     * adyacencia del nodo origen e indicar el nodo destino en el atributo respectivo
     * de la arista
    */
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
    /**
     * Método que permite insertar nuevos elementos en una pila
    */
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

    /**
     * Método que permite sacar los elmentos de la pila
    */
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
    /**
     * Reinicia los valores se los nodos dejando el grafo listo para la siguiente evaluación
    */
    void reiniciar(){
        if(inicio!=NULL){
            Nodo*aux=inicio;
            while(aux!=NULL){
                aux->visitado=aux->terminado=0;
                aux=aux->siguiente;
            }
        }
    }
    /**
     * Método cuya función consiste en ejecutar Dijkstra desde un nodo a hasta un nodo
     * b
    */
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
            //printf("%c ",paso);
            ruta = ruta+" "+paso;

        }
            //printf("\n");
        reiniciar();
        return ruta;
    }
};
#endif
