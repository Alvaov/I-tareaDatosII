#include <stdio.h>
#include "linkedList.hpp"


int main(){
    linkedList<int> lista;
    lista.insertarInicio(3);
    lista.insertarInicio(5);
    lista.insertarInicio(76);
    lista.insertarFinal(876);
    lista.insertarInicio(13);
    lista.insertarFinal(27);
    lista.display();
    return 0;
}