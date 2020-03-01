#include "mainwindow.h"
#include "Graph.hpp"
#include <QApplication>
#include <stdio.h>

int main(int argc, char *argv[])
{
    Graph* grafo = new Graph();
    grafo->insertarNodo('A');
    grafo->insertarNodo('B');
    grafo->insertarNodo('C');
    grafo->insertarNodo('D');
    grafo->insertarNodo('E');
    grafo->insertarNodo('F');
    grafo->insertarNodo('G');
    grafo->insertarNodo('H');
    grafo->insertarNodo('I');
    grafo->insertarArista(5,'A','B');
    grafo->insertarArista(1,'A','G');
    grafo->insertarArista(2,'B','E');
    grafo->insertarArista(6,'B','C');
    grafo->insertarArista(3,'G','E');
    grafo->insertarArista(10,'G','H');
    grafo->insertarArista(1,'E','F');
    grafo->insertarArista(2,'C','D');
    grafo->insertarArista(3,'C','F');
    grafo->insertarArista(3,'F','H');
    grafo->insertarArista(2,'H','I');
    grafo->insertarArista(1,'H','D');
    grafo->insertarArista(2,'D','I');
    grafo->dijkstra('A', 'I');
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
