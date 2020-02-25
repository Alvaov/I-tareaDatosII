#include <stdio.h>
#include "linkedList.hpp"


int main(){
    linkedList<int> lista;
    lista.insertarFinal(3);
    lista.insertarFinal(5);
    lista.insertarFinal(76);
    lista.insertarFinal(876);
    //lista.insertarInicio(13);
    lista.insertarFinal(27);
    //lista.insertarPosicion(555,5);
    lista.display();
    //lista.eliminarPosicion(2);
    //lista.eliminarInicio();
    lista.intercambiar(3,5);
    lista.display();
    //lista.eliminarInicio();
    //lista.displayR();
    return 0;
}