#include <stdio.h>
#include "linkedList.hpp"


int main(){
    printf("hola mundo");
    linkedList<int> lista;
    lista.insertarInicio(3);
    lista.insertarInicio(5);
    lista.insertarInicio(76);
    lista.insertarInicio(876);
    lista.insertarInicio(13);
    lista.display();
    return 0;
}